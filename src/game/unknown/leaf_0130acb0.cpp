/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "stdlib.h"
#include "tlg_game_object0130acb0.h"
#include "tlg_game_object05adaaa8.h"

/* The destructor walks the object's private data: each entry's own block
 * freed when it has one, the entry handed back to the device, the chain
 * cleared, then the device's count at +0x10090 taken down and JsUnknown's
 * destructor (its report inlined). The destructor is the class's key
 * function, so this file emits the vtable (0x16c3990) and the deleting
 * destructor 0x130adf0. */
Object0130acb0::~Object0130acb0()
{
    PrivateData01306250 *data = privateData20;
    while (data) {
        if (data->unknown2)
            free(data->unknown8);
        PrivateData01306250 *next = data->next.GetPointer();
        D_5adaaa8->DeallocatePrivateData(data);
        data = next;
    }
    privateData20 = nullptr;
    __sync_fetch_and_sub(&D_5adaaa8->unknown10090, 1);
}
