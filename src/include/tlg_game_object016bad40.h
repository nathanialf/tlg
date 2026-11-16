/* src/include/tlg_game_object016bad40.h: the class whose vtable is at
 * 0x16bad40 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BAD40_H
#define TLG_GAME_OBJECT016BAD40_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16bad40
 * (config/vtables.derived.base.txt, stored by FUN_00d85060 FUN_013bbb30
 * FUN_013bbc00), derived from Object01343880: slots 7 and 8 override
 * the base's (FUN_00d85230, FUN_00d85500; declared, their bodies are not
 * members yet). 0x70 bytes (`mov edi,
 * 0x70` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00d85060 sets them and its destructor FUN_013bbb30
 * tears them down. */
class Object016bad40 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two arrays, each
     * cleared (`vmovdqu [r15+0x38], xmm0`, `vmovdqu [r15+0x50], xmm0`) with its
     * owner index from the thread's heap and its lock, `mov dword [r15+0x68],
     * 0`; the base's pointer and int cleared before the vptr store */
    Object016bad40(const Name &name) : Object01343880(name), unknown68(0) {}

    virtual ~Object016bad40();
    /* slot 7, FUN_00d85230: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_00d85500: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void slot8();

  private:
    u8 unknown34[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record38; /* +0x38: an array of counted references */
    /* +0x50: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x50]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array50;
    int unknown68; /* +0x68: zero from the constructor; not traced */
    u8 unknown6c[0x4];
};

/* derived name: the complete destructor FUN_013bbb30: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_013bbc00, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00d85060.cpp)
 * emits the vtable and both destructors. */
inline Object016bad40::~Object016bad40() {}

#endif
