/* src/include/tlg_game_object016cc260.h: the class whose vtable is at
 * 0x16cc260 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC260_H
#define TLG_GAME_OBJECT016CC260_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cc260
 * (config/vtables.derived.base.txt, stored by FUN_008785d0 FUN_01372650
 * FUN_01372760), derived from Object016b9108. 0xa0 bytes (`mov edi,
 * 0xa0` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008785d0 sets them and its destructor FUN_01372650
 * tears them down. The destructor is implicit
 * (see the class). */
class Object016cc260 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the three arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, then at +0x40 and +0x58) with its
     * owner index from the thread's heap and its lock, `mov qword [r15+0x70],
     * 0`, the 20 bytes from +0x80 cleared (`vmovdqu [r15+0x80], xmm0; mov dword
     * [r15+0x90], 0`: five ints, a run of zero stores made one memset) */
    Object016cc260(const Name &name)
        : Object016b9108(name), unknown70(0), unknown80(0), unknown84(0), unknown88(0),
          unknown8c(0), unknown90(0)
    {
    }

    /* no destructor is declared: the complete one FUN_01372650 and the deleting
     * FUN_01372760 sit in the stretch of inline functions (from 0x1340000),
     * away from the creator, so the class has no key function and the unit
     * that constructs it (leaf_008785d0.cpp) emits the vtable with both. An
     * implicit destructor carries the inline hint: the deleting one holds
     * the complete one's body, as the base's does, where a destructor
     * defined in a unit of its own left a call. */

  private:
    u8 unknown24[0x4];
    /* +0x28: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array28;
    /* +0x40: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x40]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array40;
    Array01343a80<Ref00503fb0<Object016b9108>> record58; /* +0x58: an array of counted references */
    void *unknown70; /* +0x70: null from the constructor; not traced */
    u8 unknown78[0x8];
    int unknown80; /* +0x80: zero from the constructor; not traced */
    int unknown84; /* +0x84: zero from the constructor; not traced */
    int unknown88; /* +0x88: zero from the constructor; not traced */
    int unknown8c; /* +0x8c: zero from the constructor; not traced */
    int unknown90; /* +0x90: zero from the constructor; not traced */
    u8 unknown94[0xc];
};

#endif
