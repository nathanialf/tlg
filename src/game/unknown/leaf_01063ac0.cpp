/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_simd.h"

/* derived names: a vector that copies itself through its own constructor
 * (one `vmovaps` load and store), so that a class holding it copies it on
 * its own and not inside a block with its neighbours */
struct Vector01063ac0 { /* derived name */

    Vector01063ac0(const Vector01063ac0 &other) : quad(other.quad) {}

    Vec4 quad;
};

/* derived names: the 0x60-byte element FUN_01063ac0 appends (two sites of
 * FUN_010532f0): four such vectors, then a vector and an int. Its implicit
 * copy constructor copies the four one by one and the last two members as
 * one 0x14-byte block (`vmovaps` at +0x0 to +0x30, the int at +0x50, then
 * the vector at +0x40: clang merges the trivially copyable members of a
 * defaulted copy constructor into one copy from the first to the end of
 * the last, CGClass.cpp:1056). With five trivially copyable vectors the
 * whole element is one block (`vmovups ymm`); with hkVector4 (tlg_simd.h)
 * copied member by member the int comes after the vector. The members' use
 * is not traced. */
struct Element01063ac0 { /* derived name */
    Vector01063ac0 unknown0;
    Vector01063ac0 unknown10; /* +0x10 */
    Vector01063ac0 unknown20; /* +0x20 */
    Vector01063ac0 unknown30; /* +0x30 */
    Vec4 unknown40;           /* +0x40 */
    int unknown50;            /* +0x50 */
};

/* FUN_01063ac0 */
template void Array05943280<Element01063ac0>::push(const Element01063ac0 &);
