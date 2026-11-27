/* src/include/tlg_game_object016b0448.h: the object the pointer at 0x581f740
 * holds, the class of the vtable at 0x16b0448 (config/vtables.derived.base.txt:
 * its constructor FUN_008e45b0 stores the pointer at 0x8e46b4, its destructor
 * FUN_008e4880 clears it at 0x8e489b; the vtable's two slots are the
 * destructors),
 * whose floats the script C functions "MSC_GetFadeIn", "MSC_GetFadeOut",
 * "MSC_GetFadeStay" and "MSC_GetGameDelta" push (FUN_008e5370, FUN_008e54a0,
 * FUN_008e55d0, FUN_008e6030) and their setters store (FUN_008e52d0 stores
 * +0x44 with `vmovss` from the script's number), and whose four Names the
 * script C functions "MSC_GetPreviousStage", "MSC_GetCurrentStage",
 * "MSC_GetPreviousState" and "MSC_GetCurrentState" push as strings
 * (FUN_008e5c30, FUN_008e5ab0, FUN_008e5cf0, FUN_008e5b70). The ints and
 * floats from +0x20 are named after the "MSC_" script C functions that read
 * and write them (FUN_008e5660 to FUN_008e8130). derived names throughout. */
#ifndef TLG_GAME_OBJECT016B0448_H
#define TLG_GAME_OBJECT016B0448_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_record01373de0.h"

struct Object0581f4b8; /* derived name: the object FUN_008db510 takes */

/* derived names: one registered state, 0x34 bytes, named by the Name at
 * +0x18 (MSC_HasState and MSC_GetIncludeCurrentState look one up by it);
 * MSC_UnRegisterState2 finds one by the Names at +0x14 and +0x18 and sets
 * its int at +0x28 */
struct State0581f740 { /* derived name */
    /* FUN_01373ca0 (leaf_01373ca0.cpp), called for each state by
     * FUN_008e4880 and by 0x8e6d10, 0x8e7ec0, 0x8e85f0, 0x8ec8b0: the
     * names released, the last first */
    ~State0581f740();

    bool operator==(const Name &other) const
    {
        return name == other;
    }

    u8 unknown0[0x4];
    int unknown4;   /* +0x4: MSC_UnRegisterStateAll leaves a state with */
    int unknown8;   /* +0x8: any of these three set */
    int unknownc;   /* +0xc */
    Name name10;    /* +0x10 */
    Name unknown14; /* +0x14 */
    Name name;      /* +0x18 */
    Name name1c;    /* +0x1c */
    u8 unknown20[0x8];
    int unknown28; /* +0x28 */
    Name name2c;   /* +0x2c */
    Name name30;   /* +0x30 */
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

/* Record01373de0, the 0x28-byte elements at +0x68: tlg_game_record01373de0.h */

/* derived names: the 0x1c-byte elements of the array at +0xb0, five names
 * (FUN_008e4880 releases +0x14, +0x10, +0x8, +0x4 and +0x0) */
struct Names016b0448 { /* derived name */
    Name name0;        /* +0x0 */
    Name name4;        /* +0x4 */
    Name name8;        /* +0x8 */
    u8 unknownc[0x4];
    Name name10; /* +0x10 */
    Name name14; /* +0x14 */
    u8 unknown18[0x4];
};

class Object016b0448 /* derived name */
{
  public:
    /* 0x8e45b0: the pointer at 0x581f740 set to the new object, then its
     * settings given their first values */
    Object016b0448();
    virtual ~Object016b0448();

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
    int unknown64;           /* +0x64: 5 from the constructor */
    Array01343a80<Record01373de0> records; /* +0x68 */
    Array01343a80<State0581f740> states;   /* +0x80 */
    Array01343a80<Timer0581f740> timers;   /* +0x98: MSC_CreateTime adds one */
    Array01343a80<Names016b0448> names;    /* +0xb0 */
    void *unknownc8;                       /* +0xc8 */
    int unknownd0;                         /* +0xd0 */
    int unknownd4;                         /* +0xd4: 1 from the constructor */
};

/* The pointer at 0x581f740 to the one object is the static of the unit that holds the class
 * (src/game/unknown/func_008ed750.cpp, round 605E). */

#endif
