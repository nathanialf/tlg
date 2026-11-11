/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 1 of the vtables at 0x16d5850 and 0x16d5878 (their
 * pointers at 0x16d5868 and 0x16d5890; slot 0 FUN_0140b680), stored by
 * FUN_010b0530, FUN_010b1800, FUN_014068b0 and FUN_01406b30: copies the
 * 32-byte entries (two vectors each, the entry's assignment copying one
 * vector at a time) of the array at +0x48 to
 * the array at +0x30, as many as the unsigned int at +0x60 counts (an
 * unsigned counter, the arrays' accessor taking an int index: sign-extended
 * each pass; both pointers reloaded each pass). The arrays' other fields are
 * not traced. Class and method unknown. */
struct Entry01408ad0 /* derived name */
{
    Vec4 unknown0;  /* +0x0 */
    Vec4 unknown10; /* +0x10 */

    Entry01408ad0 &operator=(const Entry01408ad0 &other)
    {
        unknown0 = other.unknown0;
        unknown10 = other.unknown10;
        return *this;
    }
};

struct Array01408ad0 /* derived name */
{
    Entry01408ad0 *data; /* derived name */

    Entry01408ad0 &operator[](int index) const
    {
        return data[index];
    }
};

struct Object01408ad0 /* derived name */
{
    u8 unknown0[0x30];
    Array01408ad0 unknown30; /* +0x30 */
    u8 unknown38[0x10];
    Array01408ad0 unknown48; /* +0x48 */
    u8 unknown50[0x10];
    unsigned unknown60; /* +0x60: the count */
};

// NONMATCHING: greedy's assignment: the same 17 instructions; the base keeps the
// source pointer, the destination and the offset in rsi, rdx and rcx, where this
// has rdx, rcx and rsi.
void FUN_01408ad0(Object01408ad0 *self) /* derived name */
{
    for (unsigned i = 0; i < self->unknown60; i++)
        self->unknown30[i] = self->unknown48[i];
}
