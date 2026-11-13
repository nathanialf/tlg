/* src/include/tlg_game_object0134f620.h: the array of counted references
 * that 0x134f620 tears down, a member of many game classes (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT0134F620_H
#define TLG_GAME_OBJECT0134F620_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived name: the record is the game's growable array (tlg_game_array.h)
 * of counted references (tlg_game_node.h's Ref00503fb0), 0x18 bytes: the
 * block at +0x0, the count at +0x8, the capacity at +0xc, the index of its
 * first block's owner at +0x10. Its destructor is 0x134f620 (the classes
 * that hold it call it where a member's destructor runs, `lea rdi,
 * [rbx+X]; call 0x134f620`, 683 call sites): each reference released first
 * to last, the block and the count read again at each one (`mov rax, [r14];
 * mov ebx, ebx; mov r15, [rax+rbx*8]` ... `inc ebx; cmp ebx, [r14+8]; jb`),
 * then the block released (`movzx ecx, byte [rax-0x10]; cmp ecx, 0xa`):
 * the array's destructor over that element. 0x138c8d0 is the array's
 * clear(unsigned) over it: the same releases, the count cleared, the block
 * reallocated to the argument's capacity through the owner at +0x10 (`mov
 * ecx, [r15+0x10]` ... `mov rdi, [rax+rcx*8]`). */
typedef Array05943280<Ref00503fb0<Node00503fb0>> Object0134f620; /* derived name */

#endif
