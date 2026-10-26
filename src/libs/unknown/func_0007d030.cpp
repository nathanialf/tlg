/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: bind a bridge atom to the constraint data it serves, the
 * solver's call going through FUN_0007d020 to the data. */
void FUN_0007d030(hkpBridgeConstraintAtom *self, hkpConstraintData *data) /* derived name */
{
    self->constraintData = data;
    self->buildJacobianFunc = FUN_0007d020;
}
