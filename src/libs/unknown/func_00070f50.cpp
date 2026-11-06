/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The signal's destructor is the one call. */
hknpBodyQualityLibrary::~hknpBodyQualityLibrary() {}

/* One reference, no slots, each quality constructed (0x16a370). */
hknpBodyQualityLibrary::hknpBodyQualityLibrary() {}

/* The signal cleared (not serialized); the qualities' array takes no flag,
 * so each quality is default-constructed, the same callee as above. */
hknpBodyQualityLibrary::hknpBodyQualityLibrary(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag)
{
}
