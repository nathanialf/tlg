/* src/include/tlg_game_object016a8c00.h: the class whose vtable is at
 * 0x16a8c00 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8C00_H
#define TLG_GAME_OBJECT016A8C00_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16a8c00
 * (config/vtables.derived.base.txt, stored by FUN_003714e0 FUN_00371690
 * FUN_00371760), derived from Object016b9108. 0x90 bytes (`mov edi,
 * 0x90` before operator new in the creator). Its own fields are traced
 * where its creator FUN_003714e0 sets them and its destructor FUN_00371690
 * tears them down. */
class Object016a8c00 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x60], xmm0`), its owner index from the thread's heap and
     * its lock, then the body's assignments: 0 and 1 from +0x24 in one
     * `movabs`, the 24 bytes from +0x2c cleared (`vmovdqu [r15+0x2c], xmm0; mov
     * qword [r15+0x3c], 0`: six ints, a run of zero stores made one memset), the
     * aligned four floats at +0x50 cleared (`vmovdqa [r15+0x50], xmm0`) */
    Object016a8c00(const Name &name) : Object016b9108(name)
    {
        unknown24 = 0;
        unknown28 = 1;
        unknown2c = 0;
        unknown30 = 0;
        unknown34 = 0;
        unknown38 = 0;
        unknown3c = 0;
        unknown40 = 0;
        unknown50.set(0.0f, 0.0f, 0.0f, 0.0f);
    }

    virtual ~Object016a8c00();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    int unknown28; /* +0x28: 1 from the constructor; not traced */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    int unknown30; /* +0x30: zero from the constructor; not traced */
    int unknown34; /* +0x34: zero from the constructor; not traced */
    int unknown38; /* +0x38: zero from the constructor; not traced */
    int unknown3c; /* +0x3c: zero from the constructor; not traced */
    int unknown40; /* +0x40: zero from the constructor; not traced */
    u8 unknown44[0xc];
    Float4A unknown50; /* +0x50: zero from the constructor; not traced */
    /* +0x60: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x60]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array60;
    u8 unknown78[0x18];
};

/* derived name: the complete destructor FUN_00371690: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00371760, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_003714e0.cpp)
 * emits the vtable and both destructors. */
inline Object016a8c00::~Object016a8c00() {}

#endif
