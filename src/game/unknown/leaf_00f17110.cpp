/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_sce_kernel.h"
#include "tlg_types.h"

/* derived names: no direct caller. A read through a stream's functions:
 * the buffer given back through the last argument when there is one; -1
 * without functions or a read function (+0x10); otherwise the read with the
 * stream's handle (+0x20), its two pointers (+0x8, +0x18) and the position
 * (the stream's base at +0x10 plus the offset given), the buffer and the
 * size; a failure (below 0) returned as it is; when the functions have a
 * wait (+0x18), it is asked with the handle and the two pointers until it
 * stops answering 1, a millisecond's sleep between; then 0. */
struct Functions00f17110 { /* derived name */
    u8 unknown0[0x10];
    int (*read)(int handle, void *first, void *second, u64 position, void *buffer,
                void *size);                            /* +0x10 */
    int (*wait)(int handle, void *first, void *second); /* +0x18 */
};

struct Stream00f17110 {           /* derived name */
    Functions00f17110 *functions; /* +0x0 */
    void *first;                  /* +0x8 */
    u64 base;                     /* +0x10 */
    void *second;                 /* +0x18 */
    int handle;                   /* +0x20 */
};

// NONMATCHING: the return. The base tests the wait first and the result in
// each arm (`test eax, eax; js` to the return of the result, `xor eax, eax`
// otherwise), the wait held in r13; this build gives the result's minimum
// with 0 (`sar; and`) after the loop and keeps the result over it (the wait
// spilled); 163 bytes against 162.
int FUN_00f17110(Stream00f17110 *stream, u32 offset, void *buffer, void *size,
                 void **bufferOut) /* derived name */
{
    if (bufferOut)
        *bufferOut = buffer;
    Functions00f17110 *functions = stream->functions;
    if (!functions || !functions->read)
        return -1;
    void *first = stream->first;
    void *second = stream->second;
    int handle = stream->handle;
    u64 position = stream->base + offset;
    bool waits = functions->wait != 0;
    int result = functions->read(handle, first, second, position, buffer, size);
    if (waits && result >= 0) {
        while (functions->wait(handle, first, second) == 1)
            sceKernelUsleep(1000);
    }
    return result < 0 ? result : 0;
}
