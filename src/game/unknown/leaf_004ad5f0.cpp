/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the bool at +0x1a8 of its second argument.
 * FUN_004acae0 stores its address at 0x57d7528, beside the int at 0x57d7520
 * that holds the result of FUN_013baad0 for the string
 * "Marker.firerange.leave" (its hash from FUN_013bad90, its length 22 in edx),
 * the seventh of the 15 such 16-byte pairs from 0x57d74c0 that FUN_004acae0
 * fills and that 0x4ac53f walks, inserting each missing one into the map at
 * +0x48 of its record through FUN_004acf60. The handler's call is not traced:
 * its first argument is unused, its type unknown. Owner and meaning unknown. */
struct Object004ad5f0 { /* derived name */
    u8 unknown0[0x1a8];
    bool unknown1a8;
};

void FUN_004ad5f0(void *, Object004ad5f0 *owner) /* derived name */
{
    owner->unknown1a8 = false;
}
