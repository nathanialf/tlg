/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks_string.h"

/* derived names: the callback FUN_001b29c0 hands FUN_00cb8490 (lea at
 * 0x1b2a57) with the list the pointer at 0x58b65c0 holds and a context on its
 * stack: the script's state, a name and a count. For an entry whose record at
 * +0x60 has that name at +0xc, pushes the entry's own name's string (+0xc)
 * through pushString (tlg_hks_string.h) and counts it; returns 1 for every
 * entry (the walk goes on). The entries and the list are not traced. */
struct Record001b58b0 { /* derived name */
    u8 unknown0[0xc];
    Name unknownC; /* +0xc */
};

struct Entry001b58b0 { /* derived name */
    u8 unknown0[0xc];
    Name unknownC; /* +0xc */
    u8 unknown10[0x60 - 0x10];
    Record001b58b0 *unknown60; /* +0x60 */
};

struct Context001b58b0 { /* derived name */
    lua_State *state;
    Name name; /* +0x8 */
    int count; /* +0xc */
};

int FUN_001b58b0(Entry001b58b0 *entry, Context001b58b0 *context) /* derived name */
{
    if (entry->unknown60 && entry->unknown60->unknownC == context->name) {
        pushString(context->state, D_17ac870[entry->unknownC.index].string0);
        ++context->count;
    }
    return 1;
}
