/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the entry at 0x16c5770 of a table of function pointers:
 * stores four times the product of the two 16-bit values at +0xe560 and
 * +0xe562 of its first argument in the int array at +0x18 of its third, at
 * the index the byte at +0x2 of the 4-byte entry its second argument selects
 * (in the array at +0x0 of the third) less 16. The records' types are not
 * traced. */
struct Entry0132c500 /* derived name */
{
    u8 unknown0[2];
    u8 unknown2; /* +0x2 */
    u8 unknown3;
};

struct Context0132c500 /* derived name */
{
    const Entry0132c500 *unknown0; /* +0x0 */
    u8 unknown8[0x10];
    int *unknown18; /* +0x18 */
};

struct Object0132c500 /* derived name */
{
    u8 unknown0[0xe560];
    u16 unknownE560; /* +0xe560 */
    u16 unknownE562; /* +0xe562 */
};

// NONMATCHING: the base zero-extends the index through a mask in a register
// (`mov ecx, 0xfffffff0; or rcx, 0xf; and rcx, rax`) and loads the entry array
// first; 4.0.0 and the prebuilt 3.8.1 and 3.9.1 give `add eax, -16` alone. The
// source form of the mask is not found.
void FUN_0132c500(const Object0132c500 *self, unsigned index,
                  Context0132c500 *context) /* derived name */
{
    context->unknown18[(unsigned)(context->unknown0[index].unknown2 - 16)] =
        self->unknownE562 * self->unknownE560 * 4;
}
