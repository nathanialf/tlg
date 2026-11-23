/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the scene node FUN_00516350 resets, as far as the fields
 * it touches: values at +0x270, +0x278, +0x2a0, +0x348 and +0x34c cleared
 * and the child at +0x290, read before the lock is taken (`mov r14,
 * [rbx+0x290]` before `call 0xd8f040`). The class is the scene node's (its
 * slot 6 takes the child out, `call [rax+0x30]`). */
struct Part00516350 : Object016b85e0 { /* derived name */
    u8 unknown238[0x38];
    void *unknown270; /* +0x270 */
    int unknown278;   /* +0x278 */
    u8 unknown27c[0x14];
    Object016b9108 *child290; /* +0x290 */
    u8 unknown298[0x8];
    void *unknown2a0; /* +0x2a0 */
    u8 unknown2a8[0xa0];
    int unknown348; /* +0x348 */
    int unknown34c; /* +0x34c */
};

void FUN_005154c0(Part00516350 *part); /* derived name */

/* derived name: the part reset: its values cleared, FUN_005154c0 run over
 * it and its child taken out under the world's write lock, held by a
 * WorldWriteLock05938c40 (the unlock at the end is a call the function
 * returns from, 0x516427) */
void FUN_00516350(Part00516350 *part) /* derived name */
{
    part->unknown270 = 0;
    part->unknown278 = 0;
    part->unknown348 = 0;
    part->unknown34c = 0;
    part->unknown2a0 = 0;
    FUN_005154c0(part);
    Object016b9108 *child = part->child290;
    WorldWriteLock05938c40 lock;
    part->removeChild(child);
}
