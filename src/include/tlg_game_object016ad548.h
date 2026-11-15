/* src/include/tlg_game_object016ad548.h: the class whose vtable is at
 * 0x16ad548 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD548_H
#define TLG_GAME_OBJECT016AD548_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad548
 * (config/vtables.derived.base.txt, stored by FUN_0078de30 FUN_0078e010), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0078e010 tears them
 * down (the counted reference at +0x108, the Names at +0x138, +0xfc); the rest are not traced. */
class Object016ad548 : public Object00774560 /* derived name */
{
  public:
    Object016ad548(const Name &name); /* FUN_0078de30 */
    virtual ~Object016ad548();

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    u8 unknown100[0x8];
    /* +0x108: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held108;
    u8 unknown110[0x28];
    Name name138; /* +0x138: released by the destructor (`mov eax, [rbx+0x138]; shl 5`) */
};

#endif
