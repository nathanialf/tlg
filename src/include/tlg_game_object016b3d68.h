/* src/include/tlg_game_object016b3d68.h: the class whose vtable is at
 * 0x16b3d68 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B3D68_H
#define TLG_GAME_OBJECT016B3D68_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b3d68
 * (config/vtables.derived.base.txt, stored by FUN_00ae7880 FUN_00ae79b0), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00ae79b0 tears them
 * down (the counted reference at +0x28, the Name at +0x24); the rest are not traced. */
class Object016b3d68 : public Object016b9108 /* derived name */
{
  public:
    Object016b3d68(const Name &name); /* FUN_00ae7880 */
    virtual ~Object016b3d68();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped); the
     * constructor sets it by exchange (`lock cmpxchg` at 0xae78f6) */
    AtomicRef0045c470<Node00503fb0> held28;
};

#endif
