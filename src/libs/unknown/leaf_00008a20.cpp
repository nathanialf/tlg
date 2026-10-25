/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 3 of hkOstream's vtable returns its reflected class. */
// NONMATCHING: the compiler emits movq D_57b7e18@GOTPCREL(%rip) (48 8b); the base holds the linker-relaxed leaq (48 8d), docs/NOTES.md Round 8
const hkClass *hkOstream::FUN_00008a20() const /* derived name */
{
    return &D_57b7e18;
}
