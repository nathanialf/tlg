/* An object at +0xf0 of its owner whose first virtual method takes a pointer
 * and an int; three matched thunks in src/game/unknown/ forward their own
 * second argument to it with a constant and return 0. derived names. */
#ifndef TLG_DEVICE_THUNK_H
#define TLG_DEVICE_THUNK_H

#include "tlg_types.h"

struct Device583950Vtable {
    void (*method0)(void *self, void *arg, int mode);
};

struct Device583950 {
    Device583950Vtable *vtable;
};

struct Owner583950 {
    u8 unknown0[0xf0];
    Device583950 *device;
};

#endif
