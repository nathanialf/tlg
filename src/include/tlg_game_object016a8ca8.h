/* src/include/tlg_game_object016a8ca8.h: the class whose vtable is at
 * 0x16a8ca8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8CA8_H
#define TLG_GAME_OBJECT016A8CA8_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8ca8
 * (config/vtables.derived.base.txt, stored by FUN_003795e0 FUN_00379710 FUN_00379830), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00379710 tears them
 * down (the counted reference at +0xe8); the rest are not traced. */
class Object016a8ca8 : public Object016b9108 /* derived name */
{
  public:
    Object016a8ca8(const Name &name); /* FUN_003795e0 */
    virtual ~Object016a8ca8();

  private:
    u8 unknown24[0xc4];
    /* +0xe8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> helde8;
    u8 unknownf0[0x30]; /* the rest of the 0x120 bytes the creator allocates; not traced */
};

#endif
