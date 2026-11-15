/* src/include/tlg_game_object016ad7a0.h: the class whose vtable is at
 * 0x16ad7a0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD7A0_H
#define TLG_GAME_OBJECT016AD7A0_H

#include "tlg_game_link0079ab40.h"
#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad7a0
 * (config/vtables.derived.base.txt, stored by FUN_007970d0 FUN_00797370), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_00797370 tears them
 * down (the counted references at +0x138, +0x108, the Name at +0xfc); the rest are not traced. */
class Object016ad7a0 : public Object00774560 /* derived name */
{
  public:
    Object016ad7a0(const Name &name); /* FUN_007970d0 */
    virtual ~Object016ad7a0();

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    /* +0x100, +0x130: two links, each reset by the constructor's body */
    Link0079ab40 link100;
    Link0079ab40 link130;
    int unknown160;   /* +0x160: zero from the constructor; not traced */
    int unknown164;   /* +0x164: zero from the constructor; not traced */
    float unknown168; /* +0x168: 45.0 from the constructor; not traced */
    float unknown16c; /* +0x16c: 0.001 from the constructor; not traced */
    u8 unknown170[0x4];
    int unknown174;     /* +0x174: 1 from the constructor; not traced */
    u8 unknown178[0x8]; /* the rest of the 0x180 bytes the creator allocates; not traced */
};

#endif
