/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a thread's setup with a memory router (called at 0x8f5cc
 * after the floating-point control word is set): the router becomes the
 * thread's, then the thread's block is made; always a success. */
hkResult FUN_00009a60(hkMemoryRouter *router) /* derived name */
{
    FUN_0000bb40(router);
    FUN_014aff00();
    return HK_SUCCESS;
}
