/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_simd.h"

/* derived names: a vector that copies itself through its own constructor
 * (one `vmovaps` load and store), so that a class holding it copies it on
 * its own and not inside a block with its neighbours (leaf_01063ac0.cpp's
 * form) */
struct Vector013474b0 { /* derived name */

    Vector013474b0(const Vector013474b0 &other) : quad(other.quad) {}

    Vec4 quad;
};

/* derived names: the element of an array appended to by FUN_00f48730 and FUN_0120b6c0:
 * four vectors each copied by its own aligned move, then 40 plain bytes copied together (the last 8 first); the fields are not traced */
struct Record013474b0 {       /* derived name */
    Vector013474b0 unknown0;  /* +0x0 */
    Vector013474b0 unknown10; /* +0x10 */
    Vector013474b0 unknown20; /* +0x20 */
    Vector013474b0 unknown30; /* +0x30 */
    u64 unknown40[5];         /* +0x40 */
};

/* FUN_013474b0: the append that returns the new element's index (the old
 * count kept across the growth and the copy, then returned) */
template unsigned Array05943280<Record013474b0>::add(const Record013474b0 &);
