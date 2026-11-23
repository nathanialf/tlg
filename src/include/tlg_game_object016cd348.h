/* src/include/tlg_game_object016cd348.h: the class whose vtable is at
 * 0x16cd348, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016CD348_H
#define TLG_GAME_OBJECT016CD348_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16cd348
 * (config/vtables.derived.base.txt, stored by FUN_00991430 FUN_00991560
 * FUN_00991670 and 3 more), derived from Object016b9108: its slots 2 to 4
 * are the base's, slot 5 its own. 0x48
 * bytes (`mov edi, 0x48` before operator new in its creator FUN_00e5b650,
 * which inlines the constructor). Every function of the class lies in the
 * stretch of inline functions (from 0x1340000: the complete and the
 * deleting destructor FUN_01382c30 and FUN_01382d00, slot 5), so it has no
 * key function and declares no destructor: the units that construct it
 * emit the vtable and both destructors, and the destructor of a class over
 * it holds its body (FUN_00991560). The rest is not traced. */
class Object016cd348 : public Object016b9108 /* derived name */
{
  public:
    /* the base's constructor, then the array made empty and the pointer at
     * +0x40 cleared (0xe5b758 to 0xe5b7a4) */
    Object016cd348(const Name &name) : Object016b9108(name), unknown40(0) {}

    /* slot 5, FUN_01382dd0: the array's address */
    virtual Array05943280<u32> *values() /* derived name */
    {
        return &values28;
    }

  private:
    u8 unknown24[0x4];
    /* +0x28: an array, released by the destructor (`mov rax, [rbx+0x28];
     * ... cmp ecx, 0xa`); 32-bit elements, as the class over it makes 64
     * of (0x991430) */
    Array05943280<u32> values28;
    void *unknown40; /* +0x40: not traced */
};

/* derived names: the class whose vtable is at 0x16b1738
 * (config/vtables.derived.base.txt, stored by FUN_00991430 FUN_00991560
 * FUN_00991670), derived from Object016cd348: slot 5 is its own, the
 * others the base's. 0x68 bytes (`mov
 * edi, 0x68` before operator new in its creator FUN_009912d0). Its
 * constructor 0x991430 is out of line (stores both vtables) and not
 * written; its destructor is
 * FUN_00991560 (leaf_00991560.cpp). The rest is not traced. */
class Object016b1738 : public Object016cd348 /* derived name */
{
  public:
    Object016b1738(const Name &name);
    virtual ~Object016b1738();
    /* slot 5: its own array's address (FUN_00038120, a body the
     * executable keeps once for every class whose slot returns the address
     * at +0x50) */
    virtual Array05943280<u32> *values(); /* derived name */

  private:
    u8 unknown48[0x8];
    /* +0x50: an array of 64 values made 0 by the constructor (0x991430:
     * an array's fields, the capacity made 64 exactly, then each element
     * cleared), released by the destructor (`mov rax, [rbx+0x50]; ... cmp
     * ecx, 0xa`). Slot 5 returns its address as the base's returns its
     * array's. Its elements have no destructor, so its block goes back
     * through FUN_00ebf3f0 at the unit stage (tlg_game_array.h) and the
     * deleting destructor FUN_00991670 holds the complete one. */
    Array05943280<u32> values50;
};

#endif
