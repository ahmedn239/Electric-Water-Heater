#include "Main.h"
#include "Port.h"
#include "Util.h"
#include "Led.h"


void LED_Init(tLED led, tLED_State state)
{
    /* Add your code here! */
    /* Configure led pins as output */
    switch (led)
    {
        case LED_1:
            GPIO_InitPortPin(LED_1_PORT_CR, LED_1_PIN, GPIO_OUT);
            break;

        default:
            /* Should not come here */
            break;
    }
    /* Set led state */
    LED_SetState(led, state);
    /* End of your code */

}

void LED_Toggle(tLED led)
{
    /* Add your code here! */
    /* Toggle led */
    if (LED_GetState(led) == LED_ON)
    {
        LED_SetState(led, LED_OFF);
    } else
    {
        LED_SetState(led, LED_ON);
    }

    /* Delay to show toggling effect */
    //Delay_MS(LED_DELAY_MS);
    /* End of your code */
}


void LED_SetState(tLED led, tLED_State state)
{
    /* Add your code here! */
    /* Set led state */
    switch (led)
    {
        case LED_1:
            GPIO_WritePortPin(LED_1_PORT_DR, LED_1_PIN, state);
            break;

        default:
            /* Should not come here */
            break;
    }
    /* End of your code */
}

tLED_State LED_GetState(tLED led)
{
    tLED_State ret = LED_OFF;

    /* Add your code here! */
    /* Set led state */
    switch (led)
    {
        case LED_1:
            ret = GPIO_ReadPortPin(LED_1_PORT_DR, LED_1_PIN);
            break;

        default:
            /* Should not come here */
            break;
    }
    /* End of your code */
    return ret;
}

void LED_Update(void)
{
    LED_Toggle(LED_1);
    Delay_MS(LED_DELAY_MS);
}
