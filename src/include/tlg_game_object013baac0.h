/* src/include/tlg_game_object013baac0.h: an array of counted references with
 * an int after it in the array's tail padding, three of them the file-scope
 * objects of FUN_00d667c0's unit, the shape of tlg_game_object013c9e50.h's
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013BAAC0_H
#define TLG_GAME_OBJECT013BAAC0_H

#include "tlg_game_object0134f620.h"

/* derived name: the array (tlg_game_object0134f620.h) as its base, the int
 * at +0x14 cleared by the constructor (0x59497e4, 0x5949814 and 0x59497fc
 * stored after each array's owner index). The destructor (0x13baac0) has
 * an empty body: the array's destructor, 0x134f620, runs as a tail call. */
class Object013baac0 : public Object0134f620 /* derived name */
{
  public:
    Object013baac0() : unknown14(0) {}

    ~Object013baac0();

    int unknown14; /* +0x14 */
};

#endif
