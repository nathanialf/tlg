/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_sce_fios.h"

/* derived names: returns the size of the file whose handle is its 32-bit
 * argument through sceFiosFHGetSize (the import's name verified by its NID,
 * tools/nid_names.py) as a tail call; slot 7 of the vtable at 0x16bdc60 (its
 * pointer at 0x16bdca8), the vtable stored by FUN_00e5c990 FUN_00e5d180. Class
 * and method unknown. */
struct Object00e5dbb0;

SceFiosSize FUN_00e5dbb0(Object00e5dbb0 *self, SceFiosFH fh) /* derived name */
{
    return sceFiosFHGetSize(fh);
}
