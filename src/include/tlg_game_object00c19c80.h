/* src/include/tlg_game_object00c19c80.h: the class whose vtable is at
 * 0x16b7fb0 and whose destructor is 0xc19c80, a base of two game classes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT00C19C80_H
#define TLG_GAME_OBJECT00C19C80_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b7fb0
 * (config/vtables.derived.base.txt, stored by FUN_00c19b00 and its two
 * destructors), derived from Object016b9108: its slots 2 to 4 are the
 * base's, slots 5 and 6 its own (declared; their bodies are not written).
 * The classes of leaf_00a84b70.cpp and leaf_00a84d30.cpp derive from it:
 * their destructors tail-call its complete destructor (FUN_00c19c80,
 * leaf_00c19c80.cpp), the key function. Its own fields from +0x24 are traced
 * only where that destructor releases them (the Names at +0x2c, +0x28). */
class Object00c19c80 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object00c19c80();
    virtual void slot5(); /* derived name; FUN_00c19e60, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown24[0x4];
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    Name name2c; /* +0x2c: released by the destructor (`mov eax, [rbx+0x2c]; shl 5`) */
};

#endif
