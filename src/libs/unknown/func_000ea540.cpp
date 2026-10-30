/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Object000ea540's destructor (slot 0 of its vtable): the array's storage
 * given back. */
Object000ea540::~Object000ea540() {}

// NONMATCHING: the complete destructor 0xea380 is equal written here, out
// of line; the deleting one 0xea440 holds the body inline in the base, which
// 3.3 does only with the inline hint (its cost lies between 225 and 250), so
// the destructor is the class's inline one, emitted with the vtable in the
// builder 0xea610 (not written yet): docs/NOTES.md, Round 58.
/* The class over it (slot 0 of its vtable, 0xea380; the deleting destructor
 * 0xea440): the signals, the tree, then the base's inline. */
Object000ea380::~Object000ea380() {}
