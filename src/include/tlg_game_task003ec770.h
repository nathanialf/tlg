/* src/include/tlg_game_task003ec770.h: the interface the two composites at
 * 0x16a92c8 and 0x16a9328 call on their children (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_TASK003EC770_H
#define TLG_GAME_TASK003EC770_H

#include "tlg_game_object016b9108.h"

/* derived names: a class over Object016b9108 with five virtuals of its own,
 * slots 5 to 9. Object016a92c8 and Object016a9328 derive from it and hold
 * their children as counted references to it: each of their slots calls the
 * same slot of every child (`call [rax+0x28]` to `call [rax+0x48]`). Slots 6
 * to 8 take one argument and answer an int (`test eax, eax` on the child's
 * answer at 0x3ec7e4); slot 9 takes one argument and answers nothing. No
 * vtable of its own is seen: its virtuals are pure, and its constructor is
 * inlined under the derived ones' (its vptr store dead). The argument's type is not
 * traced. */
class Task003ec770 : public Object016b9108 /* derived name */
{
  public:
    Task003ec770(const Name &name) : Object016b9108(name) {}

    virtual void slot5() = 0;               /* derived name */
    virtual int slot6(void *argument) = 0;  /* derived name */
    virtual int slot7(void *argument) = 0;  /* derived name */
    virtual int slot8(void *argument) = 0;  /* derived name */
    virtual void slot9(void *argument) = 0; /* derived name */
};

#endif
