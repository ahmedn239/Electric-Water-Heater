#include "Main.h"
#include "SSD.h"
#include "Timer.h"
#include "Temp.h"
#include "Display.h"
#include "SW.h"


/* SSD_Update period */
#define DISP_PERIOD_MS   (20)
#define DISP_SECOND_BLINK_MS (1000)

static tByte SecondsDotState = 0;
static tWord DISP_blink_count = 0;

static void DISPOFF(void);
static void DISP_Temp(tTEMP *Temp);
static void DISP_BlinkTemp(tTEMP *Temp);


void DISP_Init(void)
{
        SSD_Init(SSD_UNITS);
        SSD_Init(SSD_TENS);

        SSD_SetValue(SSD_UNITS, SSD_NULL);
        SSD_SetValue(SSD_TENS,SSD_NULL);

        /* Initialize TIM_LastTime */
}
void DISP_Update(void)
{
    static tWord DISP_counter = 0;


    tTEMP Temp;
    tTEMP_State TEMP_State;

    /* Check if it is time for the DISP_Update to run */
    DISP_counter += TMR_TICK_MS;

    if (DISP_counter != DISP_PERIOD_MS)
    {
        return;
    }
    DISP_counter = 0;

    TEMP_GetTemp(&Temp);

    /* Set SSD values based on the new time value */

    DISP_blink_count += DISP_PERIOD_MS;

    /* Blink the correct field */
    if (DISP_blink_count != DISP_SECOND_BLINK_MS)
    {

        return;
    }

    DISP_blink_count = 0;

    TEMP_State = TEMP_GetState();
    switch (TEMP_State)
    {

        case TEMP_NORMAL:
            /* Blink seconds dot  */
            DISP_Temp(&Temp);
            break;
        case TEMP_SET:
            /* Blink hours */
            DISP_BlinkTemp(&Temp);
            break;
        case OFF_State:
            DISPOFF();
            break;
        /* Should not be here */
        default:
            break;
    }
}
static void DISP_Temp(tTEMP *Temp)
{
    DISP_blink_count = 0;

    SSD_SetValue(SSD_UNITS, Temp->Measured_Temp %10);
        SSD_SetValue(SSD_TENS, Temp->Measured_Temp /10);
}

static void DISPOFF(void)
{
    DISP_blink_count = 0;
    SSD_SetValue(SSD_UNITS, SSD_NULL);
                SSD_SetValue(SSD_TENS, SSD_NULL);

}
static void DISP_BlinkTemp(tTEMP *Temp)
{

    DISP_blink_count = 0;

    if (SSD_GetValue(SSD_UNITS) == SSD_NULL)
    {
        SSD_SetValue(SSD_UNITS, Temp->temps %10);
        SSD_SetValue(SSD_TENS, Temp->temps /10);
    } else
    {
        SSD_SetValue(SSD_UNITS, SSD_NULL);
        SSD_SetValue(SSD_TENS, SSD_NULL);
    }



}
