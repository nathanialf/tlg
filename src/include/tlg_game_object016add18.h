/* src/include/tlg_game_object016add18.h: the class whose vtable is at 0x16add18
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ADD18_H
#define TLG_GAME_OBJECT016ADD18_H

#include "tlg_game_name.h"
#include "tlg_game_object016c7880.h"

/* derived names: the class whose vtable is at 0x16add18
 * (config/vtables.derived.base.txt, stored by FUN_007a8b20 FUN_007a8f80), 0x100 bytes
 * (`mov edi, 0x100` before operator new in its creator FUN_007a68a0),
 * derived from Object016c7880 (its constructor 0x7a8b20 first calls 0x7a7110, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016add18 : public Object016c7880 /* derived name */
{
  public:
    Object016add18(const Name &name); /* 0x7a8b20, its row named after it (D15) */
    virtual ~Object016add18();

  private:
    u8 unknownb8[0x48];
};

#endif
