/* src/include/tlg_game_object016cc130.h: the class whose vtable is at
 * 0x16cc130 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC130_H
#define TLG_GAME_OBJECT016CC130_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cc130
 * (config/vtables.derived.base.txt, stored by its creators), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields from
 * +0x24 are traced only where its destructor tears them down (an array of
 * counted references at +0x28, an array of Names at +0x40); the rest are
 * not traced. Its complete destructor FUN_01370c30 (slot 0 of 0x16cc130 and
 * of 0x16b4ca0, leaf_01370c30.cpp, the key function's file) is tail-called by
 * the destructors of the classes below (FUN_0138fd60, FUN_01371b50), whose
 * first fields are at +0x58. Slots 0 and 1 of the vtable at 0x16b4ca0 (stored by
 * FUN_00b0eda0, a class derived from this one with no destructor work of
 * its own) are these same two bodies. */
class Object016cc130 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cc130();

  private:
    u8 unknown24[0x4];
    Object0134f620 references28; /* +0x28 */
    Array05943280<Name> names40; /* +0x40 */
};

/* derived names: the class whose vtable is at 0x16b4c60
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b0ea40):
 * five counted references from +0x58, released last to first by its
 * destructor (FUN_0138fd60), its key function. */
class Object016b4c60 : public Object016cc130 /* derived name */
{
  public:
    virtual ~Object016b4c60();

  private:
    Ref00503fb0<Object016b9108> unknown58[5]; /* +0x58 */
};

/* derived names: the class whose vtable is at 0x16af138
 * (config/vtables.derived.base.txt, stored by its creator FUN_0086b920): a
 * counted reference at +0x68 and a Name at +0x70, released by its
 * destructor (FUN_01371b50), its key function, the Name first. The fields
 * from +0x58 are not traced. */
class Object016af138 : public Object016cc130 /* derived name */
{
  public:
    virtual ~Object016af138();

  private:
    u8 unknown58[0x10];
    Ref00503fb0<Object016b9108> unknown68; /* +0x68 */
    Name name70;                           /* +0x70 */
};

#endif
