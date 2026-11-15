/* src/include/tlg_game_object016ad9f8.h: the class whose vtable is at
 * 0x16ad9f8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD9F8_H
#define TLG_GAME_OBJECT016AD9F8_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad9f8
 * (config/vtables.derived.base.txt, stored by FUN_0079c900 FUN_0079cad0), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0079cad0 tears them
 * down (the counted reference at +0x158, the Name at +0xfc); the rest are not traced. */
class Object016ad9f8 : public Object00774560 /* derived name */
{
  public:
    Object016ad9f8(const Name &name); /* FUN_0079c900 */
    virtual ~Object016ad9f8();

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    u8 unknown100[0x58];
    /* +0x158: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held158;
    u8 unknown160[0x10]; /* the rest of the 0x170 bytes the creator allocates; not traced */
};

#endif
