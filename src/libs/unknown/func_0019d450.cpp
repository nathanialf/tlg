/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of its vtable (0x16a69e0), the complete destructor: the
 * attributes destroyed from the last and their storage given back, then
 * the name. */
// NONMATCHING: the deleting destructor (0x19d500, slot 1) calls this one
// here; the base inlines it, which the inliner's threshold of 225 admits
// only with the inline hint (cost about 238; docs/NOTES.md, Round 56).
XmlStartElement::~XmlStartElement() {}
