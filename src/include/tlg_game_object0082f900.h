/* src/include/tlg_game_object0082f900.h: the class whose vtable is at 0x16aebe0 and whose
 * complete destructor is 0x82f900 (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT0082F900_H
#define TLG_GAME_OBJECT0082F900_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16aebe0
 * (config/vtables.derived.base.txt, the class named for its complete
 * destructor 0x82f900 as that row names it, D15; stored by FUN_0082f780 FUN_0082f900 FUN_0082fa20), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 9 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_0082f900 tears them
 * down (the counted reference at +0x40); the rest are not traced. */
class Object0082f900 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object0082f900();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */
    virtual void slot9(); /* derived name; FUN_0082fb30, not traced */

  private:
    u8 unknown24[0x1c];
    /* +0x40: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held40;
};

#endif
