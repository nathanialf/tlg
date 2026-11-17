/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived names: two script C functions FUN_002212a0 registers through
 * FUN_00c89b70 under the script names "Ai2PulseManager_IsDispCondorElectricity"
 * (lea at 0x223900) and "Ai2PulseManager_IsDispTailCharaElectricity" (lea at
 * 0x223916). Each pushes 1.0 when the record at +0x8c8 of the record at +0x38
 * of the object the pointer at 0x57c9390 holds is on (+0x548) and the object
 * its Name at +0x28 names, of the type D_57d49c0 points to, has the state 2
 * or 8 at +0x48; else 0.0. Returns 1. The C functions' own names are
 * unknown; the classes are not traced. */
struct Pulse00236cb0 { /* derived name */
    u8 unknown0[0x28];
    Name name28; /* +0x28 */
    u8 unknown2c[0x51c];
    int on548; /* +0x548 */
};

struct Ai200236cb0 { /* derived name */
    u8 unknown0[0x8c8];
    Pulse00236cb0 *unknown8c8;
};

struct Game00236cb0 { /* derived name */
    u8 unknown0[0x38];
    Ai200236cb0 *unknown38;
};

extern Game00236cb0 *D_57c9390;

struct Named00236cb0 : Object016b9108 /* derived name */
{
    u8 unknown24[0x24];
    int state48; /* +0x48 */
};

extern const Type00503fb0 *D_57d49c0; /* derived name: the object's type */

// NONMATCHING: 58 of 63, block layout: the base branches to the 1.0 block (`je`) and places it
// last, after the 0.0 block's `vxorps; jmp`; the build falls into the 1.0 block (`jne` to the
// 0.0 block). The ternary, a bool pushed as 1.0 or 0.0 and the inverted test give the same or worse
int FUN_00236cb0(lua_State *state) /* derived name */
{
    float displayed = 0.0f;
    Pulse00236cb0 *pulse = D_57c9390->unknown38->unknown8c8;
    if (pulse->on548 != 0 && pulse->name28.index != 0) {
        Named00236cb0 *named = findNamed<Named00236cb0>(pulse->name28, D_57d49c0);
        if (named && named->state48 == 2)
            displayed = 1.0f;
    }
    pushNumber(state, displayed);
    return 1;
}

// NONMATCHING: FUN_00236cb0's layout
int FUN_00236d90(lua_State *state) /* derived name */
{
    float displayed = 0.0f;
    Pulse00236cb0 *pulse = D_57c9390->unknown38->unknown8c8;
    if (pulse->on548 != 0 && pulse->name28.index != 0) {
        Named00236cb0 *named = findNamed<Named00236cb0>(pulse->name28, D_57d49c0);
        if (named && named->state48 == 8)
            displayed = 1.0f;
    }
    pushNumber(state, displayed);
    return 1;
}
