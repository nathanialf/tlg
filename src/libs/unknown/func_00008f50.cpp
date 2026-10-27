/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Equal to the base but for its vtable (0x168d210), which neither vtable
 * file names yet: unclaimed until a ruling gives it a row (D14). */

hkBufferedStreamWriter::hkBufferedStreamWriter(void *memory, int memorySize, hkBool memoryIsString)
    : stream(0), buffer(static_cast<char *>(memory)), bufferSize(0),
      bufferCapacity(memoryIsString ? memorySize - 1 : memorySize), ownsBuffer(false)
{
    if (memoryIsString) {
        FUN_00018160(memory, 0, memorySize);
    }
}
