/* src/include/tlg_game_object016a7e28.h: the class whose vtable is at
 * 0x16a7e28 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7E28_H
#define TLG_GAME_OBJECT016A7E28_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7e28
 * (config/vtables.derived.base.txt, stored by FUN_002aa2a0 FUN_002aa490), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_002aa490 tears them
 * down (the counted references at +0x68, +0x48, the records at +0x50, +0x30); the rest are not traced. */
class Object016a7e28 : public Object016b9108 /* derived name */
{
  public:
    Object016a7e28(const Name &name); /* FUN_002aa2a0 */
    virtual ~Object016a7e28();

  private:
    int unknown24; /* +0x24: zero from the constructor's body; not traced */
    int unknown28; /* +0x28: zero from the constructor's body; not traced */
    u8 unknown2c[0x4];
    /* +0x30: an array of references with its lock (the word at +0x44 stored
     * apart from the clears around it), torn down by the destructor (`lea
     * rdi, [rbx+0x30]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array30;
    /* +0x48: a counted reference another thread may replace, emptied by
     * compare-and-swap by the constructor, released by the destructor (the
     * pointer cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    AtomicRef0045c470<Object016b9108> held48;
    /* +0x50: the same kind of array (its lock at +0x64), torn down by the
     * destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array50;
    /* +0x68: a counted reference another thread may replace, emptied by
     * compare-and-swap by the constructor, released by the destructor (the
     * pointer cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    AtomicRef0045c470<Object016b9108> held68;
};

#endif
