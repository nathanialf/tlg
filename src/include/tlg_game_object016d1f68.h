/* src/include/tlg_game_object016d1f68.h: the class whose vtable is at
 * 0x16d1f68 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1F68_H
#define TLG_GAME_OBJECT016D1F68_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object00cf7fb0.h"

/* derived names: the class whose vtable is at 0x16d1f68
 * (config/vtables.derived.base.txt, stored by FUN_00cf9470 FUN_013b34f0 FUN_013b35a0), derived from
 * Object00cf7fb0 (the class whose destructor is 0xcf7fb0): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013b34f0 tears them
 * down (the counted reference at +0xe0, the record at +0xc8); the rest are not traced. */
class Object016d1f68 : public Object00cf7fb0 /* derived name */
{
  public:
    /* inlined in the creator FUN_00cf9470: Object00cf7fb0's constructor with 7, the
     * vptr, the members empty */
    Object016d1f68(const Name &name) : Object00cf7fb0(name, 7) {}

    virtual ~Object016d1f68();

  private:
    /* +0xc8: torn down by the destructor (`lea rdi, [rbx+0xc8]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Node00503fb0>> recordc8;
    /* +0xe0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> helde0;
    u8 unknowne8[0x8]; /* the rest of the 0xf0 bytes the creator allocates; not traced */
};

#endif
