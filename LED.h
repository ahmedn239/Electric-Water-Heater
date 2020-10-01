#ifndef __LED_H__
#define __LED_H__

#define LED_DELAY_MS (1000)

typedef enum
{
    LED_1,

}tLED;

typedef enum
{
   LED_OFF = 0,
   LED_ON  = 1
}tLED_State;


void LED_Init(tLED led, tLED_State state);
void LED_SetState(tLED led, tLED_State state);
void LED_Toggle(tLED led);
tLED_State LED_GetState(tLED led);
void LED_Update(void);
#endif // __LED_H__


