/* src/include/tlg_game_object016d06d0.h: the class whose vtable is at
 * 0x16d06d0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D06D0_H
#define TLG_GAME_OBJECT016D06D0_H

#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d06d0
 * (config/vtables.derived.base.txt, stored by FUN_00c24000 FUN_013a2770 FUN_013a2840), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_013a2770 tears them down
 * (the Name at +0x24, the records at +0x50, +0x38); the rest are not traced. */
class Object016d06d0 : public Object016b9108 /* derived name */
{
  public:
    Object016d06d0(const Name &name); /* FUN_00c24000 */
    virtual ~Object016d06d0();

  private:
    Name name24;   /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    int unknown28; /* +0x28: zero from the constructor's body; not traced */
    u8 unknown2c[0x4];
    int unknown30; /* +0x30: zero from the constructor's body, before +0x28; not traced */
    u8 unknown34[0x4];
    /* +0x38: an array of references with its lock (+0x4c), emptied by the
     * constructor with a capacity of 0, torn down by the destructor (`lea
     * rdi, [rbx+0x38]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array38;
    /* +0x50: the same (its lock at +0x64), emptied after the first, torn
     * down by the destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array50;
    int unknown68; /* +0x68: zero from the constructor's body, last; not traced */
    u8 unknown6c[0x4];
};

#endif
