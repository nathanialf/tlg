/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_hks.h"
#include "tlg_simd.h"
#include "tlg_game_object016b85e0.h"

/* derived names: a list FUN_00c67c10 appends an entry to (0x90 bytes: a
 * name at +0x80 assigned from the first argument, counted references at
 * +0x48 and +0x50 set from the two nodes); not traced further */
struct List00c67c10; /* derived name */

void FUN_00c67c10(List00c67c10 *list, const Name &name, Object016b85e0 *first,
                  Object016b85e0 *second, const Vec4 &third, const Vec4 &fourth); /* derived name */

/* derived names: the record at +0x38 of the object the pointer at 0x5938c40
 * holds, its node at +0x30 the default; the object's lists from +0x78, one
 * chosen by the index at +0x90 */
struct Member05938c40_38 { /* derived name */
    u8 unknown0[0x30];
    Object016b85e0 *unknown30; /* +0x30 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x38];
    Member05938c40_38 *unknown38; /* +0x38 */
    u8 unknown40[0x38];
    List00c67c10 *lists[3]; /* +0x78: the extent not traced */
    unsigned current;       /* +0x90 */
};

extern Object05938c40 *D_5938c40;

/* derived name: appends a node twice, with an empty name and two zero
 * vectors, to the current list */
static void append(Object016b85e0 *node)
{
    FUN_00c67c10(D_5938c40->lists[D_5938c40->current], Name(), node, node, _mm_setzero_ps(),
                 _mm_setzero_ps());
}

/* derived name: a script function: appends the node its first argument
 * names when this thread may use it, else the default node; returns no
 * values */
// NONMATCHING: the thread's flag: here its address is computed before the
// node's flag 4 is tested and the byte tested in place (`test byte [rax],
// 1; jne`); the base tests flag 4 first, then `mov al, [rax]; and al, 1;
// je` to the default node, with the node's own call laid out first.
int FUN_00e70cc0(lua_State *state) /* derived name */
{
    HashedString string;
    FUN_00e81bd0(&string, state, 1);
    Name name(string);
    Object016b85e0 *node = static_cast<Object016b85e0 *>(D_17ac870[name.index].record18);
    if (node && isUsable(node))
        append(node);
    else
        append(D_5938c40->unknown38->unknown30);
    return 0;
}
