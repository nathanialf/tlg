/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointers at +0x0 and +0x28 of the record the
 * pointer at +0xf0 of the object the pointer at 0x5938c40 holds, 1 and that
 * object's float at +0x19c to FUN_00ccabc0, a tail call; slot 5 of the vtable
 * at 0x16d0a90 (its pointer at 0x16d0ac8, stored by FUN_00c3b420), one of the
 * 109 vtables whose slot 0 is the destructor of Object013a6a50 (FUN_013a6a50).
 * The object itself is not read. The record's types and the callee's return
 * type are not traced. */
class Object013a6a50;        /* derived name */
struct Member05938c40_f0_0;  /* derived name */
struct Member05938c40_f0_28; /* derived name */

struct Member05938c40_f0 { /* derived name */
    Member05938c40_f0_0 *unknown0;
    u8 unknown8[0x20];
    Member05938c40_f0_28 *unknown28;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf0];
    Member05938c40_f0 *unknownf0;
    u8 unknownf8[0xa4];
    float unknown19c;
};

extern Object05938c40 *D_5938c40;

void FUN_00ccabc0(Member05938c40_f0_0 *first, Member05938c40_f0_28 *second, int value,
                  float time); /* derived name */

void FUN_013a38b0(Object013a6a50 *) /* derived name */
{
    Object05938c40 *object = D_5938c40;
    FUN_00ccabc0(object->unknownf0->unknown0, object->unknownf0->unknown28, 1, object->unknown19c);
}
