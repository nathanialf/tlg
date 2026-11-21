/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_types.h"

/* derived names: slot 6 of the vtable at 0x16d1c38 (its pointer at
 * 0x16d1c68): the array it is given resized to the count it is given, each
 * element ten cleared words (40 bytes, aligned to 4: `mov ecx, 4` in the
 * reallocation; the loop's 32-byte and 8-byte zero stores). The object is
 * not read; the element's fields are not traced. */
struct Object013af390; /* derived name */

struct Element013af390 { /* derived name */

    Element013af390()
        : unknown0(0), unknown4(0), unknown8(0), unknownc(0), unknown10(0), unknown14(0),
          unknown18(0), unknown1c(0), unknown20(0), unknown24(0)
    {
    }

    u32 unknown0;
    u32 unknown4;
    u32 unknown8;
    u32 unknownc;
    u32 unknown10;
    u32 unknown14;
    u32 unknown18;
    u32 unknown1c;
    u32 unknown20;
    u32 unknown24;
};

void FUN_013af390(Object013af390 *, Array05943280<Element013af390> *array,
                  unsigned size) /* derived name */
{
    array->resize(size);
}
