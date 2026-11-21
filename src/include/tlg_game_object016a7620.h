/* src/include/tlg_game_object016a7620.h: the message of three Names
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7620_H
#define TLG_GAME_OBJECT016A7620_H

#include "tlg_game_name.h"

/* derived names: the count a message's receivers raise, the base of the
 * message class below: cleared by its own constructor, before the
 * message's vptr is stored (`mov dword [rbx+8], 0` before the vptr store at
 * 0x9480c1) */
struct Counted016a7620 { /* derived name */

    Counted016a7620() : references(0) {}

    int references; /* +0x8 of the message */
};

/* derived names: the class of the vtable at 0x16a7620
 * (config/vtables.derived.base.txt; made by FUN_001b0a40 and FUN_00948040):
 * the count at +0x8 and three Names at +0xc, +0x10 and +0x14 (the
 * dispatcher FUN_00c644d0 reads the first two). Its complete destructor
 * 0x13cd140 (leaf_013cd140.cpp, the key function) releases +0x14, then
 * +0x10, then +0xc, and calls no base; the deleting one 0x13cd1f0 is the
 * compiler's. */
class Object016a7620 : public Counted016a7620 /* derived name */
{
  public:
    Object016a7620(const Name &a, const Name &b, const Name &c)
        : unknownc(a), unknown10(b), unknown14(c)
    {
    }

    virtual ~Object016a7620();

  private:
    Name unknownc;  /* +0xc */
    Name unknown10; /* +0x10 */
    Name unknown14; /* +0x14 */
};

#endif
