/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks_string.h"

/* derived names: the script C function "Ai2GetTricoTailJointName"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x22392c): reads its
 * first argument as a number (FUN_00c8d380); with the object at +0x8f8 of
 * the global's member at +0x38, pushes the string of the Name FUN_003690c0
 * gives for it (from the name table with its length), else the empty
 * string. Returns 1. */
struct ArgumentReader00c8c290 { /* derived name */

    explicit ArgumentReader00c8c290(lua_State *state_)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index =
            -(int)((unsigned long)((char *)state_->top - (char *)state_->base) / sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

struct Tail003690c0; /* derived name */

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x8f8];
    Tail003690c0 *unknown8f8; /* +0x8f8 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

void FUN_00c8d380(ArgumentReader00c8c290 *reader, float *value); /* derived name */
Name FUN_003690c0(Tail003690c0 *tail, float value);              /* derived name */

// NONMATCHING: the Name's index (0x3e7260's class): the base loads it once after FUN_003690c0
// (`mov r14d, [rbp-0x58]`) and keeps it across FUN_013aacc0 to the release (the callee known
// not to keep the result's address); FUN_003690c0 is not in the module (its body takes the
// creation lock's wait loop), so the build reloads it after the call; every other instruction
// as the base's
int FUN_00369260(lua_State *state) /* derived name */
{
    float value = 0.0f;
    ArgumentReader00c8c290 reader(state);
    FUN_00c8d380(&reader, &value);
    if (Tail003690c0 *tail = D_57c9390->unknown38->unknown8f8) {
        const Name name = FUN_003690c0(tail, value);
        const NameTableEntry017ac870 &entry = D_17ac870[name.index];
        FUN_013aacc0(state, entry.string0, entry.length14);
    } else {
        pushString(state, "");
    }
    return 1;
}
