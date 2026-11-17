/* src/include/tlg_game_object016aba80.h: the class whose vtable is at
 * 0x16aba80 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ABA80_H
#define TLG_GAME_OBJECT016ABA80_H

#include "tlg_game_name.h"
#include "tlg_game_object016cb168.h"

/* derived names: the class whose vtable is at 0x16aba80
 * (config/vtables.derived.base.txt, stored by its creator FUN_005ab380, where
 * its constructor is inlined after Object016cb168's), derived from
 * Object016cb168 (the destructor FUN_005ab510 stores that class's vptr,
 * 0x16cb178, tears its record at +0x28 down and goes on to Object016b9108's
 * names): its five slots are the destructors and Object016b9108's three.
 * 0x40 bytes (`mov edi, 0x40` before operator new in the creator): nothing of
 * its own. The destructor is the class's key function (leaf_005ab510.cpp). */
class Object016aba80 : public Object016cb168 /* derived name */
{
  public:
    Object016aba80(const Name &name) : Object016cb168(name) {}

    virtual ~Object016aba80();
};

#endif
