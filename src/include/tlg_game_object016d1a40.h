/* src/include/tlg_game_object016d1a40.h: the class whose vtable is at 0x16d1a40
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1A40_H
#define TLG_GAME_OBJECT016D1A40_H

#include "tlg_game_node.h"
#include "tlg_game_object00ccfd00.h"

/* derived names: the class whose vtable is at 0x16d1a40
 * (config/vtables.derived.base.txt), derived from Object00ccfd00 with a
 * counted reference at +0x58. Its destructor is inline: its own copy
 * (0x13aedc0) holds the base's body too, the derived class at 0x16d3248's
 * (0x13cbe00) holds the release and calls the base's. */
class Object016d1a40 : public Object00ccfd00 /* derived name */
{
  public:
    virtual ~Object016d1a40() {}

  private:
    /* +0x58: a counted reference, released by the destructor before the
     * base's */
    Ref00503fb0<Object016b9108> held58;
};

#endif
