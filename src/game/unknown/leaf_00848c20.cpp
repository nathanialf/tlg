/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: with a context at +0xc0, the function at +0x18 of the
 * table at +0xc8 is called with the context, the target and two of the
 * three floats beside the scale at +0xb8; then the node the name at +0x11c
 * names, when this thread may use it and its type is the one the pointer at
 * 0x581fa48 holds or derives from it, is passed to FUN_008f2f80 under a
 * reference of its own, with the first float times the third. Called at
 * 0x13352cb and 0x133533d. The classes, the
 * target and the floats' meaning are not traced. */
struct Target00848c20; /* derived name */

struct Handler00848c20 { /* derived name */
    u8 unknown0[0x18];
    void (*update)(void *context, Target00848c20 *target, float x, float y,
                   float scale); /* +0x18 */
};

/* a context and the table of functions called with it */
struct Callback00848c20 {     /* derived name */
    void *context;            /* +0x0 */
    Handler00848c20 *handler; /* +0x8 */

    /* the scale is read before the table (0x848c4a) */
    void update(Target00848c20 *target, float x, float y, float scale) /* derived name */
    {
        handler->update(context, target, x, y, scale);
    }
};

struct Object00848c20 { /* derived name */
    u8 unknown0[0xb8];
    float scale; /* +0xb8 */
    u8 unknownbc[0x4];
    Callback00848c20 callback; /* +0xc0 */
    u8 unknownd0[0x4c];
    Name name; /* +0x11c */
};

extern const Type00503fb0 *D_581fa48;

void FUN_008f2f80(Object016b9108 *node, Target00848c20 *target, float x, float y,
                  float scale); /* derived name */

void FUN_00848c20(Object00848c20 *self, Target00848c20 *target, float x, float y,
                  float z) /* derived name */
{
    if (!self->callback.context)
        return;
    self->callback.update(target, x, y, self->scale);
    Object016b9108 *node = static_cast<Object016b9108 *>(D_17ac870[self->name.index].record18);
    if (node && ((node->flags16 & 4) || threadMayUse()) && node->isKindOf(D_581fa48)) {
        Ref00503fb0<Object016b9108> reference(node);
        FUN_008f2f80(node, target, x * z, y, self->scale);
    }
}
