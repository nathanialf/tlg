/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: a 0x80-byte entry, 16-byte aligned (its block is
 * allocated with alignment 16): a counted reference at +0x78; the rest
 * not traced */
struct Entry01370af0 /* derived name */
{
    Float4A unknown0;
    u8 unknown10[0x68];
    Ref00503fb0<Object016b9108> held78; /* +0x78 */
};

/* derived names: the entries at +0x20 and a pointer at +0x38; the rest
 * not traced */
struct Object01370af0 /* derived name */
{
    u8 unknown0[0x20];
    Array05943280<Entry01370af0> entries20; /* +0x20 */
    void *unknown38;                        /* +0x38 */
};

/* derived name: the pointer cleared and the entries emptied to no capacity
 * (the calls at 0x854ad8, 0x854ae0, 0xb07eaa, 0xb07eb2, 0xb47cc0, 0xb47cc8) */
void FUN_01370af0(Object01370af0 *object)
{
    object->unknown38 = 0;
    object->entries20.clear(0);
}
