/* src/include/tlg_game_object016b99b0.h: the class whose vtable is at 0x16b99b0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B99B0_H
#define TLG_GAME_OBJECT016B99B0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b99b0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00cefe40 and
 * its destructor FUN_00cf0c70), 0x68 bytes (`mov edi, 0x68` before
 * operator new in the creator). Its destructor is its key function (defined
 * out of line, leaf_00cf0c70.cpp): the deleting one FUN_00cf0e40 calls it.
 * The creator leaves +0x24 alone: not over Object016b9108Kind.
 * Its own slots: slot 5 0x58a0; slot 6 FUN_01343880; slot 7 the empty body at 0x1af750; slot 8 the empty body at 0x1af750. */
class Object016b99b0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b99b0();
    virtual void slot5(); /* derived name; 0x58a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; the empty body at 0x1af750 */
    virtual void slot8(); /* derived name; the empty body at 0x1af750 */

  private:
    u8 unknown24[0x4];  /* not traced */
    u8 unknown28[0x28]; /* not traced */
    /* +0x50: an array of references with its lock (the word at +0x64),
     * emptied to no capacity by the destructor, then torn down (`call
     * 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array50;
};

#endif
