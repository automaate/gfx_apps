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

#include "gfx/legato/generated/le_gen_init.h"

static uint32_t currentScreen;

void legato_initialize(void)
{
    legato_initialize_schemes();

    leSetStringTable(&stringTable);

    currentScreen = -1;

    legato_showScreen(screenID_SplashScreen);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

void legato_hideCurrentScreen()
{
    switch(currentScreen)
    {
        case screenID_SplashScreen:
        {
            screenHide_SplashScreen();
            currentScreen = 0;
            break;
        }
        case screenID_FPSCounters:
        {
            screenHide_FPSCounters();
            currentScreen = 0;
            break;
        }
        case screenID_FPSMotion:
        {
            screenHide_FPSMotion();
            currentScreen = 0;
            break;
        }
        case screenID_FPSImages:
        {
            screenHide_FPSImages();
            currentScreen = 0;
            break;
        }
    }
}

void legato_showScreen(uint32_t id)
{
    legato_hideCurrentScreen(currentScreen);

    switch(id)
    {
        case screenID_SplashScreen:
        {
            screenShow_SplashScreen();
            currentScreen = id;
            break;
        }
        case screenID_FPSCounters:
        {
            screenShow_FPSCounters();
            currentScreen = id;
            break;
        }
        case screenID_FPSMotion:
        {
            screenShow_FPSMotion();
            currentScreen = id;
            break;
        }
        case screenID_FPSImages:
        {
            screenShow_FPSImages();
            currentScreen = id;
            break;
        }
    }
}

void legato_updateCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_SplashScreen:
        {
            screenUpdate_SplashScreen();
            break;
        }
        case screenID_FPSCounters:
        {
            screenUpdate_FPSCounters();
            break;
        }
        case screenID_FPSMotion:
        {
            screenUpdate_FPSMotion();
            break;
        }
        case screenID_FPSImages:
        {
            screenUpdate_FPSImages();
            break;
        }
    }
}

