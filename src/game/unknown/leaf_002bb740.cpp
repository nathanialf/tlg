/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the element of an array appended to by FUN_002af9d0 (0x2afda5, 0x2afde1):
 * two Names (each count raised before the index is stored) and a pointer; the fields are not traced */
struct Record002bb740 { /* derived name */
    Name name0;         /* +0x0 */
    Name name4;         /* +0x4 */
    void *unknown8;     /* +0x8 */
};

/* FUN_002bb740: the append (the count raised, the block grown when it is
 * full, then the element's copy) */
template void Array05943280<Record002bb740>::push(const Record002bb740 &);
