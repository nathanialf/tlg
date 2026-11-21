/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016abc00.h"

/* derived name: the constructor of Object016abc00
 * (tlg_game_object016abc00.h): the base built from the name, the vptr, the
 * array cleared (`vmovups [r15+0x38], xmm0`, its owner index from the
 * thread's heap, its state), `mov qword [r15+0x50], 0`; then the object
 * named "_swing_common_param" (looked up, not interned: `xor ecx, ecx` at
 * 0x5c107c; 19 characters, `mov edx, 0x13`) of the type at 0x598a628 is
 * taken from the registry (FUN_00cbc5a0, mode 0) and the reference at +0x50
 * set to it; the name is released after the exchange (0x5c1154). */
// NONMATCHING: 115 of 116, whole module (the reference's exchange relaxed, tlg_game_node.h):
// the base frees the name's entry from the index it kept in r14d since the intern call (`mov
// edi, r14d` at 0x5c1177, after the name's `lock xadd`); the build reads it back from the name's
// slot (`mov edi, [rbp-0x38]`): an ordered fall is a clobber of every location for GVN. A relaxed
// fall makes this equal but changes Name::~Name (0x1331800, whose base reads the index again
// after the xadd) and 936 other rows (round 408C)
Object016abc00::Object016abc00(const Name &name) : Object01343880(name)
{
    held50.set(Value005c0fe0::find(D_5945a38, Name("_swing_common_param", false)));
}
