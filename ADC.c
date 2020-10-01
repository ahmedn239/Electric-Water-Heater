#include "Main.h"
#include "Port.h"
#include "ADC.h"


void ADC_Init(tByte clock)
{
    /* Add your code here ! */
    /* Turn ADC OFF, configure clock and configure port */
    ADC_OFF;
    ADC_SELECT_CLOCK(clock);
    ADC_CONFIGURE_PORT;
    /* End of your code ! */

}

tWord ADC_Convert(tByte channel, tByte adjustment)
{
    tWord  ret = 0;
    /* Add your code here ! */
    /* Turn ADC ON, select result adjustment and channel then start conversion.
       After conversion return result */
    ADC_ON;
    ADC_ADJUST_RESULT(adjustment);
    ADC_SELECT_CHANNEL(channel);
    ADC_START_CONVERSION;
    ADC_WAIT_FOR_RESULT;
    ret = ADC_READ_RESULT(adjustment);
    ADC_OFF;
    /* End of your code ! */
    return ret;
}

