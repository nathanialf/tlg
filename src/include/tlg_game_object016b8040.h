/* src/include/tlg_game_object016b8040.h: the class whose vtable is at 0x16b8040
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8040_H
#define TLG_GAME_OBJECT016B8040_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b8040
 * (config/vtables.derived.base.txt, stored by its creator FUN_00c19f10 and
 * its destructor FUN_00c1a5e0), 0x58 bytes (`mov edi, 0x58` before operator
 * new in the creator, which clears the fields from +0x24). Its destructor
 * is its key function (leaf_00c1a5e0.cpp): the deleting one FUN_00c1ac20
 * calls it. Slot 5 is FUN_00c1ac40 (leaf_00c1ac40.cpp: FUN_00c1a0c0, then
 * slot 5 of the object at +0x50), slot 6 FUN_00c1b350. */
class Object016b8040 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b8040();
    virtual void slot5(void *argument); /* derived name; FUN_00c1ac40 */
    virtual void slot6();               /* derived name; FUN_00c1b350, not traced */

  private:
    int unknown24;  /* +0x24: zero from the creator */
    Name unknown28; /* +0x28 */
    Name unknown2c; /* +0x2c */
    /* +0x30: an array of references with its lock (the word at +0x44),
     * emptied by the destructor with its block kept, then torn down (`lea
     * r12, [rcx+0x30]`, `call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array30;
    u8 unknown48[0x8];
    Ref00503fb0<Object016b9108> unknown50; /* +0x50 */
};

#endif
