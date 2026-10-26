/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_sce_net.h"

/* derived name: whether this file brought the network library up. Nothing in
 * the executable sets it; it is read and cleared only below. */
static hkBool D_57c87a0;

/* derived name: the platform's network shutdown, the function pointer at
 * 0x16dc588 that the base system's quit (0x9b03) calls while its own
 * network-initialized flag is set: terminate the network library if this file
 * initialized it. */
void FUN_00091c60()
{
    if (D_57c87a0) {
        sceNetTerm();
        D_57c87a0 = false;
    }
}
