/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void StringMap::FUN_00180bf0() /* derived name */
{
    for (Iterator it = FUN_00091600(); FUN_00013890(it); it = FUN_00091650(it)) {
        FUN_00018090(const_cast<char *>(FUN_00091630(it)), D_57b8480);
    }
    FUN_00091ac0();
}
