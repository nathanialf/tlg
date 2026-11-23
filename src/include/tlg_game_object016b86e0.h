/* src/include/tlg_game_object016b86e0.h: a pad's record (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B86E0_H
#define TLG_GAME_OBJECT016B86E0_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object01367090.h"

/* derived names: an element of the pad record's array, 24 bytes: a pair of
 * counted references and 8 bytes not traced (the destructor runs
 * FUN_01367090 on each element, `lea rax, [rax + rax*2]; lea rdi, [rcx +
 * rax*8]`) */
struct Record016b86e0 /* derived name */
{
    Object01367090 pair; /* +0x0 */
    u8 unknown10[8];
};

/* derived name: the block of 0x78 bytes the pad record owns at +0x10,
 * zeroed by the creator after the user is read. Not traced. */
struct State016b86e0 /* derived name */
{
    u8 unknown0[0x78];
};

/* derived names: the record of a pad, 0x50 bytes, whose vtable at 0x16b86e0
 * holds only its two destructors (FUN_00c66230, FUN_00c662e0). The giant
 * FUN_00c32940 (FUN_00cff180, slot 17 of the vtable at 0x16b9cb0, calls it
 * on its object) creates one and keeps it at +0x98 of that object (the
 * script functions of leaf_00c87690.cpp read a pad handle at +0x20 of a
 * record at +0x98 of the object at 0x5938c40: the same record by its
 * fields, not proven to be this one): an int at +0x8 from its own object's +0xf70 record
 * (+0x2c), 1 at +0xc, a new zeroed block at +0x10, the initial user at
 * +0x1c (sceUserServiceGetInitialUser), no handle at +0x20 and an empty
 * locked array at +0x28. The destructor closes an open handle, deletes the
 * block, then the array's elements and block go. */
class Object016b86e0 /* derived name */
{
  public:
    virtual ~Object016b86e0();

    int unknown8;         /* +0x8 */
    int unknownc;         /* +0xc: 1 when created */
    State016b86e0 *state; /* +0x10 */
    int unknown18;        /* +0x18: 0 when created */
    int user;             /* +0x1c */
    int handle;           /* +0x20: the pad library's, open when positive */
    u8 pad24[4];
    Array01343a80<Record016b86e0> records; /* +0x28 */
    u8 unknown40[0x10];
};

#endif
