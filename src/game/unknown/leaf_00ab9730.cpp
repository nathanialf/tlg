/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c7cb8.h"

/* slot 6 of 0x16c7cb8: with an object held at +0x28, every item its queue
 * gives up (FUN_0134d990, the held object read again for each) handed to
 * slot 7 with the argument; the item's reference dropped at the end */
// NONMATCHING: 73/75: in the loop the base reads the item (`mov rdx, [rbp-0x30]`) before the vtable
// (`mov rax, [rbx]`), the build the other way; the item read into a local first is loaded once after
// each call and kept for the release (worse, 5/77)
void Object016c7cb8::slot6(void *argument)
{
    if (held28.get()) {
        Ref00503fb0<Object016b9108> item;
        while (FUN_0134d990(held28.get(), &item))
            slot7(argument, item.get());
    }
}
