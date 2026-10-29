/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* LoadedImage's destructor (slot 0 of its vtable 0x16a7580): the members'
 * arrays freed. The deleting destructor (0x1a03a0, slot 1) is emitted beside
 * it. */
LoadedImage::~LoadedImage() {}
