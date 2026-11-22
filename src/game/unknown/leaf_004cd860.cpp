/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: the element of an array appended to by FUN_004bcc80 (0x4bccb3, 0x4bcd96, 0x4bcdcd) and FUN_004c1910 (0x4c4a12, 0x4c4a21, 0x4c55b6):
 * one 16-byte aligned point copied lane by lane; the fields are not traced */
struct Point004cd860 { /* derived name */
    Float4A value;     /* +0x0 */
};

/* FUN_004cd860: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Point004cd860>::push(const Point004cd860 &);
