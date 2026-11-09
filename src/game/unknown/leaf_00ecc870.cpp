/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a thread's entry: calls the function pointer at +0x30 of the
 * record its argument points to and returns null. FUN_00ec4540 passes its
 * address (lea at 0xec56fd) to scePthreadCreate with the thread name
 * "sndx_audio3d_out_thread", the record as the argument and its first field as
 * the thread handle. Whether the function at +0x30 takes the record is not
 * traced (rdi still holds it at the call); it is written taking it. */
struct Thread00ecc870 { /* derived name */
    u8 unknown0[0x30];  /* the thread handle at +0x0 */
    void (*run)(Thread00ecc870 *thread);
};

void *FUN_00ecc870(void *argument) /* derived name */
{
    Thread00ecc870 *thread = static_cast<Thread00ecc870 *>(argument);
    thread->run(thread);
    return 0;
}
