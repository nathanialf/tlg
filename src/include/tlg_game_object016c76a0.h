/* src/include/tlg_game_object016c76a0.h: the class whose vtable is at
 * 0x16c76a0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C76A0_H
#define TLG_GAME_OBJECT016C76A0_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16c76a0
 * (config/vtables.derived.base.txt, stored by its creator FUN_003518e0,
 * where its constructor is inlined after Object016b85e0's), derived from
 * Object016b85e0. 0x260 bytes (`mov edi, 0x260` before operator new in the
 * creator): a Name at +0x238 and a locked array of Names at +0x240. Its
 * complete destructor FUN_0134dc10 releases the array's Names first to
 * last and its block, then the Name, then tail-calls the base's destructor
 * 0xc55550; FUN_0134dd20, slot 1, is the deleting one. The destructor is
 * the class's key function (leaf_0134dc10.cpp), so that unit emits the
 * vtable. */
class Object016c76a0 : public Object016b85e0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the
     * empty Name (0 at +0x238), the array at +0x240 (its block, count and
     * capacity cleared in one store, its owner index from the thread's
     * heap, its lock free) */
    Object016c76a0(const Name &name) : Object016b85e0(name) {}

    virtual ~Object016c76a0();

  private:
    Name name238; /* +0x238 */
    u8 unknown23c[0x4];
    Array01343a80<Name> names240; /* +0x240 */
    u8 unknown258[0x8];
};

#endif
