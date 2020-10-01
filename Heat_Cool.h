#ifndef HEAT_COOL_H_INCLUDED
#define HEAT_COOL_H_INCLUDED


typedef enum
 {
    OFF = 0,
    ON = 1
}tState;

void Heat_Init(void);
void Cool_Init(void);
void Heat_SetState(tState state);
void Cool_SetState(tState state);
void Heat_Cool_Update();
#endif // HEAT_COOL_H_INCLUDED
