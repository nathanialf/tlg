/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 0 of its vtable (0x16a6a60), the complete destructor: the text's
 * destructor is out of line. */
XmlCharacters::~XmlCharacters()
{
    FUN_0000e5d0(&text);
}
