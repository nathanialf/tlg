/* src/include/tlg_game_object016c7c78.h: the class whose vtable is at
 * 0x16c7c78, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016C7C78_H
#define TLG_GAME_OBJECT016C7C78_H

#include "tlg_game_creation.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7c78
 * (config/vtables.derived.base.txt, stored by FUN_00a29d80 FUN_00a29f30 FUN_00a2a290 and 4 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced where its destructor FUN_00a2a290 tears them down
 * (the Name at +0x24) and where the creators FUN_00a29d80 and FUN_00a29f30
 * inline its constructor (the stores before the derived vptr); their meaning
 * is not traced. 0x50 bytes. */
class Object016c7c78 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creators FUN_00a29d80 and FUN_00a29f30: the Name empty
     * and the lock made free (the members), then the int at +0x28 and the
     * seven from +0x34 cleared (the body: the int's store apart from the
     * Name's, the lock's release between) */
    Object016c7c78(const Name &name) : Object016b9108(name)
    {
        unknown28 = 0;
        for (int i = 0; i < 7; ++i)
            unknown34[i] = 0;
    }

    virtual ~Object016c7c78();

  private:
    Name name24;   /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    u8 unknown2c[0x4];
    /* +0x30: a lock, made free by the constructor: the word's release is an
     * atomic store (`mov dword [rbx+0x30], 0` apart from the clear of +0x34
     * to +0x50, and the base's vptr store kept before the derived one) */
    Lock059458a4 lock30;
    int unknown34
        [7]; /* +0x34: zero from the constructor (two overlapping 16-byte stores); not traced */
};

#endif
