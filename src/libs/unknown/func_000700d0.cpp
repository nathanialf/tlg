/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the cleanup callback of hknpConstraint's type info
 * (stored at 0x57c2be0 by the initializer at 0x706ee): destroy the
 * constraint in place. */
void FUN_000700d0(void *object) /* derived name */
{
    static_cast<hknpConstraint *>(object)->~hknpConstraint();
}
