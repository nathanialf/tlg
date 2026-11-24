/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_00e7d5a0 registers (lea at
 * 0xe7da43, through FUN_00dd6ba0) under the script name
 * "SoundSetCurrentListener": with at least one argument, the listener at
 * +0x160 of the record at +0x100 of the object the pointer at 0x5938c40
 * holds becomes the object the first argument's string names (interned
 * as a copy: the last argument of FUN_013baad0 0), of the type D_5949500
 * points to (usable by this thread), or null; returns 0 (no results). A
 * null or empty string names nothing. The C function's own name is unknown;
 * the classes are not traced. */
struct Sound00e7d1a0 { /* derived name */
    u8 unknown0[0x160];
    Object016b9108 *listener; /* +0x160 */
};

struct Game00e7d1a0 { /* derived name */
    u8 unknown0[0x100];
    Sound00e7d1a0 *sound; /* +0x100 */
};

extern Game00e7d1a0 *D_5938c40;
extern const Type00503fb0 *D_5949500; /* derived name: the listener's type */

// NONMATCHING: the found object's copies: the base moves the object into rcx before each of the
// walk's compares (`mov rcx, r12`) and keeps the flags word in r13d; the build splits the walk's
// exit edges for the copies and spills the flags word (`mov [rbp-0x2c], eax`). The name is made from
// its index (Name::intern), as FUN_00875410's: its part, to the store of +0x160, is unchanged by it
int FUN_00e7d1a0(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        const char *string = 0;
        if (state->base < state->top)
            string = FUN_00db6b20(state, state->base, 0);
        const unsigned interned = Name::intern(string);
        Name name(interned);
        Sound00e7d1a0 *sound = D_5938c40->sound;
        if (name.index != 0)
            sound->listener = findNamed<Object016b9108>(name, D_5949500);
        else
            sound->listener = 0;
    }
    return 0;
}
