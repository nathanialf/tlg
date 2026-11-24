/* src/include/tlg_game_record0052d2f0.h: the element of the array FUN_0052c610
 * appends to (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_RECORD0052D2F0_H
#define TLG_GAME_RECORD0052D2F0_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the element of an array appended to by FUN_0052c610
 * (0x52c67f, 0x52c6bc): two Names and two ints copied as one 8-byte move
 * (the block aligned 4); the fields are not traced. Made empty, its 16 bytes
 * zeroed (`vxorps; vmovaps [rbp-0x40]` at 0x52c634), then the names assigned
 * (each index tested before its count is raised: the empty name's
 * assignment) */
struct Record0052d2f0 { /* derived name */

    Record0052d2f0() : unknown8(0), unknownc(0) {}

    Name name0;   /* +0x0 */
    Name name4;   /* +0x4 */
    int unknown8; /* +0x8 */
    int unknownc; /* +0xc */
};

#endif
