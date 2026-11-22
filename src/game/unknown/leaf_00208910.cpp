/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: two 16-byte aligned points (FUN_00206df0 builds them
 * with w 1 at +0x270 and +0x280 of its object before the append at
 * 0x206ed0), each copied lane by lane: the element copied as
 * eight 4-byte moves, the block aligned 16 */
struct Segment00208910 { /* derived name */
    Float4A start;       /* +0x0 */
    Float4A end;         /* +0x10 */
};

/* FUN_00208910: the append, called at 0x206ed0, 0x207770 and 0x207f67 on
 * the array at +0x10 of the object at +0x260 */
template void Array05943280<Segment00208910>::push(const Segment00208910 &);
