/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 17 of hknpCapsuleShape's vtable (0x169b270). */
// NONMATCHING: gate gap, not a code residual: quick_diff equal, but layout_link cannot place
// the 4-byte constant-pool literal (its value occurs many times in the base); docs/NOTES.md Round 10.
float FUN_00073940(const hknpCapsuleShape *self) /* derived name */
{
    return 3.14159265358979f * 0.5f;
}
