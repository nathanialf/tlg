/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback, the first word of the 16-byte record at 0x16b3518
 * (its second word null): looks the object at 0x57d6d38 up through
 * FUN_002a45c0, with 1, in the object the pointer at +0x28 holds (when there
 * is one) and, for a record found, passes the objects at 0x57d6cf4 and
 * 0x57d6b88 and the record's member at +0x58 to FUN_004a6bf0, a tail call.
 * The objects' and the records' types and the callees' results are not
 * traced; the callback's signature is taken from its body. */
struct Object057d6d38; /* derived name */
struct Object057d6cf4; /* derived name */
struct Object057d6b88; /* derived name */
struct Owner002a45c0;  /* derived name */

struct Record002a45c0 /* derived name */
{
    u8 unknown0[0x58];
    u8 unknown58[8]; /* +0x58: the member passed on */
};

struct Object00abec40 /* derived name */
{
    u8 unknown0[0x28];
    Owner002a45c0 *unknown28; /* +0x28 */
};

extern Object057d6d38 D_57d6d38;
extern Object057d6cf4 D_57d6cf4;
extern Object057d6b88 D_57d6b88;

Record002a45c0 *FUN_002a45c0(Owner002a45c0 *owner, const Object057d6d38 *key,
                             int unknown2);                                      /* derived name */
void FUN_004a6bf0(Object057d6cf4 *target, Object057d6b88 *source, void *member); /* derived name */

void FUN_00abec40(const Object00abec40 *self) /* derived name */
{
    if (!self->unknown28)
        return;
    Record002a45c0 *record = FUN_002a45c0(self->unknown28, &D_57d6d38, 1);
    if (record)
        FUN_004a6bf0(&D_57d6cf4, &D_57d6b88, record->unknown58);
}
