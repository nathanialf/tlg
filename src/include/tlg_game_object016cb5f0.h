/* src/include/tlg_game_object016cb5f0.h: the class whose vtable is at 0x16cb5f0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB5F0_H
#define TLG_GAME_OBJECT016CB5F0_H

#include "tlg_game_name.h"
#include "tlg_game_object016c7d08.h"

/* derived names: the class whose vtable is at 0x16cb5f0
 * (config/vtables.derived.base.txt, stored by FUN_00690a30), 0xb00 bytes
 * (`mov edi, 0xb00` before operator new in its creator FUN_006908d0),
 * derived from Object016c7d08 (its constructor 0x690a30 first calls 0xafd2e0, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016cb5f0 : public Object016c7d08 /* derived name */
{
  public:
    Object016cb5f0(const Name &name); /* 0x690a30, its row named after it (D15) */
    virtual ~Object016cb5f0();

  private:
    u8 unknown60[0xaa0];
};

#endif
