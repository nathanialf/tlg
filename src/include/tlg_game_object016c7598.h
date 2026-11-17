/* src/include/tlg_game_object016c7598.h: the class whose vtable is at
 * 0x16c7598 and the class derived from it whose vtable is at 0x16a8748 (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7598_H
#define TLG_GAME_OBJECT016C7598_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016aea40.h"

/* derived names: the class whose vtable is at 0x16c7598
 * (config/vtables.derived.base.txt, stored by FUN_003442a0, where its
 * constructor is inlined, and by its destructors 0x134d360 and 0x134d3d0),
 * derived from Object016aea40. It holds an array at +0x248 whose block its
 * destructor releases (leaf_0134d360.cpp, the class's key function): the
 * creator clears its block, count and capacity in one store
 * (`vmovdqu [r15+0x248], xmm0`), stores its owner index from the thread's
 * heap at +0x258 and its free lock at +0x25c. Its elements are not traced. */
class Object016c7598 : public Object016aea40 /* derived name */
{
  public:
    Object016c7598(const Name &name) : Object016aea40(name) {}

    virtual ~Object016c7598();

  private:
    Array01343a80<void *> array248; /* +0x248 */
};

/* derived names: the class whose vtable is at 0x16a8748
 * (config/vtables.derived.base.txt, stored by its creator FUN_003442a0, where
 * its constructor is inlined after Object016c7598's), derived from
 * Object016c7598. 0x260 bytes (`mov edi, 0x260` before operator new in the
 * creator): nothing of its own. Its constructor's body sets its base's int at
 * +0x238 to 0 after the vptr; its destructor is not written. */
class Object016a8748 : public Object016c7598 /* derived name */
{
  public:
    Object016a8748(const Name &name) : Object016c7598(name)
    {
        unknown238 = 0;
    }

    virtual ~Object016a8748();
};

#endif
