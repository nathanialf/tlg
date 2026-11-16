/* src/include/tlg_game_object016b0028.h: the class whose vtable is at
 * 0x16b0028 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0028_H
#define TLG_GAME_OBJECT016B0028_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0028
 * (config/vtables.derived.base.txt, stored by FUN_008bef40 FUN_008bf130
 * FUN_008bf1e0), derived from Object016b9108. 0x70 bytes (`mov edi,
 * 0x70` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008bef40 sets them and its destructor FUN_008bf130
 * tears them down. */
class Object016b0028 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the three arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, then at +0x40 and +0x58) with its
     * owner index from the thread's heap and its lock */
    Object016b0028(const Name &name) : Object016b9108(name) {}

    virtual ~Object016b0028();

  private:
    u8 unknown24[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
    Array01343a80<Ref00503fb0<Object016b9108>> record40; /* +0x40: an array of counted references */
    Array01343a80<Ref00503fb0<Object016b9108>> record58; /* +0x58: an array of counted references */
};

/* derived name: the complete destructor FUN_008bf130: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_008bf1e0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_008bef40.cpp)
 * emits the vtable and both destructors. */
inline Object016b0028::~Object016b0028() {}

#endif
