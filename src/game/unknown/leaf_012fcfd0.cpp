/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether the console runs in its Neo (PS4 Pro) mode, asked of
 * the kernel once (sceKernelIsNeoMode, its NID verified) and kept in the
 * guarded static at 0x5ada910 (guard 0x5ada908) as an int. Called by
 * FUN_001a5cb0 and FUN_001a6d80. */
extern "C" int sceKernelIsNeoMode();

int FUN_012fcfd0() /* derived name */
{
    static int D_5ada910 = sceKernelIsNeoMode() != 0;
    return D_5ada910;
}
