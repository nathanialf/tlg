/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The signal's destructor is the one call. */
hknpBodyQualityLibrary::~hknpBodyQualityLibrary() {}

/* The two constructors are equal at quick_diff but for their calls' target:
 * each quality's constructor is out of line, the default and the finish one
 * both folded by the linker into the empty body 0x16a370, whose row the
 * collision dispatcher names FUN_0016a370 by symbol (one name per address,
 * D15): a ruling for the supervisor (docs/NOTES.md, Round 73A). */
// NONMATCHING: the 32 calls to hknpBodyQuality's constructor resolve to no row
hknpBodyQualityLibrary::hknpBodyQualityLibrary() {}

/* The signal cleared (not serialized), each quality finished. */
// NONMATCHING: the 32 calls to hknpBodyQuality's finish constructor resolve to no row
hknpBodyQualityLibrary::hknpBodyQualityLibrary(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag)
{
}
