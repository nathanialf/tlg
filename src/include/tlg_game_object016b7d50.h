/* src/include/tlg_game_object016b7d50.h: the class whose vtable is at
 * 0x16b7d50 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B7D50_H
#define TLG_GAME_OBJECT016B7D50_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the objects the array at +0x28 holds (counted, derived
 * from the root class); not traced. The array's destructor over them is
 * leaf_00bf57d0.cpp's alone and has one caller, so the link inlines it in
 * the class's destructor, as the base shows (no call to 0x134f620 for it) */
class Element28016b7d50 : public Object016b9108
{
};

/* derived names: the class whose vtable is at 0x16b7d50
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00bf1b20
 * and its destructor FUN_00bf57d0, leaf_00bf57d0.cpp), derived from
 * Object016b9108; the class at 0x16b7dd0 holds an array of them
 * (leaf_00bf8e10.cpp). Its fields are traced where the destructor and
 * reset() tear them down: arrays of counted references at +0x28, +0x40 and
 * +0x98 to +0xe0, references another thread may replace at +0x58, +0x88
 * and +0x90 and an array of names at +0xf8. */
class Object016b7d50 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7d50();

    /* every array emptied with its block kept and every reference emptied
     * by compare-and-swap, in the order of the fields (FUN_00bf8e10 on each
     * object of its array) */
    void reset() /* derived name */
    {
        array28.removeAll();
        array40.removeAll();
        held58.clear();
        held88.clear();
        held90.clear();
        array98.removeAll();
        arrayB0.removeAll();
        arrayC8.removeAll();
        arrayE0.removeAll();
        namesF8.removeAll();
    }

  private:
    u8 unknown24[0x4];
    Array05943280<Ref00503fb0<Element28016b7d50>> array28; /* +0x28 */
    Array05943280<Ref00503fb0<Object016b9108>> array40;    /* +0x40 */
    AtomicRef0045c470<Object016b9108> held58;              /* +0x58 */
    u8 unknown60[0x28];
    AtomicRef0045c470<Object016b9108> held88;           /* +0x88 */
    AtomicRef0045c470<Object016b9108> held90;           /* +0x90 */
    Array05943280<Ref00503fb0<Object016b9108>> array98; /* +0x98 */
    Array05943280<Ref00503fb0<Object016b9108>> arrayB0; /* +0xb0 */
    Array05943280<Ref00503fb0<Object016b9108>> arrayC8; /* +0xc8 */
    Array05943280<Ref00503fb0<Object016b9108>> arrayE0; /* +0xe0 */
    Array05943280<Name> namesF8;                        /* +0xf8 */
};

#endif
