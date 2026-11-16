/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: the function at 0x16bb290, beside FUN_00daba20 (0x16bb288)
 * in the same table: declares the script's implicit "arg" parameter of a
 * vararg function, as Lua 5.1's parser does under LUA_COMPAT_VARARG: the
 * name made through FUN_00dd0a60 (the string "arg" and its length 3, with
 * the field at +0x1a8 of the object the owner at +0x8 holds at its +0x10 and
 * the owner), passed to FUN_00daba60 with the count at +0xf60 of the record
 * at +0x7dc8, -1 and 0; the count incremented and the byte at +0xf58 set to
 * 7 (Lua's VARARG_HASARG | VARARG_NEEDSARG | VARARG_ISVARARG). The types
 * are not traced. */
struct Table00dabe70; /* derived name */
struct Entry00dabe70; /* derived name */

struct Holder00dabe70 { /* derived name */
    u8 unknown0[0x1a8];
    Table00dabe70 *unknown1a8; /* type not traced; its address is passed */
};

struct Owner00dabe70 { /* derived name */
    u8 unknown0[0x10];
    Holder00dabe70 *unknown10;
};

struct Record00dabe70_7dc8 { /* derived name */
    u8 unknown0[0xf58];
    u8 unknownF58; /* +0xf58 */
    u8 unknownF59[7];
    int unknownF60; /* +0xf60 */
};

struct Object00dabe70 { /* derived name */
    u8 unknown0[0x8];
    Owner00dabe70 *unknown8;
    u8 unknown10[0x7dc8 - 0x10];
    Record00dabe70_7dc8 *unknown7dc8; /* +0x7dc8 */
};

Entry00dabe70 *FUN_00dd0a60(Table00dabe70 **table, Owner00dabe70 *owner, const char *name,
                            size_t length); /* derived name */
void FUN_00daba60(Object00dabe70 *self, Entry00dabe70 *name, int count, int limit,
                  int flag); /* derived name */

void FUN_00dabe70(Object00dabe70 *self) /* derived name */
{
    int count = self->unknown7dc8->unknownF60;
    Owner00dabe70 *owner = self->unknown8;
    FUN_00daba60(self, FUN_00dd0a60(&owner->unknown10->unknown1a8, owner, "arg", 3), count, -1, 0);
    ++self->unknown7dc8->unknownF60;
    self->unknown7dc8->unknownF58 = 7;
}
