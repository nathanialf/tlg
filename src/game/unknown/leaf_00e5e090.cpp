/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_fios.h"

/* derived names: slot 13 of the vtable at 0x16bdc60 (its pointer at
 * 0x16bdcd8): seeks the file to the offset from its start and reports whether
 * it got there. The object (this) is not read. Class and method unknown. */
int FUN_00e5e090(void *, SceFiosFH fh, u32 offset) /* derived name */
{
    return sceFiosFHSeek(fh, offset, 0) == offset;
}
