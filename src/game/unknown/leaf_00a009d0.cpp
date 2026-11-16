/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: a 16-byte entry, an int and a counted reference to an
 * object of the root class (copied `mov ecx, [r14]; mov [rax+r15], ecx`,
 * then the reference with its count raised unless released) */
struct Entry00a009d0 {
    int value;                          /* +0x0 */
    Ref00503fb0<Object016b9108> object; /* +0x8 */
};

/* FUN_00a009d0 appends a copy of an entry to the array (tlg_game_array.h's
 * push). Called from 4 sites in 2 functions (FUN_009f9890, FUN_009f9a70). */
void FUN_00a009d0(Array05943280<Entry00a009d0> *array,
                  const Entry00a009d0 &entry) /* derived name */
{
    array->push(entry);
}
