/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_lib_unknown.h"

/* The copier swaps bytes when the two layouts' byte orders differ. */
// NONMATCHING: equal but for the vtable 0x16a75d0, which has no row (a D14
// ruling: stored only here; docs/NOTES.md, Round 30).
hkObjectCopier::hkObjectCopier(const Layout00180ef0 &layoutIn, const Layout00180ef0 &layoutOut,
                               int flags)
    : layoutIn(layoutIn), layoutOut(layoutOut), flags(flags)
{
    byteSwap = this->layoutIn.rules.littleEndian != this->layoutOut.rules.littleEndian;
}
