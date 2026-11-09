/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the unsigned 32-bit value at +0xc of its
 * argument is at least the one at +0x30 of the object, as an int (setae,
 * movzbl); slot 8 of the vtable at 0x16b97f8 (its pointer at 0x16b9848), the
 * vtable stored by FUN_00cef230 FUN_00eadb60 FUN_00eb1a20; slot 8 of the
 * vtable at 0x16be768 (its pointer at 0x16be7b8), the vtable stored by
 * FUN_00eadb60; slot 8 of the vtable at 0x16be878 (its pointer at 0x16be8c8),
 * the vtable stored by FUN_00eb1a20; slot 19 of the vtable at 0x16d3578 (its
 * pointer at 0x16d3620), the vtable stored by FUN_00e9a5f0 FUN_00ea53a0
 * FUN_00ea5be0. FUN_00cef250, FUN_00cef260 and FUN_00cef270 (slots 6 to 8)
 * have the same body. Class, argument and method unknown. */
class Object00cef230 /* derived name */
{
  public:
    virtual ~Object00cef230();

    u8 unknown8[0x30 - 8];
    u32 unknown30;
};

struct
    Argument00cef250 { /* derived name: the argument of FUN_00cef250, FUN_00cef260 and FUN_00cef270 */
    u8 unknown0[0xc];
    u32 unknownc;
};

int FUN_00cef270(const Object00cef230 *self, const Argument00cef250 *argument) /* derived name */
{
    return argument->unknownc >= self->unknown30;
}
