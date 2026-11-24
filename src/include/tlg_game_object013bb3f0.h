/* src/include/tlg_game_object013bb3f0.h: a count waited on under a mutex
 * (FUN_013baf50 waits for it to reach zero, FUN_013bb3f0 takes one off).
 * The including unit defines RENDER_UTIL_DIR (tlg_game_render_mutex.h).
 * derived names throughout. */
#ifndef TLG_GAME_OBJECT013BB3F0_H
#define TLG_GAME_OBJECT013BB3F0_H

#include "tlg_types.h"

#include "tlg_game_render_mutex.h"

struct Object013bb3f0 {                  /* derived name */
    ConditionVariable conditionVariable; /* +0x0 */
    Mutex mutex;                         /* +0x10 */
    /* +0x20: taken down atomically by other threads; volatile: the
     * destructor of Object016c81c0 spins on it (0xd687e0) */
    volatile int count;
};

void FUN_013baf50(Object013bb3f0 *self); /* derived name */
void FUN_013bb3f0(Object013bb3f0 *self); /* derived name */

#endif
