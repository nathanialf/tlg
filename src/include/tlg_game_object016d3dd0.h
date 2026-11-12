/* src/include/tlg_game_object016d3dd0.h: the class whose vtable is at
 * 0x16d3dd0, a member of game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016D3DD0_H
#define TLG_GAME_OBJECT016D3DD0_H

#include "tlg_types.h"

/* derived names: the class whose vtable is at 0x16d3dd0
 * (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00f71bc0): its complete destructor 0x13d8b70 (leaf_013d8b70.cpp, the
 * key function's file) stores the vtable, runs the class's FUN_013d8be0 on
 * the object, then releases the heap block it owns at +0x8
 * (tlg_game_block.h). It has no base. FUN_013d9060, slot 1, is the deleting
 * one. The other members are not traced. */
class Object016d3dd0 /* derived name */
{
  public:
    virtual ~Object016d3dd0();
    void FUN_013d8be0(); /* derived name */

  private:
    void *block8;       /* +0x8 */
    u8 unknown10[0x10]; /* 0x20 in all: the stride of the pair at +0x80 of Object016bfc70 */
};

#endif
