/* src/include/tlg_game_object016ad930.h: the class whose vtable is at
 * 0x16ad930 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD930_H
#define TLG_GAME_OBJECT016AD930_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad930
 * (config/vtables.derived.base.txt, stored by FUN_0079ab40 FUN_0079adb0), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0079adb0 tears them
 * down (the counted references at +0x138, +0x108, the Name at +0xfc); the rest are not traced. */
class Object016ad930 : public Object00774560 /* derived name */
{
  public:
    Object016ad930(const Name &name); /* FUN_0079ab40 */
    virtual ~Object016ad930();

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    u8 unknown100[0x8];
    /* +0x108: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held108;
    u8 unknown110[0x28];
    /* +0x138: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held138;
    u8 unknown140[0x30]; /* the rest of the 0x170 bytes the creator allocates; not traced */
};

#endif
