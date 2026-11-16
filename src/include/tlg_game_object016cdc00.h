/* src/include/tlg_game_object016cdc00.h: the class whose vtable is at
 * 0x16cdc00 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDC00_H
#define TLG_GAME_OBJECT016CDC00_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cdc00
 * (config/vtables.derived.base.txt, stored by FUN_009b57a0 FUN_01386190
 * FUN_01386240), derived from Object016b9108. 0x78 bytes (`mov edi,
 * 0x78` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b57a0 sets them and its destructor FUN_01386190
 * tears them down. */
class Object016cdc00 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the three arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, then at +0x40 and +0x58) with its
     * owner index from the thread's heap and its lock, `mov dword [r15+0x70],
     * 0` */
    Object016cdc00(const Name &name) : Object016b9108(name), unknown70(0) {}

    virtual ~Object016cdc00();

  private:
    u8 unknown24[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
    Array01343a80<Ref00503fb0<Object016b9108>> record40; /* +0x40: an array of counted references */
    Array01343a80<Ref00503fb0<Object016b9108>> record58; /* +0x58: an array of counted references */
    int unknown70; /* +0x70: zero from the constructor; not traced */
    u8 unknown74[0x4];
};

/* derived name: the complete destructor FUN_01386190: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_01386240, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_009b57a0.cpp)
 * emits the vtable and both destructors. */
inline Object016cdc00::~Object016cdc00() {}

#endif
