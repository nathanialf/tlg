/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_00b746b0 appends a counted reference to the array at
 * 0x58354c0 (tlg_game_array.h's push), which the function reaches directly:
 * the file's own object (D17). The array is destroyed at exit, so the
 * counted class is one the references can release: the node's interface
 * (tlg_game_node.h; the real class is not traced). */
static Array05943280<Ref00503fb0<Node00503fb0>> D_58354c0;

// NONMATCHING: the base reads the count and the capacity with one 8-byte load (`mov rbx,
// [D_58354c8]; mov rcx, rbx; lea eax, [rbx+1]; shr rcx, 0x20`): GVN's widening of an
// over-aligned load, which the prebuilt 3.7.1 and 3.9.1 do on this source (211 bytes, the
// base's size) and the 4.0.0 line does not (MemoryDependenceAnalysis.cpp no longer calls
// getLoadLoadClobberFullWidthSize); the build reads them apart (205 bytes). A compiler
// question for the region, not a source one.
void FUN_00b746b0(const Ref00503fb0<Node00503fb0> &value) /* derived name */
{
    D_58354c0.push(value);
}
