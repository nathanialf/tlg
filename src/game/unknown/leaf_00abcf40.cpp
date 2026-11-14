/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: takes the object a source refers to when the source's
 * kind is one of the first 22, else puts the whole state back to empty (the
 * int at +0x0 made -1, the pointer at +0x8, the ints at +0x18 and +0x24
 * cleared and the reference emptied); the int at +0x1c and the byte at +0x20
 * are cleared either way. The classes are not traced. */
struct Source00abcf40 { /* derived name */
    unsigned kind;      /* +0x0 */
    u8 unknown4[0x4];
    AtomicRef0045c470<Node00503fb0> object; /* +0x8 */
};

struct Object00abcf40 { /* derived name */
    int unknown0;       /* +0x0 */
    u8 unknown4[0x4];
    void *unknown8;                         /* +0x8 */
    AtomicRef0045c470<Node00503fb0> object; /* +0x10 */
    int unknown18;                          /* +0x18 */
    int unknown1c;                          /* +0x1c */
    bool unknown20;                         /* +0x20 */
    u8 unknown21[0x3];
    int unknown24; /* +0x24 */
};

void FUN_00abcf40(Object00abcf40 *self, const Source00abcf40 *source) /* derived name */
{
    if (source->kind < 22) {
        self->object = source->object;
        self->unknown1c = 0;
        self->unknown20 = false;
    } else {
        self->unknown0 = -1;
        self->unknown8 = 0;
        self->unknown18 = 0;
        self->object.clear();
        self->unknown1c = 0;
        self->unknown20 = false;
        self->unknown24 = 0;
    }
}
