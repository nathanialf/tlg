/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16a8218 and 0x16a9a30 in
 * .data.rel.ro) that, when the pointer at +0x28 is set and the one at +0x108
 * is still null, has FUN_002054d0 fill the slot at +0x108 from it (third
 * argument 0) and then clears bit 1 of the byte at +0x100 of the object the
 * slot now holds. FUN_002054d0 takes the slot by address and exchanges the
 * pointer into it. Class and method unknown; the fields' types beyond their
 * widths are not traced. */
struct Source0042dbe0; /* derived name */

struct Target0042dbe0 /* derived name */
{
    u8 unknown0[0x100];
    u8 flags100; /* +0x100 */
};

struct Position0042dbe0 { /* derived name */
    int x;                /* copied whole */
    float y;              /* raised by 0.5 for the debug text */
    int z;                /* copied whole */
    int w;                /* copied whole */
};

struct Object0042dbe0 /* derived name */
{
    u8 unknown0[0x28];
    Source0042dbe0 *unknown28; /* +0x28 */
    u8 unknown30[0x20];
    Position0042dbe0 position; /* +0x50 */
    u8 unknown60[0xa8];
    Target0042dbe0 *unknown108; /* +0x108 */
    u8 unknown110[0xcc];
    float jumpSpeed; /* +0x1dc: derived name, after its debug text */
};

void FUN_002054d0(Target0042dbe0 **slot, Source0042dbe0 *source, int flag); /* derived name */

void FUN_0042dbe0(Object0042dbe0 *self) /* derived name */
{
    if (self->unknown28 && !self->unknown108) {
        FUN_002054d0(&self->unknown108, self->unknown28, 0);
        if (self->unknown108)
            self->unknown108->flags100 &= ~2;
    }
}

/* derived names: the method in the same place of another class (its address
 * at 0x16aa780): FUN_0042dbe0's body, then, with the slot at +0x108 filled,
 * a line of debug text "JumpSpeed: %f" with the float at +0x1dc drawn half a
 * unit above the position at +0x50 (FUN_00205720: the position, a colour
 * 0xc080a0ff and a scale of 1, a flag 0, the format and its value) */
struct TextStyle0042dbe0 { /* derived name */
    u32 colour;
    float scale;
};

void FUN_00205720(const Position0042dbe0 *position, const TextStyle0042dbe0 *style, int flag,
                  const char *format, ...); /* derived name */

// NONMATCHING: greedy's assignment: the base holds the object in rbx and the slot's address in
// r14, the build the other way; the operations the same
void FUN_004eafd0(Object0042dbe0 *self) /* derived name */
{
    FUN_0042dbe0(self);
    if (self->unknown108) {
        Position0042dbe0 position = self->position;
        position.y += 0.5f;
        TextStyle0042dbe0 style = {0xc080a0ff, 1.0f};
        FUN_00205720(&position, &style, 0, "JumpSpeed: %f", self->jumpSpeed);
    }
}
