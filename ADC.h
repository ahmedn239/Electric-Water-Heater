#ifndef __ADC_H__
#define __ADC_H__

#include "Main.h"

#define ADC_MAX_READING     (1023)

void ADC_Init(tByte clock);

tWord ADC_Convert(tByte channel, tByte adjustment);

#endif // __ADC_H__
