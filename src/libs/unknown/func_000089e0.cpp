/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: flushes hkOstream's writer (slot 7 of the writer at +0x10).
 * Slot 7 of the forwarding writer at 0x16a6410 reaches the same body. */
void hkOstream::FUN_000089e0() /* derived name */
{
    writer->flush();
}
