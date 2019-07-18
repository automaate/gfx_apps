/*******************************************************************************
  2D Graphics Engine PLIB_GFX2D PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_gfx2d.c

  Summary
    PLIB_GFX2D PLIB Implementation File.

  Description
    This file defines the interface to the PLIB_GFX2D peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/
#include "device.h"
#include "plib_gfx2d.h"


#define CONF_GFX2D_GC_REGEN             1
#define CONF_GFX2D_GC_MTY               1
#define GFX2D_GC_MTY_Pos                1
#define GFX2D_GC_REGEN_Pos              1
#define CONF_GFX2D_GC_MTY               1
#define GFX2D_GC_MTY_Pos                1
#define CONF_GFX2D_GC_REGQOS1           1
#define GFX2D_GC_REGQOS1_Pos            1
#define CONF_GFX2D_GC_REGQOS2           1
#define GFX2D_GC_REGQOS2_Pos            1
#define CONF_GFX2D_GC_REGQOS3           1
#define GFX2D_GC_REGQOS3_Pos            1
#define GFX2D_IS_EXEND                  1
#define GFX2D_PC0_SEL_Pos               1
#define GFX2D_PC0_FILT_Pos              1
#define GFX2D_PC1_SEL_Pos               1
#define GFX2D_PC1_FILT_Pos              1
//#define GFX2D_GS_STATUS                 1

#ifndef CONF_GFX2D_PC1_REG
#define CONF_GFX2D_PC1_REG ((CONF_GFX2D_PC1_SEL << GFX2D_PC1_SEL_Pos) | (CONF_GFX2D_PC1_FILT << GFX2D_PC1_FILT_Pos))
#endif

// <o> Memory Tile Access
// <0x0=> tile
// <0x1=> linear
// <id> gc_mty
#ifndef CONF_GFX2D_GC_MTY
#define CONF_GFX2D_GC_MTY 0
#endif
// </h>

// <e> Traffic Balancing Using Outstanding Regulation
// <i> Enable Traffic Balancing by using Outstanding Regulation
// <id> gc_regen
#ifndef CONF_GFX2D_GC_REGEN
#define CONF_GFX2D_GC_REGEN 0
#endif

// <o> Regulation for QoS Level 1 <0-10>
// <i> Indicates the number of clock cycles inserted between outstanding transactions.
// <i> The number of clock cycles added is calculated as follows. latency = (2^qos) - 1.
// <i> The maximum number of clock cycles is 1023.
// <id> gc_regqos1
#ifndef CONF_GFX2D_GC_REGQOS1
#define CONF_GFX2D_GC_REGQOS1 0
#endif

// <o> Regulation for QoS Level 2 <0-10>
// <i> Indicates the number of clock cycles inserted between outstanding transactions.
// <i> The number of clock cycles added is calculated as follows. latency = (2^qos) - 1.
// <i> The maximum number of clock cycles is 1023.
// <id> gc_regqos2
#ifndef CONF_GFX2D_GC_REGQOS2
#define CONF_GFX2D_GC_REGQOS2 0
#endif

// <o> Regulation for QoS Level 3 <0-10>
// <i> Indicates the number of clock cycles inserted between outstanding transactions.
// <i> The number of clock cycles added is calculated as follows. latency = (2^qos) - 1.
// <i> The maximum number of clock cycles is 1023.
// <id> gc_regqos3
#ifndef CONF_GFX2D_GC_REGQOS3
#define CONF_GFX2D_GC_REGQOS3 0
#endif

// <o> Metrics Selection 0
// <0x0=> disable
// <0x1=> read
// <0x2=> write
// <0x2=> cycle
// <id> pc0_sel
#ifndef CONF_GFX2D_PC0_SEL
#define CONF_GFX2D_PC0_SEL 0
#endif

// <o> Filter Selection 0
// <0x0=> disable
// <0x1=> qos0
// <0x2=> qos1
// <0x2=> qos2
// <id> pc0_filt
#ifndef CONF_GFX2D_PC0_FILT
#define CONF_GFX2D_PC0_FILT 0
#endif

// <o> Metrics Selection 1
// <0x0=> disable
// <0x1=> read
// <0x2=> write
// <0x2=> cycle
// <id> pc1_sel
#ifndef CONF_GFX2D_PC1_SEL
#define CONF_GFX2D_PC1_SEL 0
#endif

// <o> Filter Selection 1
// <0x0=> disable
// <0x1=> qos0
// <0x2=> qos1
// <0x2=> qos2
// <id> pc1_filt
#ifndef CONF_GFX2D_PC1_FILT
#define CONF_GFX2D_PC1_FILT 0
#endif
// </e>

#ifndef CONF_GFX2D_GC_REG
#define CONF_GFX2D_GC_REG                                                                                              \
        ((CONF_GFX2D_GC_REGEN << GFX2D_GC_REGEN_Pos) | (CONF_GFX2D_GC_MTY << GFX2D_GC_MTY_Pos)                             \
         | (CONF_GFX2D_GC_REGQOS1 << GFX2D_GC_REGQOS1_Pos)                                                                 \
         | (CONF_GFX2D_GC_REGQOS2 << GFX2D_GC_REGQOS2_Pos)                                                                 \
         | (CONF_GFX2D_GC_REGQOS3 << GFX2D_GC_REGQOS3_Pos))
#endif

#ifndef CONF_GFX2D_PC0_REG
#define CONF_GFX2D_PC0_REG ((CONF_GFX2D_PC0_SEL << GFX2D_PC0_SEL_Pos) | (CONF_GFX2D_PC0_FILT << GFX2D_PC0_FILT_Pos))
#endif

#ifndef CONF_GFX2D_PC1_REG
#define CONF_GFX2D_PC1_REG ((CONF_GFX2D_PC1_SEL << GFX2D_PC1_SEL_Pos) | (CONF_GFX2D_PC1_FILT << GFX2D_PC1_FILT_Pos))
#endif

#ifndef CONF_GFX2D_LEN_REG
#define CONF_GFX2D_LEN_REG 0x1
#endif

struct gpu_instruction_ldr {
        uint32_t wd0;
        uint32_t wd1;
};

struct gpu_instruction_str {
        uint32_t wd0;
};

struct gpu_instruction_wfe {
        uint32_t wd0;
};

struct gpu_instruction_fill {
        uint32_t wd0;
        uint32_t wd1;
        uint32_t wd2;
        uint32_t wd3;
};

struct gpu_instruction_copy {
        uint32_t wd0;
        uint32_t wd1;
        uint32_t wd2;
        uint32_t wd3;
};

struct gpu_instruction_blend {
        uint32_t wd0;
        uint32_t wd1;
        uint32_t wd2;
        uint32_t wd3;
        uint32_t wd4;
        uint32_t wd5;
};

struct gpu_instruction_rop {
        uint32_t wd0;
        uint32_t wd1;
        uint32_t wd2;
        uint32_t wd3;
        uint32_t wd4;
        uint32_t wd5;
        uint32_t wd6;
};

/**
 * \berif LDR Instruction.
 */
#define GFX2D_INST_LDR_WD0(ldrc, ldrcid, ldrcs, ie)                                                                    \
        (((ldrc) << 8) | ((ldrcid) << 9) | ((ldrcs) << 10) | ((reg) << 16) | ((ie) << 24) | (0x8 << 28))
#define GFX2D_INST_LDR_WD1(data) (data)

/**
 * \berif STR Instruction.
 */
#define GFX2D_INST_STR_WD0(regad, reg, ie) (((regad) << 12) | ((reg) << 16) | ((ie) << 24) | (0x9 << 28))

/**
 * \berif WFE Instruction.
 */
#define GFX2D_INST_WFE_WD0() (0xA << 28)

/**
 * \berif FILL Instruction.
 */
#define GFX2D_INST_FILL_WD0(args, dir, reg, ie) ((args) | ((dir) << 8) | ((reg) << 16) | ((ie) << 24) | (0xB << 28))
#define GFX2D_INST_FILL_WD1(width, heigh) ((width) | ((heigh) << 16))
#define GFX2D_INST_FILL_WD2(dx0, dy0) ((dx0) | ((dy0) << 16))
#define GFX2D_INST_FILL_WD3(a, r, g, b) ((b) | ((g) << 8) | ((r) << 16) | ((a) << 24))

/**
 * \berif COPY Instruction.
 */
#define GFX2D_INST_COPY_WD0(dir, reg, hwt, ie)                                                                         \
        (2 | ((dir) << 8) | ((reg) << 16) | ((hwt) << 20) | ((ie) << 24) | (0xC << 28))
#define GFX2D_INST_COPY_WD1(width, heigh) ((width) | ((heigh) << 16))
#define GFX2D_INST_COPY_WD2(dx0, dy0) ((dx0) | ((dy0) << 16))
#define GFX2D_INST_COPY_WD3(sx0, sy0) ((sx0) | ((sy0) << 16))

/**
 * \berif BLEND Instruction.
 */
#define GFX2D_INST_BLEND_WD0(dir, reg, ie) (4 | ((dir) << 8) | ((reg) << 16) | ((ie) << 24) | (0xD << 28))
#define GFX2D_INST_BLEND_WD1(width, heigh) ((width) | ((heigh) << 16))
#define GFX2D_INST_BLEND_WD2(dx0, dy0) ((dx0) | ((dy0) << 16))
#define GFX2D_INST_BLEND_WD3(sx0, sy0) ((sx0) | ((sy0) << 16))
#define GFX2D_INST_BLEND_WD4(sx1, sy1) ((sx1) | ((sy1) << 16))
#define GFX2D_INST_BLEND_WD5(spe, func, dfact, sfact) ((sfact) | ((dfact) << 4) | ((func) << 8) | ((spe) << 12))

/**
 * \berif ROP Instruction.
 */
#define GFX2D_INST_ROP_WD0(reg, ie) (5 | ((reg) << 16) | ((ie) << 24) | (0xE << 28))
#define GFX2D_INST_ROP_WD1(width, heigh) ((width) | ((heigh) << 16))
#define GFX2D_INST_ROP_WD2(dx0, dy0) ((dx0) | ((dy0) << 16))
#define GFX2D_INST_ROP_WD3(sx0, sy0) ((sx0) | ((sy0) << 16))
#define GFX2D_INST_ROP_WD4(sx1, sy1) ((sx1) | ((sy1) << 16))
#define GFX2D_INST_ROP_WD5(pmask) (pmask)
#define GFX2D_INST_ROP_WD6(ropl, roph, ropm) ((ropl) | ((roph) << 8) | ((ropm) << 16))

// *****************************************************************************
// *****************************************************************************
// Section: GFX2D temporary
// *****************************************************************************
// *****************************************************************************
/* -------- GFX2D : (GFX2D Offset: 0x2C) ( R/ 32) Interrupt Mask Register -------- */
//#define GFX2D_GD_Msk                     _U_(0x1)
//#define GFX2D_GE_ENABLE                  _U_(0x1)
//#define GFX2D_GS_BUSY                    _U_(0x1)
//#define GFX2D_ID_Msk                     _U_(0x1)
//#define GFX2D_IE_EXEND_Msk               _U_(0x1)
//#define GFX2D_IE_RERR_Msk                _U_(0x1)
//#define GFX2D_IE_BERR                    _U_(0x1)
//#define GFX2D_IE_IERR                    _U_(0x1)

//#define GFX2D_REGS                         ((gfx2d_registers_t*)0x40044000)                /**< \brief GFX2D Registers Address        */
#define GPU_BUFFER_FORMAT_SIZE      400

// *****************************************************************************
// *****************************************************************************
// Global Configuration, Enable, Disable, Status
// *****************************************************************************
// *****************************************************************************
          
void GFX2D_SetClockGatingDisableCore(GFX2D_CLOCK_GATING gating)
{
    GFX2D_REGS->GFX2D_GC = (GFX2D_REGS->GFX2D_GC & ~GFX2D_GC_CGDISCORE_Msk) | 
                                GFX2D_GC_CGDISCORE(gating == GFX2D_CLOCK_GATING_DISABLED);
}
          
void GFX2D_SetClockGatingDisableAXI(GFX2D_CLOCK_GATING gating)
{
    GFX2D_REGS->GFX2D_GC = (GFX2D_REGS->GFX2D_GC & ~GFX2D_GC_CGDISAXI_Msk) | 
                                GFX2D_GC_CGDISAXI(gating == GFX2D_CLOCK_GATING_DISABLED);
}

void GFX2D_SetClockGatingDisableFIFO(GFX2D_CLOCK_GATING gating)
{
    GFX2D_REGS->GFX2D_GC = (GFX2D_REGS->GFX2D_GC & ~GFX2D_GC_CGDISFIFO_Msk) | 
                                GFX2D_GC_CGDISFIFO(gating == GFX2D_CLOCK_GATING_DISABLED);
}

void GFX2D_SetOutstandingRegulationEnable(bool enable)
{
    GFX2D_REGS->GFX2D_GC = (GFX2D_REGS->GFX2D_GC & ~GFX2D_GC_REGEN_Msk) | 
                                  GFX2D_GC_REGEN(enable == true);
}

void GFX2D_SetMemoryTileAccess(GFX2D_MEMORY_ACCESS access)
{
    GFX2D_REGS->GFX2D_GC = (GFX2D_REGS->GFX2D_GC & ~GFX2D_GC_MTY_Msk) | 
                                  GFX2D_GC_MTY(access == GFX2D_MEMORY_LINEAR_ACCESS);
}

void GFX2D_SetControllerEnable(bool enable)
{
    if (enable == true)
        GFX2D_REGS->GFX2D_GE = (GFX2D_REGS->GFX2D_GE & ~GFX2D_GE_ENABLE_Msk) | 
                                      GFX2D_GE_ENABLE(1);
    else
        GFX2D_REGS->GFX2D_GD = (GFX2D_REGS->GFX2D_GD & ~GFX2D_GD_DISABLE_Msk) | 
                                      GFX2D_GD_DISABLE(1);
}

bool GFX2D_GetGlobalStatusEnabled( void )
{
    return ((GFX2D_REGS->GFX2D_GS & GFX2D_GS_STATUS_Msk) == GFX2D_GS_STATUS_Msk);
}

bool GFX2D_GetGlobalStatusBusy( void )
{
    return ((GFX2D_REGS->GFX2D_GS & GFX2D_GS_BUSY_Msk) == GFX2D_GS_BUSY_Msk);
}

bool GFX2D_GetGlobalStatusWaitForEvent( void )
{
    return ((GFX2D_REGS->GFX2D_GS & GFX2D_GS_WFEIP_Msk) == GFX2D_GS_WFEIP_Msk);
}

// *****************************************************************************
// *****************************************************************************
// Performance Configuration
// *****************************************************************************
// *****************************************************************************

void GFX2D_SetPerformanceConfigFilter0(GFX2D_PERFORMANCE_FILTER_CONFIG filter)
{
    GFX2D_REGS->GFX2D_SUB0[0].GFX2D_PC = (GFX2D_REGS->GFX2D_SUB0[0].GFX2D_PC & ~GFX2D_PC_FILT_Msk) | 
                                  GFX2D_PC_FILT(filter);
}

void GFX2D_SetPerformanceConfigFilter1(GFX2D_PERFORMANCE_FILTER_CONFIG filter)
{
    GFX2D_REGS->GFX2D_SUB0[1].GFX2D_PC = (GFX2D_REGS->GFX2D_SUB0[1].GFX2D_PC & ~GFX2D_PC_FILT_Msk) | 
                                  GFX2D_PC_FILT(filter);
}

void GFX2D_SetPerformanceMetricsSelection0(GFX2D_PERFORMANCE_METRICS_SELECTION selection)
{
    GFX2D_REGS->GFX2D_SUB0[0].GFX2D_PC = (GFX2D_REGS->GFX2D_SUB0[0].GFX2D_PC & ~GFX2D_PC_SEL_Msk) | 
                                  GFX2D_PC_SEL(selection);
}

void GFX2D_SetPerformanceMetricsSelection1(GFX2D_PERFORMANCE_METRICS_SELECTION selection)
{
    GFX2D_REGS->GFX2D_SUB0[1].GFX2D_PC = (GFX2D_REGS->GFX2D_SUB0[1].GFX2D_PC & ~GFX2D_PC_SEL_Msk) | 
                                  GFX2D_PC_SEL(selection);
}

// *****************************************************************************
// *****************************************************************************
// Fill Instruction
// *****************************************************************************
// *****************************************************************************
void GFX2D_SetSurfaceAddress(GFX2D_SURFACE surface, uint32_t addr)
{
    GFX2D_REGS->GFX2D_CHID[surface].GFX2D_PA = GFX2D_PA_PA(addr);
}

void GFX2D_SetSurfacePitch(GFX2D_SURFACE surface, uint16_t pitch)
{
    GFX2D_REGS->GFX2D_CHID[surface].GFX2D_PITCH = GFX2D_PITCH_PITCH(pitch);
}

void GFX2D_SetSurfaceColorLookupTable(GFX2D_SURFACE surface, GFX2D_COLOR_LOOKUP_TABLE table)
{
    GFX2D_REGS->GFX2D_CHID[surface].GFX2D_CFG = GFX2D_CFG_IDXCX(table);
}

void GFX2D_SetSurfacePixelFormat(GFX2D_SURFACE surface, GFX2D_PIXEL_FORMAT format)
{
    GFX2D_REGS->GFX2D_CHID[surface].GFX2D_CFG = GFX2D_CFG_PF(format);
}

// *****************************************************************************
// *****************************************************************************
// Section: GFX2D local
// *****************************************************************************
// *****************************************************************************

PLIB_GFX2D_IRQ_CALLBACK_OBJECT GFX2D_IRQ_CallbackObj;

static GFX2D_OBJ gfx2dObj;
static gfx2d_registers_t *GFX2D_Module = GFX2D_REGS;

/* GPU Instruction Ring Buffer */
__attribute__((aligned(256))) uint32_t rb[0x40 * (CONF_GFX2D_LEN_REG + 1)];

static uint8_t _gfx2d_pixel_size[GPU_BUFFER_FORMAT_SIZE] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 4, 4};

static inline int32_t _gfx2d_check_rb(uint8_t l)
{
        uint32_t head;
        uint32_t tail;
        uint32_t len;

    head = GFX2D_Module->GFX2D_HEAD;
    tail = GFX2D_Module->GFX2D_TAIL;
    len = GFX2D_Module->GFX2D_LEN;
    len  = (0x40 << len);

        /* Only GPU engine can make head equals tail. Ringbuffer is empty */
        if (head == tail) {
                return 0;
        }

        /* The queue is full when have inserted N-1 instructions,
               where N is the number of entries */
        if (tail > head) {
                if ((tail - head) <= len) {
                        return -1;
                }
        } else if ((head - tail) <= len) {
                return -1;
        }
        return 0;
}

int32_t _gpu_instruction(uint32_t *i, uint8_t len)
{
        uint32_t cmd;
        uint32_t rbase;
        uint32_t head;
        uint32_t rblen;

        /* Check if there enough ring buffer space to store instruction */
        if (_gfx2d_check_rb(len) != 0) {
                return 1;
        }

        /* Check if previous instruction finished */
        if ( GFX2D_GetGlobalStatusBusy() == true )
        {
                //if (((GFX2D_Module->GFX2D_GS & GFX2D_GS_STATUS) > 0) == 0) {
                return 1;
        }

        rbase  = GFX2D_Module->GFX2D_BASE;
        head  = GFX2D_Module->GFX2D_HEAD;
        rblen = GFX2D_Module->GFX2D_LEN;

        /* FILL instruction may have variable length */
        if ((((*i) >> 28) == 0xB) && (((*i) & 0xF) != 2)) {
                len -= (2 - ((*i) & 0xF));
        }

        /* Store instruction to Ring Buffer */
        do {
                cmd                = rbase + (head << 2);
                *((uint32_t *)cmd) = *i;
                head               = (head + 1) % (0x40 << rblen);
                i++;
                len--;
        } while (len > 0);

        /* Synchronize Head-Pointer */
//	__asm("DSB");

        /* Update HEAD register to inform the graphic that new instruction have
         * been added to the queue */
        GFX2D_Module->GFX2D_HEAD = head;

        return 0;
}

// *****************************************************************************
// *****************************************************************************
// Section: GFX2D Implementation
// *****************************************************************************
// *****************************************************************************


/* Register callback for period interrupt */
void PLIB_GFX2D_IRQ_CallbackRegister(PLIB_GFX2D_IRQ_CALLBACK callback, uintptr_t context)
{
    if (callback == NULL)
    {
        GFX2D_Module->GFX2D_ID = GFX2D_ID_Msk;
        return;
    }

    //GFX2D_Module->GFX2D_ID = (GFX2D_IE_EXEND_Msk | GFX2D_IE_RERR_Msk | GFX2D_IE_BERR | GFX2D_IE_IERR);

    GFX2D_IRQ_CallbackObj.callback_fn = callback;
    GFX2D_IRQ_CallbackObj.context = context;
}

void PLIB_GFX2D_Initialize( void )
{
  GFX2D_SetClockGatingDisableCore(GFX2D_CLOCK_GATING_ACTIVATED);
  GFX2D_SetClockGatingDisableAXI(GFX2D_CLOCK_GATING_ACTIVATED);
  GFX2D_SetClockGatingDisableFIFO(GFX2D_CLOCK_GATING_ACTIVATED);
  GFX2D_SetOutstandingRegulationEnable(false);
  GFX2D_SetMemoryTileAccess(GFX2D_MEMORY_TILE_ACCESS);

  GFX2D_SetPerformanceConfigFilter0(GFX2D_FILTER_DISABLED);
  GFX2D_SetPerformanceConfigFilter1(GFX2D_FILTER_DISABLED);
  GFX2D_SetPerformanceMetricsSelection0(GFX2D_METRICS_DISABLED);
  GFX2D_SetPerformanceMetricsSelection1(GFX2D_METRICS_DISABLED);

    //#if CONF_GFX2D_GC_REGEN == 1
    //GFX2D_Module->GFX2D_SUB0[0].GFX2D_PC = CONF_GFX2D_PC0_REG;
    //GFX2D_Module->GFX2D_SUB0[1].GFX2D_PC = CONF_GFX2D_PC1_REG;
    //#endif
}

void PLIB_GFX2D_DeInitialize( void )
{
    GFX2D_Module->GFX2D_GD = GFX2D_GD_Msk;
    GFX2D_Module->GFX2D_GC = 0;
}

void PLIB_GFX2D_Enable( void )
{
    GFX2D_Module->GFX2D_HEAD = 0;
    GFX2D_Module->GFX2D_TAIL = 0;
    GFX2D_Module->GFX2D_BASE = (uint32_t)rb;
    GFX2D_Module->GFX2D_LEN = CONF_GFX2D_LEN_REG;

    GFX2D_SetControllerEnable(true);
}

void PLIB_GFX2D_Disable( void )
{

    GFX2D_Module->GFX2D_HEAD = 0;
    GFX2D_Module->GFX2D_TAIL = 0;
    GFX2D_Module->GFX2D_BASE = (uint32_t)rb;
    GFX2D_Module->GFX2D_LEN = CONF_GFX2D_LEN_REG;

    GFX2D_SetControllerEnable(false);
}

void PLIB_GFX2D_InterruptHandler(void)
{
    uint32_t status;

    if ( gfx2dObj.callback == NULL )
    {
        return;
    }

    /* Read the peripheral status */
    status = GFX2D_Module->GFX2D_IS;

    switch( gfx2dObj.state )
    {
        default:
        {
            break;
        }
    }

    /*  */
    if( status & GFX2D_IS_EXEND )
    {
        GFX2D_IRQ_CallbackObj.callback_fn(GFX2D_IRQ_CallbackObj.context);
    }
}

GFX2D_STATUS PLIB_GFX2D_Fill(struct gpu_buffer *dst, struct gpu_rectangle *rect, gpu_color_t color)
{
    struct gpu_instruction_fill instr;

    GFX2D_SetSurfaceAddress(GFX2D_SURFACE_ZERO, dst->addr);
    GFX2D_SetSurfacePitch(GFX2D_SURFACE_ZERO, dst->width * _gfx2d_pixel_size[dst->format]);
    GFX2D_SetSurfaceColorLookupTable(GFX2D_SURFACE_ZERO, GFX2D_COLOR_LOOKUP_TABLE_ZERO);
    GFX2D_SetSurfacePixelFormat(GFX2D_SURFACE_ZERO, dst->format);

    instr.wd0 = GFX2D_INST_FILL_WD0(2, dst->dir, 0, 1);
    instr.wd1 = GFX2D_INST_FILL_WD1((rect->width - 1), (rect->height - 1));
    instr.wd2 = GFX2D_INST_FILL_WD2(rect->x, rect->y);
    instr.wd3 = GFX2D_INST_FILL_WD3(color&0xFF000000>>24, color&0x00ff0000>>16, color&0x0000ff00>>8, color&0x000000ff);

    return _gpu_instruction((uint32_t *)(&instr), 4);
}

GFX2D_STATUS PLIB_GFX2D_Copy(struct gpu_buffer *dst, struct gpu_rectangle *dst_rect, struct gpu_buffer *src,
                        struct gpu_rectangle *src_rect)
{
    struct gpu_instruction_copy instr;

    GFX2D_Module->GFX2D_CHID[0].GFX2D_PA = dst->addr;
    GFX2D_Module->GFX2D_CHID[0].GFX2D_PITCH = dst->width * _gfx2d_pixel_size[dst->format];
    GFX2D_Module->GFX2D_CHID[0].GFX2D_CFG = dst->format;

    GFX2D_Module->GFX2D_CHID[1].GFX2D_PA = dst->addr;
    GFX2D_Module->GFX2D_CHID[1].GFX2D_PITCH = dst->width * _gfx2d_pixel_size[dst->format];
    GFX2D_Module->GFX2D_CHID[1].GFX2D_CFG = dst->format;

    instr.wd0 = GFX2D_INST_COPY_WD0(0, 0, 0, 1);
    instr.wd1 = GFX2D_INST_COPY_WD1((dst_rect->width - 1), (dst_rect->height - 1));
    instr.wd2 = GFX2D_INST_COPY_WD2(dst_rect->x, dst_rect->y);
    instr.wd3 = GFX2D_INST_COPY_WD3(src_rect->x, src_rect->y);

    return _gpu_instruction((uint32_t *)(&instr), 4);
}

static const uint32_t _gfx2d_blend_val[12] = {
    GFX2D_INST_BLEND_WD5(0, 0, 7, 1), /* SRC_OVER, S + (1-Sa)xD */
    GFX2D_INST_BLEND_WD5(0, 0, 1, 9), /* DST_OVER, (1-Da)*S + D */
    GFX2D_INST_BLEND_WD5(0, 0, 0, 8), /* SRC_IN, Da*S */
    GFX2D_INST_BLEND_WD5(0, 0, 6, 0), /* DST_IN, Sa*D */
    GFX2D_INST_BLEND_WD5(0, 0, 1, 1), /* ADDITIVE, S + D */
    GFX2D_INST_BLEND_WD5(0, 0, 3, 0)  /* SUBTRACT, D * (1-S) */
};

GFX2D_STATUS PLIB_GFX2D_Blend(struct gpu_buffer *dst, struct gpu_rectangle *dst_rect, struct gpu_buffer *fg,
                         struct gpu_rectangle *fg_rect, struct gpu_buffer *bg, struct gpu_rectangle *bg_rect,
                         enum gpu_blend blend)
{
    struct gpu_instruction_blend instr;

    GFX2D_Module->GFX2D_CHID[0].GFX2D_PA = dst->addr;
    GFX2D_Module->GFX2D_CHID[0].GFX2D_PITCH = dst->width * _gfx2d_pixel_size[dst->format];
    GFX2D_Module->GFX2D_CHID[1].GFX2D_CFG = dst->format;

    GFX2D_Module->GFX2D_CHID[1].GFX2D_PA = dst->addr;
    GFX2D_Module->GFX2D_CHID[1].GFX2D_PITCH = dst->width * _gfx2d_pixel_size[dst->format];
    GFX2D_Module->GFX2D_CHID[1].GFX2D_CFG = dst->format;

    GFX2D_Module->GFX2D_CHID[2].GFX2D_PA = dst->addr;
    GFX2D_Module->GFX2D_CHID[2].GFX2D_PITCH = dst->width * _gfx2d_pixel_size[dst->format];
    GFX2D_Module->GFX2D_CHID[1].GFX2D_CFG = dst->format;


    instr.wd0 = GFX2D_INST_BLEND_WD0(0, 0, 1);
    instr.wd1 = GFX2D_INST_BLEND_WD1((dst_rect->width - 1), (dst_rect->height - 1));
    instr.wd2 = GFX2D_INST_BLEND_WD2(dst_rect->x, dst_rect->y);
    instr.wd3 = GFX2D_INST_BLEND_WD3(fg_rect->x, fg_rect->y);
    instr.wd4 = GFX2D_INST_BLEND_WD4(bg_rect->x, bg_rect->y);
    instr.wd5 = _gfx2d_blend_val[blend];

    return _gpu_instruction((uint32_t *)(&instr), 6);
}

// *****************************************************************************
/* Function:
    bool PLIB_GFX2D_IsBusy(void)

   Summary:
    Returns the Peripheral busy status.

   Precondition:
    GFX2D_Initialize must have been called.

   Parameters:
    None.

   Returns:
    true - Busy.
    false - Not busy.
*/

bool PLIB_GFX2D_IsBusy(void)
{
    if( gfx2dObj.state == GFX2D_STATE_IDLE )
    {
        return false;
    }
    else
    {
        return true;
    }
}

// *****************************************************************************
/* Function:
    GFX2D_STATUS PLIB_GFX2D_StatusGet(void)

   Summary:
    Returns the error during transfer.

   Precondition:
    PLIB_GFX2D_Initialize must have been called.

   Parameters:
    None.

   Returns:
    Error during transfer.
*/

GFX2D_STATUS PLIB_GFX2D_StatusGet(void)
{
    GFX2D_STATUS error;

    error = gfx2dObj.error;
    gfx2dObj.error = GFX2D_ERROR_NONE;

    return error;
}

void PLIB_GFX2D_Interrupt_Handler(void)
{
    if (GFX2D_IRQ_CallbackObj.callback_fn != NULL)
    {
        GFX2D_IRQ_CallbackObj.callback_fn(GFX2D_IRQ_CallbackObj.context);
    }
}