/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a thread's quit, the counterpart of FUN_00009a60 (called at
 * 0x8f609 and by the game at 0xe99468): the thread's block gives its buffer
 * back, then the thread leaves its router; always a success. */
hkResult FUN_00009a80() /* derived name */
{
    if (D_16dc078) {
        FUN_0000ead0(D_16dc078);
    }
    if (D_16dc070) {
        FUN_0000bb40(0);
    }
    return HK_SUCCESS;
}
