/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The defaults, local to this file (the base reaches them with direct
 * rip-relative operands, docs/DECISIONS.md D17): one for every primary type,
 * another for type 0. derived names. */
static CommandDispatcher16a3410 D_16dc710;
static CommandDispatcher16a33c0 D_16dc720;

hkPrimaryCommandDispatcher::hkPrimaryCommandDispatcher()
{
    for (int i = 0; i < 8; i++) {
        dispatchers[i] = &D_16dc710;
    }
    dispatchers[0] = &D_16dc720;
}
