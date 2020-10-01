#ifndef TEMP_H_INCLUDED
#define TEMP_H_INCLUDED

#include "Main.h"

typedef struct
{
    tByte temps;
    tByte Measured_Temp;

}tTEMP;




typedef enum
{

    OFF_State =0,
    ON_State,
    TEMP_SET,
    TEMP_NORMAL,

}tTEMP_State;

void TEMP_Init(void);
void TEMP_Update(void);
void TEMP_GetTemp(tTEMP * Temp);
tTEMP_State TEMP_GetState(void);
void MTemp_Update(void);


#endif
// TEMP_H_INCLUDED
