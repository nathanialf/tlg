/* src/include/tlg_game_object016b6208.h: the class whose vtable is at 0x16b6208
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B6208_H
#define TLG_GAME_OBJECT016B6208_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b6208
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b480b0 and
 * its destructor FUN_00b48890), 0x90 bytes (`mov edi, 0x90` before
 * operator new in the creator). Its destructor is its key function (defined
 * out of line, leaf_00b48890.cpp): the deleting one FUN_00b48a60 calls it.
 * The creator leaves +0x24 alone: not over Object016b9108Kind.
 * Its own slots: slot 5 0x58a0; slot 6 FUN_01343880; slot 7 the empty body at 0x1af750; slot 8 the empty body at 0x1af750. */
class Object016b6208 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b6208();
    virtual void slot5(); /* derived name; 0x58a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; the empty body at 0x1af750 */
    virtual void slot8(); /* derived name; the empty body at 0x1af750 */

  private:
    u8 unknown24[0x4];  /* not traced */
    u8 unknown28[0x20]; /* not traced */
    /* +0x48: an array of references with its lock (the word at +0x5c),
     * emptied to no capacity by the destructor, then torn down (`call
     * 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array48;
    u8 unknown60[0x30]; /* not traced */
};

#endif
