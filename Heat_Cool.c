#include "Main.h"
#include "Port.h"
#include "Heat_Cool.h"
#include "Timer.h"
#include "Temp.h"
#include "LED.h"
#include "ADC.h"

#include "Util.h"
#define HC_PERIOD_MS   (1000)


void Heat_Init(void)
{

    GPIO_InitPortPin(HEAT_PORT_CR, HEAT_PIN, GPIO_OUT);
}

void Cool_Init(void)
{

    GPIO_InitPortPin(FAN_PORT_CR, FAN_PIN, GPIO_OUT);
}

void Heat_SetState(tState state)
{
    GPIO_WritePortPin(HEAT_PORT_DR, HEAT_PIN, state);
}

void Cool_SetState(tState state)
{
    GPIO_WritePortPin(FAN_PORT_DR, FAN_PIN, state);
}

void Heat_Cool_Update()
{
    static tWord HC_counter =0;
     tTEMP Temp ;
    tTEMP_State TEMP_State;



TEMP_State = TEMP_GetState();

    if (TEMP_State ==  OFF_State)
    {
        return;
    }
    HC_counter += TMR_TICK_MS;

    if (HC_counter != HC_PERIOD_MS)
    {
        return;
    }
    HC_counter = 0;

     TEMP_GetTemp(&Temp);

   if((Temp.Measured_Temp) < Temp.temps)
    {
     Heat_SetState(ON);
     Cool_SetState(OFF);
     LED_Toggle(LED_1);

    }

    if ((Temp.Measured_Temp) > Temp.temps)
    {
        Heat_SetState(OFF);
        Cool_SetState(ON);
        LED_SetState(LED_1,LED_ON);

    }

}
