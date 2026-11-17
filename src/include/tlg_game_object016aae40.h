/* src/include/tlg_game_object016aae40.h: the class whose vtable is at 0x16aae40
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AAE40_H
#define TLG_GAME_OBJECT016AAE40_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_value004af700.h"

/* derived names: the value every object of the class starts with, four ints
 * the creator copies member by member (`mov dword; shr rax, 0x20; mov
 * dword` from 0x57da770) */
extern Value004af700 D_57da770;

/* derived names: the class whose vtable is at 0x16aae40
 * (config/vtables.derived.base.txt, stored by its creator FUN_0050b7f0, where
 * its constructor is inlined, and by its complete destructor FUN_0050bf40,
 * leaf_0050bf40.cpp), derived from Object016b9108: its slots 2 to 4 are the
 * base's. 0x70 bytes (`mov edi, 0x70` before operator new in the creator).
 * Its own fields are traced where the creator sets them and the destructor
 * tears them down (the counted reference at +0x60, the Names at +0x48,
 * +0x40, +0x3c, +0x28, +0x24). */
class Object016aae40 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, zero
     * from +0x24 to +0x4c (one 32-byte store and one eight-byte store), then
     * the body: the value at +0x50 copied from D_57da770 */
    Object016aae40(const Name &name)
        : Object016b9108(name), unknown2c(0), unknown30(0), unknown34(0), unknown38(0), unknown44(0)
    {
        unknown50.set(D_57da770);
    }

    virtual ~Object016aae40();

  private:
    Name name24;   /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    Name name28;   /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    int unknown2c; /* +0x2c: 0 from the constructor */
    int unknown30; /* +0x30: 0 from the constructor */
    int unknown34; /* +0x34: 0 from the constructor */
    int unknown38; /* +0x38: 0 from the constructor */
    Name name3c;   /* +0x3c: released by the destructor (`mov eax, [rbx+0x3c]; shl 5`) */
    Name name40;   /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    int unknown44; /* +0x44: 0 from the constructor */
    Name name48;   /* +0x48: released by the destructor (`mov eax, [rbx+0x48]; shl 5`) */
    u8 unknown4c[0x4];
    Value004af700 unknown50; /* +0x50: D_57da770 from the constructor */
    /* +0x60: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held60;
    u8 unknown68[0x8];
};

#endif
