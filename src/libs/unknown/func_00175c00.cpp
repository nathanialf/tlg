/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal but for the base destructor's call, which names
// hknpHeightFieldShape's base destructor (0x12a8c0); its row and its
// vtable's (0x16a3e30) wait for a ruling (docs/NOTES.md, Round 57).
hknpCompressedHeightFieldShape::~hknpCompressedHeightFieldShape() {}
