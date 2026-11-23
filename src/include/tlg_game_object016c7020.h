/* src/include/tlg_game_object016c7020.h: the class whose vtable is at
 * 0x16c7020 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7020_H
#define TLG_GAME_OBJECT016C7020_H

#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16c7020
 * (config/vtables.derived.base.txt, stored by FUN_001bd010 and 42 other
 * functions that build it inline): 32 names from +0x14. Its slots 2 and 3
 * are pure (zero in the vtable, relocated at load), 4 and 5 point at
 * 0x1af750 and 0x21a00. 0x120 bytes. The class has no key function: the
 * unit that builds one emits the vtable and the destructors
 * (leaf_007b0720.cpp). */
class Object016c7020 /* derived name */
{
  public:
    /* inlined where it is built (FUN_007b0720 at +0x40 of Object016cbe98):
     * 1 and 4 at +0x8 and +0xc, 0 at +0x10, the names and the words after them
     * cleared (one memset), -1 at +0x114 and 0 at +0x118 (`mov qword
     * [rbx+0x154], rax` with rax 0xffffffff) */
    Object016c7020()
        : unknown8(1), unknownc(4), unknown10(0), unknown94(), unknown114(-1), unknown118(0)
    {
    }

    /* inline: its body is held by the destructors of the classes that
     * hold one (FUN_0136e990 at +0x40), and its own two sit with the inline
     * functions (the deleting one, FUN_01343010, holds the body); the names
     * are released from the last down */
    virtual ~Object016c7020() {}

  private:
    int unknown8;      /* +0x8: 1 from the constructor */
    int unknownc;      /* +0xc: 4 from the constructor */
    int unknown10;     /* +0x10: 0 from the constructor */
    Name names[32];    /* +0x14 */
    int unknown94[32]; /* +0x94: zeros from the constructor; not traced */
    int unknown114;    /* +0x114: -1 from the constructor */
    int unknown118;    /* +0x118: 0 from the constructor */
};

#endif
