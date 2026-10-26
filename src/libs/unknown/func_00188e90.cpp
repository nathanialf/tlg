/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the body is the base's (the new object's count, then the
// vtable), but _ZTV11ImageSource (0x16a6610) is in neither vtable table:
// the class has no type info, so its vtable waits for a ruling (D14).
ImageSource::ImageSource() {}
