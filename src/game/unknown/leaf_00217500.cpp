/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_simd.h"

/* derived names: a vector that copies itself through its own constructor
 * (one `vmovaps` load and store), so that a class holding it copies it on
 * its own and not inside a block with its neighbours (leaf_01063ac0.cpp's
 * form) */
struct Vector00217500 { /* derived name */

    Vector00217500(const Vector00217500 &other) : quad(other.quad) {}

    Vec4 quad;
};

/* derived names: the element of an array appended to by FUN_002155f0, FUN_008302e0, FUN_00a00010 and FUN_013325c0:
 * six vectors each copied by its own aligned move, an int, three more such vectors, a vector and an int copied together (the int first), two more vectors and an 8-byte word; the fields are not traced */
struct Record00217500 {       /* derived name */
    Vector00217500 unknown0;  /* +0x0 */
    Vector00217500 unknown10; /* +0x10 */
    Vector00217500 unknown20; /* +0x20 */
    Vector00217500 unknown30; /* +0x30 */
    Vector00217500 unknown40; /* +0x40 */
    Vector00217500 unknown50; /* +0x50 */
    int unknown60;            /* +0x60 */
    Vector00217500 unknown70; /* +0x70 */
    Vector00217500 unknown80; /* +0x80 */
    Vector00217500 unknown90; /* +0x90 */
    Vec4 unknowna0;           /* +0xa0 */
    int unknownb0;            /* +0xb0 */
    Vector00217500 unknownc0; /* +0xc0 */
    Vector00217500 unknownd0; /* +0xd0 */
    void *unknowne0;          /* +0xe0 */
};

/* FUN_00217500: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record00217500>::push(const Record00217500 &);
