/* src/include/tlg_game_object016a7fc0.h: the class whose vtable is at
 * 0x16a7fc0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7FC0_H
#define TLG_GAME_OBJECT016A7FC0_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7fc0
 * (config/vtables.derived.base.txt, stored by FUN_002bbed0 FUN_002bc150
 * FUN_002bc2a0), derived from Object016b9108. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_002bbed0 sets them and its destructor FUN_002bc150
 * tears them down. The destructor is the class's key function
 * (leaf_002bc150.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016a7fc0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0x28], 0`,
     * `mov dword [r15+0x30], 0`, then FUN_002bc040 is called (not inlined) */
    Object016a7fc0(const Name &name) : Object016b9108(name)
    {
        FUN_002bc040();
    }

    virtual ~Object016a7fc0();

    /* FUN_002bc040 (leaf_002bc040.cpp): puts the object back to its empty
     * state */
    void FUN_002bc040(); /* derived name */

  private:
    /* +0x28: a counted reference, empty from the constructor, cleared by
     * FUN_002bc040, released by the destructor */
    AtomicRef0045c470<Object016b9108> held28;
    Name name30;   /* +0x30: empty from the constructor, released by the destructor */
    int unknown34; /* +0x34: cleared by FUN_002bc040 */
    u8 unknown38[0x8];
    u64 unknown40[4]; /* +0x40: cleared by FUN_002bc040 */
};

#endif
