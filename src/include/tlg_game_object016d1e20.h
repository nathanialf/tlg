/* src/include/tlg_game_object016d1e20.h: the class whose vtable is at
 * 0x16d1e20 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1E20_H
#define TLG_GAME_OBJECT016D1E20_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d1e20
 * (config/vtables.derived.base.txt, stored by FUN_00ceae70 FUN_013b27b0
 * FUN_013b28d0), derived from Object016b9108: its slots 2 to 4 are the
 * base's. Its fields are traced where its constructor FUN_00ceae70 clears
 * them (+0x28 to +0x44, two 16-byte stores) and its destructor FUN_013b27b0
 * tears them down (the counted reference at +0x28). */
class Object016d1e20 : public Object016b9108 /* derived name */
{
  public:
    Object016d1e20(const Name &name); /* FUN_00ceae70 */
    virtual ~Object016d1e20();

  private:
    u8 unknown24[0x4];
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held28;
    int unknown30[5]; /* +0x30: zero from the constructor */
};

#endif
