/* src/include/tlg_game_object016a8688.h: the class whose vtable is at
 * 0x16a8688 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8688_H
#define TLG_GAME_OBJECT016A8688_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8688
 * (config/vtables.derived.base.txt, stored by FUN_00332b80 FUN_00332fe0), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00332fe0 tears them
 * down (the counted references at +0x38, +0x30, +0x28); the rest are not traced. */
class Object016a8688 : public Object016b9108 /* derived name */
{
  public:
    Object016a8688(const Name &name); /* FUN_00332b80 */
    virtual ~Object016a8688();

  private:
    u8 unknown24[0x4];
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held28;
    /* +0x30: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held30;
    /* +0x38: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held38;
    u8 unknown40[0x20]; /* the rest of the 0x60 bytes the creator allocates; not traced */
};

#endif
