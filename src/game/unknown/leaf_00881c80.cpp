/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: slot 9 of the vtable at 0x16af2d8 (its pointer at
 * 0x16af330), the vtable stored by FUN_0087fe50 FUN_00880310: passes the
 * object to FUN_00881d80, hands the names of two script functions (the
 * volume viewer's mode) to FUN_00c89a10 with the object at +0x40 of the one
 * the pointer at 0x5938c40 holds (read again for the second), passes the
 * object to FUN_00d6caf0 with the one the pointer at 0x5989c08 holds, then
 * empties the counted reference at +0x1a0 by compare-and-swap and the array
 * of counted references at +0x1a8 (FUN_0138c8d0 with 0). The class and what
 * the callees do are not traced. */
struct Registry05938c40_40; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x40];
    Registry05938c40_40 *unknown40;
};

extern Object05938c40 *D_5938c40;

class Object05989c08; /* derived name */

extern Object05989c08 *D_5989c08;

struct Object00881c80 { /* derived name */
    u8 unknown0[0x1a0];
    AtomicRef0045c470<Node00503fb0> unknown1a0;          /* +0x1a0 */
    Array05943280<Ref00503fb0<Node00503fb0>> unknown1a8; /* +0x1a8 */
};

void FUN_00881d80(Object00881c80 *self);                            /* derived name */
void FUN_00c89a10(Registry05938c40_40 *registry, const char *name); /* derived name */
void FUN_00d6caf0(Object05989c08 *owner, Object00881c80 *object);   /* derived name */

void FUN_00881c80(Object00881c80 *self) /* derived name */
{
    FUN_00881d80(self);
    FUN_00c89a10(D_5938c40->unknown40, "GetVolumeViewerModeSw");
    FUN_00c89a10(D_5938c40->unknown40, "SwitchVolumeViewerMode");
    FUN_00d6caf0(D_5989c08, self);
    self->unknown1a0.clear();
    self->unknown1a8.clear(0);
}
