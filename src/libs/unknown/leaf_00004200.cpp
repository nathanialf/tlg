/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: an hkClass's name, read by 30 direct callers;
 * FUN_0017de40 passes it to strcmp (through FUN_00017f40). */
const char *FUN_00004200(const hkClass *self) /* derived name */
{
    return self->name;
}
