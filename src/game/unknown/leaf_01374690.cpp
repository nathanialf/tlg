/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 7 of the object its second argument points to, a
 * tail call, when the int at +0xf38 of the object the pointer at 0x5938c40
 * holds is 1; slot 1 of the vtable at 0x16cc408 (its pointer at 0x16cc420; no
 * constructor stores it), its slot 0 the empty method FUN_001af750. The first
 * argument is not read. The classes and the return type are not traced. */
struct Object01374690; /* derived name */

class Argument01374690 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf38];
    int unknownF38;
};

extern Object05938c40 *D_5938c40;

void FUN_01374690(Object01374690 *, Argument01374690 *object) /* derived name */
{
    if (D_5938c40->unknownF38 == 1)
        object->slot7();
}
