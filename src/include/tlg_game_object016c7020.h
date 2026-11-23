/* src/include/tlg_game_object016c7020.h: the class whose vtable is at
 * 0x16c7020 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7020_H
#define TLG_GAME_OBJECT016C7020_H

#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: the three ints at +0x8 to +0x10, a non-polymorphic base
 * class: every inline build stores 1, 4 and 0 apart and ahead of the
 * class's vptr (0x7b0871 to 0x7b087f before 0x7b088d; 0xc18b80 to 0xc18ba2
 * before 0xc18caf); as the class's own members after its vptr the first two
 * are joined into one 8-byte store. What they hold is not traced. */
struct Base016c7020 /* derived name */
{
    Base016c7020() : unknown8(1), unknownc(4), unknown10(0) {}

    int unknown8;  /* +0x8 */
    int unknownc;  /* +0xc */
    int unknown10; /* +0x10 */
};

/* derived names: the class whose vtable is at 0x16c7020
 * (config/vtables.derived.base.txt, stored by FUN_001bd010 and 42 other
 * functions that build it inline): 32 names from +0x14. Its slots 2 and 3
 * are pure (zero in the vtable, relocated at load), 4 and 5 point at
 * 0x1af750 and 0x21a00. 0x120 bytes. The class has no key function: the
 * unit that builds one emits the vtable and the destructors
 * (leaf_007b0720.cpp). */
class Object016c7020 : public Base016c7020 /* derived name */
{
  public:
    /* inlined where it is built (FUN_007b0720 at +0x40 of Object016cbe98,
     * FUN_00c18b70 for the global at 0x5937540): the base's three ints, the
     * names cleared (one memset), -1 at +0x114 and 0 at +0x118 (`mov qword
     * [rbx+0x154], rax` with rax 0xffffffff), then the words after the
     * names cleared (a second memset, after the -1 and the 0) */
    Object016c7020() : unknown114(-1), unknown118(0)
    {
        for (int i = 0; i < 32; ++i)
            unknown94[i] = 0;
    }

    /* inline: its body is held by the destructors of the classes that
     * hold one (FUN_0136e990 at +0x40), and its own two sit with the inline
     * functions (the deleting one, FUN_01343010, holds the body); the names
     * are released from the last down */
    virtual ~Object016c7020() {}

  private:
    Name names[32];    /* +0x14 */
    int unknown94[32]; /* +0x94: zeros from the constructor; not traced */
    int unknown114;    /* +0x114: -1 from the constructor */
    int unknown118;    /* +0x118: 0 from the constructor */
};

#endif
