/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkBlockStreamCommandWriter::FUN_000904f0(const hkCommand &command)
{
    const int size = command.sizePaddedTo16;
    void *destination = writer.reserve(size);
    hkString::memCpy4(destination, &command, size >> 2);
    writer.advance(size);
}
