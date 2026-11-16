/* src/include/tlg_game_object016a8b00.h: the class whose vtable is at 0x16a8b00
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8B00_H
#define TLG_GAME_OBJECT016A8B00_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16a8b00
 * (config/vtables.derived.base.txt, stored by FUN_00366b30 FUN_00367020), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_00367020 tears them
 * down (the counted references at +0x80, +0x78, +0x40, +0x38); the rest are not traced.
 * The creator FUN_003669d0 allocates 0x90 bytes (`mov edi, 0x90` before operator new). */
class Object016a8b00 : public Object016b9108 /* derived name */
{
  public:
    Object016a8b00(const Name &name); /* FUN_00366b30, its row named after it (D15) */
    virtual ~Object016a8b00();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_003672e0, not traced */
    virtual void slot8(); /* derived name; FUN_003677b0, not traced */

  private:
    u8 unknown24[0x14];
    /* +0x38: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held38;
    /* +0x40: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held40;
    u8 unknown48[0x30];
    /* +0x78: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held78;
    /* +0x80: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held80;
    u8 unknown88[0x8];
};

#endif
