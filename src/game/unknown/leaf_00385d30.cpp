/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <float.h>

#include "tlg_game_array01343a80.h"
#include "tlg_math.h"

/* derived names: FUN_00385d30 constructs a record that FUN_003806f0
 * builds: its fields in member order (1 at +0x28, the largest float at
 * +0x5c), the array of 16-byte vectors at +0x68 with its lock and the three
 * ints after it, then the array emptied with room for 16 vectors
 * (tlg_game_array.h's clear(size)). The bytes not named are not set here;
 * what the fields hold is not traced. */
struct Record00385d30 { /* derived name */
    Record00385d30();

    u8 unknown0[0x20];              /* not traced */
    void *unknown20;                /* +0x20 */
    int unknown28;                  /* +0x28 */
    u8 unknown2c[0x24];             /* not traced */
    void *unknown50;                /* +0x50 */
    int unknown58;                  /* +0x58 */
    float unknown5c;                /* +0x5c */
    u8 unknown60[0x8];              /* not traced */
    Array01343a80<Float4A> vectors; /* +0x68 */
    int unknown80;                  /* +0x80 */
    int unknown84;                  /* +0x84 */
    int unknown88;                  /* +0x88 */
};

Record00385d30::Record00385d30()
    : unknown20(0), unknown28(1), unknown50(0), unknown58(0), unknown5c(FLT_MAX), unknown80(0),
      unknown84(0), unknown88(0)
{
    vectors.clear(16);
}
