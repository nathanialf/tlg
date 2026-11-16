/* src/include/tlg_game_object016b8a80.h: the class whose vtable is at
 * 0x16b8a80 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8A80_H
#define TLG_GAME_OBJECT016B8A80_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16b8a80
 * (config/vtables.derived.base.txt, stored by FUN_00c92fd0 FUN_00c930e0), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00c930e0 tears them
 * down (the counted references at +0x30, +0x28), the others where its
 * constructor FUN_00c92fd0 sets them. 0x50 bytes (`mov edi, 0x50` before
 * operator new in its creator FUN_00c92e70). */
class Object016b8a80 : public Object016b9108 /* derived name */
{
  public:
    Object016b8a80(const Name &name); /* FUN_00c92fd0 */
    virtual ~Object016b8a80();

  private:
    u8 unknown24[0x4];
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held28;
    /* +0x30: a counted reference another thread may replace, set by the
     * constructor by compare-and-swap (`lock cmpxchg [r14+0x30], rcx`),
     * released by the destructor (the pointer cleared, `cmp dword [r+8],
     * 0xdeadc0de`, the count dropped) */
    AtomicRef0045c470<Object016b9108> held30;
    u8 unknown38[0x8];
    /* +0x40: (1.0, 1.0, 0, 0) from the constructor, one aligned store
     * (`vmovaps [r14+0x40]`); not traced */
    Float4A unknown40;
};

#endif
