/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b0448.h"

extern Name D_581f748; /* func_008ed750.cpp */

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
