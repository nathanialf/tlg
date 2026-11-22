/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* The graphics library's depth target taking its depth and stencil
 * addresses (the setter names from their assertion messages), emitted out of
 * line here (called by FUN_01307080 and FUN_01320fe0): the depth address is
 * both the read and the write address, the stencil address likewise, each
 * checked to be 256-byte aligned by its setter (tlg_game_gnm.h). */
// NONMATCHING: the order around the debug trap: the base issues the register copies that follow each trap in its block (the shift's copy, the next call's first argument, the merge copy) before `int 0x41`; here the trap comes first (btver2 gives INT WriteSystem's latency 100, which the post-RA list scheduler issues first; a region-wide question, 72 of the base's 492 traps have instructions between the report and the trap)
void DepthRenderTarget01499280::setAddresses(void *zAddr, void *stencilAddr)
{
    setZReadAddress(zAddr);
    setZWriteAddress(zAddr);
    setStencilReadAddress(stencilAddr);
    setStencilWriteAddress(stencilAddr);
}
