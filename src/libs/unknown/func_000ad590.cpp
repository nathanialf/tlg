/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the body is the base's (the vtable, then the name's
// destructor), but _ZTV15FileImageSource (0x16a3aa0) is in neither vtable
// table: the class has no type info, so its vtable waits for a ruling
// (D14).
FileImageSource::~FileImageSource()
{
    FUN_0000e5d0(&fileName);
}
