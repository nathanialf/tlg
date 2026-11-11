/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: hands each of the object's entries (0x100 bytes each from
 * the pointer at +0x50, their count at +0x58) to slot 4 of its argument,
 * stopping with 0 at the first zero answer, else 1. Its pointer is at
 * 0x16b12a8 (a vtable without a row). Class and method unknown. */
struct Entry00968640 { /* derived name */
    u8 unknown0[0x100];
};

class Visitor00968640 /* derived name */
{
  public:
    virtual void slot0();                    /* derived name; not traced */
    virtual void slot1();                    /* derived name; not traced */
    virtual void slot2();                    /* derived name; not traced */
    virtual void slot3();                    /* derived name; not traced */
    virtual int slot4(Entry00968640 *entry); /* derived name */
};

struct Object00968640 { /* derived name */
    u8 unknown0[0x50];
    Entry00968640 *entries; /* +0x50 */
    u32 count;              /* +0x58 */
};

int FUN_00968640(Object00968640 *self, Visitor00968640 *visitor) /* derived name */
{
    for (u32 i = 0; i < self->count; i++) {
        if (!visitor->slot4(&self->entries[i]))
            return 0;
    }
    return 1;
}
