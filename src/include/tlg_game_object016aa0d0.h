/* src/include/tlg_game_object016aa0d0.h: the class whose vtable is at 0x16aa0d0 and
 * whose complete destructor is 0x4af8a0, a base of other game classes (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA0D0_H
#define TLG_GAME_OBJECT016AA0D0_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16aa0d0
 * (config/vtables.derived.base.txt, stored by FUN_004af700 FUN_004af8a0 FUN_004b16e0 FUN_004b7d80), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 11 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_004af8a0 tears them
 * down (the counted references at +0x30, +0x28); the rest are not traced. */
class Object016aa0d0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016aa0d0();
    virtual void slot5();  /* derived name; FUN_004afa60, not traced */
    virtual void slot6();  /* derived name; FUN_000042d0, not traced */
    virtual void slot7();  /* derived name; FUN_004b00f0, not traced */
    virtual void slot8();  /* derived name; FUN_004b00a0, not traced */
    virtual void slot9();  /* derived name; FUN_004aff80, not traced */
    virtual void slot10(); /* derived name; FUN_004affa0, not traced */
    virtual void slot11(); /* derived name; FUN_004affb0, not traced */

  private:
    u8 unknown24[0x4];
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held28;
    /* +0x30: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held30;
};

#endif
