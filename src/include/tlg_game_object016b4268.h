/* src/include/tlg_game_object016b4268.h: the class whose vtable is at 0x16b4268
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4268_H
#define TLG_GAME_OBJECT016B4268_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108kind.h"

/* derived names: the class whose vtable is at 0x16b4268
 * (config/vtables.derived.base.txt, stored by its creator FUN_00aebf80 and
 * its destructor FUN_00aec130), 0x58 bytes (`mov edi, 0x58` before
 * operator new in the creator). Its destructor is its key function (defined
 * out of line, leaf_00aec130.cpp): the deleting one FUN_00aec300 calls it.
 * The creator clears +0x24 before the vptr and stores the kind there last
 * (Object016b9108Kind).
 * Its own slots: slot 5 the empty body at 0x1af750; slot 6 FUN_00c1b350. */
class Object016b4268 : public Object016b9108Kind /* derived name */
{
  public:
    virtual ~Object016b4268();
    virtual void slot5(); /* derived name; the empty body at 0x1af750 */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown28[0x18]; /* not traced */
    /* +0x40: an array of references with its lock (the word at +0x54),
     * emptied to no capacity by the destructor, then torn down (`call
     * 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array40;
};

#endif
