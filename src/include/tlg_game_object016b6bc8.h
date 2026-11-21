/* src/include/tlg_game_object016b6bc8.h: the subtitles' class, whose
 * vtable is at 0x16b6bc8 (game region; docs/TARGETS.md). Every name here
 * is derived. */
#ifndef TLG_GAME_OBJECT016B6BC8_H
#define TLG_GAME_OBJECT016B6BC8_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the objects the array at +0x88 holds (counted, derived
 * from the root class); not traced. The array's destructor over them is
 * leaf_00b724e0.cpp's alone and has one caller, so the link inlines it in
 * the class's destructor, as the base shows (no call to 0x134f620) */
class Element88016b6bc8 : public Object016b9108
{
};

/* derived names: the subtitles' class, whose vtable is at 0x16b6bc8
 * (config/vtables.derived.base.txt: its destructor 0xb724e0 stores it, and
 * the constructor 0xa64050 of the class at 0x16b22e0, leaf_00a64370.cpp,
 * builds it in place at +0x98 of that class, `mov [r12+0x98], rcx`, then
 * keeps its address at 0x5828450), with no base whose destructor does
 * anything. Its functions are 0xb728c0 to 0xb738b0. Its fields are traced
 * where the destructor tears them down: counted references at +0x30,
 * +0x40, +0x78 and +0xa0, an array of counted references at +0x88 and an
 * array of names at +0xb0. */
class Object016b6bc8 /* derived name */
{
  public:
    virtual ~Object016b6bc8(); /* 0xb724e0, its row named after it (D15) */

    void FUN_00b728c0();

  private:
    u8 unknown8[0x28];
    Ref00503fb0<Object016b9108> held30; /* +0x30 */
    u8 unknown38[0x8];
    Ref00503fb0<Object016b9108> held40; /* +0x40 */
    u8 unknown48[0x30];
    Ref00503fb0<Object016b9108> held78; /* +0x78 */
    u8 unknown80[0x8];
    Array05943280<Ref00503fb0<Element88016b6bc8>> array88; /* +0x88 */
    Ref00503fb0<Object016b9108> heldA0;                    /* +0xa0 */
    u8 unknownA8[0x8];
    Array05943280<Name> namesB0; /* +0xb0 */
};

#endif
