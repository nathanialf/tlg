/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: whether any object of the array at +0x48 (count +0x50,
 * read once) answers true at its virtual function of slot 10; a counted
 * reference to the object is held for the call. The counter is unsigned
 * (`inc r13d; cmp r13d, [rbp-0x34]; jb`) and the array's index a signed
 * int (`movsxd rax, r13d`). The classes are not traced. */
struct Item009667d0 : Node00503fb0 { /* derived name */
    virtual void slot3();            /* derived name; not traced */
    virtual void slot4();            /* derived name; not traced */
    virtual void slot5();            /* derived name; not traced */
    virtual void slot6();            /* derived name; not traced */
    virtual void slot7();            /* derived name; not traced */
    virtual void slot8();            /* derived name; not traced */
    virtual void slot9();            /* derived name; not traced */
    virtual bool slot10();           /* derived name */
};

struct Object009667d0 { /* derived name */

    Ref00503fb0<Item009667d0> item(int index) const /* derived name */
    {
        return items[index];
    }

    u8 unknown0[0x48];
    Ref00503fb0<Item009667d0> *items; /* +0x48 */
    unsigned itemCount;               /* +0x50 */
};

// NONMATCHING: a register exchange (66/75: the counter in r13 and the mark in r12 in the base, the other way
// round in the build) and the two spill slots' order (the object at [rbp-0x30] and the count at [rbp-0x34] in
// the base; [rbp-0x38] and [rbp-0x2c] in the build)
bool FUN_009667d0(Object009667d0 *self) /* derived name */
{
    unsigned count = self->itemCount;
    for (unsigned i = 0; i < count; ++i) {
        if (self->item(i).get()->slot10())
            return true;
    }
    return false;
}
