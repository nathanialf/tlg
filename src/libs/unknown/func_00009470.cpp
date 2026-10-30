/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkTraceStreamTitle's loaded-object cleanup: nothing to clean up. The
 * linker folded it into the empty body 0x8d60, whose row is AllocatorBase's
 * destructor: spelled under the address's own name as hkColor's (0xa1d0)
 * is (docs/DECISIONS.md D15, the round 57 addendum). */
void FUN_00008d60(void *object) {}

/* This file's static initializer (0x9470): hkTraceStreamTitle's
 * reflection, no parent, its one member, flags 1, then its type info (no
 * finish callback, no vtable). The type info's name is the base's string
 * "!hkTraceStream::Title": the class is hkTraceStream's nested Title, which
 * the hkClass record spells hkTraceStreamTitle. */
const hkClass D_57b8038("hkTraceStreamTitle", 0, sizeof(hkTraceStreamTitle), 0, 0, 0, 0, D_168d280,
                        1, 0, 0, 1, 0);
extern const hkTypeInfo D_57b8088;
const hkTypeInfo D_57b8088("hkTraceStreamTitle", "!hkTraceStream::Title", 0, FUN_00008d60, 0,
                           sizeof(hkTraceStreamTitle));
