/* src/include/tlg_game_object01372e50.h: the class whose destructor is
 * 0x1372e50 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT01372E50_H
#define TLG_GAME_OBJECT01372E50_H

#include "tlg_types.h"

/* derived names: the class whose destructor is 0x1372e50 (its row named for
 * it, D15), a base of Object01372e40 (leaf_01372e40.cpp) and a member at
 * +0x10 of the 64-byte records FUN_01372960 empties (so 0x30 bytes); the
 * destructor is not written and the fields are not traced */
class Object01372e50 /* derived name */
{
  public:
    virtual ~Object01372e50();

  private:
    u8 unknown8[0x28];
};

#endif
