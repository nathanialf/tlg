/* src/include/tlg_game_object016b41d8.h: the class whose vtable is at 0x16b41d8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B41D8_H
#define TLG_GAME_OBJECT016B41D8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108kind.h"

/* derived names: the class whose vtable is at 0x16b41d8
 * (config/vtables.derived.base.txt, stored by its creator FUN_00aeb540 and
 * its destructor FUN_00aeb780), 0x90 bytes (`mov edi, 0x90` before
 * operator new in the creator). Its destructor is its key function (defined
 * out of line, leaf_00aeb780.cpp): the deleting one FUN_00aeba30 calls it.
 * The creator clears +0x24 before the vptr and stores the kind there last
 * (Object016b9108Kind).
 * Its own slots: slot 5 the empty body at 0x1af750; slot 6 FUN_00c1b350. */
class Object016b41d8 : public Object016b9108Kind /* derived name */
{
  public:
    virtual ~Object016b41d8();
    virtual void slot5(); /* derived name; the empty body at 0x1af750 */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown28[0x8]; /* not traced */
    /* +0x30: an array with its lock (the word at +0x44) whose destructor
     * only gives the block back (`movzx ecx, byte [rax-0x10]; cmp ecx,
     * 0xa`): its elements have no destructor; their type is not traced */
    Array01343a80<u32> array30;
    /* +0x48: an array with its lock (the word at +0x5c) whose destructor
     * only gives the block back (`movzx ecx, byte [rax-0x10]; cmp ecx,
     * 0xa`): its elements have no destructor; their type is not traced */
    Array01343a80<u32> array48;
    /* +0x60: an array with its lock (the word at +0x74) whose destructor
     * only gives the block back (`movzx ecx, byte [rax-0x10]; cmp ecx,
     * 0xa`): its elements have no destructor; their type is not traced */
    Array01343a80<u32> array60;
    /* +0x78: an array of references with its lock (the word at +0x8c),
     * emptied to no capacity by the destructor, then torn down (`call
     * 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array78;
};

#endif
