/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtable at 0x16b4d58 (no row; the class of
 * leaf_01392520.cpp; the method stores no vptr): FUN_01392310 resets the
 * members at +0x98 and +0x68, the bytes at +0x50 and +0x51, the int at +0x54
 * and the pointer at +0x58 are cleared and the float at +0x60 becomes 1;
 * then, when the byte at +0x53 is set, each entry of the member at +0x68
 * (its array at +0x18, its count at +0x20) has its link's pointer cleared and
 * the link's ints at +0x1c and +0x20 copied to its own at +0x10 and +0x14.
 * The classes are not traced. */
struct Link00b1a520 { /* derived name */
    void *unknown0;   /* +0x0 */
    u8 unknown8[0x14];
    int unknown1c; /* +0x1c */
    int unknown20; /* +0x20 */
};

struct Entry00b1a520 { /* derived name */
    u8 unknown0[0x10];
    int unknown10; /* +0x10 */
    int unknown14; /* +0x14 */
    u8 unknown18[0x18];
    Link00b1a520 *link; /* +0x30 */
};

struct Member00b1a520 { /* derived name */
    u8 unknown0[0x18];
    Entry00b1a520 **entries; /* +0x18 */
    unsigned count;          /* +0x20 */
    u8 unknown24[0xc];
};

struct Object00b1a520 { /* derived name */
    u8 unknown0[0x50];
    bool unknown50; /* +0x50 */
    bool unknown51; /* +0x51 */
    u8 unknown52;
    bool unknown53;  /* +0x53 */
    int unknown54;   /* +0x54 */
    void *unknown58; /* +0x58 */
    float unknown60; /* +0x60 */
    u8 unknown64[4];
    Member00b1a520 unknown68; /* +0x68 */
    Member00b1a520 unknown98; /* +0x98 */
};

void FUN_01392310(Member00b1a520 *member); /* derived name */

void FUN_00b1a520(Object00b1a520 *self) /* derived name */
{
    FUN_01392310(&self->unknown98);
    FUN_01392310(&self->unknown68);
    self->unknown51 = false;
    self->unknown50 = false;
    self->unknown54 = 0;
    self->unknown58 = 0;
    self->unknown60 = 1.0f;
    if (self->unknown53) {
        Entry00b1a520 **end = self->unknown68.entries + self->unknown68.count;
        for (Entry00b1a520 **entry = self->unknown68.entries; entry != end; ++entry) {
            Entry00b1a520 *current = *entry;
            current->link->unknown0 = 0;
            current->unknown10 = current->link->unknown1c;
            current->unknown14 = current->link->unknown20;
        }
    }
}
