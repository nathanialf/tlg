/* src/include/tlg_game_object016ad6d8.h: the class whose vtable is at
 * 0x16ad6d8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD6D8_H
#define TLG_GAME_OBJECT016AD6D8_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad6d8
 * (config/vtables.derived.base.txt, stored by FUN_00794290 FUN_00794380),
 * derived from Object00774560: slots 2 to 22 are the base's or override
 * them. 0x110 bytes (`mov edi, 0x110` before operator new in its creator
 * FUN_00794130). Its own fields are traced where its constructor FUN_00794290 sets
 * them and its destructor FUN_00794380 tears them down. The destructor is
 * the class's key function (leaf_00794380.cpp), so that unit emits the
 * vtable. */
class Object016ad6d8 : public Object00774560 /* derived name */
{
  public:
    Object016ad6d8(const Name &name); /* FUN_00794290 */
    virtual ~Object016ad6d8();        /* FUN_00794380 */

  private:
    u8 unknowne8[0x14];
    Name
        namefc; /* +0xfc: set by the constructor, released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    /* +0x100: a counted reference, empty from the constructor, released by
     * the destructor (the pointer cleared, `cmp dword [r+8], 0xdeadc0de`, the
     * count dropped) */
    Ref00503fb0<Node00503fb0> held100;
    u8 unknown108[0x8];
};

#endif
