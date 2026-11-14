/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_sce_audio3d.h"
#include "tlg_sce_kernel.h"
#include "tlg_types.h"

/* derived names: a thread's entry whose address FUN_00ec4540 takes (lea at
 * 0xec5624): until the bool at +0x40 of its argument is set, it waits for bit
 * 0 of the event flag the handle at 0x5a8dfb0 holds and, when the 3D audio
 * port at 0x179ef90 is open (not -1), pushes it (blocking); returns null.
 * The argument's type is not traced. */
struct Thread00ecc810 { /* derived name */
    u8 unknown0[0x40];
    bool quit; /* derived name */
};

extern SceKernelEventFlag D_5a8dfb0;
extern unsigned int D_179ef90; /* derived name: the port, -1 when closed */

void *FUN_00ecc810(void *argument) /* derived name */
{
    Thread00ecc810 *thread = static_cast<Thread00ecc810 *>(argument);
    while (!thread->quit) {
        sceKernelWaitEventFlag(D_5a8dfb0, 1, 0x11, 0, 0);
        if (D_179ef90 != 0xffffffffu)
            sceAudio3dPortPush(D_179ef90, 1);
    }
    return 0;
}
