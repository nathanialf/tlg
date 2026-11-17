/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: the 0x70-byte element FUN_00f6d440 appends (nine sites of
 * FUN_00f59e00, each building one on the stack: the ints at +0x0 and +0x4,
 * zero vectors, an address at +0x40, the word at +0x60 -1). Its
 * copy constructor copies member by member: each member on its own, the
 * pair at +0x0 as one quadword, the vectors as `vmovaps`, the three ints at
 * +0x30 as a quadword and a doubleword, the pointer, the aligned four floats
 * lane by lane and the int (0xf6d4dd to 0xf6d536). An implicit copy
 * constructor copies the trivially copyable members from +0x0 to +0x48 as
 * one block (two `vmovups ymm`): clang merges members into one copy only
 * for a defaulted constructor (CGClass.cpp:1056, MemcpyableCtor). The
 * members' use is not traced. */
struct Pair00f6d440 { /* derived name */
    int unknown0;
    int unknown4;
};

struct Triple00f6d440 { /* derived name */
    int unknown0;
    int unknown4;
    int unknown8;
};

struct Element00f6d440 { /* derived name */

    Element00f6d440(const Element00f6d440 &other)
        : unknown0(other.unknown0), unknown10(other.unknown10), unknown20(other.unknown20),
          unknown30(other.unknown30), unknown40(other.unknown40), unknown50(other.unknown50),
          unknown60(other.unknown60)
    {
    }

    Pair00f6d440 unknown0;
    hkVector4 unknown10;      /* +0x10 */
    hkVector4 unknown20;      /* +0x20 */
    Triple00f6d440 unknown30; /* +0x30 */
    const char *unknown40;    /* +0x40 */
    Float4A unknown50;        /* +0x50 */
    int unknown60;            /* +0x60 */
};

/* FUN_00f6d440 */
template void Array05943280<Element00f6d440>::push(const Element00f6d440 &);
