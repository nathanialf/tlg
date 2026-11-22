/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* The render library's utilities as this unit includes them, from props
 * (0x15b8147, 0x15b8188). */
#define RENDER_UTIL_DIR /* derived name */                                                         \
    "D:\\trico\\engine\\anzu\\engine_src\\props\\..\\render/ps4/util/"

#include "tlg_game_object013bb3f0.h"

/* derived name: one taken off the count; the last wakes every waiter */
void FUN_013bb3f0(Object013bb3f0 *self)
{
    if (__sync_fetch_and_sub(&self->count, 1) == 1) {
        self->mutex.Lock();
        self->conditionVariable.Broadcast();
        self->mutex.Unlock();
    }
}
