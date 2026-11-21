/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: a 16-byte entry of an array: a counted reference to an
 * object, then a pointer (the count raised behind the null test and the
 * released mark, `cmp dword [rcx+8], 0xdeadc0de`). Neither is traced
 * further. */
struct Entry00901010 {                  /* derived name */
    Ref00503fb0<Object016b9108> object; /* +0x0 */
    void *value;                        /* +0x8 */
};

/* FUN_00901010: this unit's copy of the array's append over the entries (the
 * block grown by half the count plus one, at most 0x40000 elements a step) */
template void Array05943280<Entry00901010>::push(const Entry00901010 &value);
