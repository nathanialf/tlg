/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_string01331840.h"
#include "tlg_game_object016b9108.h"

/* derived names: the object at 0x5938c40 as the volume events see it: the
 * record at +0xd0 FUN_00c633b0 posts them to */
struct Events00c633b0; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xd0];
    Events00c633b0 *unknownd0; /* +0xd0 */
};

extern Object05938c40 *D_5938c40;

/* derived name: the class's name in the events' names ("GameObject.%s";
 * no file defines it yet) */
extern Name D_57d9b3c;

/* derived names: the class whose vtable is at 0x16aa8e0 (stored by
 * FUN_004f3ad0 FUN_004f3df0) as slot 27 sees it: the object at +0x28 whose
 * name the events carry, and the member at +0x120 they are posted with */
struct Object004fde80 { /* derived name */
    u8 unknown0[0x28];
    Object016b9108 *unknown28; /* +0x28 */
    u8 unknown30[0xf0];
    u8 unknown120[8]; /* +0x120: not traced */
};

/* derived names: slot 27 of the vtable at 0x16aa8e0's base, run first */
void FUN_00502bc0(Object004fde80 *self); /* derived name */
/* derived names: an event named `event` posted for the object's name */
void FUN_00c633b0(Events00c633b0 *events, const Name &event, const Name &object,
                  void *unknown); /* derived name */

/* derived name: the name of a string, the empty name for an empty one
 * (FUN_013baad0 with add false) */
static inline Name nameOf(const char *string) /* derived name */
{
    Name name;
    name.index = string[0] ? FUN_013baad0(string, FUN_013bad90(string), strlen(string), false) : 0;
    return name;
}

/* derived names: slot 27 of the vtable at 0x16aa8e0 (its pointer at
 * 0x16aa9c8): the base's slot 27 (FUN_00502bc0), then the events
 * "GameObject.%s.enterVolume" and "GameObject.%s.leaveVolume" posted with
 * the class's name. Class and method unknown. */
// NONMATCHING: the event's name: the base keeps its index in ebx across FUN_00c633b0 and
// releases it from the register (`test ebx, ebx; ... mov edi, ebx`), storing it once after the
// string's test; the build stores 0 first (the Name's constructor) and reloads it after the call
// (the callee's readonly argument, inferable once its body is in the module, as 0x46fb90's).
// The frame is the base's: the two texts are locals of the function, the names temporaries
void FUN_004fde80(Object004fde80 *self) /* derived name */
{
    FUN_00502bc0(self);
    Events00c633b0 *events = D_5938c40->unknownd0;
    String01331840 enter;
    FUN_01331840(&enter, "GameObject.%s.enterVolume", D_17ac870[D_57d9b3c.index].string0);
    FUN_00c633b0(events, nameOf(enter.text), self->unknown28->name, self->unknown120);
    events = D_5938c40->unknownd0;
    String01331840 leave;
    FUN_01331840(&leave, "GameObject.%s.leaveVolume", D_17ac870[D_57d9b3c.index].string0);
    FUN_00c633b0(events, nameOf(leave.text), self->unknown28->name, self->unknown120);
}
