/* src/include/tlg_game_object016a8b90.h: the class whose vtable is at 0x16a8b90
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8B90_H
#define TLG_GAME_OBJECT016A8B90_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16a8b90
 * (config/vtables.derived.base.txt, stored by FUN_0036af00 FUN_0036b650), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_0036b650 tears them
 * down (the counted references at +0xa8, +0xa0, +0x98, +0x90, +0x88, +0x68, the record at +0x70); the rest are not traced.
 * The creator FUN_0036ada0 allocates 0xc0 bytes (`mov edi, 0xc0` before operator new). */
class Object016a8b90 : public Object016b9108 /* derived name */
{
  public:
    Object016a8b90(const Name &name); /* FUN_0036af00, its row named after it (D15) */
    virtual ~Object016a8b90();

  private:
    u8 unknown24[0x44];
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held68;
    /* +0x70: torn down by the destructor (`lea rdi, [rbx+0x70]; call 0x134f620`) */
    Object0134f620 record70;
    /* +0x88: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held88;
    /* +0x90: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held90;
    /* +0x98: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held98;
    /* +0xa0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> helda0;
    /* +0xa8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> helda8;
    u8 unknownb0[0x10];
};

#endif
