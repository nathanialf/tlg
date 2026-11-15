/* src/include/tlg_game_object016d0098.h: the class whose vtable is at
 * 0x16d0098 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D0098_H
#define TLG_GAME_OBJECT016D0098_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d0098
 * (config/vtables.derived.base.txt, stored by FUN_00b49df0 FUN_0139bff0
 * FUN_0139c0c0), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b49df0 sets them and its destructor FUN_0139bff0
 * tears them down. */
class Object016d0098 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x24
     * cleared (`vmovdqu [r15+0x24], xmm0; mov dword [r15+0x34], 0`: an int and
     * the array's block, count and capacity, a run of zero stores made one
     * memset), the array's owner index from the thread's heap and its lock */
    Object016d0098(const Name &name) : Object016b9108(name), unknown24(0) {}

    virtual ~Object016d0098();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    /* +0x28: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array28;
};

/* derived name: the complete destructor FUN_0139bff0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_0139c0c0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00b49df0.cpp)
 * emits the vtable and both destructors. */
inline Object016d0098::~Object016d0098() {}

#endif
