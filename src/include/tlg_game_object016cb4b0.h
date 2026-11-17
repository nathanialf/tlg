/* src/include/tlg_game_object016cb4b0.h: the class whose vtable is at
 * 0x16cb4b0 and the class derived from it whose vtable is at 0x16ac098 (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB4B0_H
#define TLG_GAME_OBJECT016CB4B0_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016aea40.h"

/* derived names: the class whose vtable is at 0x16cb4b0
 * (config/vtables.derived.base.txt, stored by FUN_006703a0, where its
 * constructor is inlined, and by its destructors 0x670840 and 0x6708b0),
 * derived from Object016aea40. It holds an array at +0x248 whose block its
 * destructor releases (leaf_00670840.cpp, the class's key function): the
 * creator clears its block, count and capacity in one store
 * (`vmovdqu [r15+0x248], xmm0`), stores its owner index from the thread's
 * heap at +0x258 and its free lock at +0x25c. Its elements are not traced. */
class Object016cb4b0 : public Object016aea40 /* derived name */
{
  public:
    Object016cb4b0(const Name &name) : Object016aea40(name) {}

    virtual ~Object016cb4b0();

  private:
    Array01343a80<void *> array248; /* +0x248 */
};

/* derived names: the class whose vtable is at 0x16ac098
 * (config/vtables.derived.base.txt, stored by its creator FUN_006703a0, where
 * its constructor is inlined after Object016cb4b0's), derived from
 * Object016cb4b0. 0x270 bytes (`mov edi, 0x270` before operator new in the
 * creator). -1.0 at +0x260 and +0x264 (one eight-byte store after the vptr);
 * its destructor is not written. */
class Object016ac098 : public Object016cb4b0 /* derived name */
{
  public:
    Object016ac098(const Name &name) : Object016cb4b0(name), unknown260(-1.0f), unknown264(-1.0f) {}

    virtual ~Object016ac098();

  private:
    float unknown260; /* +0x260: -1.0 from the constructor */
    float unknown264; /* +0x264: -1.0 from the constructor */
    u8 unknown268[0x8];
};

#endif
