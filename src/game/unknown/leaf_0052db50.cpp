/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 11 of the object its second argument points to
 * with the float at +0x19c of the object the pointer at 0x5938c40 holds, a
 * tail call; slot 2 of the vtable at 0x16ab3a8 (its pointer at 0x16ab3c8),
 * stored by FUN_0052c710, its slots 0 and 1 FUN_0052d4f0 and FUN_0052db10.
 * The first argument is not read. The classes and the return type are not
 * traced. */
struct Object0052db50; /* derived name */

class Argument0052db50 /* derived name */
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
    virtual void slot11(float value); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x19c];
    float unknown19c;
};

extern Object05938c40 *D_5938c40;

void FUN_0052db50(Object0052db50 *, Argument0052db50 *object) /* derived name */
{
    object->slot11(D_5938c40->unknown19c);
}
