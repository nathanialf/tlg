/* src/include/tlg_game_object016d22b8.h: the class whose vtable is at
 * 0x16d22b8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D22B8_H
#define TLG_GAME_OBJECT016D22B8_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d22b8
 * (config/vtables.derived.base.txt, stored by FUN_00d48470 FUN_013b8d30 FUN_013b8e50), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_013b8d30 tears them
 * down (the counted reference at +0x30); the rest are not traced. */
class Object016d22b8 : public Object016b9108 /* derived name */
{
  public:
    Object016d22b8(const Name &name); /* FUN_00d48470 */
    virtual ~Object016d22b8();

  private:
    u8 unknown24[0xc];
    /* +0x30: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held30;
};

#endif
