/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: whether the object's item at +0x28 is the one the owner
 * found through the record at +0x900 of the object at +0x38 of the object
 * the pointer at 0x57c9390 holds (that record's +0x10) has at +0x28 of its
 * +0x138's +0x30, once FUN_002c2580 has accepted the owner, the node the
 * record at +0x8d8 refers to (at +0x60) and the item's +0xc. The node is
 * taken through a counted reference that is dropped at once. The classes
 * are not traced. */
struct Item00aba610; /* derived name */

struct Target00aba610 { /* derived name */
    u8 unknown0[0x28];
    Item00aba610 *unknown28; /* +0x28 */
};

struct Record00aba610 { /* derived name */
    u8 unknown0[0x30];
    Target00aba610 *unknown30; /* +0x30 */
};

struct Owner00aba610 { /* derived name */
    u8 unknown0[0x138];
    Record00aba610 *unknown138; /* +0x138 */
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x10];
    Owner00aba610 *unknown10; /* +0x10 */
};

struct Member057c9390_38_8d8 { /* derived name */
    u8 unknown0[0x28];
    Ref00503fb0<Object016b9108> unknown28; /* +0x28 */

    Ref00503fb0<Object016b9108> node() const /* derived name */
    {
        return unknown28;
    }
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x8d8];
    Member057c9390_38_8d8 *unknown8d8; /* +0x8d8 */
    u8 unknown8e0[0x20];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

struct Object00aba610 { /* derived name */
    u8 unknown0[0x28];
    Item00aba610 *unknown28; /* +0x28 */
};

int FUN_002c2580(Owner00aba610 *owner, void *node, void *item); /* derived name */

// NONMATCHING: 8/78, 259 bytes for 278. The base keeps the result in r15d (`xor r15d, r15d` at the
// entry, `mov r15d, 1; je; xor r15d, r15d` at the end: a phi of the constants reaching one return)
// and tests the node for null again after its reference is dropped (`test r13, r13` at 0xaba6d8);
// the build returns from each arm and folds the second test into the first. The early-return form
// and the result-variable form give the same bytes.
// Round 560C: the base's result is an int phi (`mov eax, r15d` at the return), the same class as
// FUN_005b0500's (one block of 0 every failure joins), with the node's re-test after the release on
// top; not compiled.
bool FUN_00aba610(const Object00aba610 *self) /* derived name */
{
    bool found = false;
    Member057c9390_38 *member = D_57c9390->unknown38;
    if (member->unknown8d8) {
        Item00aba610 *item = self->unknown28;
        Owner00aba610 *owner = member->unknown900->unknown10;
        Object016b9108 *node = member->unknown8d8->node().get();
        if (owner && node &&
            FUN_002c2580(owner, reinterpret_cast<u8 *>(node) + 0x60,
                         reinterpret_cast<u8 *>(item) + 0xc)) {
            Target00aba610 *target = owner->unknown138->unknown30;
            found = target && target->unknown28 == item;
        }
    }
    return found;
}
