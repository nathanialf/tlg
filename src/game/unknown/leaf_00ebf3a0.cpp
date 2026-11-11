/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: allocates size bytes aligned to 32 from the heap that slot
 * 33 of the object at +0x100 of the object the pointer at 0x5938c40 holds
 * gives (its slot 4, with 1 as the last argument), a tail call; nothing (null)
 * for a size of 0. The slots' meaning is not traced. */
class Heap00ebf3a0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void *slot4(unsigned size, unsigned alignment, int flags); /* derived name */
};

class Member05938c40_100 /* derived name */
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
    virtual void slot10();          /* derived name; not traced */
    virtual void slot11();          /* derived name; not traced */
    virtual void slot12();          /* derived name; not traced */
    virtual void slot13();          /* derived name; not traced */
    virtual void slot14();          /* derived name; not traced */
    virtual void slot15();          /* derived name; not traced */
    virtual void slot16();          /* derived name; not traced */
    virtual void slot17();          /* derived name; not traced */
    virtual void slot18();          /* derived name; not traced */
    virtual void slot19();          /* derived name; not traced */
    virtual void slot20();          /* derived name; not traced */
    virtual void slot21();          /* derived name; not traced */
    virtual void slot22();          /* derived name; not traced */
    virtual void slot23();          /* derived name; not traced */
    virtual void slot24();          /* derived name; not traced */
    virtual void slot25();          /* derived name; not traced */
    virtual void slot26();          /* derived name; not traced */
    virtual void slot27();          /* derived name; not traced */
    virtual void slot28();          /* derived name; not traced */
    virtual void slot29();          /* derived name; not traced */
    virtual void slot30();          /* derived name; not traced */
    virtual void slot31();          /* derived name; not traced */
    virtual void slot32();          /* derived name; not traced */
    virtual Heap00ebf3a0 *slot33(); /* derived name */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Member05938c40_100 *unknown100; /* +0x100 */
};

extern Object05938c40 *D_5938c40;

// NONMATCHING: the base keeps the argument in a 64-bit register (`mov rbx, rdi`) though it tests
// and passes only its low half (`test ebx, ebx`, `mov esi, ebx`): a 64-bit parameter used as 32
// bits, whose source form is not found; this copies a 32-bit one (`mov ebx, edi`), the rest equal
void *FUN_00ebf3a0(unsigned size) /* derived name */
{
    Heap00ebf3a0 *heap = D_5938c40->unknown100->slot33();
    if (!size)
        return 0;
    return heap->slot4(size, 0x20, 1);
}
