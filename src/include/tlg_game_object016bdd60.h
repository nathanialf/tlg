/* src/include/tlg_game_object016bdd60.h: the class whose vtable is at 0x16bdd60
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BDD60_H
#define TLG_GAME_OBJECT016BDD60_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108kind.h"

/* derived names: the class whose vtable is at 0x16bdd60
 * (config/vtables.derived.base.txt, stored by its creator FUN_00e628f0 and
 * its destructor FUN_00e62a90), 0x48 bytes (`mov edi, 0x48` before
 * operator new in the creator). Its destructor is its key function (defined
 * out of line, leaf_00e62a90.cpp): the deleting one FUN_00e62c60 calls it.
 * The creator clears +0x24 before the vptr and stores the kind there last
 * (Object016b9108Kind).
 * Its own slots: slot 5 FUN_00e62c80; slot 6 FUN_00c1b350. */
class Object016bdd60 : public Object016b9108Kind /* derived name */
{
  public:
    virtual ~Object016bdd60();
    virtual void slot5(); /* derived name; FUN_00e62c80, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown28[0x8]; /* not traced */
    /* +0x30: an array of references with its lock (the word at +0x44),
     * emptied to no capacity by the destructor, then torn down (`call
     * 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array30;
};

#endif
