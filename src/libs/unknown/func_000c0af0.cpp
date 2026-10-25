/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the current calendar time, a wrapper over the imported
 * time with no result pointer. Its one caller (0x33707) compares the time,
 * shifted down 8 bits, against 0x50e0d4 (the end of 2012) and a limit
 * derived from a key. */
time_t FUN_000c0af0() /* derived name */
{
    return time(0);
}
