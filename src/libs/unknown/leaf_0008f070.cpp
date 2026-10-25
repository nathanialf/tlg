/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: decodes a byte-coded value through a static table of 256
 * increasing 16-bit values (at 0x14c3cf0, 0 for code 0). The callers pass a
 * byte widened to the full register (0x935cc, 0x93640, 0x156e15, 0x16210d,
 * 0x162137) and turn a nonzero result into a float's bits ((value << 12) +
 * 0x3b800000 at 0x935da): an 8-bit compressed float. */
extern const u16 D_14c3cf0[256];

u16 FUN_0008f070(unsigned long code) /* derived name */
{
    return D_14c3cf0[code];
}
