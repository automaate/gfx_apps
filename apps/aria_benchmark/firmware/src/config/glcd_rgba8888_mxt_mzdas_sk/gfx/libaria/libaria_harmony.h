/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Definitions Header

  File Name:
    libaria_harmony.h

  Summary:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _LIBARIA_HARMONY_H
#define _LIBARIA_HARMONY_H


#include "gfx/libaria/libaria.h"


#include "gfx/libaria/libaria_init.h"



// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

typedef enum
{
    LIBARIA_STATE_INIT = 0,
    LIBARIA_STATE_RUNNING,
	LIBARIA_STATE_ERROR
} LIBARIA_STATES;

// *****************************************************************************
/* MPLAB Harmony Graphics Composer Objects

  Summary:
    Structure holding the graphics object handles

  Description:
    This structure contains the object handles for all graphics objects 
    generated by the Harmony Graphics Composer

  Remarks:
*/

typedef struct libaria_objects_t
{
	laContext* context;
} libaria_objects;

extern libaria_objects libariaObj;

/******************************************************************************
  Function:
    void LibAria_Initialize(void)

  Summary:
    This function initializes the LibAria state machine.  
 */
int32_t LibAria_Initialize(void);


/******************************************************************************
  Function:
    void LibAria_Tasks(void);

  Summary:
    This function is called in SYS_Tasks.  
*/
void LibAria_Tasks(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _LIBARIA_HARMONY_H
/*******************************************************************************
 End of File
*/
