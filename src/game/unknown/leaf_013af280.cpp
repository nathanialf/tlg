/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_element013af390.h"
#include "tlg_types.h"

/* derived names: slot 4 of the vtable at 0x16d1c38 (its pointer at
 * 0x16d1c68): the array it is given made a copy of the other it is
 * given (tlg_game_element013af390.h). The object is not read. */
struct Object013af280; /* derived name */

// NONMATCHING: 18/80: the base looks the block's owner up with a null default (`xor edi, edi;
// cmp edx, 0xa; jne`, the split of reallocateOwnedBlock in tlg_game_block.h) and copies each
// element word by word (ten 32-bit moves), where the copy here is one 32-byte and one 8-byte move
void FUN_013af280(Object013af280 *, Array05943280<Element013af390> *array,
                  const Array05943280<Element013af390> *other) /* derived name */
{
    *array = *other;
}
