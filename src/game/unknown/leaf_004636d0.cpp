/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: an object with a pointer at +0xd8, a name at +0xe0 and a
 * counted reference at +0xe8, exchanged (called at 0x432165 and
 * 0x463660); the rest not traced */
struct Object004636d0 /* derived name */
{
    u8 unknown0[0xd8];
    void *unknownd8;                          /* +0xd8 */
    Name namee0;                              /* +0xe0 */
    AtomicRef0045c470<Object016b9108> helde8; /* +0xe8 */
};

/* derived name: the three emptied in order, the reference by
 * compare-and-swap */
void FUN_004636d0(Object004636d0 *object)
{
    object->unknownd8 = 0;
    object->namee0.release();
    object->helde8.clear();
}
