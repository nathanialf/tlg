/* src/include/tlg_game_owner00f707b0.h: the owner of the objects of 43
 * classes over Object00c1b7f0 (their counted reference at +0x1b8), as far as
 * the destructors of the classes that make them (FUN_00f707b0 and its 42
 * copies) read it (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OWNER00F707B0_H
#define TLG_GAME_OWNER00F707B0_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: an object of the root class with an array of counted
 * references at +0xc0 (the block at +0xc0, the count at +0xc8) to the
 * objects it owns */
class Owner00f707b0 : public Object016b9108 /* derived name */
{
  private:
    u8 unknown24[0x9c];

  public:
    Array05943280<Ref00503fb0<Object016b9108>> held; /* +0xc0 */
};

#endif
