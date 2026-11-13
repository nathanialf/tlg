/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16a7c38
 * (config/vtables.derived.base.txt, stored by FUN_002a2460 FUN_002a2a00), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_002a2a00 tears them
 * down (the counted references at +0x100, +0x68, +0x38, the Names at +0x60, +0x44, +0x40, +0x34, the blocks at +0x120, +0x108, +0x78); the rest are not traced. */
class Object016a7c38 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a7c38();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x10];
    Name name34; /* +0x34: released by the destructor (`mov eax, [rbx+0x34]; shl 5`) */
    /* +0x38: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held38;
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    Name name44; /* +0x44: released by the destructor (`mov eax, [rbx+0x44]; shl 5`) */
    u8 unknown48[0x18];
    Name name60; /* +0x60: released by the destructor (`mov eax, [rbx+0x60]; shl 5`) */
    u8 unknown64[0x4];
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held68;
    u8 unknown70[0x8];
    /* +0x78: an owned block, released by the destructor (`mov rax, [rbx+0x78]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block78;
    u8 unknown80[0x80];
    /* +0x100: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held100;
    /* +0x108: an owned block, released by the destructor (`mov rax, [rbx+0x108]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block108;
    u8 unknown110[0x10];
    /* +0x120: an owned block, released by the destructor (`mov rax, [rbx+0x120]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block120;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_002a2d90, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a7c38::~Object016a7c38() {}
