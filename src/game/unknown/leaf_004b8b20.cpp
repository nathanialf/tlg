/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: the object FUN_004b8b20 is given and holds: the pointer at
 * +0x28 (handed to FUN_004afab0) and the points at +0x50 and +0x70 it
 * copies. Their meaning is not traced. */
struct Target004b8b20 : Object016b9108 /* derived name */
{
    u8 unknown24[0x4];
    void *unknown28; /* +0x28 */
    u8 unknown30[0x20];
    Float4A unknown50; /* +0x50 */
    u8 unknown60[0x10];
    Float4A unknown70; /* +0x70 */
};

/* derived names: the object FUN_004b6d00 gives a target through
 * FUN_004b8b20: points at +0x60 to +0xf0 and a counted reference another
 * thread may replace at +0x4e0. Their meaning is not traced. */
struct Object004b8b20 /* derived name */
{
    /* 0x4b8b20: the target held, FUN_004afab0 told of its pointer at
     * +0x28, then six points set to its point at +0x50 and one to its
     * point at +0x70 */
    void setTarget(Target004b8b20 *target); /* derived name */

    u8 unknown0[0x60];
    Float4A unknown60; /* +0x60 */
    Float4A unknown70; /* +0x70 */
    Float4A unknown80; /* +0x80 */
    Float4A unknown90; /* +0x90 */
    Float4A unknownA0; /* +0xa0 */
    u8 unknownB0[0x30];
    Float4A unknownE0; /* +0xe0 */
    Float4A unknownF0; /* +0xf0 */
    u8 unknown100[0x3e0];
    AtomicRef0045c470<Object016b9108> held4e0; /* +0x4e0 */
};

void FUN_004afab0(Object004b8b20 *self, void *unknown); /* derived name */

void Object004b8b20::setTarget(Target004b8b20 *target)
{
    held4e0.set(target);
    FUN_004afab0(this, target->unknown28);
    const Target004b8b20 *held = static_cast<Target004b8b20 *>(held4e0.get());
    unknownA0 = held->unknown50;
    unknown60 = held->unknown50;
    unknown70 = held->unknown50;
    unknown80 = held->unknown50;
    unknown90 = held->unknown50;
    unknownE0 = held->unknown50;
    unknownF0 = held->unknown70;
}
