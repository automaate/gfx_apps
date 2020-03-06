// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef LE_GEN_SCREEN_SPLASH_H
#define LE_GEN_SCREEN_SPLASH_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget0;
extern leImageWidget* MHGCImageWidget;
extern leImageWidget* BarImageWidget;
extern leImageWidget* MicrochipLogoImageWidget;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Splash(); // called when Legato is initialized
leResult screenShow_Splash(); // called when screen is shown
void screenHide_Splash(); // called when screen is hidden
void screenDestroy_Splash(); // called when Legato is destroyed
void screenUpdate_Splash(); // called when Legato is updating

leWidget* screenGetRoot_Splash(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void Splash_OnShow(void);

void Splash_OnHide(void);

void Splash_OnUpdate(void);


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SPLASH_H
