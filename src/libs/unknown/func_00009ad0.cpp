/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The base system's teardown of the singleton list and the threads'
 * monitor streams (0x9720). derived name. */
void FUN_00009720(); /* derived name */

/* Whether the platform's network was brought up for the base system, and
 * the shutdown to run for it (the function pointer the network file
 * provides, FUN_00091c60). derived names. */
extern bool D_57b9b98;
extern void (*D_16dc588)();

/* The base system's quit (derived name; hkBaseSystem::quit by its place
 * after the initialiser 0x98d0): when initialised, the reference counts
 * unlocked, the singletons torn down, the network shut down if it was
 * brought up and has a shutdown, the error and file system instances released, the lock
 * singleton too, then the calling thread's monitor stream and memory
 * router given back. */
hkResult FUN_00009ad0() /* derived name */
{
    if (D_57b80c0) {
        FUN_00006950(0);
        FUN_00009720();
        if (D_57b9b98 && D_16dc588) {
            D_16dc588();
            D_57b9b98 = false;
        }
        if (D_57af768) {
            D_57af768->removeReference();
        }
        D_57af768 = HK_NULL;
        if (D_57b9b70) {
            D_57b9b70->removeReference();
        }
        D_57b9b70 = HK_NULL;
        FUN_000068e0();
        if (ThreadBuffer *stream = D_16dc078) {
            FUN_0000ead0(stream);
        }
        if (D_16dc070) {
            FUN_0000bb40(HK_NULL);
        }
        D_57b80c0 = false;
    }
    return HK_SUCCESS;
}
