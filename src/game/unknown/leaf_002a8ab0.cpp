/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a7d48.h"

/* derived name: the constructor (tlg_game_object016a7d48.h): its base
 * Object016b9108 is built from the name passed on, the array at +0x28 starts
 * empty; then the body: the array emptied with a capacity of 0 (`mov dword
 * [rbx+0x30], 0; cmp dword [rbx+0x34], 0; je`), the value at +0x40 and the
 * float at +0x50. */
Object016a7d48::Object016a7d48(const Name &name) : Object016b9108(name)
{
    array28.clear(0);
    unknown40 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    unknown50 = 0.1f;
}
