/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback that, when the int at +0x8 of the record the
 * pointer at +0x0 of its third argument holds is not 0, stores that pointer
 * and the pointer at +0x8 of the third argument in the file's own pointers at
 * 0x57ca6c0 and 0x57ca6c8 (direct RIP-relative stores: internal linkage,
 * docs/DECISIONS.md D17), as leaf_0021c640.cpp's callback; FUN_0021c670 reads
 * them (0x21c731 on). FUN_001bd010 appends its address (lea at 0x1d32cf) to
 * the list leaf_0021c640.cpp names. Its first two arguments are unused and
 * their types not traced. Owner and meaning unknown. */
struct Record0021c620 { /* derived name */
    u8 unknown0[8];
    int unknown8;
};

struct Pair0021c620 { /* derived name */
    Record0021c620 *unknown0;
    void *unknown8;
};

static Record0021c620 *D_57ca6c0;
static void *D_57ca6c8;

void FUN_0021c620(void *, void *, const Pair0021c620 *pair) /* derived name */
{
    if (pair->unknown0->unknown8 != 0) {
        D_57ca6c0 = pair->unknown0;
        D_57ca6c8 = pair->unknown8;
    }
}
