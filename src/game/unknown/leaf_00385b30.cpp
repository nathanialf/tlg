/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_math.h"

/* derived names: FUN_00385b30 constructs a record that FUN_0037e6a0 and
 * FUN_003806f0 build (Record00385d30's neighbour): an int, an array of
 * 16-byte vectors with its lock, three cleared pointers and an int (their
 * stores made one 28-byte clear, two overlapping 16-byte stores at +0x60
 * and +0x6c, placed after the second array's fields) and a second
 * array with its lock, then the first array emptied with room for 16
 * vectors. The second array's elements and the fields' use are not traced. */
struct Record00385b30 { /* derived name */
    Record00385b30();

    u8 unknown0[0x30];              /* not traced */
    int unknown30;                  /* +0x30 */
    Array01343a80<Float4A> vectors; /* +0x38 */
    u8 unknown50[0x10];             /* not traced */
    void *unknown60;                /* +0x60 */
    void *unknown68;                /* +0x68 */
    void *unknown70;                /* +0x70 */
    int unknown78;                  /* +0x78 */
    Array01343a80<u32> values;      /* +0x80: the elements not traced */
};

Record00385b30::Record00385b30()
    : unknown30(0), unknown60(0), unknown68(0), unknown70(0), unknown78(0)
{
    vectors.clear(16);
}
