/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_simd.h"

/* derived names: the static initializer of the file of FUN_00187750 (its
 * one relocated pointer at 0x57ae7e8 in the initializer table): a
 * file-local tolerance of 1e-4 in all four lanes, which FUN_00187750 reads
 * at 0x187fae and 0x18847d. It is file-local: the base stores to it and
 * reads it RIP-relative, with no GOT load (D10). */
static Vec4 D_57c8990 = _mm_set1_ps(1e-4f); /* derived name */

// NONMATCHING: a file-local object with no reader in the TU is dead, so the
// initializer compiles to a bare ret; its reader FUN_00187750 (0xdec bytes)
// belongs in this TU. With it, the store's relocation is against the .bss
// section symbol, which the gate resolves by searching the base for the
// object's bytes (zeros, not unique): docs/NOTES.md, Round 19.
