/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: each lane's conversion to double: the base folds the load,
// `vcvtss2sd (mem)` after one `vxorps`; this loads with `vmovss` first
// (docs/NOTES.md, Rounds 32 and 33: no 3.3 path gives a vxorps feeding the
// memory form).
hkOstream &hkOstream::FUN_000086b0(const Vec4 &v)
{
    FUN_000086f0("[%g,%g,%g,%g]", lane(v, 0), lane(v, 1), lane(v, 2), lane(v, 3));
    return *this;
}
