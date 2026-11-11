/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: slots 5 and 18 of the vtable at 0x16bc0a0 (their pointers at
 * 0x16bc0d8 and 0x16bc140; stored by FUN_00ddbb60, home BytecodeReader.cpp),
 * two copies of one lazy lookup: when the pointer at +0x18 is null, it is set
 * to what FUN_00dd0a60 returns for the name at +0x80 of the record at +0x10
 * and its length, with the field at +0x1a8 of the object the owner at +0x8
 * holds at its +0x10 and the owner; the pointer is returned. The types of the
 * table and the result are not traced. */
struct Table00db4090; /* derived name */
struct Entry00db4090; /* derived name */

struct Holder00db4090 { /* derived name */
    u8 unknown0[0x1a8];
    Table00db4090 *unknown1a8; /* type not traced; its address is passed */
};

struct Owner00db4090 { /* derived name */
    u8 unknown0[0x10];
    Holder00db4090 *unknown10;
};

struct Record00db4090 { /* derived name */
    u8 unknown0[0x80];
    const char *name; /* derived name */
};

struct Object00db4090 { /* derived name */
    void *vtable;       /* the vtable at 0x16bc0a0; its class not traced */
    Owner00db4090 *unknown8;
    Record00db4090 *unknown10;
    Entry00db4090 *unknown18;
};

Entry00db4090 *FUN_00dd0a60(Table00db4090 **table, Owner00db4090 *owner, const char *name,
                            size_t length); /* derived name */

Entry00db4090 *FUN_00db4090(Object00db4090 *self) /* derived name */
{
    if (!self->unknown18) {
        Owner00db4090 *owner = self->unknown8;
        const char *name = self->unknown10->name;
        size_t length = strlen(name);
        self->unknown18 = FUN_00dd0a60(&owner->unknown10->unknown1a8, owner, name, length);
    }
    return self->unknown18;
}

Entry00db4090 *FUN_013c8440(Object00db4090 *self) /* derived name */
{
    if (!self->unknown18) {
        Owner00db4090 *owner = self->unknown8;
        const char *name = self->unknown10->name;
        size_t length = strlen(name);
        self->unknown18 = FUN_00dd0a60(&owner->unknown10->unknown1a8, owner, name, length);
    }
    return self->unknown18;
}
