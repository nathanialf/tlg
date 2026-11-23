/* src/include/tlg_game_object0134a810.h: the class whose vtable is at
 * 0x16c7328, a member of game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT0134A810_H
#define TLG_GAME_OBJECT0134A810_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: the class whose vtable is at 0x16c7328
 * (config/vtables.derived.base.txt): its complete destructor 0x134a810
 * (leaf_0134a810.cpp, the key function's file) stores the vtable and
 * releases the block the pointer at +0x68 holds (tlg_game_block.h); the
 * deleting one is the compiler's. The other members are not traced. */
/* derived names: the non-polymorphic base at +0x8 of Object0134a810: its
 * int is set to 1 before the derived vptr is stored (`mov dword [rbx+8], 1;
 * mov [rbx], rax` at 0x134b4f4), the base's constructor running first */
struct Base0134a810 { /* derived name */

    Base0134a810() : unknown8(1) {}

    int unknown8; /* +0x8 */
};

class Object0134a810 : public Base0134a810 /* derived name */
{
  public:
    /* FUN_0134b4e0 (27 callers): two points copied lane by lane, a
     * pointer, the ints and floats after them one store each (the types
     * alternate, so none is merged), then the array emptied with a capacity
     * of 8 (clear(8) in line) */
    Object0134a810(const Float4A &first, const Float4A &second, void *pointer);

    virtual ~Object0134a810();

  private:
    Float4A unknown10;           /* +0x10 */
    Float4A unknown20;           /* +0x20 */
    void *unknown30;             /* +0x30 */
    int unknown38;               /* +0x38 */
    float unknown3c;             /* +0x3c */
    int unknown40;               /* +0x40: 1 from the constructor */
    float unknown44;             /* +0x44 */
    u8 unknown48[0x8];           /* +0x48: not traced */
    void *unknown50;             /* +0x50 */
    void *unknown58;             /* +0x58 */
    int unknown60;               /* +0x60 */
    Array01343a80<Vec4> vectors; /* +0x68: its block released by the destructor */
    int unknown80;               /* +0x80 */
};

#endif
