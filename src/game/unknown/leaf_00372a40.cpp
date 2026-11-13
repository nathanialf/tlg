/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16a8c38
 * (config/vtables.derived.base.txt, stored by FUN_003720d0 FUN_00372a40), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00372a40 tears them
 * down (the counted references at +0x688, +0x5d8, +0x528, +0x478, +0x368, +0x2b8, +0x208, +0x158, +0x78, +0x70, +0x68, +0x60, +0x58, the Name at +0x3d0, the block at +0x98); the rest are not traced. */
class Object016a8c38 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a8c38();

  private:
    u8 unknown24[0x34];
    /* +0x58: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held58;
    /* +0x60: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held60;
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held68;
    /* +0x70: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held70;
    /* +0x78: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held78;
    u8 unknown80[0x18];
    /* +0x98: an owned block, released by the destructor (`mov rax, [rbx+0x98]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block98;
    u8 unknowna0[0xb8];
    /* +0x158: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held158;
    u8 unknown160[0xa8];
    /* +0x208: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held208;
    u8 unknown210[0xa8];
    /* +0x2b8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held2b8;
    u8 unknown2c0[0xa8];
    /* +0x368: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held368;
    u8 unknown370[0x60];
    Name name3d0; /* +0x3d0: released by the destructor (`mov eax, [rbx+0x3d0]; shl 5`) */
    u8 unknown3d4[0xa4];
    /* +0x478: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held478;
    u8 unknown480[0xa8];
    /* +0x528: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held528;
    u8 unknown530[0xa8];
    /* +0x5d8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held5d8;
    u8 unknown5e0[0xa8];
    /* +0x688: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held688;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_003731e0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a8c38::~Object016a8c38() {}
