/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_element013742e0.h"
#include "tlg_game_object016cc398.h"
#include "tlg_game_shared.h"

/* derived names: the device at +0x2c8 of the object below: FUN_012ff2f0 is
 * its CreateBuffer (the name and JsBuffer.cpp from its assert strings),
 * taking the description of the buffer, no initial data and where to put
 * the buffer made */
struct Device012ff2f0; /* derived name */

/* derived names: the description CreateBuffer reads (its assert names
 * pDesc and pDesc->ByteWidth): the size first; the other fields as slot 5
 * sets them */
struct BufferDesc012ff2f0 { /* derived name */
    unsigned ByteWidth;     /* +0x0: from the assert string */
    unsigned unknown4;      /* +0x4 */
    unsigned unknown8;      /* +0x8 */
    unsigned unknownc;      /* +0xc */
    unsigned unknown10;     /* +0x10 */
    unsigned unknown14;     /* +0x14 */
};

int FUN_012ff2f0(Device012ff2f0 *device, const BufferDesc012ff2f0 *pDesc, const void *initialData,
                 Shared00901550 **buffer); /* derived name */

/* derived names: the object the pointer at 0x5835fb0 holds
 * (leaf_00df2f80.cpp): the device at +0x2c8 */
struct Object05835fb0 { /* derived name */
    u8 unknown0[0x2c8];
    Device012ff2f0 *unknown2c8; /* +0x2c8 */
};

extern Object05835fb0 *D_5835fb0;

/* derived names: an array with an int of its own in the array's tail
 * (zero from the constructor, `mov dword [r15+0xb4], 0`; 0x18 bytes a
 * list), two of them at +0xa0 of the class below, destroyed last to first
 * (the first's address taken before the second's destructor is called:
 * `lea r14, [rbx+0xa0]` at 0x9015ac) */
struct List00901550 : public Array05943280<Element013742e0> { /* derived name */
    int unknown14;                                            /* +0x14 */
};

void FUN_00900dc0(List00901550 *list); /* derived name: not traced */

/* derived names: the class whose vtable is at 0x16b0a98
 * (config/vtables.derived.base.txt, stored by its constructor FUN_009010e0
 * and its destructor), over Object016cc398: the 16 bytes at +0x80 and the
 * buffer at +0x90 cleared by the constructor (slot 5 makes it), two lists
 * at +0xa0, one of them current */
class Object016b0a98 : public Object016cc398 /* derived name */
{
  public:
    virtual ~Object016b0a98();
    /* slots 5 to 11: Object016cc398's vtable has them too (0x40b0 and
     * empty bodies); declared here */
    virtual bool slot5();  /* FUN_009016e0 */
    virtual void slot6();  /* derived name; FUN_00901750, not traced */
    virtual void slot7();  /* derived name; empty */
    virtual void slot8();  /* derived name; empty */
    virtual void slot9();  /* derived name; empty */
    virtual void slot10(); /* derived name; empty */
    virtual void slot11(); /* FUN_00903790 */

  private:
    u8 unknown58[0x20];
    /* +0x78: which list of the two is current, flipped by slot 11 by
     * compare-and-swap; volatile: other threads read it while it is
     * flipped (the base reads it again for the exchange after reading it
     * for the next value: `mov edx, [rbx+0x78]; ...; mov ecx, [rsi]`) */
    volatile int current78;
    u8 unknown7c[0x4];
    void *unknown80;                            /* +0x80 */
    void *unknown88;                            /* +0x88 */
    SharedRef00901550<Shared00901550> shared90; /* +0x90 */
    u8 unknown98[0x8];
    List00901550 listsa0[2]; /* +0xa0 */
};

/* derived names: the complete destructor: the shared object dropped while
 * the object at 0x5835fb0 is there, then the members in reverse (the two
 * lists, the shared object's holder again) and Object016cc398's body
 * inline. FUN_009016c0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016b0a98::~Object016b0a98()
{
    if (D_5835fb0)
        shared90.reset();
}

/* derived names: slot 5 of the vtable at 0x16b0a98: while the object at
 * 0x5835fb0 is there, its device (read first) makes the 16-byte buffer at +0x90 (the
 * description set field by field on the stack: (16, 0, 4, 0) one aligned
 * vector, then the last eight bytes zero); true */
bool Object016b0a98::slot5()
{
    if (D_5835fb0) {
        Device012ff2f0 *device = D_5835fb0->unknown2c8;
        BufferDesc012ff2f0 desc;
        desc.ByteWidth = 16;
        desc.unknown4 = 0;
        desc.unknown8 = 4;
        desc.unknownc = 0;
        desc.unknown10 = 0;
        desc.unknown14 = 0;
        FUN_012ff2f0(device, &desc, 0, &shared90);
    }
    return true;
}

/* derived names: slot 11 of the vtable at 0x16b0a98: the current list
 * emptied (the index read once for it), handed to FUN_00900dc0 (the index
 * read again), then the other list made current by compare-and-swap */
void Object016b0a98::slot11()
{
    listsa0[current78].clear();
    FUN_00900dc0(&listsa0[current78]);
    const int next = current78 ^ 1;
    int old;
    do
        old = current78;
    while (compareAndSwap(const_cast<int *>(&current78), old, next) != old);
}
