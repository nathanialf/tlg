/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* The graphics library's render target taking its three addresses (the
 * header path and the three setter names from their assertion messages),
 * emitted out of line here (called by FUN_01307080 and
 * FUN_0131fea0): each address must be 256-byte aligned, a failure reported
 * through FUN_012fbca0 (file, line, function, format, value) and a debug
 * trap; the base address goes on in 256-byte blocks to FUN_012fbf40, the
 * cmask address is stored in blocks at +0x1c, the fmask address goes on in
 * blocks to FUN_012fc330. The record's other words are not traced. */
void RenderTarget0149a070::setAddresses(void *baseAddr, void *cmaskAddr, void *fmaskAddr)
{
    setBaseAddress(baseAddr);
    setCmaskAddress(cmaskAddr);
    setFmaskAddress(fmaskAddr);
}
