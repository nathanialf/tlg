/* src/include/tlg_game_object0139b6b0.h: five arrays of records that each
 * hold one counted reference, members of game classes (game region;
 * docs/TARGETS.md). Every name here is derived. Each is the game's growable
 * array (tlg_game_array.h) over a record whose only member with a destructor
 * is a counted reference (tlg_game_node.h's Ref00503fb0); the array's
 * destructor is a function of its own in the executable, the same body as
 * 0x134f620's with the element's size and the reference's offset: each
 * reference released first to last, the block and the count read again at
 * each one, then the block released. The other fields of the records are
 * not traced. */
#ifndef TLG_GAME_OBJECT0139B6B0_H
#define TLG_GAME_OBJECT0139B6B0_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* 16 bytes, the reference at +0x8 (0x139b6b0: `shl rax, 4; mov r15,
 * [rcx+rax+8]`) */
struct Entry0139b6b0 /* derived name */
{
    u8 unknown0[0x8];
    Ref00503fb0<Node00503fb0> unknown8; /* +0x8 */
};

typedef Array05943280<Entry0139b6b0> Object0139b6b0; /* derived name */

/* 64 bytes, the reference at +0x38 (0x135f4e0: `shl rax, 6; mov r15,
 * [rcx+rax+0x38]`) */
struct Entry0135f4e0 /* derived name */
{
    u8 unknown0[0x38];
    Ref00503fb0<Node00503fb0> unknown38; /* +0x38 */
};

typedef Array05943280<Entry0135f4e0> Object0135f4e0; /* derived name */

/* 64 bytes, the reference at +0x30 (0x13e9b40: `shl rax, 6; mov r15,
 * [rcx+rax+0x30]`) */
struct Entry013e9b40 /* derived name */
{
    u8 unknown0[0x30];
    Ref00503fb0<Node00503fb0> unknown30; /* +0x30 */
    u8 unknown38[0x8];
};

typedef Array05943280<Entry013e9b40> Object013e9b40; /* derived name */

/* 80 bytes, the reference at +0x48 (0x13e9a00: `lea rcx, [rcx+rcx*4]; shl
 * rcx, 4; mov r15, [rax+rcx+0x48]`) */
struct Entry013e9a00 /* derived name */
{
    u8 unknown0[0x48];
    Ref00503fb0<Node00503fb0> unknown48; /* +0x48 */
};

typedef Array05943280<Entry013e9a00> Object013e9a00; /* derived name */

/* 96 bytes, the reference at +0x58 (0x1347230: `lea rcx, [rcx+rcx*2]; shl
 * rcx, 5; mov r15, [rax+rcx+0x58]`) */
struct Entry01347230 /* derived name */
{
    u8 unknown0[0x58];
    Ref00503fb0<Node00503fb0> unknown58; /* +0x58 */
};

typedef Array05943280<Entry01347230> Object01347230; /* derived name */

#endif
