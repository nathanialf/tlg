/* src/include/tlg_game_object016d24f8.h: the class whose vtable is at
 * 0x16d24f8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D24F8_H
#define TLG_GAME_OBJECT016D24F8_H

#include "tlg_game_node.h"
#include "tlg_game_object00c55550.h"

/* derived names: the class whose vtable is at 0x16d24f8
 * (config/vtables.derived.base.txt, stored by FUN_00d63f10 FUN_013ba440
 * FUN_013ba530), derived from Object00c55550 (the class whose destructor is
 * 0xc55550): the base's slots and fields are not traced, so the bytes below
 * the first member here are the base's. Its own fields: the Name at +0x238
 * and the counted reference at +0x240, which the constructor FUN_00d63f10
 * sets and the destructor FUN_013ba440 releases. 0x250 bytes (the factory
 * FUN_00d63db0 allocates them). */
class Object016d24f8 : public Object00c55550 /* derived name */
{
  public:
    Object016d24f8(const Name &name);
    virtual ~Object016d24f8();

  private:
    u8 unknown8[0x230];
    Name name238; /* +0x238: empty from the constructor */
    u8 unknown23c[0x4];
    AtomicRef0045c470<Node00503fb0> held240; /* +0x240 */
    u8 unknown248[0x8]; /* the rest of the 0x250 bytes the creator allocates; not traced */
};

/* derived name: the complete destructor FUN_013ba440: the body is empty; the
 * reference and the name are released, then the base's destructor
 * FUN_00c55550 runs as a tail call. FUN_013ba530, slot 1, is the deleting
 * one. Defined here, so the unit that defines the constructor
 * (leaf_00d63f10.cpp) emits the vtable and both destructors. */
inline Object016d24f8::~Object016d24f8() {}

#endif
