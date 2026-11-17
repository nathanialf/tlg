/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_hks.h"

/* derived names: the script C function FUN_00874ec0 registers (lea at
 * 0x874fdd, through FUN_00c87e30) under the script name "Guide_SaveData":
 * when the guide (the object the pointer at 0x581e3a8 holds) has entries,
 * the object the name "_guideProgress" (0x15abd27) names, of the type
 * D_5833b80 points to (that type itself), takes the int at +0xc8 of each
 * entry into its array at +0x28 (sized to the count first) and the guide's
 * int at +0x114 at +0x24; returns 0 (no results). The object is not tested
 * for null. The C function's own name is unknown; the classes are not
 * traced. */
struct Entry008757a0 { /* derived name */
    u8 unknown0[0xc8];
    int unknownc8; /* +0xc8 */
};

struct Guide008757a0 { /* derived name */
    u8 unknown0[0x20];
    Entry008757a0 **entries; /* +0x20 */
    int count;               /* +0x28 */
    u8 unknown2c[0xe8];
    int unknown114; /* +0x114 */
};

struct Progress008757a0 : Object016b9108 /* derived name */
{
    int unknown24;               /* +0x24 */
    Array05943280<int> values28; /* +0x28 */
};

extern Guide008757a0 *D_581e3a8;
extern const char D_15abd27[15];
extern const Type00503fb0 *D_5833b80; /* derived name: the progress object's type */

// NONMATCHING: the reallocation's owner: the base looks it up with a null default (`movzx edx, byte
// [rsi-0x10]; xor edi, edi; cmp edx, 0xa; jne`), the open split of tlg_game_block.h's
// reallocateOwnedBlock (rounds 315E to 324E); resize() reallocates through reallocateBlock
int FUN_008757a0(lua_State *) /* derived name */
{
    Guide008757a0 *guide = D_581e3a8;
    if (guide->count != 0) {
        Progress008757a0 *progress = findNamedOf<Progress008757a0>(Name(D_15abd27), D_5833b80);
        progress->values28.resize(guide->count);
        for (int i = 0; i < guide->count; i++)
            progress->values28[i] = guide->entries[i]->unknownc8;
        progress->unknown24 = guide->unknown114;
    }
    return 0;
}
