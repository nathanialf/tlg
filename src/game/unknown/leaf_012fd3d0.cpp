/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the first byte of the 4-byte value its
 * argument points to is 1, as an int (sete, movzbl). FUN_001ada10 calls it at
 * 0x1adb07 on a stack copy of FUN_012fcae0's 32-bit result and tests eax. The
 * value's type is not traced. Owner and meaning unknown. */
struct Value012fd3d0 { /* derived name: 4 bytes, stored whole by the caller */
    u8 unknown0;
    u8 unknown1[3];
};

int FUN_012fd3d0(const Value012fd3d0 *value) /* derived name */
{
    return value->unknown0 == 1;
}
