/* src/include/tlg_game_object016b3f50.h: the class whose vtable is at 0x16b3f50
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B3F50_H
#define TLG_GAME_OBJECT016B3F50_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108kind.h"

/* derived names: the class whose vtable is at 0x16b3f50
 * (config/vtables.derived.base.txt, stored by its creator FUN_00ae9220 and
 * its destructor FUN_00ae9400), 0xa0 bytes (`mov edi, 0xa0` before
 * operator new in the creator). Its destructor is its key function (defined
 * out of line, leaf_00ae9400.cpp): the deleting one FUN_00ae95f0 calls it.
 * The creator clears +0x24 before the vptr and stores the kind there last
 * (Object016b9108Kind).
 * Its own slots: slot 5 the empty body at 0x1af750; slot 6 FUN_00c1b350. */
class Object016b3f50 : public Object016b9108Kind /* derived name */
{
  public:
    virtual ~Object016b3f50();
    virtual void slot5(); /* derived name; the empty body at 0x1af750 */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown28[0x58]; /* not traced */
    /* +0x80: an array of references with its lock (the word at +0x94),
     * emptied to no capacity by the destructor, then torn down (`call
     * 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array80;
    u8 unknown98[0x8]; /* not traced */
};

#endif
