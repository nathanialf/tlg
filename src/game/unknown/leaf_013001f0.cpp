/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jscomputecontext.h"

/* ~JsComputeContext: the five entries handed back, then the base's
 * destructor, a tail call. The destructor is the class's key function, so
 * this file emits the vtable and the deleting destructor 0x13002e0 (which
 * in the base inlines this one). */
JsComputeContext::~JsComputeContext()
{
    returnEntryE8(entry1cf8);
    returnEntryE8(entry1ce8);
    returnEntryB8(entry1cd8);
    returnEntryB8(entry1d08);
    returnEntryB8(entry1d00);
}
