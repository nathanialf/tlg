/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the function a bridge atom holds (stored by FUN_0007d030):
 * the solver's call goes on to the wrapped constraint data's slot 24. */
void FUN_0007d020(hkpConstraintData *data, const void *input, void *output) /* derived name */
{
    data->buildJacobianCallback(input, output);
}
