/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: called by slots 5 and 7 of the vtable at 0x16b38c0
 * (FUN_00acc450, FUN_00accde0) on their object: clears the byte at +0x4a1
 * of the object the owner at +0x8 points to; then, when its byte at +0x20
 * is set: when its byte at +0x4d is set too, looks the name at 0x57d6d38 up
 * through FUN_002a45c0, with 1, in the owner's object at +0x28 (when there
 * is one) and, for a record found, hands the names at 0x57d6d4c and
 * 0x57d6b70 and the record's name at +0x58 to FUN_004a6bf0, then clears the
 * byte at +0x4d; clears the byte at +0x20, sets the int at +0x294 of the
 * owner's object at +0xd68 as FUN_00ac0160 does and, when its int at +0x44
 * is 2, sets it to 3 and the int at +0x48 to 0. The fields' meanings are
 * not traced. */
struct Owner002a45c0; /* derived name */

struct Record002a45c0 /* derived name */
{
    u8 unknown0[0x58];
    Name name; /* +0x58 */
};

struct Object00accd20_390 { /* derived name */
    u8 unknown0[0x2d];
    u8 unknown2d; /* +0x2d: compared with 0 (`cmp byte [rdx+0x2d], 0`) */
};

struct Object00accd20_d68 { /* derived name */
    u8 unknown0[0x294];
    int unknown294;
};

struct Object00accd20_8 { /* derived name */

    /* the int at +0x294 of the object at +0xd68, when there is one: 3 when
     * the object at +0x390 exists with its byte at +0x2d set, else 2 */
    void updateUnknown294() /* derived name */
    {
        if (unknownd68)
            unknownd68->unknown294 = unknown390 && unknown390->unknown2d != 0 ? 3 : 2;
    }

    u8 unknown0[0x28];
    Owner002a45c0 *unknown28; /* +0x28 */
    u8 unknown30[0x360];
    Object00accd20_390 *unknown390;
    u8 unknown398[0x109];
    bool unknown4a1;
    u8 unknown4a2[0x8c6];
    Object00accd20_d68 *unknownd68;
};

struct Object00accd20 { /* derived name */
    u8 unknown0[0x8];
    Object00accd20_8 **unknown8;
    u8 unknown10[0x10];
    bool unknown20;
    u8 unknown21[0x23];
    int unknown44;
    int unknown48;
    bool unknown4c;
    bool unknown4d;
};

extern const Name D_57d6d38; /* derived name: the key looked up */
extern const Name D_57d6d4c; /* derived name */
extern const Name D_57d6b70; /* derived name */

Record002a45c0 *FUN_002a45c0(Owner002a45c0 *owner, const Name *key,
                             int unknown2);                                  /* derived name */
void FUN_004a6bf0(const Name &first, const Name &second, const Name &third); /* derived name */

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 230 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_00accd20(Object00accd20 *self) /* derived name */
{
    (*self->unknown8)->unknown4a1 = false;
    if (!self->unknown20)
        return;
    if (self->unknown4d) {
        if (Owner002a45c0 *owner = (*self->unknown8)->unknown28) {
            if (Record002a45c0 *record = FUN_002a45c0(owner, &D_57d6d38, 1))
                FUN_004a6bf0(D_57d6d4c, record->name, D_57d6b70);
        }
        self->unknown4d = false;
    }
    self->unknown20 = false;
    (*self->unknown8)->updateUnknown294();
    if (self->unknown44 == 2) {
        self->unknown44 = 3;
        self->unknown48 = 0;
    }
}
