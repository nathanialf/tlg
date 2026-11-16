/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_libc.h"

/* derived names: a virtual method (its address is a vtable's word, at
 * 0x16a8820). The part at +0x250, when there is one, gets 16 less bit 1 of
 * its word at +0x100 at its +0x48; then, when the object at +0xc8 of the
 * object at +0x68 of the one the pointer at 0x57c9390 holds has a name at
 * +0xc0 that names a record this thread may use and this object has both
 * pointers at +0x238 and +0x240: the sine of the holder's float at +0xd0
 * times 2.1 (0 without a holder) when either word at +0x28c or +0x290 is
 * set, and, unless the float at +0x288 is negative, the cosine and sine of
 * a quarter turn each way. The classes are not traced. */
struct Part003447b0 { /* derived name */
    u8 unknown0[0x48];
    int unknown48; /* +0x48 */
    u8 unknown4c[0xb4];
    u32 flags100; /* +0x100 */
};

struct Record003447b0 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16; /* +0x16 */
};

struct Named003447b0 { /* derived name */
    u8 unknown0[0xc0];
    Name name; /* +0xc0 */
};

struct Holder003447b0 { /* derived name */
    u8 unknown0[0xc8];
    Named003447b0 *unknownc8; /* +0xc8 */
    float unknownd0;          /* +0xd0 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x68];
    Holder003447b0 *unknown68; /* +0x68 */
};

extern Object057c9390 *D_57c9390;

struct Object003447b0 { /* derived name */
    u8 unknown0[0x238];
    void *unknown238; /* +0x238 */
    void *unknown240; /* +0x240 */
    u8 unknown248[0x8];
    Part003447b0 *part; /* +0x250 */
    u8 unknown258[0x30];
    float unknown288; /* +0x288 */
    int unknown28c;   /* +0x28c */
    int unknown290;   /* +0x290 */
};

/* derived name: whether either word at +0x28c or +0x290 is set (both are
 * read and or-ed, `mov eax, [r14+0x28c]; or eax, [r14+0x290]` at 0x344864:
 * the object is a reference here, so the second read may be made before the
 * first is tested) */
static bool hasCount(const Object003447b0 &object)
{
    return object.unknown290 || object.unknown28c;
}

// NONMATCHING: the last call (the sine of -pi/2) is a tail call here and the
// base keeps it a call with one shared epilogue: TailCallElim at the unit's
// stage did not mark the four calls, so a local's address escaped before
// them, through a call the link removed (probe: the sine passed by const
// reference to an empty function of another unit gives the base's bytes).
void FUN_003447b0(Object003447b0 *self) /* derived name */
{
    if (Part003447b0 *part = self->part)
        part->unknown48 = 16 - ((part->flags100 >> 1) & 1);
    Holder003447b0 *holder = D_57c9390->unknown68;
    Named003447b0 *named = holder->unknownc8;
    if (named && named->name.index != 0) {
        const Record003447b0 *record =
            static_cast<const Record003447b0 *>(D_17ac870[named->name.index].record18);
        if (record && ((record->flags16 & 4) || threadMayUse()) && self->unknown238 &&
            self->unknown240) {
            /* the readers of these sines and cosines were a debug draw
             * compiled out of the retail build; the calls to the C library
             * stay */
            if (hasCount(*self)) {
                float sine = sin(holder ? holder->unknownd0 * 2.1f : 0.0f);
            }
            if (self->unknown288 < 0.0f)
                return;
            float upX = cos(1.57079637f);
            float upY = sin(1.57079637f);
            float downX = cos(-1.57079637f);
            float downY = sin(-1.57079637f);
        }
    }
}
