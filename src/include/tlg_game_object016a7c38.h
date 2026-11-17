/* src/include/tlg_game_object016a7c38.h: the class whose vtable is at 0x16a7c38
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7C38_H
#define TLG_GAME_OBJECT016A7C38_H

#include "tlg_game_object01343880.h"
#include "tlg_game_node.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a7c38
 * (config/vtables.derived.base.txt, stored by FUN_002a2460 FUN_002a2a00), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's).
 * Its own fields are traced only where its destructor FUN_002a2a00 tears them
 * down (the counted references at +0x100, +0x68, +0x38, the Names at +0x60, +0x44, +0x40, +0x34, the blocks at +0x120, +0x108, +0x78); the rest are not traced.
 * The creator FUN_002a2300 allocates 0x140 bytes (`mov edi, 0x140` before operator new). */
class Object016a7c38 : public Object01343880 /* derived name */
{
  public:
    Object016a7c38(const Name &name); /* FUN_002a2460, its row named after it (D15) */
    virtual ~Object016a7c38();

  private:
    Name name34; /* +0x34: released by the destructor (`mov eax, [rbx+0x34]; shl 5`) */
    /* +0x38: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held38;
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    Name name44; /* +0x44: released by the destructor (`mov eax, [rbx+0x44]; shl 5`) */
    u8 unknown48[0x18];
    Name name60; /* +0x60: released by the destructor (`mov eax, [rbx+0x60]; shl 5`) */
    u8 unknown64[0x4];
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held68;
    u8 unknown70[0x8];
    /* +0x78: an owned block, released by the destructor (`mov rax, [rbx+0x78]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block78;
    u8 unknown80[0x80];
    /* +0x100: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held100;
    /* +0x108: an owned block, released by the destructor (`mov rax, [rbx+0x108]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block108;
    u8 unknown110[0x10];
    /* +0x120: an owned block, released by the destructor (`mov rax, [rbx+0x120]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block120;
    u8 unknown128[0x18];
};

#endif
