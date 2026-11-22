/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the 32-byte element FUN_00905c40 appends (called at
 * 0x904007, 0x904271, 0x904422 and 0x904565): two counted references, then
 * a pointer and an int copied as one block (`mov ecx, [r14+0x18]` before
 * `mov rcx, [r14+0x10]`). The fields' use is not traced. */
struct Element00905c40 {              /* derived name */
    Ref00503fb0<Object016b9108> ref0; /* +0x0 */
    Ref00503fb0<Object016b9108> ref8; /* +0x8 */
    void *unknown10;                  /* +0x10 */
    int unknown18;                    /* +0x18 */
};

/* FUN_00905c40 */
template void Array05943280<Element00905c40>::push(const Element00905c40 &);
