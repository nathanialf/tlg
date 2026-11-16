/* src/include/tlg_game_object0581f740.h: the object the pointer at 0x581f740
 * holds (stored by the function at 0x8e46b4's site, cleared at 0x8e489b),
 * whose floats the script C functions "MSC_GetFadeIn", "MSC_GetFadeOut",
 * "MSC_GetFadeStay" and "MSC_GetGameDelta" push (FUN_008e5370, FUN_008e54a0,
 * FUN_008e55d0, FUN_008e6030) and their setters store (FUN_008e52d0 stores
 * +0x44 with `vmovss` from the script's number), and whose four Names the
 * script C functions "MSC_GetPreviousStage", "MSC_GetCurrentStage",
 * "MSC_GetPreviousState" and "MSC_GetCurrentState" push as strings
 * (FUN_008e5c30, FUN_008e5ab0, FUN_008e5cf0, FUN_008e5b70). The ints and
 * floats from +0x20 are named after the "MSC_" script C functions that read
 * and write them (FUN_008e5660 to FUN_008e8130). derived names throughout. */
#ifndef TLG_GAME_OBJECT0581F740_H
#define TLG_GAME_OBJECT0581F740_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array.h"

struct Object0581f4b8; /* derived name: the object FUN_008db510 takes */

/* derived names: one registered state, 0x34 bytes, named by the Name at
 * +0x18 (MSC_HasState and MSC_GetIncludeCurrentState look one up by it);
 * MSC_UnRegisterState2 finds one by the Names at +0x14 and +0x18 and sets
 * its int at +0x28 */
struct State0581f740 { /* derived name */

    bool operator==(const Name &other) const
    {
        return name == other;
    }

    u8 unknown0[0x14];
    Name unknown14; /* +0x14 */
    Name name;      /* +0x18 */
    u8 unknown1c[0xc];
    int unknown28; /* +0x28 */
    u8 unknown2c[0x8];
};

/* derived names: one timer the script C function "MSC_CreateTime" adds, 12
 * bytes: its Name, its time and whether it repeats (the script's third
 * argument's truth, stored as an int) */
struct Timer0581f740 { /* derived name */

    Timer0581f740(const Name &name_, float time_, int loop_) : name(name_), time(time_), loop(loop_)
    {
    }

    Name name;  /* +0x0 */
    float time; /* +0x4 */
    int loop;   /* +0x8 */
};

struct Object0581f740 { /* derived name */
    u8 unknown0[0x8];
    /* +0x8: given to FUN_008db510 when MSC_SetFlagGameover sets the flag */
    Object0581f4b8 *unknown8;
    Name previousStage;      /* +0x10 */
    Name currentStage;       /* +0x14 */
    Name previousState;      /* +0x18 */
    Name currentState;       /* +0x1c */
    int contEnable;          /* +0x20: MSC_GetContEnable, MSC_SetContEnable */
    int unknown24;           /* +0x24: MSC_UnRegisterState2 sets it to 1 */
    int needStageChangeProc; /* +0x28: MSC_GetNeedStageChangeProc, MSC_SetNeedStageChangeProc */
    int flagGameover;        /* +0x2c: MSC_GetFlagGameover, MSC_SetFlagGameover */
    int stepRestart;         /* +0x30: MSC_GetStepRestart, MSC_SetStepRestart */
    int unknown34;           /* +0x34: MSC_SetCondorStart stores 10 */
    int unknown38;           /* +0x38: MSC_SetCondorStart stores 10 */
    int skipMS;              /* +0x3c: MSC_SetSkipMS */
    int propsMode;           /* +0x40: MSC_GetPropsMode, MSC_SetPropsMode */
    float fadeIn;            /* +0x44 */
    float fadeOut;           /* +0x48 */
    float fadeStay;          /* +0x4c */
    float gameDelta;         /* +0x50 */
    float gameSpeedFade[2];  /* +0x54: the two numbers MSC_SetGameSpeedFade stores */
    float patSpeedFade[2];   /* +0x5c: the two numbers MSC_SetPatSpeedFade stores */
    u8 unknown64[0x1c];
    Array05943280<State0581f740> states; /* +0x80 */
    Array05943280<Timer0581f740> timers; /* +0x98: MSC_CreateTime adds one */
};

extern Object0581f740 *D_581f740;

#endif
