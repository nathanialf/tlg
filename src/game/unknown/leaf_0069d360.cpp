/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 4 of the object at +0x48 of the object the pointer
 * at 0x5938c40 holds with the pointer at +0x28 of the record at +0x98 of the
 * object the pointer at 0x57c9390 holds, a tail call; FUN_01337360 stores its
 * address in a local record it passes on (lea at 0x1337453). Its parameters
 * are not read; the classes and the slot's return type are not traced. */
struct Member057c9390_98_28; /* derived name */

class Member05938c40_48 /* derived name */
{
  public:
    virtual void slot0();                            /* derived name; not traced */
    virtual void slot1();                            /* derived name; not traced */
    virtual void slot2();                            /* derived name; not traced */
    virtual void slot3();                            /* derived name; not traced */
    virtual void slot4(Member057c9390_98_28 *value); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x48];
    Member05938c40_48 *unknown48;
};

extern Object05938c40 *D_5938c40;

struct Member057c9390_98 { /* derived name */
    u8 unknown0[0x28];
    Member057c9390_98_28 *unknown28;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x98];
    Member057c9390_98 *unknown98;
};

extern Object057c9390 *D_57c9390;

void FUN_0069d360() /* derived name */
{
    D_5938c40->unknown48->slot4(D_57c9390->unknown98->unknown28);
}
