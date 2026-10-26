/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 0 of its vtable (0x16a6a20), the complete destructor: the name's
 * destructor is out of line. */
// NONMATCHING: instructions equal; the vtable 0x16a6a20 (_ZTV13XmlEndElement) waits for a D14 ruling
XmlEndElement::~XmlEndElement()
{
    FUN_0000e5d0(&name);
}
