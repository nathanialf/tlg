/* src/include/tlg_game_object016d1520.h: the class whose vtable is at
 * 0x16d1520 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1520_H
#define TLG_GAME_OBJECT016D1520_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16d1520
 * (config/vtables.derived.base.txt, stored by FUN_00c5fb80 FUN_013a9670 FUN_013a9790), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's).
 * Its own fields are traced only where its destructor FUN_013a9670 tears them
 * down (the counted reference at +0x48, the record at +0x50); the rest are not traced. */
class Object016d1520 : public Object01343880 /* derived name */
{
  public:
    Object016d1520(const Name &name); /* FUN_00c5fb80 */
    virtual ~Object016d1520();

  private:
    u8 unknown34[0x14];
    /* +0x48: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held48;
    /* +0x50: torn down by the destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Object0134f620 record50;
    u8 unknown68[0x10]; /* the rest of the 0x78 bytes the creator allocates; not traced */
};

#endif
