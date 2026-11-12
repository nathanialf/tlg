/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* The graphics library's render target taking its three addresses (the
 * header path and the three setter names from their assertion messages),
 * emitted out of line here (called by FUN_01307080 and
 * FUN_0131fea0): each address must be 256-byte aligned, a failure reported
 * through FUN_012fbca0 (file, line, function, format, value) and a debug
 * trap; the base address goes on in 256-byte blocks to FUN_012fbf40, the
 * cmask address is stored in blocks at +0x1c, the fmask address goes on in
 * blocks to FUN_012fc330. The record's other words are not traced. */
int FUN_012fbca0(const char *file, int line, const char *function, const char *format,
                 ...); /* derived name */

#define RENDER_TARGET_HEADER /* derived name */                                                    \
    "C:\\Program Files (x86)\\SCE\\ORBIS SDKs\\3.500\\target\\include_common\\gnm/rendertarget.h"

struct RenderTarget0149a070; /* derived name, from the header's file name */

/* derived names: the setters of the base and fmask addresses in 256-byte
 * blocks (their bodies are not written; void: no caller reads eax) */
void FUN_012fbf40(RenderTarget0149a070 *target, u32 baseAddr256);
void FUN_012fc330(RenderTarget0149a070 *target, u32 fmaskAddr256);

struct RenderTarget0149a070 { /* derived name, from the header's file name */

    void setBaseAddress(void *baseAddr)
    {
        if (reinterpret_cast<u64>(baseAddr) & 0xff) {
            FUN_012fbca0(RENDER_TARGET_HEADER, 250, "setBaseAddress",
                         "baseAddr (0x%p) must be 256-byte-aligned!", baseAddr);
            __builtin_debugtrap();
        }
        FUN_012fbf40(this, static_cast<u32>(reinterpret_cast<u64>(baseAddr) >> 8));
    }

    void setCmaskAddress(void *cmaskAddr)
    {
        if (reinterpret_cast<u64>(cmaskAddr) & 0xff) {
            FUN_012fbca0(RENDER_TARGET_HEADER, 491, "setCmaskAddress",
                         "cmaskAddr (0x%p) must be 256-byte-aligned!", cmaskAddr);
            __builtin_debugtrap();
        }
        cmaskAddress = static_cast<u32>(reinterpret_cast<u64>(cmaskAddr) >> 8);
    }

    void setFmaskAddress(void *fmaskAddr)
    {
        if (reinterpret_cast<u64>(fmaskAddr) & 0xff) {
            FUN_012fbca0(RENDER_TARGET_HEADER, 535, "setFmaskAddress",
                         "fmaskAddr (0x%p) must be 256-byte-aligned!", fmaskAddr);
            __builtin_debugtrap();
        }
        FUN_012fc330(this, static_cast<u32>(reinterpret_cast<u64>(fmaskAddr) >> 8));
    }

    void setAddresses(void *baseAddr, void *cmaskAddr, void *fmaskAddr); /* derived name */

    u8 unknown0[0x1c];
    u32 cmaskAddress; /* +0x1c: the cmask address in 256-byte blocks */
};

void RenderTarget0149a070::setAddresses(void *baseAddr, void *cmaskAddr, void *fmaskAddr)
{
    setBaseAddress(baseAddr);
    setCmaskAddress(cmaskAddr);
    setFmaskAddress(fmaskAddr);
}
