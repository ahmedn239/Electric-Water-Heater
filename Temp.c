#include "Main.h"
#include "Timer.h"
#include "SW.h"
#include "Temp.h"
#include "ADC.h"
#include "Port.h"
#include "SSD.h"
#include "Heat_Cool.h"
#include "Util.h"
#define TEMP_SECOND_MS (5000)
#define TEMP_PERIOD_MS (20)
#define MTEMP_PERIOD_MS (100)


static void TIM_UpdateTime(void);

static tTEMP TEMP_CurrentTemp = { 0,0};

static tTEMP_State TEMP_State = OFF_State;


void TEMP_Init(void)
{

    TEMP_CurrentTemp.temps = 60;


}
void TEMP_Update(void)
{
    static tWord TEMP_counter = 0;
    static tWord TEMP_seconds_counter = 0;



    /* Check if it is time for the DISP_Update to run */
    TEMP_counter += TMR_TICK_MS;

    if (TEMP_counter != TEMP_PERIOD_MS){
        return;
    }
    TEMP_counter = 0;



    switch (TEMP_State)
    {

        case OFF_State:


                Heat_SetState(OFF);
                Cool_SetState(OFF);
            if (SW_GetState(SW_PW) == SW_PRE_PRESSED)
            {



             TEMP_State = TEMP_NORMAL;
            }else
            {
               TEMP_State = OFF_State;

            }
            break;

        case TEMP_NORMAL:

             if (SW_GetState(SW_PW) == SW_PRE_PRESSED)
            {

             TEMP_State = OFF_State;

            }
            else if (SW_GetState(SW_PLUS) || SW_GetState(SW_MINUS) == SW_PRE_PRESSED)
            {



                TEMP_State = TEMP_SET;
                TEMP_seconds_counter = 0;
            }
            else
           {
                /* Do nothing */
            }
            break;


        case TEMP_SET:

             TEMP_seconds_counter += TEMP_PERIOD_MS;

            if (TEMP_seconds_counter == TEMP_SECOND_MS)
                {

                    TEMP_seconds_counter = 0;



                    TEMP_State = TEMP_NORMAL;

                } else {

                    TEMP_State = TEMP_SET;
                }
             if (SW_GetState(SW_PLUS) == SW_PRE_PRESSED)
            {

                TEMP_seconds_counter = 0;



               if (TEMP_CurrentTemp.temps == 75)
                {

                    TEMP_CurrentTemp.temps ==75;
                } else {
                     TEMP_CurrentTemp.temps += 5;

                }
            } else if (SW_GetState(SW_PW) == SW_PRE_PRESSED)
            {

             TEMP_State = OFF_State;

            }
             else if (SW_GetState(SW_MINUS) == SW_PRE_PRESSED)
            {
                TEMP_seconds_counter = 0;


               if (TEMP_CurrentTemp.temps == 35)
                {

                    TEMP_CurrentTemp.temps ==35;

                 } else {
                    TEMP_CurrentTemp.temps -= 5;
                }
            }

            }
    }

void MTemp_Update(void)
{
    static tWord TEMP_counter = 0;
TEMP_counter += TMR_TICK_MS;

    if (TEMP_counter != MTEMP_PERIOD_MS){
        return;
    }
    TEMP_counter = 0;
    tWord kelvin;
    TRISA=0x07;

  ADC_Init(ADCS1);
    kelvin = (ADC_Convert(2,ADC_ADJUST_RESULT_RIGHT)/2);
TEMP_CurrentTemp.Measured_Temp = kelvin ;

}
void TEMP_GetTemp(tTEMP * temp)
{
    MTemp_Update();
    temp->temps = TEMP_CurrentTemp.temps;
    temp->Measured_Temp = TEMP_CurrentTemp.Measured_Temp;


}

tTEMP_State TEMP_GetState(void)
{
    return TEMP_State;
}


