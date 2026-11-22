/* src/include/tlg_game_object016a8650.h: the class whose vtable is at 0x16a8650
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8650_H
#define TLG_GAME_OBJECT016A8650_H

#include "tlg_game_array.h"
#include "tlg_game_entry00c8b0d0.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8650
 * (config/vtables.derived.base.txt, stored by FUN_0032e7e0 FUN_0032ed50), 0x27b0 bytes
 * (`mov edi, 0x27b0` before operator new in its creator FUN_00326ab0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0032e7e0 is not written. Its fields are traced where its destructor
 * FUN_0032ed50, the key function (leaf_0032ed50.cpp), tears them down,
 * last first. */
class Object016a8650 : public Object016b9108 /* derived name */
{
  public:
    Object016a8650(const Name &name); /* FUN_0032e7e0 */
    virtual ~Object016a8650();

  private:
    u8 unknown24[0x60];
    Name name84; /* +0x84: not traced */
    u8 unknown88[0x68];
    /* +0xf0 and +0x1380: two sets of 27 records, each record's reference at
     * +0x98 dropped, last record first */
    Entry00c8b0d0 entriesF0[27];
    Entry00c8b0d0 entries1380[27];
    u8 unknown2610[0x8];
    /* +0x2618: an array whose elements have no destructor (the block given
     * back only); the element type is not traced */
    Array05943280<u32> unknown2618;
    u8 unknown2630[0xa8];
    Ref00503fb0<Object016b9108> held26d8; /* +0x26d8 */
    u8 unknown26e0[0x20];
    Name name2700; /* +0x2700: not traced */
    u8 unknown2704[0xac];
};

#endif
