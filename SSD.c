#include "Main.h"
#include "Port.h"
#include "Timer.h"
#include "SSD.h"

/* SSD_Update period */
#define SSD_PERIOD_MS   (5)

/* Number of SSD symbols */
#define N_SSD_SYMBOLS   (11)


/* SSD Symbols port data values */
static tByte SSD_Data[N_SSD_SYMBOLS] =
{
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b00000000,
};

/* Current SSD to be updated */
static tSSD SSD_current = SSD_UNITS;

/* SSD values */
static tSSD_Symbol SSD_Values[N_SSD] = {SSD_NULL};

static void SSD_Out(tSSD ssd, tSSD_Symbol ssd_symbol);

void SSD_Init(tSSD ssd)
{
    /* Add your code here! */
    /* Initialize SSD data pins */
    GPIO_InitPort(SSD_DATA_PORT_CR, GPIO_OUT);
    SSD_Out(ssd, SSD_NULL);

    /* Initialize SSD control pin and turn SSD OFF*/
    switch (ssd)
    {
        case SSD_UNITS:
            GPIO_InitPortPin(SSD_UNITS_CR, SSD_UNITS_PIN, GPIO_OUT);
            break;
        case SSD_TENS:
            GPIO_InitPortPin(SSD_TENS_CR, SSD_TENS_PIN, GPIO_OUT);
            break;
        /* Should not be here */
        default:
            break;
    }
    SSD_SetState(ssd, SSD_OFF);
    /* End of your code!*/
}

void SSD_Update(void)
{
    static tWord SSD_counter = 0;


    /* Check if it is time for the SSD_Update to run */
    SSD_counter += TMR_TICK_MS;

    if (SSD_counter != SSD_PERIOD_MS){
        return;
    }

    SSD_counter = 0;

    /* display current SSD value of the current SSD */
    /* Add your code here! */
    SSD_Out(SSD_current, SSD_Values[SSD_current]);

    if (SSD_current == SSD_TENS)
    {
        SSD_current = SSD_UNITS;
    } else
    {
        SSD_current++;
    }
    /* End of your code!*/
}
tSSD_Symbol SSD_GetValue(tSSD ssd)
{
    /* Add your code here! */
    return SSD_Values[ssd];
    /* End of your code!*/
}
void SSD_SetValue(tSSD ssd, tSSD_Symbol ssd_symbol)
{
    /* Add your code here! */
    SSD_Values[ssd] = ssd_symbol;
    /* End of your code!*/
}

tSSD_State SSD_GetState(tSSD ssd)
{
    tSSD_State ret = SSD_OFF;
    /* Add your code here! */
    switch (ssd)
    {
        case SSD_UNITS:
            ret = GPIO_ReadPortPin(SSD_UNITS_DR, SSD_UNITS_PIN);
            break;
        case SSD_TENS:
            ret = GPIO_ReadPortPin(SSD_TENS_DR, SSD_TENS_PIN);
            break;
        /* Should not be here */
        default:
            break;
    }
     /* End of your code!*/
     return ret;

}

void SSD_SetState(tSSD ssd, tSSD_State state)
{
    /* Add your code here! */
    switch (ssd)
    {
        case SSD_UNITS:
            GPIO_WritePortPin(SSD_UNITS_DR, SSD_UNITS_PIN, state);
            break;
        case SSD_TENS:
            GPIO_WritePortPin(SSD_TENS_DR, SSD_TENS_PIN, state);
            break;

        /* Should not be here */
        default:
            break;
    }
     /* End of your code!*/
}


static  void SSD_Out(tSSD ssd, tSSD_Symbol ssd_symbol)
{
    /* Add your code here! */
    /* Turn off SSDs */
    SSD_SetState(SSD_UNITS, SSD_OFF);
    SSD_SetState(SSD_TENS, SSD_OFF);

    /* Output ssd_symbol on selected ssd */
    GPIO_WritePort(SSD_DATA_PORT_DR, SSD_Data[ssd_symbol]);

    /* Turn ssd ON */
    SSD_SetState(ssd, SSD_ON);

    /* End of your code!*/

}
