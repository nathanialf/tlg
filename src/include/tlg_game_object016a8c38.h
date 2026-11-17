/* src/include/tlg_game_object016a8c38.h: the class whose vtable is at 0x16a8c38
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8C38_H
#define TLG_GAME_OBJECT016A8C38_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a8c38
 * (config/vtables.derived.base.txt, stored by FUN_003720d0 FUN_00372a40), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00372a40 tears them
 * down (the counted references at +0x688, +0x5d8, +0x528, +0x478, +0x368, +0x2b8, +0x208, +0x158, +0x78, +0x70, +0x68, +0x60, +0x58, the Name at +0x3d0, the block at +0x98); the rest are not traced.
 * The creator FUN_00371f70 allocates 0x6a0 bytes (`mov edi, 0x6a0` before operator new). */
class Object016a8c38 : public Object016b9108 /* derived name */
{
  public:
    Object016a8c38(const Name &name); /* FUN_003720d0, its row named after it (D15) */
    virtual ~Object016a8c38();

  private:
    u8 unknown24[0x34];
    /* +0x58: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held58;
    /* +0x60: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held60;
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held68;
    /* +0x70: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held70;
    /* +0x78: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held78;
    u8 unknown80[0x18];
    /* +0x98: an owned block, released by the destructor (`mov rax, [rbx+0x98]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block98;
    u8 unknowna0[0xb8];
    /* +0x158: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held158;
    u8 unknown160[0xa8];
    /* +0x208: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held208;
    u8 unknown210[0xa8];
    /* +0x2b8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held2b8;
    u8 unknown2c0[0xa8];
    /* +0x368: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held368;
    u8 unknown370[0x60];
    Name name3d0; /* +0x3d0: released by the destructor (`mov eax, [rbx+0x3d0]; shl 5`) */
    u8 unknown3d4[0xa4];
    /* +0x478: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held478;
    u8 unknown480[0xa8];
    /* +0x528: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held528;
    u8 unknown530[0xa8];
    /* +0x5d8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held5d8;
    u8 unknown5e0[0xa8];
    /* +0x688: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held688;
    u8 unknown690[0x10];
};

#endif
