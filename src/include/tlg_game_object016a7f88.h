/* src/include/tlg_game_object016a7f88.h: the class whose vtable is at 0x16a7f88
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7F88_H
#define TLG_GAME_OBJECT016A7F88_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_object01367090.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7f88
 * (config/vtables.derived.base.txt, stored by FUN_002bbb10 FUN_002bbc70 FUN_002bbda0), 0x80 bytes
 * (`mov edi, 0x80` before operator new in its creator FUN_002bb9b0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_002bbb10 (leaf_002bbc70.cpp) sets the fields; its destructor
 * FUN_002bbc70 tears down the array of pairs at +0x60, then the Name at
 * +0x24. */
class Object016a7f88 : public Object016b9108 /* derived name */
{
  public:
    Object016a7f88(const Name &name); /* FUN_002bbb10 */

    /* defined in the class: the class has no key function, so the unit of
     * the constructor emits the vtable and the destructors (FUN_002bbc70,
     * then FUN_002bbda0, the deleting one, with it inlined) */
    virtual inline ~Object016a7f88() {}

  private:
    Name name24;     /* +0x24: emptied by the constructor; not traced */
    float unknown28; /* +0x28: 0 from the constructor; not traced */
    float unknown2c; /* +0x2c: 0.5 from the constructor; not traced */
    float unknown30; /* +0x30: 0.5 from the constructor; not traced */
    u8 unknown34[0xc];
    Float4A unknown40; /* +0x40: (0.5, 0.5, 0.5, 1) from the constructor; not traced */
    Float4A unknown50; /* +0x50: (0, 0, 0, 1) from the constructor; not traced */
    /* +0x60: pairs of counted references with the array's lock at +0x74
     * (made free, `mov dword [r14+0x74], 0`, after the owner's index), each
     * destroyed, then the block; made room for one by the constructor */
    Array01343a80<Object01367090> unknown60;
    u8 unknown78[0x8];
};

#endif
