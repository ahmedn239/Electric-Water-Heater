#include "Main.h"
#include "Heat_Cool.h"
#include "ADC.h"
#include "SW.h"
#include "Timer.h"
#include "SSD.h"
#include "Temp.h"
#include "Display.h"
#include "I2C.h"
#include "Util.h"
#include "LED.h"
#include "Port.h"

tWord __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;
tByte flag = 0;


void main (void)
{
    /* Initialization */
    SW_Init();
    Heat_Init();
    Cool_Init();

    DISP_Init();
    LED_Init(LED_1, LED_OFF);
    TEMP_Init();

    TMR_Init();
    TMR_Start();

    /* TRISC7 = 0;
    RC7 = 0;*/

    while (1)
    {
        /* Do nothing */
        /* while (flag == 0)
        {

        }

        flag = 0;*/

    }

}

