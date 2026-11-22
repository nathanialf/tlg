/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* The render library's utilities as this unit includes them, from props
 * (0x15b8147, 0x15b8188). */
#define RENDER_UTIL_DIR /* derived name */                                                         \
    "D:\\trico\\engine\\anzu\\engine_src\\props\\..\\render/ps4/util/"

#include "tlg_game_object013bb3f0.h"

/* derived name: a wait, while the count is above zero, for the last one to
 * be taken off */
void FUN_013baf50(Object013bb3f0 *self)
{
    if (self->count > 0) {
        self->mutex.Lock();
        while (self->count > 0)
            self->conditionVariable.Wait(self->mutex);
        self->mutex.Unlock();
    }
}
