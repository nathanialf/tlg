/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: hands the float at +0x39c of the member at +0xb0 of the
 * object the pointer at 0x5938c40 holds to slot 12 of each of that member's
 * entries (the array at +0x3c8, its count at +0x3d0), the float read again
 * for each call; slot 5 of the vtable at 0x16d0f58 (its pointer at
 * 0x16d0f90), one of the 109 vtables whose slot 0 is the destructor of
 * Object013a6a50 (FUN_013a6a50). The object itself is not read. */
class Object013a6a50; /* derived name */

class Entry013a5580 /* derived name */
{
  public:
    virtual void slot0();             /* derived name; not traced */
    virtual void slot1();             /* derived name; not traced */
    virtual void slot2();             /* derived name; not traced */
    virtual void slot3();             /* derived name; not traced */
    virtual void slot4();             /* derived name; not traced */
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6();             /* derived name; not traced */
    virtual void slot7();             /* derived name; not traced */
    virtual void slot8();             /* derived name; not traced */
    virtual void slot9();             /* derived name; not traced */
    virtual void slot10();            /* derived name; not traced */
    virtual void slot11();            /* derived name; not traced */
    virtual void slot12(float value); /* derived name */
};

struct Member05938c40_b0 { /* derived name */
    u8 unknown0[0x39c];
    float unknown39c; /* +0x39c */
    u8 unknown3a0[0x28];
    Entry013a5580 **entries; /* +0x3c8 */
    u32 count;               /* +0x3d0 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    Member05938c40_b0 *unknownb0;
};

extern Object05938c40 *D_5938c40;

void FUN_013a5580(Object013a6a50 *) /* derived name */
{
    Member05938c40_b0 *member = D_5938c40->unknownb0;
    Entry013a5580 **end = member->entries + member->count;
    for (Entry013a5580 **entry = member->entries; entry != end; ++entry)
        (*entry)->slot12(member->unknown39c);
}
