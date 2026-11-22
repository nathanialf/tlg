/* src/include/tlg_game_object016a7620.h: the message of three Names
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7620_H
#define TLG_GAME_OBJECT016A7620_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class of the vtable at 0x16a7620
 * (config/vtables.derived.base.txt; made by FUN_001b0a40 and FUN_00948040):
 * a counted object that is not of the root class (tlg_game_object016b9108.h's
 * counted base: the count at +0x8 cleared before the message's vptr is
 * stored, `mov dword [rbx+8], 0` before the vptr store at 0x9480c1; slot 2
 * of the vtable the base's release, 0x69a0) with three Names at +0xc, +0x10
 * and +0x14 (the dispatcher FUN_00c644d0 reads the first two). Its complete
 * destructor 0x13cd140 (leaf_013cd140.cpp, the key function) releases
 * +0x14, then +0x10, then +0xc, and calls no base; the deleting one
 * 0x13cd1f0 is the compiler's. */
class Object016a7620 : public Counted00c14bc0 /* derived name */
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

/* derived names: messages over Object016a7620 that hold a counted
 * reference: the class at 0x16d1d98 (made by FUN_00ce6250, eight
 * times) at +0x18, the class at 0x16d3550 (made by FUN_00eac8a0) at
 * +0x20. Their destructors (0x13b2640, 0x13cc010) release it, then run the
 * message's own destructor inlined: they are in its unit
 * (leaf_013cd140.cpp). */
class Object016d1d98 : public Object016a7620 /* derived name */
{
  public:
    virtual ~Object016d1d98();

  private:
    Ref00503fb0<Object016b9108> unknown18; /* +0x18 */
};

class Object016d3550 : public Object016a7620 /* derived name */
{
  public:
    virtual ~Object016d3550();

  private:
    u8 unknown18[0x8];
    Ref00503fb0<Object016b9108> unknown20; /* +0x20 */
};

#endif
