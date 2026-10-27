/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The XML reader's constructor: a new reference-counted object, no pending
 * nodes and no error (hkStringPtr's default constructor is out of line,
 * FUN_0000e3d0, the tail call). */
// NONMATCHING: equal but for the vtable 0x16a6aa0 (address point 0x16a6ab0),
// which has no row (docs/NOTES.md, Round 31).
hkXmlParser::hkXmlParser()
{
    FUN_0000e3d0(&lastError);
}
