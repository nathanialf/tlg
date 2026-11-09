/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a thread's entry: calls the function pointer at +0x30 of the
 * record its argument points to and returns null. FUN_00f03a60 passes its
 * address (lea at 0xf05357) to scePthreadCreate with the thread name
 * "sndx_out_thread", the record as the argument and its first field as the
 * thread handle. Whether the function at +0x30 takes the record is not traced
 * (rdi still holds it at the call); it is written taking it. */
struct Thread00f0ed80 { /* derived name */
    u8 unknown0[0x30];  /* the thread handle at +0x0 */
    void (*run)(Thread00f0ed80 *thread);
};

void *FUN_00f0ed80(void *argument) /* derived name */
{
    Thread00f0ed80 *thread = static_cast<Thread00f0ed80 *>(argument);
    thread->run(thread);
    return 0;
}
