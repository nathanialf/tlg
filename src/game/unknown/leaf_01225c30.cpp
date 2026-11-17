/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: the 0x70-byte element FUN_01225c30 appends (six sites of
 * FUN_0121a680, each building one on the stack: the ints at +0x0 and +0x4,
 * zero vectors, an address at +0x40, the word at +0x60 -1). Its
 * copy constructor copies member by member: each member on its own, the
 * pair at +0x0 as one quadword, the vectors as `vmovaps`, the three ints at
 * +0x30 as a quadword and a doubleword, the pointer, the aligned four floats
 * lane by lane and the int (0x1225cd4 to 0x1225d26). An implicit copy
 * constructor copies the trivially copyable members from +0x0 to +0x48 as
 * one block (two `vmovups ymm`): clang merges members into one copy only
 * for a defaulted constructor (CGClass.cpp:1056, MemcpyableCtor). The
 * members' use is not traced. */
struct Pair01225c30 { /* derived name */
    int unknown0;
    int unknown4;
};

struct Triple01225c30 { /* derived name */
    int unknown0;
    int unknown4;
    int unknown8;
};

struct Element01225c30 { /* derived name */

    Element01225c30(const Element01225c30 &other)
        : unknown0(other.unknown0), unknown10(other.unknown10), unknown20(other.unknown20),
          unknown30(other.unknown30), unknown40(other.unknown40), unknown50(other.unknown50),
          unknown60(other.unknown60)
    {
    }

    Pair01225c30 unknown0;
    hkVector4 unknown10;      /* +0x10 */
    hkVector4 unknown20;      /* +0x20 */
    Triple01225c30 unknown30; /* +0x30 */
    const char *unknown40;    /* +0x40 */
    Float4A unknown50;        /* +0x50 */
    int unknown60;            /* +0x60 */
};

/* FUN_01225c30 */
template void Array05943280<Element01225c30>::push(const Element01225c30 &);
