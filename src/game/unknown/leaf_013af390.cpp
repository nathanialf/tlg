/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_element013af390.h"
#include "tlg_types.h"

/* derived names: slot 6 of the vtable at 0x16d1c38 (its pointer at
 * 0x16d1c78): the array it is given resized to the count it is given, each
 * element ten cleared words (tlg_game_element013af390.h). The object is not
 * read. */
struct Object013af390; /* derived name */

void FUN_013af390(Object013af390 *, Array05943280<Element013af390> *array,
                  unsigned size) /* derived name */
{
    array->resize(size);
}
