/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the cleanup callback of hkBitField's type info (registered
 * at 0x9e2b): destroy the field in place, which frees its words. */
void hkBitField::FUN_00009cc0(void *object)
{
    static_cast<hkBitField *>(object)->storage.words.clearAndDeallocate();
}
