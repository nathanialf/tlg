/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the 0x70-byte element FUN_00ea4bf0 appends default
 * constructed (its callers FUN_00ea17a0 and FUN_00ea2770): its constructor
 * clears the pointers at +0x0, +0x10, +0x20 and +0x68, the int at +0xc and
 * the flag at +0x18, sets the 16-bit word at +0x8 to -1 and the float at
 * +0x60 to 0.001 (0x3a83126f) with the int after it zero. The bytes from
 * +0x28 to +0x60 are left; the element is 16-byte aligned (the block's
 * alignment 0x10), so vectors lie there: three are assumed at +0x30 to
 * +0x50. The fields' use is not traced. */
struct Element00ea4bf0 { /* derived name */

    Element00ea4bf0()
        : unknown0(0), unknown8(-1), unknownc(0), unknown10(0), unknown18(false), unknown20(0),
          unknown60(0.001f), unknown64(0), unknown68(0)
    {
    }

    void *unknown0;
    short unknown8;  /* +0x8 */
    int unknownc;    /* +0xc */
    void *unknown10; /* +0x10 */
    bool unknown18;  /* +0x18 */
    void *unknown20; /* +0x20 */
    u8 unknown28[0x8];
    Float4A unknown30; /* +0x30 */
    Float4A unknown40; /* +0x40 */
    Float4A unknown50; /* +0x50 */
    float unknown60;   /* +0x60 */
    int unknown64;     /* +0x64 */
    void *unknown68;   /* +0x68 */
};

/* FUN_00ea4bf0 */
// NONMATCHING: the stores' order and width: the base clears +0x0 after +0x10 and writes +0x60 and
// +0x64 as one 64-bit constant after +0x68 (`mov qword [..+0x60], 0x3a83126f`); this build stores
// in member order, the float and the int apart (two 32-bit pairs at +0x0 and +0x60 measured: the
// same, 3.7.1 merges no constant stores)
template unsigned Array05943280<Element00ea4bf0>::add();
