/* src/include/tlg_game_object013c9e50.h: an array of counted references with
 * an int after it in the array's tail padding, three of them the file-scope
 * objects of FUN_00e63c90's unit (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT013C9E50_H
#define TLG_GAME_OBJECT013C9E50_H

#include "tlg_game_object0134f620.h"

/* derived name: the array (tlg_game_object0134f620.h) as its base, the int
 * at +0x14 cleared by the constructor (0x5a8cc5c, 0x5a8cc74 and 0x5a8cc8c
 * stored after each array's owner index). The destructor (0x13c9e50) has
 * an empty body: the array's destructor, 0x134f620, runs as a tail call. */
class Object013c9e50 : public Object0134f620 /* derived name */
{
  public:
    Object013c9e50() : unknown14(0) {}

    ~Object013c9e50();

    int unknown14; /* +0x14 */
};

#endif
