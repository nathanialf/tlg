/* src/include/tlg_game_object016b6c98.h: the class whose vtable is at
 * 0x16b6c98 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B6C98_H
#define TLG_GAME_OBJECT016B6C98_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b6c20.h"

/* derived names: the class whose vtable is at 0x16b6c98
 * (config/vtables.derived.base.txt, stored by FUN_00b77360 FUN_00b781a0),
 * derived from Object016b6c20: its creator FUN_00b77360 inlines the base's
 * constructor, then stores this class's vptr and clears the int at +0x6c and
 * the reference at +0x70. 0x80 bytes (`mov edi, 0x80` before operator new).
 * Slots 9 to 11 (FUN_00b78920, FUN_00b78a00, FUN_00b78ae0) override the
 * base's; the others are the base's. The destructor FUN_00b781a0 is the key
 * function; FUN_00b78340, the deleting one, calls it. */
class Object016b6c98 : public Object016b6c20 /* derived name */
{
  public:
    Object016b6c98(const Name &name) : Object016b6c20(name), unknown6c(0) {}

    virtual ~Object016b6c98();
    virtual void slot9();  /* derived name; FUN_00b78920, not traced */
    virtual void slot10(); /* derived name; FUN_00b78a00, not traced */
    virtual void slot11(); /* derived name; FUN_00b78ae0, not traced */

  private:
    int unknown6c; /* +0x6c: zero from the constructor; not traced */
    /* +0x70: a counted reference, empty from the constructor, released by
     * the destructor first (the pointer cleared, `cmp dword [r14+8],
     * 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held70;
    u8 unknown78[0x8];
};

#endif
