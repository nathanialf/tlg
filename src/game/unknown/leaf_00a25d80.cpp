/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16b1c18
 * (config/vtables.derived.base.txt, stored by FUN_00a1cfe0 FUN_00a25d80), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00a25d80 tears them
 * down (the counted references at +0x38, +0x30, +0x28, the block at +0x40); the rest are not traced. */
class Object016b1c18 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b1c18();

  private:
    u8 unknown24[0x4];
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held28;
    /* +0x30: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held30;
    /* +0x38: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held38;
    /* +0x40: an owned block, released by the destructor (`mov rax, [rbx+0x40]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block40;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00a25fe0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b1c18::~Object016b1c18() {}
