/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: the name stored first in an object, read by 30 direct
 * callers; FUN_0017de40 passes it to strcmp (through FUN_00017f40). Class
 * unknown. */
struct Named00004200 {
    const char *name;
};

const char *FUN_00004200(const Named00004200 *self) /* derived name */
{
    return self->name;
}
