/* src/include/tlg_game_object00ccfd00.h: the class whose destructor is
 * 0xccfd00, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT00CCFD00_H
#define TLG_GAME_OBJECT00CCFD00_H

#include "tlg_types.h"

#include "tlg_game_name.h"

/* derived names: the class whose complete destructor is 0xccfd00 (its row
 * named for it, D15). The classes derived from it tail-call that destructor
 * from their own (the files that include this header). The destructor is
 * not written, so nothing here emits the vtable; the class's other slots
 * and its fields are not traced. */
class Object00ccfd00 /* derived name */
{
  public:
    Object00ccfd00(
        const Name &name,
        int kind); /* 0xccfbe0, its row named after it (D15): the derived classes' creators call it (FUN_00e90cb0 passes 4) */
    virtual ~Object00ccfd00();

  private:
    /* 0x60 bytes: the derived classes' second base starts at +0x60
     * (FUN_00e90cb0, FUN_00e91f20); the fields are not traced */
    u8 unknown8[0x58];
};

#endif
