/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: runs a command through the executor of its primary type. */
void hkPrimaryCommandDispatcher::FUN_00090830(const hkCommand &command) /* derived name */
{
    dispatchers[command.primaryType]->exec(command);
}
