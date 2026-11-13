/* src/include/tlg_game_object00cbdb30.h: the class whose vtable is at 0x16b9190 and whose
 * complete destructor is 0xcbdb30 (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT00CBDB30_H
#define TLG_GAME_OBJECT00CBDB30_H

#include "tlg_game_object00c55550.h"
#include "tlg_game_node.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16b9190
 * (config/vtables.derived.base.txt, the class named for its complete
 * destructor 0xcbdb30 as that row names it, D15; stored by FUN_00cbd730 FUN_00cbdb30 FUN_00d00a40), derived from
 * Object00c55550 (the class whose destructor is 0xc55550): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00cbdb30 tears them
 * down (the counted reference at +0x238, the blocks at +0x290, +0x278, +0x260, +0x248); the rest are not traced. */
class Object00cbdb30 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object00cbdb30();

  private:
    u8 unknown8[0x230];
    /* +0x238: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held238;
    u8 unknown240[0x8];
    /* +0x248: an owned block, released by the destructor (`mov rax, [rbx+0x248]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block248;
    u8 unknown250[0x10];
    /* +0x260: an owned block, released by the destructor (`mov rax, [rbx+0x260]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block260;
    u8 unknown268[0x10];
    /* +0x278: an owned block, released by the destructor (`mov rax, [rbx+0x278]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block278;
    u8 unknown280[0x10];
    /* +0x290: an owned block, released by the destructor (`mov rax, [rbx+0x290]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block290;
};

#endif
