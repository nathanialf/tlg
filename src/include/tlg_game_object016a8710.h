/* src/include/tlg_game_object016a8710.h: the class whose vtable is at 0x16a8710
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8710_H
#define TLG_GAME_OBJECT016A8710_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8710
 * (config/vtables.derived.base.txt, stored by FUN_00343430 FUN_00343820),
 * derived from Object016b9108: its destructor FUN_00343820 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: four counted references from +0x78 and an array of Names at +0x98 (the loop over `[r12+rbx*4]` with the count at +0xa0, its block released after it).
 * The creator FUN_003432d0 allocates 0xb0 bytes (`mov edi, 0xb0` before operator new). */
class Object016a8710 : public Object016b9108 /* derived name */
{
  public:
    Object016a8710(const Name &name); /* FUN_00343430, its row named after it (D15) */
    virtual ~Object016a8710();

  private:
    u8 unknown24[0x54];
    AtomicRef0045c470<Object016b9108> held78; /* +0x78: a counted reference */
    AtomicRef0045c470<Object016b9108> held80; /* +0x80: a counted reference */
    AtomicRef0045c470<Object016b9108> held88; /* +0x88: a counted reference */
    AtomicRef0045c470<Object016b9108> held90; /* +0x90: a counted reference */
    Array05943280<Name> names98;              /* +0x98: an array of Names */
};

#endif
