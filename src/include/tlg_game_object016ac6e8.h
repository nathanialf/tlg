/* src/include/tlg_game_object016ac6e8.h: the class whose vtable is at 0x16ac6e8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AC6E8_H
#define TLG_GAME_OBJECT016AC6E8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ac6e8
 * (config/vtables.derived.base.txt, stored by its creator FUN_006e05e0, where
 * its constructor is inlined, and by its complete destructor FUN_006e0900,
 * leaf_006e0900.cpp), derived from Object016b9108: its slots 2 to 4 are the
 * base's. 0x28 bytes (`mov edi, 0x28` before operator new in the creator):
 * the object keeps a copy of the name it is built from. */
class Object016ac6e8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, then
     * the name copied to +0x24 (its count raised first) */
    Object016ac6e8(const Name &name) : Object016b9108(name), name24(name) {}

    virtual ~Object016ac6e8();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
};

#endif
