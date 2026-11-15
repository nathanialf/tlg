/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object05945a38.h"

/* derived names: unless the float at +0x19c of the object the pointer at
 * 0x5938c40 holds is below 0.00001, hands it by address to FUN_0082fbe0 for
 * each entry of the list the pointer at 0x581c720 holds (FUN_00cb8490),
 * under the recursive lock of the object at 0x5945a38 (one of four such
 * functions: FUN_0133f330, FUN_01340240, FUN_01340310, FUN_01342d50). Its
 * parameters, if any, are not read; the list's entries are not traced. */
struct Object05938c40 { /* derived name */
    u8 unknown0[0x19c];
    float unknown19c; /* +0x19c */
};

struct List0581c720;  /* derived name */
struct Entry0082fbe0; /* derived name: the callback's object */

extern Object05938c40 *D_5938c40;
extern List0581c720 *D_581c720;

int FUN_0082fbe0(Entry0082fbe0 *entry, const float *value); /* derived name */
void FUN_00cb8490(List0581c720 *list, int (*callback)(Entry0082fbe0 *entry, const float *value),
                  const float *value); /* derived name */

// NONMATCHING: frame layout: the value whose address is passed sits at [rbp-0x28] in the base, a
// 4-byte hole between it and the canary at [rbp-0x20]; the build puts the float at [rbp-0x24]
// (everything else equal). The base's object is 8 bytes wide or 8-aligned: the function is equal
// with the local an 8-byte union of the float and a pointer (measured, not kept: the argument's
// real type is not traced). The int sibling 0x1331f60 and 0x1340240, 0x1340310, 0x1342d50 have
// the same slot.
void FUN_0133f330() /* derived name */
{
    if (D_5938c40->unknown19c < 0.00001f)
        return;
    float value = D_5938c40->unknown19c;
    D_5945a38->lock201028.lock();
    FUN_00cb8490(D_581c720, FUN_0082fbe0, &value);
    D_5945a38->lock201028.unlock();
}
