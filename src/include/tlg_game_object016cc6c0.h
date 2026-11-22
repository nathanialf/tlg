/* The class whose vtable is at 0x16cc6c0 (config/vtables.derived.base.txt's
 * Object016cc6c0; stored by FUN_009232e0, FUN_009240a0, FUN_0096e710 and
 * more) and its derived class at 0x16cc938 (all names derived). */
#ifndef TLG_GAME_OBJECT016CC6C0_H
#define TLG_GAME_OBJECT016CC6C0_H

#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_multibase.h"

/* The primary base: slots 0 to 2 of 0x16cc6c0 (the destructors, 0x69a0);
 * 0x10 bytes (the base after it at +0x10), its field not traced; an empty
 * destructor (0x137be20 stores no vptr of its own at
 * +0x0 after its members'). */
class Base016cc6c0_0 /* derived name */
{
  public:
    virtual ~Base016cc6c0_0() {}

    virtual void slot2(); /* derived name; 0x69a0, not traced */

    u8 unknown8[0x8];
};

/* 0x28 bytes: the base at +0x10 is Object016cc450 (its vptr 0x16cc460
 * stored, then its reference at +0x18 released), after the class's own
 * counted reference at +0x20. Its destructor is 0x137be20 (its row named for
 * it, D15); slot 0 of the vtable (0x137bf60) runs it as a tail call. */
class Object016cc6c0 /* derived name */
    : public Base016cc6c0_0,
      public Object016cc450
{
  public:
    virtual ~Object016cc6c0();

  private:
    Ref00503fb0<Object016b9108> unknown20; /* +0x20 */
};

/* The base at +0x28 of the class at 0x16cc938: two slots, not traced. */
class Base016cc938_28 /* derived name */
{
  public:
    virtual void slot0() = 0; /* derived name; not traced */
    virtual void slot1() = 0; /* derived name; not traced */
};

/* The class whose vtable is at 0x16cc938 (config/vtables.derived.base.txt):
 * its destructor (0x137c190, slot 0) stores the three vptrs and releases the
 * counted reference at +0x38 before the base's; slot 3 is pure. */
class Object016cc938 /* derived name */
    : public Object016cc6c0,
      public Base016cc938_28
{
  public:
    virtual ~Object016cc938();
    virtual void slot3() = 0; /* derived name; not traced */

  private:
    u8 unknown30[0x8];
    Ref00503fb0<Object016b9108> unknown38; /* +0x38 */
};

/* The bases at +0x28 and +0x30 of the class at 0x16cd290: one slot each,
 * not traced. */
class Base016cd290_28 /* derived name */
{
  public:
    virtual void slot0() = 0; /* derived name; not traced */
};

class Base016cd290_30 /* derived name */
{
  public:
    virtual void slot0() = 0; /* derived name; not traced */
};

/* The base at +0x38: two slots (0x1380640, the shared empty body 0x1af750),
 * not traced. */
class Base016cd290_38 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; 0x1380640, not traced */
    virtual void slot1(); /* derived name; 0x1af750, not traced */
};

/* The class whose vtable is at 0x16cd290 (config/vtables.derived.base.txt;
 * stored by FUN_0096e710): its destructor (0x1380670, slot 0) stores the
 * five vptrs (+0x28 and +0x30 in one store) and releases the counted
 * reference at +0xe0 before the base's; slots 3 to 5 its own (0x1380850,
 * the shared empty body 0x1af750, pure). */
class Object016cd290 /* derived name */
    : public Object016cc6c0,
      public Base016cd290_28,
      public Base016cd290_30,
      public Base016cd290_38
{
  public:
    virtual ~Object016cd290();
    virtual void slot3();     /* derived name; 0x1380850, not traced */
    virtual void slot4();     /* derived name; 0x1af750, not traced */
    virtual void slot5() = 0; /* derived name; not traced */

  private:
    u8 unknown40[0xe0 - 0x40];
    Ref00503fb0<Object016b9108> unknowne0; /* +0xe0 */
};

/* derived names: a base of classes over Object016cc6c0, at +0x28 of them (the
 * destructors 0x13974c0, 0x1397570, 0xb40050 and 0xb42e30 store its vptr
 * there and release its counted reference at +0x30): two pure functions and
 * a counted reference at +0x8, released by its destructor, which is not
 * virtual (the vtable has only the two slots). Its vtable is the one at
 * 0x16d7b30: the link merged it with Object016d7b30's (tlg_game_fade013d2490.h),
 * an identical constant of two pure slots (config/vtables.derived.base.txt,
 * its `merges` row). */
class RefHolder013974c0 /* derived name */
{
  public:
    virtual void slot0() = 0; /* derived name; not traced */
    virtual void slot1() = 0; /* derived name; not traced */

  protected:
    ~RefHolder013974c0() {}

  private:
    Ref00503fb0<Object016b9108> held; /* +0x8 */
};

#endif
