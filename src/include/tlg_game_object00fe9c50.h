/* src/include/tlg_game_object00fe9c50.h: the objects FUN_00fe9c50 and
 * FUN_01256320 give up (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT00FE9C50_H
#define TLG_GAME_OBJECT00FE9C50_H

#include "tlg_types.h"
#include "tlg_game_node.h"

/* derived names: what FUN_00fe9c50 is given: an object whose references at
 * +0x1d0 and +0x1d8 it empties and whose objects at +0x1e8 and +0x228 and
 * block at +0x220 it deletes. Polymorphic: the holder at +0x2c8 of the
 * class whose destructor is 0xfe2200 deletes it through slot 1 after the
 * call. The classes are not traced. */
class Target00fe9c50 : public Object016b9108 /* derived name */
{
};

/* deleted through slot 1 of its vtable */
class Part00fe9c50 /* derived name */
{
  public:
    virtual ~Part00fe9c50();
};

struct Block00fe9c50 { /* derived name */
};

class Object00fe9c50 /* derived name */
{
  public:
    virtual ~Object00fe9c50();

    u8 unknown8[0x1c8];
    AtomicRef0045c470<Target00fe9c50> first;  /* +0x1d0 */
    AtomicRef0045c470<Target00fe9c50> second; /* +0x1d8 */
    u8 unknown1e0[0x8];
    Part00fe9c50 *part1e8; /* +0x1e8 */
    u8 unknown1f0[0x30];
    Block00fe9c50 *block220; /* +0x220 */
    Part00fe9c50 *part228;   /* +0x228 */
};

void FUN_00fe9c50(Object00fe9c50 *self); /* derived name */

/* derived names: what FUN_01256320 is given: an object whose references at
 * +0x1d0 and +0x1d8 it empties and whose objects at +0x1e8 and +0x228 and
 * block at +0x220 it deletes. Polymorphic: the holder at +0x2c8 of the
 * class whose destructor is 0x124eb70 deletes it through slot 1 after the
 * call. The classes are not traced. */
class Target01256320 : public Object016b9108 /* derived name */
{
};

/* deleted through slot 1 of its vtable */
class Part01256320 /* derived name */
{
  public:
    virtual ~Part01256320();
};

struct Block01256320 { /* derived name */
};

class Object01256320 /* derived name */
{
  public:
    virtual ~Object01256320();

    u8 unknown8[0x1c8];
    AtomicRef0045c470<Target01256320> first;  /* +0x1d0 */
    AtomicRef0045c470<Target01256320> second; /* +0x1d8 */
    u8 unknown1e0[0x8];
    Part01256320 *part1e8; /* +0x1e8 */
    u8 unknown1f0[0x30];
    Block01256320 *block220; /* +0x220 */
    Part01256320 *part228;   /* +0x228 */
};

void FUN_01256320(Object01256320 *self); /* derived name */

#endif
