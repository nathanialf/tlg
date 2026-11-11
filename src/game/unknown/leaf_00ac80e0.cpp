/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtable at 0x16b37d0 (address point 0x16b37e0,
 * stored by FUN_00abf490; no row: the method stores no vptr). Through the
 * owner reached by the pointer at +0x8: the object at +0xd68 takes at +0x294
 * a mode, 3 when the record at +0x390 has its byte at +0x2d set and 2
 * otherwise; the owner's byte at +0x48e is cleared; and when the entry at
 * +0x40 of the owner's +0x350 has bit 0 of its flags at +0x58 set and its
 * float at +0x64 is not above 0, this object's byte at +0x18 is cleared;
 * its ints at +0x1c and +0x20 then become 0 and -1. The classes are not traced. */
struct Target00ac80e0 { /* derived name */
    u8 unknown0[0x294];
    int mode; /* +0x294: derived name */
};

struct Record00ac80e0 { /* derived name */
    u8 unknown0[0x2d];
    u8 unknown2d; /* +0x2d: compared with 0 */
};

struct Entry00ac80e0 { /* derived name */
    u8 unknown0[0x58];
    u8 flags58; /* +0x58: bit 0 tested */
    u8 unknown59[0xb];
    float unknown64;
};

struct Holder00ac80e0 { /* derived name */
    u8 unknown0[0x40];
    Entry00ac80e0 *entry; /* +0x40 */
};

struct Owner00ac80e0 { /* derived name */
    u8 unknown0[0x350];
    Holder00ac80e0 *unknown350;
    u8 unknown358[0x390 - 0x358];
    Record00ac80e0 *unknown390;
    u8 unknown398[0x48e - 0x398];
    bool unknown48e;
    u8 unknown48f[0xd68 - 0x48f];
    Target00ac80e0 *unknownd68;
};

class Object00ac80e0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name */

    Owner00ac80e0 **owner; /* +0x8 */
    u8 unknown10[8];
    bool unknown18;
    u8 unknown19[3];
    int unknown1c;
    int unknown20;
};

void Object00ac80e0::slot5()
{
    if (Target00ac80e0 *target = (*owner)->unknownd68) {
        Record00ac80e0 *record = (*owner)->unknown390;
        target->mode = record && record->unknown2d != 0 ? 3 : 2;
    }
    (*owner)->unknown48e = false;
    Entry00ac80e0 *entry = (*owner)->unknown350->entry;
    if (entry && (entry->flags58 & 1) && entry->unknown64 <= 0.0f)
        unknown18 = false;
    unknown1c = 0;
    unknown20 = -1;
}
