/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpCompressedHeightFieldShape's destructor (0x175c00; the deleting
 * destructor 0x175cb0 beside it): the two arrays freed, the shape tags
 * first, then hknpHeightFieldShape's base destructor. The call makes this
 * TU emit the height field's inline destructor with its vtable: its base
 * (0x12a8c0), complete (0x12a850) and deleting (0x12a860) destructors are
 * this file's. */
hknpCompressedHeightFieldShape::~hknpCompressedHeightFieldShape() {}
