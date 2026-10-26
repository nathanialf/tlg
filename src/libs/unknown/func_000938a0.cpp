/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

#include <xmmintrin.h>

/* derived name: the writer is bound to the stream and starts empty at its
 * first block, which is fetched ahead of the writes to it. */
void hkBlockStreamWriter::FUN_000938a0(void *blockAllocator, hkBlockStream *stream)
{
    void *block = stream->blocks.data[0];
    allocator = blockAllocator;
    blockStream = stream;
    currentByteOffset = 0;
    currentNumElements = 0;
    _mm_prefetch(static_cast<const char *>(block), _MM_HINT_NTA);
    currentBlock = block;
}
