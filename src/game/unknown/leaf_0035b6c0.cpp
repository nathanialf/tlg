/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a virtual method (its address is a vtable's word). The
 * part at +0x250, when there is one, gets 16 less bit 1 of its word at
 * +0x100 at its +0x48; then, when the object at +0xc8 of the object at +0x68
 * of the one the pointer at 0x57c9390 holds has a name at +0xc0 that names a
 * record this thread may use, slot 10 of this object's vtable is called with
 * 0. The classes and the slot are not traced. */
struct Part0035b6c0 { /* derived name */
    u8 unknown0[0x48];
    int unknown48; /* +0x48 */
    u8 unknown4c[0xb4];
    u32 flags100; /* +0x100 */
};

struct Record0035b6c0 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16; /* +0x16 */
};

struct Named0035b6c0 { /* derived name */
    u8 unknown0[0xc0];
    Name name; /* +0xc0 */
};

struct Holder0035b6c0 { /* derived name */
    u8 unknown0[0xc8];
    Named0035b6c0 *unknownc8; /* +0xc8 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x68];
    Holder0035b6c0 *unknown68; /* +0x68 */
};

extern Object057c9390 *D_57c9390;

class Object0035b6c0 /* derived name */
{
  public:
    virtual void slot0();           /* derived name; not traced */
    virtual void slot1();           /* derived name; not traced */
    virtual void slot2();           /* derived name; not traced */
    virtual void slot3();           /* derived name; not traced */
    virtual void slot4();           /* derived name; not traced */
    virtual void slot5();           /* derived name; not traced */
    virtual void slot6();           /* derived name; not traced */
    virtual void slot7();           /* derived name; not traced */
    virtual void slot8();           /* derived name; not traced */
    virtual void slot9();           /* derived name; not traced */
    virtual void slot10(int value); /* derived name; not traced */

    u8 unknown8[0x248];
    Part0035b6c0 *part; /* +0x250 */
};

void FUN_0035b6c0(Object0035b6c0 *self) /* derived name */
{
    if (Part0035b6c0 *part = self->part)
        part->unknown48 = 16 - ((part->flags100 >> 1) & 1);
    Named0035b6c0 *named = D_57c9390->unknown68->unknownc8;
    if (named && named->name.index != 0) {
        const Record0035b6c0 *record =
            static_cast<const Record0035b6c0 *>(D_17ac870[named->name.index].record18);
        if (record && ((record->flags16 & 4) || threadMayUse()))
            self->slot10(0);
    }
}
