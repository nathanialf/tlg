/* src/include/tlg_game_object016ae088.h: the class whose vtable is at 0x16ae088
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE088_H
#define TLG_GAME_OBJECT016AE088_H

#include "tlg_game_name.h"
#include "tlg_game_object016c81c0.h"

/* derived names: the class whose vtable is at 0x16ae088
 * (config/vtables.derived.base.txt, stored by FUN_007eab50 FUN_007eb4f0), 0x2ea0 bytes
 * (`mov edi, 0x2ea0` before operator new in its creator FUN_007dfa30),
 * derived from Object016c81c0 (its constructor 0x7eab50 first calls 0xd68470, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016ae088 : public Object016c81c0 /* derived name */
{
  public:
    Object016ae088(const Name &name); /* 0x7eab50, its row named after it (D15) */
    virtual ~Object016ae088();

  private:
    u8 unknown98[0x2e08];
};

#endif
