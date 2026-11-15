/* src/include/tlg_game_object016ae740.h: the class whose vtable is at
 * 0x16ae740 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE740_H
#define TLG_GAME_OBJECT016AE740_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16ae740
 * (config/vtables.derived.base.txt, stored by FUN_00818730 FUN_00818910
 * FUN_008189e0), derived from Object01343880. 0x70 bytes (`mov edi,
 * 0x70` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00818730 sets them and its destructor FUN_00818910
 * tears them down. The destructor is the class's key function
 * (leaf_00818910.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016ae740 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x34], 0`
     * (the name), `mov dword [r15+0x38], 0`, the two arrays, each cleared
     * (`vmovdqu [r15+0x40], xmm0`, `vmovdqu [r15+0x58], xmm0`) with its owner
     * index from the thread's heap and its state */
    Object016ae740(const Name &name) : Object01343880(name), unknown38(0) {}

    virtual ~Object016ae740();

  private:
    Name name34;   /* +0x34: empty from the constructor, released by the destructor */
    int unknown38; /* +0x38: zero from the constructor; not traced */
    u8 unknown3c[0x4];
    Array01343a80<Ref00503fb0<Node00503fb0>> record40; /* +0x40: an array of counted references */
    Array01343a80<Ref00503fb0<Node00503fb0>> record58; /* +0x58: an array of counted references */
};

#endif
