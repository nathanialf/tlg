/* src/include/tlg_game_object016c7fb0.h: the class whose vtable is at 0x16c7fb0 and
 * whose complete destructor is 0xbe1980, a base of other game classes (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7FB0_H
#define TLG_GAME_OBJECT016C7FB0_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16c7fb0
 * (config/vtables.derived.base.txt, stored by FUN_00be1980 FUN_00be4000 FUN_00be4a80), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00be1980 tears them down
 * (the arrays of Names at +0xc0, +0xa8, the Name at +0x24, the blocks at +0x70, +0x58, the record at +0x28); the rest are not traced. */
class Object016c7fb0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creators of the derived classes (FUN_00be4a80): the
     * base built from the name, this class's vptr (kept: the arrays' tests of
     * the thread's heap come between it and the derived class's), the name and
     * the first array's block, count and capacity cleared in 20 bytes, `mov
     * dword` 0 at +0x40, +0x44, +0x48 and +0x50, the arrays at +0x58 and +0x70,
     * the 48 bytes from +0x88 cleared (eight ints and the array's block, count
     * and capacity: two 32-byte stores that overlap, the last one first), the
     * arrays at +0xa8 and +0xc0, each array with its owner index from the
     * thread's heap and its state */
    Object016c7fb0(const Name &name)
        : Object016b9108(name), unknown40(0), unknown44(0), unknown48(0), unknown50(0),
          unknown88(0), unknown8c(0), unknown90(0), unknown94(0), unknown98(0), unknown9c(0),
          unknowna0(0), unknowna4(0)
    {
    }

    virtual ~Object016c7fb0();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    /* +0x28: an array of counted references, torn down by the destructor
     * (`lea rdi, [rbx+0x28]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Node00503fb0>> record28;
    int unknown40; /* +0x40: zero from the constructor; not traced */
    int unknown44; /* +0x44: zero from the constructor; not traced */
    int unknown48; /* +0x48: zero from the constructor; not traced */
    u8 unknown4c[0x4];
    int unknown50; /* +0x50: zero from the constructor; not traced */
    u8 unknown54[0x4];
    /* +0x58 and +0x70: arrays whose elements need no destructor: the
     * destructor only releases their blocks (`mov rax, [rbx+0x58]; ... cmp
     * ecx, 0xa`) */
    Array01343a80<u32> array58;
    Array01343a80<u32> array70;
    int unknown88; /* +0x88: zero from the constructor; not traced */
    int unknown8c; /* +0x8c: zero from the constructor; not traced */
    int unknown90; /* +0x90: zero from the constructor; not traced */
    int unknown94; /* +0x94: zero from the constructor; not traced */
    int unknown98; /* +0x98: zero from the constructor; not traced */
    int unknown9c; /* +0x9c: zero from the constructor; not traced */
    int unknowna0; /* +0xa0: zero from the constructor; not traced */
    int unknowna4; /* +0xa4: zero from the constructor; not traced */
    /* +0xa8: an array of Names (the block at +0xa8, the count at +0xb0): the destructor releases each
     * (`mov r12, [r14+0xa8]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array01343a80<Name> namesa8;
    /* +0xc0: an array of Names (the block at +0xc0, the count at +0xc8): the destructor releases each
     * (`mov r12, [r14+0xc0]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array01343a80<Name> namesc0;
};

#endif
