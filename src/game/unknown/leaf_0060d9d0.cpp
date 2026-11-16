/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: passes the object to FUN_00609480, empties the counted
 * reference at +0x2d8 of the record at +0x108 of the object the pointer at
 * 0x5938c40 holds when it holds the object's own at +0xff8, hands "camera"
 * to FUN_00c51ca0 with that object's +0xf30, then passes the object to
 * FUN_00d6caf0 with the one the pointer at 0x5989c08 holds (a tail call).
 * Called through a table not traced; the classes are not traced. */
struct Record05938c40_108 { /* derived name */
    u8 unknown0[0x2d8];
    AtomicRef0045c470<Node00503fb0> unknown2d8; /* +0x2d8 */
};

struct Member05938c40_f30; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x108];
    Record05938c40_108 *unknown108; /* +0x108 */
    u8 unknown110[0xe20];
    Member05938c40_f30 *unknownf30; /* +0xf30 */
};

extern Object05938c40 *D_5938c40;

class Object05989c08; /* derived name */

extern Object05989c08 *D_5989c08;

struct Object0060d9d0 { /* derived name */
    u8 unknown0[0xff8];
    Node00503fb0 *unknownff8; /* +0xff8 */
};

void FUN_00609480(Object0060d9d0 *self);                          /* derived name */
void FUN_00c51ca0(Member05938c40_f30 *member, const char *name);  /* derived name */
void FUN_00d6caf0(Object05989c08 *owner, Object0060d9d0 *object); /* derived name */

void FUN_0060d9d0(Object0060d9d0 *self) /* derived name */
{
    FUN_00609480(self);
    if (D_5938c40->unknown108->unknown2d8.get() == self->unknownff8)
        D_5938c40->unknown108->unknown2d8.clear();
    FUN_00c51ca0(D_5938c40->unknownf30, "camera");
    FUN_00d6caf0(D_5989c08, self);
}
