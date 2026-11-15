/* src/include/tlg_game_object016b6a70.h: the class whose vtable is at
 * 0x16b6a70 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B6A70_H
#define TLG_GAME_OBJECT016B6A70_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b6a70
 * (config/vtables.derived.base.txt, stored by FUN_00b55e60 FUN_00b56000
 * FUN_00b560d0), derived from Object01343880: slots 7 and 8 override
 * the base's (FUN_00b561a0, FUN_00b56250; declared, their bodies are not
 * members yet). 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b55e60 sets them and its destructor FUN_00b56000
 * tears them down. */
class Object016b6a70 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x34
     * cleared (`vmovdqu [r15+0x34], xmm0; mov dword [r15+0x44], 0`: the name
     * and the array's block, count and capacity, a run of zero stores made one
     * memset), the array's owner index from the thread's heap and its lock;
     * the base's pointer and int cleared before the vptr store */
    Object016b6a70(const Name &name) : Object01343880(name) {}

    virtual ~Object016b6a70();
    /* slot 7, FUN_00b561a0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_00b56250: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void slot8();

  private:
    Name name34; /* +0x34: empty from the constructor, released by the destructor */
    Array01343a80<Ref00503fb0<Node00503fb0>> record38; /* +0x38: an array of counted references */
};

/* derived name: the complete destructor FUN_00b56000: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00b560d0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00b55e60.cpp)
 * emits the vtable and both destructors. */
inline Object016b6a70::~Object016b6a70() {}

#endif
