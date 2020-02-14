/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "gfx/legato/memory/legato_memory.h"

#include <stdlib.h>
#include <string.h>

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/memory/legato_variableheap.h"

#if LE_FIXEDHEAP_ENABLE == 1

#include "gfx/legato/memory/legato_fixedheap.h"

uint8_t fixedHeap16[LE_FIXEDHEAP_BLOCK_SIZE(16) * LE_FIXEDHEAP_SIZE_16];
uint8_t fixedHeap32[LE_FIXEDHEAP_BLOCK_SIZE(32) * LE_FIXEDHEAP_SIZE_32];
uint8_t fixedHeap64[LE_FIXEDHEAP_BLOCK_SIZE(64) * LE_FIXEDHEAP_SIZE_64];
uint8_t fixedHeap128[LE_FIXEDHEAP_BLOCK_SIZE(128) * LE_FIXEDHEAP_SIZE_128];
uint8_t fixedHeap196[LE_FIXEDHEAP_BLOCK_SIZE(196) * LE_FIXEDHEAP_SIZE_196];
uint8_t fixedHeap256[LE_FIXEDHEAP_BLOCK_SIZE(256) * LE_FIXEDHEAP_SIZE_256];

typedef struct leFixedMemoryPoolDef
{
    uint32_t size;
    uint32_t count;
    void* data;
} leFixedMemoryPoolDef;

static leFixedMemoryPoolDef fixedPoolDefs[] = 
{
    { 16, LE_FIXEDHEAP_SIZE_16, fixedHeap16 },
    { 32, LE_FIXEDHEAP_SIZE_32, fixedHeap32 },
    { 64, LE_FIXEDHEAP_SIZE_64, fixedHeap64 },
    { 128, LE_FIXEDHEAP_SIZE_128, fixedHeap128 },
    { 196, LE_FIXEDHEAP_SIZE_196, fixedHeap196 },
    { 256, LE_FIXEDHEAP_SIZE_256, fixedHeap256 },
    { 0, 0, NULL }
};

leFixedHeap fixedHeaps[LE_FIXED_HEAP_COUNT];

#endif

uint8_t variableHeapData[LE_VARIABLEHEAP_SIZE];

leVariableHeap variableHeap;

leResult leMemory_Init()
{
#if LE_FIXEDHEAP_ENABLE == 1
    uint32_t i = 0;
    leFixedHeap* heap;
    
    memset(&fixedHeaps, 0, sizeof(fixedHeaps));
    
    while(fixedPoolDefs[i].data != NULL)
    {
        heap = &fixedHeaps[i];
        
        leFixedHeap_Init(heap,
                         fixedPoolDefs[i].size,
                         fixedPoolDefs[i].count,
                         fixedPoolDefs[i].data);
                         
        i++;
    }
#endif
    
    leVariableHeap_Init(&variableHeap,
                        variableHeapData,
                        LE_VARIABLEHEAP_SIZE);
    
    return LE_SUCCESS;
}

#if LE_USE_DEBUG_ALLOCATOR == 1
void* leMalloc(size_t size,
               size_t line,
               const char* func,
               const char* file)
#else
void* leMalloc(size_t size)
#endif
{
    void* ptr;
    
#if LE_FIXEDHEAP_ENABLE == 1
    uint32_t i = 0;
    
    /* try to find a fixed heap that this will fit in */
    while(fixedHeaps[i].initialized == LE_TRUE)
    {
        if(size < fixedHeaps[i].logicalBlockSize)
        {
#if LE_USE_DEBUG_ALLOCATOR == 1
            ptr = leFixedHeap_Alloc(&fixedHeaps[i],
                                    line,
                                    func,
                                    file);
#else
            ptr = leFixedHeap_Alloc(&fixedHeaps[i]);
#endif                                    
         
            LE_ASSERT(ptr != NULL);
            
            if(ptr != NULL)
            {
#if LE_MALLOC_ZEROIZE == 1
                memset(ptr, 0, size);
#endif                
                
                return ptr;        
            }
                
            return NULL;        
        }
        
        i++;
    }
#endif
    
    /* use the dynamic allocator to handle anything the fixed heaps can't fit */
#if LE_USE_DEBUG_ALLOCATOR == 1    
    ptr = leVariableHeap_Alloc(&variableHeap,
                               size,
                               line,
                               func,
                               file);
#else
    ptr = leVariableHeap_Alloc(&variableHeap, size);
#endif
    
    LE_ASSERT(ptr != NULL);
    
    if(ptr != NULL)
    {
#if LE_MALLOC_ZEROIZE == 1    
        memset(ptr, 0, size);
#endif        
        
        return ptr;        
    }
    
    return ptr;
}

#if LE_USE_DEBUG_ALLOCATOR == 1
void* leRealloc(void* ptr,
                size_t size,
                size_t line,
                const char* func,
                const char* file)
#else
void* leRealloc(void* ptr, size_t size)
#endif
{
    void* newPtr = NULL;
    uint32_t oldSize = 0;

#if LE_FIXEDHEAP_ENABLE == 1
    uint32_t i = 0;
#endif
    
    if(size == 0)
        return NULL;
    
    if(ptr == NULL)
    {
#if LE_USE_DEBUG_ALLOCATOR == 1
        return leMalloc(size, line, func, file);
#else
        return leMalloc(size);
#endif
    }
       
#if LE_FIXEDHEAP_ENABLE == 1
    /* try to find the size of the old pointer for data preservation */
    while(fixedHeaps[i].initialized == LE_TRUE)
    {
        if(leFixedHeap_Contains(&fixedHeaps[i], ptr) == LE_TRUE)
        {
            oldSize = fixedHeaps[i].logicalBlockSize;
            
            break;
        }
        
        i++;
    }
#endif
    
    if(oldSize == 0)
    {
        oldSize = leVariableHeap_SizeOf(&variableHeap, ptr);
    }
    
    /* couldn't find old pointer */
    if(oldSize == 0)
        return NULL;
        
#if LE_USE_DEBUG_ALLOCATOR == 1
    newPtr = leMalloc(size, line, func, file);
#else
    newPtr = leMalloc(size);
#endif
    
    LE_ASSERT(newPtr != NULL);
    
    if(newPtr == NULL)
        return NULL;
    
    if(oldSize < size)
    {
        /* new block can completely contain old data */
        memcpy(newPtr, ptr, size);
    }
    else
    {
        /* need to truncate old data for new block */
        memcpy(newPtr, ptr, size);
    }
    
    LE_FREE(ptr);
    
    return newPtr;
}

void leFree(void* ptr)
{
#if LE_FIXEDHEAP_ENABLE == 1
    uint32_t i = 0;
#endif
    
    if(ptr == NULL)
        return;
      
#if LE_FIXEDHEAP_ENABLE == 1  
    /* try to find the fixed heap that contains this pointer */
    while(fixedHeaps[i].initialized == LE_TRUE)
    {
        /* make sure the heap actually contains this pointer */
        if(leFixedHeap_Contains(&fixedHeaps[i], ptr) == LE_TRUE)
        {
            leFixedHeap_Free(&fixedHeaps[i], ptr);
            
            return;
        }
        
        i++;
    }
#endif
    
    /* attempt to free from the dynamic heap */
    leVariableHeap_Free(&variableHeap, ptr);
}

void leMemoryGetUsageReport(leMemoryStatusReport* rpt)
{
    size_t idx;
    
    if(rpt == NULL)
        return;
        
    rpt->variableHeapReport.size = variableHeap.size;
    rpt->variableHeapReport.maxUsage = variableHeap.maxUsage;
    rpt->variableHeapReport.used = variableHeap.used;
    
    for(idx = 0; idx < LE_FIXED_HEAP_COUNT - 1; idx++)
    {
        rpt->fixedHeapReport[idx].logicalSize = fixedHeaps[idx].logicalBlockSize;
        rpt->fixedHeapReport[idx].numElements = fixedHeaps[idx].numElements;
        rpt->fixedHeapReport[idx].maxUsage = fixedHeaps[idx].maxUsage;
        rpt->fixedHeapReport[idx].currentCapacity = fixedHeaps[idx].capacity;
    }
}

#ifdef _WIN32
void leMemoryDumpAllocations()
{
    size_t idx;
    
    leVariableHeap_Dump(&variableHeap, LE_TRUE);
    
    for(idx = 0; idx < LE_FIXED_HEAP_COUNT - 1; idx++)
    {
        leFixedHeap_Dump(&fixedHeaps[idx], LE_TRUE);
    }
}
#endif

leResult leMemoryValidateHeaps()
{
    size_t idx;
    
    if(leVariableHeap_Validate(&variableHeap) == LE_FAILURE)
        return LE_FAILURE;
        
    for(idx = 0; idx < LE_FIXED_HEAP_COUNT - 1; idx++)
    {
        if(leFixedHeap_Validate(&fixedHeaps[idx]) == LE_FAILURE)
            return LE_FAILURE;
    }
    
    return LE_SUCCESS;
}
