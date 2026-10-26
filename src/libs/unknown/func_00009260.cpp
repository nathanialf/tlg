/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hkBufferedStreamWriter's vtable (address point
 * 0x168d220): what the stream it buffers answers; without one, whether the
 * buffer has room left. */
hkBool hkBufferedStreamWriter::FUN_00009260() const /* derived name */
{
    return stream ? stream->isOk() : hkBool(bufferSize != bufferCapacity);
}
