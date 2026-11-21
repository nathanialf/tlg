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
#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_node.h"

/* 16 bytes, the reference at +0x8 (0x139b6b0: `shl rax, 4; mov r15,
 * [rcx+rax+8]`) */
struct Entry0139b6b0 /* derived name */
{
    u8 unknown0[0x8];
    Ref00503fb0<Object016b9108> unknown8; /* +0x8 */
};

typedef Array05943280<Entry0139b6b0> Object0139b6b0; /* derived name */

/* 16 bytes, a name at +0x0 and the reference at +0x8 (0x13730a0: `shl r13,
 * 4; mov r15, [r12+r13+8]`, then the name at [r12+r13] released after the
 * reference; the arrays of FUN_00882f30, FUN_00885840 and FUN_00886300) */
struct Entry013730a0 /* derived name */
{
    Name name0;                           /* +0x0 */
    Ref00503fb0<Object016b9108> unknown8; /* +0x8 */
};

typedef Array05943280<Entry013730a0> Object013730a0; /* derived name */

/* 160 bytes, a name at +0x0 and the reference at +0x8, its block aligned to
 * 16 (0x72bbc0, the array emptied: `lea r13, [rbx+rbx*4]; shl r13, 5`, the
 * reallocation with 0x10; the arrays of FUN_00729190). The rest is not
 * traced. */
struct Entry0072bbc0 /* derived name */
{
    Name name0;                           /* +0x0 */
    Ref00503fb0<Object016b9108> unknown8; /* +0x8 */
    Float4A unknown10[9];                 /* +0x10 */
};

typedef Array05943280<Entry0072bbc0> Object0072bbc0; /* derived name */

/* 64 bytes, the reference at +0x38 (0x135f4e0: `shl rax, 6; mov r15,
 * [rcx+rax+0x38]`) */
struct Entry0135f4e0 /* derived name */
{
    u8 unknown0[0x20];
    float unknown20; /* +0x20: a value in [0, 1] FUN_0135f640 picks the least of */
    u8 unknown24[0x14];
    Ref00503fb0<Object016b9108> unknown38; /* +0x38 */
};

typedef Array05943280<Entry0135f4e0> Object0135f4e0; /* derived name */

/* 64 bytes, the reference at +0x30 (0x13e9b40: `shl rax, 6; mov r15,
 * [rcx+rax+0x30]`) */
struct Entry013e9b40 /* derived name */
{
    u8 unknown0[0x30];
    Ref00503fb0<Object016b9108> unknown30; /* +0x30 */
    u8 unknown38[0x8];
};

typedef Array05943280<Entry013e9b40> Object013e9b40; /* derived name */

/* 80 bytes, the reference at +0x48 (0x13e9a00: `lea rcx, [rcx+rcx*4]; shl
 * rcx, 4; mov r15, [rax+rcx+0x48]`) */
struct Entry013e9a00 /* derived name */
{
    u8 unknown0[0x48];
    Ref00503fb0<Object016b9108> unknown48; /* +0x48 */
};

typedef Array05943280<Entry013e9a00> Object013e9a00; /* derived name */

/* 96 bytes, the reference at +0x58 (0x1347230: `lea rcx, [rcx+rcx*2]; shl
 * rcx, 5; mov r15, [rax+rcx+0x58]`) */
struct Entry01347230 /* derived name */
{
    u8 unknown0[0x58];
    Ref00503fb0<Object016b9108> unknown58; /* +0x58 */
};

typedef Array05943280<Entry01347230> Object01347230; /* derived name */

#endif
