/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the object's class (the pointer at +0x18, its parent at
 * +0x0 of each class record) is the class the pointer at 0x5948b00 holds or
 * derives from it, passes the object to FUN_0081e8d0, a tail call: a checked
 * downcast and its null test (made only on the path where the parent chain
 * matched, the direct match having read the object already). FUN_001bd010
 * takes its address (lea at 0x1bd032). The classes' other fields and the
 * callee's return type are not traced. */
struct Class01bbc00 { /* derived name */
    const Class01bbc00 *parent;
};

extern const Class01bbc00 *D_5948b00;

struct Object01bbc00 { /* derived name */
    u8 unknown0[0x18];
    const Class01bbc00 *type;

    bool isKindOf(const Class01bbc00 *of) const
    {
        const Class01bbc00 *c = type;
        do {
            if (c == of)
                return true;
            c = c->parent;
        } while (c);
        return false;
    }
};

void FUN_0081e8d0(Object01bbc00 *object); /* derived name */

// NONMATCHING: the loop's shape: the base tests the object's own class before the loop and the
// parents in a rotated loop (the downcast's null test only on the parents' path), the compile
// keeps one loop with the test at its head; the unrotated or tail-duplicated loop class of round
// 138B (3)
void FUN_001bbc00(Object01bbc00 *object) /* derived name */
{
    Object01bbc00 *target = object->isKindOf(D_5948b00) ? object : 0;
    if (target)
        FUN_0081e8d0(target);
}
