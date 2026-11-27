/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: the object whose vtable is at 0x16a7650 (stored by
 * FUN_001bbc30 FUN_00203010), its three rates as the debug print reads
 * them */
struct Object00201b70 { /* derived name */
    u8 unknown0[0x18c];
    float gpu; /* +0x18c */
    float cpu; /* +0x190 */
    float fps; /* +0x194 */
};

/* derived names: slot 9 of the vtable at 0x16a7650: prints the frame rate
 * and the CPU and GPU figures between "<DEBUG_PRINT_FPS>" tags. */
// The floats are converted from memory over a zero of the block (`vxorps`, then `vcvtss2sd x, z, [mem]`)
// by the selection rule (tools/patches/llvm-3.7.1-cvtzero-01-extload-cvtss2sd-zero-passthrough.patch, D95).
void FUN_00201b70(Object00201b70 *self) /* derived name */
{
    puts("<DEBUG_PRINT_FPS>");
    printf("FPS %5.1f\n", self->fps);
    printf("CPU %5.1f\n", self->cpu);
    printf("GPU %5.1f\n", self->gpu);
    puts("</DEBUG_PRINT_FPS>");
}
