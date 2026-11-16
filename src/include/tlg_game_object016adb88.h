/* src/include/tlg_game_object016adb88.h: the class whose vtable is at
 * 0x16adb88 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ADB88_H
#define TLG_GAME_OBJECT016ADB88_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16adb88
 * (config/vtables.derived.base.txt, stored by FUN_0079fb60 FUN_0079fc40), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0079fc40 tears them
 * down (the counted references at +0x108, +0x100, the Name at +0xfc); the rest are not traced.
 * 0x110 bytes (`mov edi, 0x110` before operator new in its creator
 * FUN_0079fa00). */
class Object016adb88 : public Object00774560 /* derived name */
{
  public:
    Object016adb88(const Name &name); /* FUN_0079fb60 */
    virtual ~Object016adb88();

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    /* +0x100: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held100;
    /* +0x108: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held108;
};

#endif
