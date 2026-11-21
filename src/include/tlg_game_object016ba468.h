/* src/include/tlg_game_object016ba468.h: the class whose vtable is at
 * 0x16ba468, a base of game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016BA468_H
#define TLG_GAME_OBJECT016BA468_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object016b9108.h"

/* derived names: the objects the arrays at +0x240 and +0x268 hold
 * (counted, derived from the root class); not traced. Each array's
 * destructor over them is leaf_00d476f0.cpp's alone and has one caller, so
 * the link inlines it in the class's destructor, as the base shows (no call
 * to 0x134f620) */
class Element240016ba468 : public Object016b9108
{
};

class Element268016ba468 : public Object016b9108
{
};

/* derived names: the class whose vtable is at 0x16ba468
 * (config/vtables.derived.base.txt, stored by FUN_00d45fc0, by the creator
 * FUN_00ca2960 of the class at 0x16b8c98 over it, leaf_00ca2bc0.cpp, and by
 * its complete destructor FUN_00d476f0, its row named for it, D15,
 * leaf_00d476f0.cpp), derived from Object016b85e0 (its
 * destructor 0xc55550): the base's slots and fields are not traced, so the
 * bytes below the first member here are the base's or this class's. Its
 * own fields are traced where the destructor tears them down: counted
 * references at +0x238 and +0x258, arrays of counted references at +0x240
 * and +0x268 and a name at +0x260. */
class Object016ba468 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016ba468();

  private:
    u8 unknown24[0x214];
    Ref00503fb0<Object016b9108> held238;                     /* +0x238 */
    Array05943280<Ref00503fb0<Element240016ba468>> array240; /* +0x240 */
    Ref00503fb0<Object016b9108> held258;                     /* +0x258 */
    Name name260;                                            /* +0x260 */
    Array05943280<Ref00503fb0<Element268016ba468>> array268; /* +0x268 */
};

#endif
