/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: whether the archive's writer is usable (slot 5 of the
 * writer at +0x10). Slot 5 of the forwarding writer at 0x16a6410 and of
 * the class at 0x16a3860 reach the same body. */
hkBool hkOArchive::FUN_0000abf0() const /* derived name */
{
    return writer->isOk();
}
