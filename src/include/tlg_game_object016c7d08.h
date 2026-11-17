/* src/include/tlg_game_object016c7d08.h: the class whose vtable is at
 * 0x16c7d08, a base of game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016C7D08_H
#define TLG_GAME_OBJECT016C7D08_H

#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7d08
 * (config/vtables.derived.base.txt, stored by its constructor 0xafd2e0, by
 * 0xafd410 and by 0xafd6a0), derived from Object016b9108 (0xafd2e0
 * first calls that class's constructor 0xcb6310). The constructor of each
 * class over it calls 0xafd2e0 first. Neither the constructor nor the
 * destructor is written; its fields are not traced. */
class Object016c7d08 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c7d08();
};

#endif
