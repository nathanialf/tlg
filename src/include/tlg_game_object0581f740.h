/* src/include/tlg_game_object0581f740.h: the object the pointer at 0x581f740
 * holds (stored by the function at 0x8e46b4's site, cleared at 0x8e489b),
 * whose floats the script C functions "MSC_GetFadeIn", "MSC_GetFadeOut",
 * "MSC_GetFadeStay" and "MSC_GetGameDelta" push (FUN_008e5370, FUN_008e54a0,
 * FUN_008e55d0, FUN_008e6030) and their setters store (FUN_008e52d0 stores
 * +0x44 with `vmovss` from the script's number), and whose four Names the
 * script C functions "MSC_GetPreviousStage", "MSC_GetCurrentStage",
 * "MSC_GetPreviousState" and "MSC_GetCurrentState" push as strings
 * (FUN_008e5c30, FUN_008e5ab0, FUN_008e5cf0, FUN_008e5b70). derived names
 * throughout. */
#ifndef TLG_GAME_OBJECT0581F740_H
#define TLG_GAME_OBJECT0581F740_H

#include "tlg_types.h"
#include "tlg_game_name.h"

struct Object0581f740 { /* derived name */
    u8 unknown0[0x10];
    Name previousStage; /* +0x10 */
    Name currentStage;  /* +0x14 */
    Name previousState; /* +0x18 */
    Name currentState;  /* +0x1c */
    u8 unknown20[0x24];
    float fadeIn;    /* +0x44 */
    float fadeOut;   /* +0x48 */
    float fadeStay;  /* +0x4c */
    float gameDelta; /* +0x50 */
};

extern Object0581f740 *D_581f740;

#endif
