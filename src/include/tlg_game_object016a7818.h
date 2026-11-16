/* src/include/tlg_game_object016a7818.h: the class whose vtable is at
 * 0x16a7818 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7818_H
#define TLG_GAME_OBJECT016A7818_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16a7818
 * (config/vtables.derived.base.txt, stored by FUN_00217680 FUN_00217c20
 * FUN_00217d90), derived from Object01343880. 0x88 bytes (`mov edi,
 * 0x88` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00217680 sets them and its destructor FUN_00217c20
 * tears them down. The destructor is the class's key function
 * (leaf_00217c20.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016a7818 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x34
     * cleared (`vmovdqu [r15+0x34], xmm0; mov dword [r15+0x44], 0`: an int and
     * the first array's block, count and capacity, a run of zero stores made
     * one memset), its owner index and state, `mov dword [r15+0x50], 0` (the
     * name), the two other arrays, each cleared with its owner index and state */
    Object016a7818(const Name &name) : Object01343880(name), unknown34(0) {}

    virtual ~Object016a7818();

  private:
    int unknown34;               /* +0x34: zero from the constructor; not traced */
    Array01343a80<Name> names38; /* +0x38: an array of Names, each released by the destructor */
    Name name50;                 /* +0x50: empty from the constructor, released by the destructor */
    u8 unknown54[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record58; /* +0x58: an array of counted references */
    Array01343a80<Ref00503fb0<Object016b9108>> record70; /* +0x70: an array of counted references */
};

#endif
