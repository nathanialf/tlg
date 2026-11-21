/* src/include/tlg_game_object016b4148.h: the class whose vtable is at 0x16b4148
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4148_H
#define TLG_GAME_OBJECT016B4148_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b4148
 * (config/vtables.derived.base.txt, stored by its creator FUN_00aeaca0 and
 * its destructor FUN_00aeae40), 0x48 bytes (`mov edi, 0x48` before operator
 * new in the creator). Its destructor is its key function (defined out of
 * line, leaf_00aeae40.cpp): the deleting one FUN_00aeb010 calls it. Slots 5 to 7
 * are the empty body at 0x1af750, slot 8 FUN_00c1b350. */
class Object016b4148 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b4148();
    virtual void slot5(); /* derived name; 0x1af750 */
    virtual void slot6(); /* derived name; 0x1af750 */
    virtual void slot7(); /* derived name; 0x1af750 */
    virtual void slot8(); /* derived name; FUN_00c1b350, not traced */

  private:
    int unknown24; /* +0x24: set by the creator; not traced */
    int unknown28; /* +0x28: zero from the creator */
    u8 unknown2c[0x4];
    /* +0x30: an array of references with its lock (the word at +0x44),
     * emptied to no capacity by the destructor, then torn down (`lea rdi,
     * [rbx+0x30]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array30;
};

#endif
