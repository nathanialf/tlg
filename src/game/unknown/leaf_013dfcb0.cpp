/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* derived names: a 0x30-byte record made with operator new by FUN_00fb0cf0,
 * FUN_00fb1d70 and the other functions from 0xfb47e0 to 0x1208520: a
 * pointer, a copy of an array of 32-bit values (with its lock: the values
 * copied whole, one memcpy), a second pointer and a copy of a name, in
 * member order (FUN_013dfcb0, its constructor). What the pointers and the
 * values are is not traced. */
struct Record013dfcb0 { /* derived name */
    Record013dfcb0(const Array01343a80<u32> &values, void *first, void *second, const Name &name);

    void *unknown0;            /* +0x0 */
    Array01343a80<u32> values; /* +0x8 */
    void *unknown20;           /* +0x20 */
    Name name;                 /* +0x28 */
};

Record013dfcb0::Record013dfcb0(const Array01343a80<u32> &values, void *first, void *second,
                               const Name &name)
    : unknown0(first), values(values), unknown20(second), name(name)
{
}
