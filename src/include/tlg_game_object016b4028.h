/* src/include/tlg_game_object016b4028.h: the class whose vtable is at 0x16b4028
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4028_H
#define TLG_GAME_OBJECT016B4028_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108kind.h"

/* derived names: the class whose vtable is at 0x16b4028
 * (config/vtables.derived.base.txt, stored by its creator FUN_00ae9d90 and
 * its destructor FUN_00ae9f60), 0x60 bytes (`mov edi, 0x60` before
 * operator new in the creator). Its destructor is its key function (defined
 * out of line, leaf_00ae9f60.cpp): the deleting one FUN_00aea140 calls it.
 * The creator clears +0x24 before the vptr and stores the kind there last
 * (Object016b9108Kind).
 * Its own slots: slot 5 the empty body at 0x1af750; slot 6 FUN_00c1b350. */
class Object016b4028 : public Object016b9108Kind /* derived name */
{
  public:
    virtual ~Object016b4028();
    virtual void slot5(); /* derived name; the empty body at 0x1af750 */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown28[0x8]; /* not traced */
    /* +0x30: an array of references with its lock (the word at +0x44),
     * torn down by the destructor (`call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array30;
    /* +0x48: an array of references with its lock (the word at +0x5c),
     * emptied to no capacity by the destructor, then torn down (`call
     * 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array48;
};

#endif
