/* src/include/tlg_game_object016a8bc8.h: the class whose vtable is at 0x16a8bc8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8BC8_H
#define TLG_GAME_OBJECT016A8BC8_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the 0x50-byte elements of Object016a8bc8's array at
 * +0xe8 (`lea rsi, [rcx+rcx*4]; shl rsi, 4`): a Name at +0x40, released by
 * the element's destructor; the rest is not traced */
struct Entry016a8bc8_e8 { /* derived name */
    u8 unknown0[0x40];
    Name name40; /* +0x40 */
    u8 unknown44[0xc];
};

/* derived names: the 0x18-byte elements of its array at +0x100: a Name at
 * +0x0; the rest is not traced */
struct Entry016a8bc8_100 { /* derived name */
    Name name0;            /* +0x0 */
    u8 unknown4[0x14];
};

/* derived names: the class whose vtable is at 0x16a8bc8
 * (config/vtables.derived.base.txt, stored by FUN_0036c400 FUN_0036c7b0), 0x130 bytes
 * (`mov edi, 0x130` before operator new in its creator FUN_0036c2a0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_0036c400 is not written. Its fields are traced where its destructor
 * FUN_0036c7b0, the key function (leaf_0036c7b0.cpp), tears them down,
 * last first. */
class Object016a8bc8 : public Object016b9108 /* derived name */
{
  public:
    Object016a8bc8(const Name &name); /* FUN_0036c400 */
    virtual ~Object016a8bc8();

  private:
    Name name24;                        /* +0x24: not traced */
    Ref00503fb0<Object016b9108> held28; /* +0x28 */
    u8 unknown30[0x28];
    Name name58; /* +0x58: not traced */
    u8 unknown5c[0x74];
    Name nameD0; /* +0xd0: not traced */
    u8 unknownD4[0x14];
    Array05943280<Entry016a8bc8_e8> entriesE8;   /* +0xe8 */
    Array05943280<Entry016a8bc8_100> entries100; /* +0x100 */
    u8 unknown118[0x8];
    Name name120; /* +0x120: not traced */
    u8 unknown124[0xc];
};

#endif
