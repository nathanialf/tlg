/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: a 0x40-byte entry, 16-byte aligned (its block is
 * allocated with alignment 16): a counted reference at +0x38; the rest
 * not traced */
struct Entry0135f390 /* derived name */
{
    Float4A unknown0;
    u8 unknown10[0x28];
    Ref00503fb0<Object016b9108> held38; /* +0x38 */
};

/* derived names: the entries at +0x30 and a pointer at +0x48; the rest
 * not traced */
struct Object0135f390 /* derived name */
{
    u8 unknown0[0x30];
    Array05943280<Entry0135f390> entries30; /* +0x30 */
    void *unknown48;                        /* +0x48 */
};

/* derived name: the pointer cleared and the entries emptied to no capacity
 * (the calls at 0x6156ff, 0x723484, 0x723609, 0x7238b1, 0x135ec83) */
void FUN_0135f390(Object0135f390 *object)
{
    object->unknown48 = 0;
    object->entries30.clear(0);
}
