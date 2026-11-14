/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a thread's entry: calls the function pointer at +0x30 of the
 * record its argument points to and returns null. FUN_00eb45d0 passes its
 * address (lea at 0xeb498e) to scePthreadCreate with the thread name
 * "sndx_stream_schedule_thread", the record as the argument and its first
 * field as the thread handle. Whether the function at +0x30 takes the record
 * is not traced (rdi still holds it at the call); it is written taking it. */
struct Thread00f02000 { /* derived name */
    u8 unknown0[0x30];  /* the thread handle at +0x0 */
    void (*run)(Thread00f02000 *thread);
};

void *FUN_00f02000(void *argument) /* derived name */
{
    Thread00f02000 *thread = static_cast<Thread00f02000 *>(argument);
    thread->run(thread);
    return 0;
}
