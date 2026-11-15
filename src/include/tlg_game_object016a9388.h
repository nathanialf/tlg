/* src/include/tlg_game_object016a9388.h: the class whose vtable is at
 * 0x16a9388 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9388_H
#define TLG_GAME_OBJECT016A9388_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9388
 * (config/vtables.derived.base.txt, stored by FUN_003ecd10 FUN_003ed000), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_003ed000 tears them down
 * (the arrays of Names at +0x60, +0x48); the others where its constructor FUN_003ecd10 sets them. */
class Object016a9388 : public Object016b9108 /* derived name */
{
  public:
    Object016a9388(const Name &name); /* FUN_003ecd10 */
    virtual ~Object016a9388();

  private:
    float unknown24; /* +0x24: -1.0 from the constructor; not traced */
    float unknown28; /* +0x28: 0.25 from the constructor; not traced */
    float unknown2c; /* +0x2c: 1.0 from the constructor; not traced */
    float unknown30; /* +0x30: 0.25 from the constructor; not traced */
    float unknown34; /* +0x34: 0.11 from the constructor; not traced */
    float unknown38; /* +0x38: 30.0 from the constructor; not traced */
    int unknown3c;   /* +0x3c: zero from the constructor; not traced */
    int unknown40;   /* +0x40: 6 from the constructor; not traced */
    u8 unknown44[0x4];
    /* +0x48: an array of Names (the block at +0x48, the count at +0x50): the destructor releases each
     * (`mov r12, [r14+0x48]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array01343a80<Name> names48;
    /* +0x60: an array of Names (the block at +0x60, the count at +0x68): the destructor releases each
     * (`mov r12, [r14+0x60]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array01343a80<Name> names60;
    float unknown78; /* +0x78: 0.2 from the constructor; not traced */
    float unknown7c; /* +0x7c: 3.0 from the constructor; not traced */
    int unknown80;   /* +0x80: zero from the constructor; not traced */
    float unknown84; /* +0x84: 0.45 from the constructor; not traced */
    float unknown88; /* +0x88: 0.2 from the constructor; not traced */
    float unknown8c; /* +0x8c: 1.0 from the constructor; not traced */
    float unknown90; /* +0x90: 0.1 from the constructor; not traced */
    float unknown94; /* +0x94: 2.0 from the constructor; not traced */
    float unknown98; /* +0x98: 45.0 from the constructor; not traced */
    float unknown9c; /* +0x9c: 0.2 from the constructor; not traced */
    float unknowna0; /* +0xa0: 1.5 from the constructor; not traced */
    float unknowna4; /* +0xa4: 0.3 from the constructor; not traced */
    /* +0xb0: (0.4, 0, 0, 1) from the constructor, one aligned store
     * (`vmovaps [rbx+0xb0]`): the class is 16-byte aligned, 0xe0 bytes; not
     * traced */
    Float4A unknownb0;
    float unknownc0; /* +0xc0: 0.25 from the constructor; not traced */
    float unknownc4; /* +0xc4: 0.2 from the constructor; not traced */
    float unknownc8; /* +0xc8: 5.0 from the constructor; not traced */
    float unknowncc; /* +0xcc: 0.3 from the constructor; not traced */
    float unknownd0; /* +0xd0: 1.2 from the constructor; not traced */
};

#endif
