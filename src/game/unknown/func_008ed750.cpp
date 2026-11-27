/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b0448.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_vector.h"
#include "tlg_hks.h"
#include "tlg_hks_string.h"
#include "tlg_libc.h"

/* derived names: one unit: the class whose vtable is at 0x16b0448 (its constructor FUN_008e45b0 and
 * destructor FUN_008e4880) and its script C functions, from 0x8e45b0 to its static initializer
 * FUN_008ed750 (round 605E). The pointer at 0x581f740 to the one object is this unit's own static:
 * the constructor sets it and the destructor clears it, and every function of the executable that
 * reads it lies in this range (44, 0x8e45b0 to 0x8ec4e0); the unit's .bss holds it next to
 * D_581f748. */
static Object016b0448 *D_581f740;

extern Name D_581f748; /* defined with the static initializer, below */

/* FUN_008e45b0 (called by FUN_008d19c0): the object made the one the
 * pointer at 0x581f740 holds, then its settings given their first values.
 * NONMATCHING: 142/154, 708 bytes as the base. (a) The four names' zero is
 * stored after the first array's (`vmovups [rbx+0x68]` before `[rbx+0x10]`):
 * MemCpyOpt merges the names' four stores into a memset placed where its scan
 * stops, past the array constructor's own memset (MemCpyOptimizer.cpp,
 * tryMergingIntoMemset, IRBuilder at BI). (b) fadeIn and fadeOut are stored
 * as one 64-bit constant where the base stores the three fades apart. */
Object016b0448::Object016b0448()
{
    D_581f740 = this;
    unknown8 = 0;
    unknownc8 = 0;
    unknownd0 = 0;
    gameDelta = 0.0f;
    gameSpeedFade[0] = 0.0f;
    gameSpeedFade[1] = 0.0f;
    patSpeedFade[0] = 0.0f;
    patSpeedFade[1] = 0.0f;
    fadeIn = 3.0f;
    fadeOut = 1.5f;
    fadeStay = 0.2f;
    previousStage = D_581f748;
    currentStage = D_581f748;
    previousState = D_581f748;
    currentState = D_581f748;
    contEnable = 1;
    unknown24 = 0;
    needStageChangeProc = 0;
    flagGameover = 0;
    stepRestart = 0;
    unknown34 = -1;
    unknown38 = -1;
    skipMS = 0;
    propsMode = 0;
    unknown64 = 5;
    unknownd4 = 1;
}

/* FUN_008e4880 (slot 0; FUN_008e4cb0, slot 1, the deleting one): the pointer
 * at 0x581f740 cleared, then the members destroyed last first */
Object016b0448::~Object016b0448()
{
    D_581f740 = 0;
}

/* derived names: the script C function named "MSC_SetFadeIn" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's number (0
 * without one) in fadeIn of the object the pointer at 0x581f740 holds;
 * returns 0 (no results). The C function's own name is unknown. */
int FUN_008e52d0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetFadeIn", 1);
    }
    D_581f740->fadeIn = toNumber(state, 1);
    return 0;
}

/* derived names: the script C function registered under "MSC_GetFadeIn" (through
 * FUN_00c87e30 with the description "MSC_GetFadeIn()"): with any argument it formats
 * the parameter-count message into a local buffer that nothing reads, then
 * pushes the float at +0x44 of the object the pointer at 0x581f740 holds as a number and returns 1 (one result). The C function's own
 * name is unknown. */
int FUN_008e5370(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetFadeIn", 0);
    }
    HksObject *top = state->top;
    top->value.number = D_581f740->fadeIn;
    top->type = 3;
    state->top = top + 1;
    return 1;
}

/* derived names: the script C function named "MSC_SetFadeOut" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's number (0
 * without one) in fadeOut of the object the pointer at 0x581f740 holds;
 * returns 0 (no results). The C function's own name is unknown. */
int FUN_008e5400(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetFadeOut", 1);
    }
    D_581f740->fadeOut = toNumber(state, 1);
    return 0;
}

/* derived names: the script C function registered under "MSC_GetFadeOut" (through
 * FUN_00c87e30 with the description "MSC_GetFadeOut()"): with any argument it formats
 * the parameter-count message into a local buffer that nothing reads, then
 * pushes the float at +0x48 of the object the pointer at 0x581f740 holds as a number and returns 1 (one result). The C function's own
 * name is unknown. */
int FUN_008e54a0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetFadeOut", 0);
    }
    HksObject *top = state->top;
    top->value.number = D_581f740->fadeOut;
    top->type = 3;
    state->top = top + 1;
    return 1;
}

/* derived names: the script C function named "MSC_SetFadeStay" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's number (0
 * without one) in fadeStay of the object the pointer at 0x581f740 holds;
 * returns 0 (no results). The C function's own name is unknown. */
int FUN_008e5530(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetFadeStay", 1);
    }
    D_581f740->fadeStay = toNumber(state, 1);
    return 0;
}

/* derived names: the script C function registered under "MSC_GetFadeStay" (through
 * FUN_00c87e30 with the description "MSC_GetFadeStay()"): with any argument it formats
 * the parameter-count message into a local buffer that nothing reads, then
 * pushes the float at +0x4c of the object the pointer at 0x581f740 holds as a number and returns 1 (one result). The C function's own
 * name is unknown. */
int FUN_008e55d0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetFadeStay", 0);
    }
    HksObject *top = state->top;
    top->value.number = D_581f740->fadeStay;
    top->type = 3;
    state->top = top + 1;
    return 1;
}

/* derived names: the script C function named "MSC_SetContEnable" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's truth
 * (false without one) in the int contEnable of the object the pointer at
 * 0x581f740 holds; returns 0 (no results). The C function's own name is
 * unknown. */
int FUN_008e5660(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetContEnable", 1);
    }
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool enable = false;
    if (type != 0) {
        enable = true;
        if (type == 1)
            enable = value->value.boolean != 0;
    }
    D_581f740->contEnable = enable;
    return 0;
}

/* derived names: the script C function named "MSC_GetContEnable" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes whether the int contEnable of
 * the object the pointer at 0x581f740 holds is not 0, as a boolean, and
 * returns 1 (one result). The C function's own name is unknown. */
int FUN_008e5710(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetContEnable", 0);
    }
    pushBoolean(state, D_581f740->contEnable != 0);
    return 1;
}

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

/* derived names: the script C function named "MSC_SetCurrentStage" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): the current stage's Name of the object
 * the pointer at 0x581f740 holds becomes the previous one, and its first
 * argument's string becomes the current one; returns 0 (no results). The C
 * function's own name is unknown. */
// NONMATCHING: greedy's assignment: the state in rbx and the pointer read from 0x581f740 in r15,
// the base the other way round (from 0x8e57b0+0x17); the rest the same two registers (whole module too)
int FUN_008e57b0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetCurrentStage", 1);
    }
    D_581f740->previousStage = D_581f740->currentStage;
    D_581f740->currentStage = argumentName(state, 1);
    return 0;
}

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */

/* derived names: the script C function named "MSC_SetCurrentState" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): the current state's Name of the object
 * the pointer at 0x581f740 holds becomes the previous one, and its first
 * argument's string becomes the current one; returns 0 (no results). The C
 * function's own name is unknown. */
// NONMATCHING: greedy's assignment: the state in rbx and the pointer read from 0x581f740 in r15,
// the base the other way round (from 0x8e5930+0x17); the rest the same two registers (whole module too)
int FUN_008e5930(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetCurrentState", 1);
    }
    D_581f740->previousState = D_581f740->currentState;
    D_581f740->currentState = argumentName(state, 1);
    return 0;
}

/* derived names: the script C function named "MSC_GetCurrentStage" by its
 * parameter-count message: with any argument it formats that message into a
 * local buffer that nothing reads, then pushes the string of the Name at
 * +0x14 of the object the pointer at 0x581f740 holds (nil when the name has
 * no string) and returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e5ab0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetCurrentStage", 0);
    }
    pushString(state, D_17ac870[D_581f740->currentStage.index].string0);
    return 1;
}

/* derived names: the script C function named "MSC_GetCurrentState" by its
 * parameter-count message: with any argument it formats that message into a
 * local buffer that nothing reads, then pushes the string of the Name at
 * +0x1c of the object the pointer at 0x581f740 holds (nil when the name has
 * no string) and returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e5b70(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetCurrentState", 0);
    }
    pushString(state, D_17ac870[D_581f740->currentState.index].string0);
    return 1;
}

/* derived names: the script C function named "MSC_GetPreviousStage" by its
 * parameter-count message: with any argument it formats that message into a
 * local buffer that nothing reads, then pushes the string of the Name at
 * +0x10 of the object the pointer at 0x581f740 holds (nil when the name has
 * no string) and returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e5c30(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetPreviousStage", 0);
    }
    pushString(state, D_17ac870[D_581f740->previousStage.index].string0);
    return 1;
}

/* derived names: the script C function named "MSC_GetPreviousState" by its
 * parameter-count message: with any argument it formats that message into a
 * local buffer that nothing reads, then pushes the string of the Name at
 * +0x18 of the object the pointer at 0x581f740 holds (nil when the name has
 * no string) and returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e5cf0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetPreviousState", 0);
    }
    pushString(state, D_17ac870[D_581f740->previousState.index].string0);
    return 1;
}

/* derived names: the script C function named "MSC_SetPropsMode" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's truth
 * (false without one) in the int propsMode of the object the pointer at
 * 0x581f740 holds; returns 0 (no results). The C function's own name is
 * unknown. */
int FUN_008e5db0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetPropsMode", 1);
    }
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool mode = false;
    if (type != 0) {
        mode = true;
        if (type == 1)
            mode = value->value.boolean != 0;
    }
    D_581f740->propsMode = mode;
    return 0;
}

/* derived names: the script C function named "MSC_GetPropsMode" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes whether the int propsMode of the
 * object the pointer at 0x581f740 holds is not 0, as a boolean, and returns 1
 * (one result). The C function's own name is unknown. */
int FUN_008e5e60(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetPropsMode", 0);
    }
    pushBoolean(state, D_581f740->propsMode != 0);
    return 1;
}

/* derived names: the script C function named "MSC_SetSkipMS" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's number (0
 * without one), truncated to an int, in skipMS of the object the pointer at
 * 0x581f740 holds; returns 0 (no results). The C function's own name is
 * unknown. */
int FUN_008e5f00(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetSkipMS", 1);
    }
    D_581f740->skipMS = toNumber(state, 1);
    return 0;
}

/* derived names: the script C function registered under "MSC_GetVersion" (through
 * FUN_00c87e30 with the description "MSC_GetVersion()"): with any argument it formats
 * the parameter-count message into a local buffer that nothing reads, then
 * pushes the number 101 as a number and returns 1 (one result). The C function's own
 * name is unknown. */
int FUN_008e5fa0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetVersion", 0);
    }
    HksObject *top = state->top;
    top->value.number = 101.0f;
    top->type = 3;
    state->top = top + 1;
    return 1;
}

/* derived names: the script C function registered under "MSC_GetGameDelta" (through
 * FUN_00c87e30 with the description "MSC_GetGameDelta()"): with any argument it formats
 * the parameter-count message into a local buffer that nothing reads, then
 * pushes the float at +0x50 of the object the pointer at 0x581f740 holds as a number and returns 1 (one result). The C function's own
 * name is unknown. */
int FUN_008e6030(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetGameDelta", 0);
    }
    HksObject *top = state->top;
    top->value.number = D_581f740->gameDelta;
    top->type = 3;
    state->top = top + 1;
    return 1;
}

/* derived names: the script C function named "MSC_SetGameSpeedFade" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first two arguments' numbers
 * (0 for one it is not given) in gameSpeedFade[0] and [1] of the object the
 * pointer at 0x581f740 holds; returns 0 (no results). The C function's own
 * name is unknown. */
int FUN_008e60c0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 2) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetGameSpeedFade", 2);
    }
    D_581f740->gameSpeedFade[0] = toNumber(state, 1);
    D_581f740->gameSpeedFade[1] = toNumber(state, 2);
    return 0;
}

/* derived names: the script C function named "MSC_SetPatSpeedFade" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first two arguments' numbers
 * (0 for one it is not given) in patSpeedFade[0] and [1] of the object the
 * pointer at 0x581f740 holds; returns 0 (no results). The C function's own
 * name is unknown. */
int FUN_008e6190(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 2) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetPatSpeedFade", 2);
    }
    D_581f740->patSpeedFade[0] = toNumber(state, 1);
    D_581f740->patSpeedFade[1] = toNumber(state, 2);
    return 0;
}

/* derived names: the script C function named "MSC_SetStepRestart" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's number (0
 * without one), truncated to an int, in stepRestart of the object the pointer
 * at 0x581f740 holds; returns 0 (no results). The C function's own name is
 * unknown. */
int FUN_008e6260(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetStepRestart", 1);
    }
    D_581f740->stepRestart = toNumber(state, 1);
    return 0;
}

/* derived names: the script C function named "MSC_GetStepRestart" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes the int stepRestart of the
 * object the pointer at 0x581f740 holds, as a number, and returns 1 (one
 * result). The C function's own name is unknown. */
int FUN_008e6300(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetStepRestart", 0);
    }
    pushNumber(state, D_581f740->stepRestart);
    return 1;
}

void FUN_008db510(Object0581f4b8 *object); /* derived name */

/* derived names: the script C function named "MSC_SetFlagGameover" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's truth
 * (false without one) in flagGameover of the object the pointer at 0x581f740
 * holds and, when it is set, hands the object at +0x8 to FUN_008db510 (as
 * the script "ResetCheckList" does its own, leaf_008d5e20.cpp); returns 0 (no
 * results). The C function's own name is unknown. */
// NONMATCHING: instruction order: on the boolean's path the base reads the pointer at 0x581f740
// after `setne al; movzx ecx, al` (0x8e6430), this build before `setne` (list-ilp); the rest equal
int FUN_008e63a0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetFlagGameover", 1);
    }
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool gameover = false;
    if (type != 0) {
        gameover = true;
        if (type == 1)
            gameover = value->value.boolean != 0;
    }
    Object016b0448 *object = D_581f740;
    object->flagGameover = gameover;
    if (gameover)
        FUN_008db510(object->unknown8);
    return 0;
}

/* derived names: the script C function named "MSC_GetFlagGameover" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes whether the int flagGameover of
 * the object the pointer at 0x581f740 holds is not 0, as a boolean, and
 * returns 1 (one result). The C function's own name is unknown. */
int FUN_008e6480(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetFlagGameover", 0);
    }
    pushBoolean(state, D_581f740->flagGameover != 0);
    return 1;
}

/* derived names: the script C function named "MSC_SetCondorStart" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores 10 in the int at +0x34 of the
 * object the pointer at 0x581f740 holds when its first argument is true,
 * else in the one at +0x38; returns 0 (no results). The C function's own
 * name is unknown. */
int FUN_008e6800(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetCondorStart", 1);
    }
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool start = false;
    if (type != 0) {
        start = true;
        if (type == 1)
            start = value->value.boolean != 0;
    }
    if (start)
        D_581f740->unknown34 = 10;
    else
        D_581f740->unknown38 = 10;
    return 0;
}

/* derived names: the script C function named "MSC_HasState" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes whether a state of the object
 * the pointer at 0x581f740 holds has the Name its first argument's string
 * makes, as a boolean; returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e6be0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_HasState", 1);
    }
    HashedString string;
    FUN_00e81bd0(&string, state, 1);
    Name wanted(string);
    bool found = false;
    for (unsigned i = 0; i < D_581f740->states.size(); ++i) {
        if (D_581f740->states.at(i) == wanted) {
            found = true;
            break;
        }
    }
    pushBoolean(state, found);
    return 1;
}

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */

/* derived names: the script C function named "MSC_UnRegisterState2" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): finds the first state of the object
 * the pointer at 0x581f740 holds whose Names at +0x14 and +0x18 are the ones
 * its two arguments' strings make, and sets that state's int at +0x28 and
 * the object's int at +0x24 to 1; returns 0 (no results). The C function's
 * own name is unknown. */
int FUN_008e7ca0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 2) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_UnRegisterState2", 2);
    }
    Name first;
    first = argumentName(state, 1);
    Name second;
    second = argumentName(state, 2);
    Object016b0448 *object = D_581f740;
    for (unsigned i = 0; i < object->states.size(); ++i) {
        State0581f740 &entry = object->states.at(i);
        if (entry.unknown14 == first && entry.name == second) {
            entry.unknown28 = 1;
            object->unknown24 = 1;
            break;
        }
    }
    return 0;
}

void FUN_008ec8b0(Object016b0448 *object); /* derived name */
void FUN_008ec4e0(
    State0581f740 *state,
    const char *handler); /* derived name: the state's script handler of that name run */

/* derived names: the script C function named "MSC_UnRegisterStateAll" by its
 * parameter-count message (with arguments it formats that message into a
 * local buffer that nothing reads): FUN_008ec8b0 run over the object the
 * pointer at 0x581f740 holds, then, last first, each state whose ints at
 * +0x4, +0x8 and +0xc are all 0 given its "onLeave" (FUN_008ec4e0) and
 * removed; returns 0 (no results). The C function's own name is unknown. */
int FUN_008e7ec0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_UnRegisterStateAll", 0);
    }
    FUN_008ec8b0(D_581f740);
    for (int i = D_581f740->states.size(); i > 0; --i) {
        State0581f740 &entry = D_581f740->states.at(i - 1);
        if (entry.unknown4 == 0 && entry.unknown8 == 0 && entry.unknownc == 0) {
            FUN_008ec4e0(&entry, "onLeave");
            D_581f740->states.removeAt(i - 1);
        }
    }
    return 0;
}

/* derived names: the script C function named "MSC_DumpState" by its
 * parameter-count message: with any argument it formats that message into a
 * local buffer that nothing reads, and returns 0 (no result); it does nothing
 * else. The C function's own name is unknown. */
int FUN_008e8010(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_DumpState", 0);
    }
    return 0;
}

/* derived names: the script C function named "MSC_SetNeedStageChangeProc" by
 * its parameter-count message (with the wrong count it formats that message
 * into a local buffer that nothing reads): stores its first argument's truth
 * (false without one) in the int needStageChangeProc of the object the
 * pointer at 0x581f740 holds; returns 0 (no results). The C function's own
 * name is unknown. */
int FUN_008e8080(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetNeedStageChangeProc", 1);
    }
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool need = false;
    if (type != 0) {
        need = true;
        if (type == 1)
            need = value->value.boolean != 0;
    }
    D_581f740->needStageChangeProc = need;
    return 0;
}

/* derived names: the script C function named "MSC_GetNeedStageChangeProc" by
 * its parameter-count message (with the wrong count it formats that message
 * into a local buffer that nothing reads): pushes whether the int
 * needStageChangeProc of the object the pointer at 0x581f740 holds is not 0,
 * as a boolean, and returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e8130(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetNeedStageChangeProc", 0);
    }
    pushBoolean(state, D_581f740->needStageChangeProc != 0);
    return 1;
}

/* derived names: the script C function named "MSC_GetIncludeCurrentState" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes whether a state of the object
 * the pointer at 0x581f740 holds has the Name its first argument's string
 * makes, as a boolean; returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e81d0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetIncludeCurrentState", 1);
    }
    HashedString string;
    FUN_00e81bd0(&string, state, 1);
    Name wanted(string);
    for (unsigned i = 0; i < D_581f740->states.size(); ++i) {
        if (D_581f740->states.at(i) == wanted) {
            pushBoolean(state, true);
            return 1;
        }
    }
    pushBoolean(state, false);
    return 1;
}

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */

/* derived names: the script C function named "MSC_CreateTime" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): the first timer of the object the
 * pointer at 0x581f740 holds whose Name is the one its first argument's
 * string makes gets the second argument's number as its time and the third
 * argument's truth as its repeat flag, and a timer with the three is added
 * to the object's timers whether one was found or not; pushes true and
 * returns 1 (one result). The C function's own name is unknown. */
// NONMATCHING: 87/183 single-file: (1) the third argument's truth is widened to an int where it is
// made (`setne cl` ... `movzx r13d, cl`), the build widens it at each store (`movzx ecx, r13b`);
// (2) the growth's reallocation keeps the owner lookup's null arm (`movzx edx, byte [rsi-0x10];
// xor edi, edi; cmp edx, 0xa; jne`), the build drops it (the parked reallocation class; round 352B)
int FUN_008e8310(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 3) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_CreateTime", 3);
    }
    Name name;
    name = argumentName(state, 1);
    float time = toNumber(state, 2);
    const HksObject *third = state->base + 2;
    const HksObject *value = third < state->top ? third : 0;
    int type = third < state->top ? value->type & 0xf : 0;
    bool loop = false;
    if (type != 0) {
        loop = true;
        if (type == 1)
            loop = value->value.boolean != 0;
    }
    Object016b0448 *object = D_581f740;
    for (unsigned i = 0; i < object->timers.size(); ++i) {
        if (object->timers.at(i).name == name) {
            object->timers.at(i).time = time;
            object->timers.at(i).loop = loop;
            break;
        }
    }
    new (object->timers.append()) Timer0581f740(name, time, loop);
    pushBoolean(state, true);
    return 1;
}

/* derived names: the script C function named "MSC_GetCurrentStates" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes a table holding, at 1 to the
 * count, a table for each state of the object the pointer at 0x581f740
 * holds, its "stage_name" the string of the state's Name at +0x14 and its
 * "state_name" the string of its Name at +0x18 (nil for a Name without
 * one); returns 1 (one result). The C function's own name is unknown. */
int FUN_008eb2f0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetCurrentStates", 0);
    }
    FUN_00d91880(state, D_581f740->states.size(), 0);
    for (unsigned i = 0; i < D_581f740->states.size(); ++i) {
        pushInteger(state, i + 1);
        FUN_00d91880(state, 2, 0);
        pushString(state, "stage_name");
        pushString(state, D_17ac870[D_581f740->states.at(i).unknown14.index].string0);
        setTable(state);
        pushString(state, "state_name");
        pushString(state, D_17ac870[D_581f740->states.at(i).name.index].string0);
        setTable(state);
        setTable(state);
    }
    return 1;
}

extern Type00503fb0 *D_5939080; /* derived name: the node's type */

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */

/* derived names: the script C function named "MSC_IsParent" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes whether the node the Name its
 * first argument's string makes names (of the type D_5939080 points to, or
 * one derived from it), or one of the nodes above it, has the Name its second
 * argument's string makes, as a boolean; returns 1 (one result). The C
 * function's own name is unknown. */
// NONMATCHING: the reload of the child's Name spilled across the thread flag's address: the base
// reloads it once where the two found paths meet (the found node tested for null first, its
// failure joining the lookup's other failures), the build on each path before the test.
int FUN_008eb530(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 2) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_IsParent", 2);
    }
    Name child = argumentName(state, 1);
    Name parent = argumentName(state, 2);
    bool found = false;
    for (Object016b85e0 *node = findNamed<Object016b85e0>(child, D_5939080); node;
         node = node->parent) {
        if (node->name == parent) {
            found = true;
            break;
        }
    }
    pushBoolean(state, found);
    return 1;
}

/* derived names: FUN_008ed750 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then one name from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_159d38c[9];

Name D_581f748(D_159d38c, false);
