/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array0081aaf0.h"
#include "tlg_game_node.h"

/* derived names: FUN_0081aaf0 takes one reference out of an array of exchanged
 * references without keeping the order (tlg_game_array0081aaf0.h's
 * removeUnordered), out of line: the array's own member, instantiated here
 * until a caller of it is written. The referenced class is not traced. */
class Value0081aaf0 : public Node00503fb0 /* derived name */
{
};

// NONMATCHING: a register exchange (96/101): at 0x81abc4 the base has the count in eax and the block in rcx
// (`mov eax, [r14+8]; mov rcx, [r14]; dec eax`), the build the block in rax and the count in ecx; the copies
// 0x8298d0, 0x82f610, 0xc64690, 0xd66a00, 0xd703b0 wait on it.
template void Array0081aaf0<AtomicRef0045c470<Value0081aaf0>>::removeUnordered(unsigned);
