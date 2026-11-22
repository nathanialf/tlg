/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* The render library's utilities as this unit includes them, from props
 * (0x15b8147, 0x15b8188). */
#define RENDER_UTIL_DIR /* derived name */                                                         \
    "D:\\trico\\engine\\anzu\\engine_src\\props\\..\\render/ps4/util/"

#include "tlg_game_render_mutex.h"

/* derived names: the second static mutex and condition variable (0x58b6020,
 * 0x58b6030; destroyed by 0x139ddf0 and 0x139ded0) and the flag at 0x5835fad
 * whose holder waits once. */
extern Mutex D_58b6020;
extern ConditionVariable D_58b6030;
extern bool D_5835fad;

/* derived name: one wait on the second pair while the flag is set */
void FUN_00b96ef0()
{
    D_58b6020.Lock();
    if (D_5835fad)
        D_58b6030.Wait(D_58b6020);
    D_58b6020.Unlock();
}
