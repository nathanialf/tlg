/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The class's key function (0x40c0): the vtable 0x168c980 and the deleting
 * destructor 0x4060 are emitted with it. The CRC is held in a local over
 * the bytes and stored once, even for none (0x4194). */
int Crc32StreamWriter::write(const void *buffer, int size)
{
    const u8 *bytes = static_cast<const u8 *>(buffer);
    u32 value = crc;
    for (int i = 0; i < size; i++) {
        u32 c = (value ^ bytes[i]) & 0xff;
        for (int bit = 0; bit < 8; bit++) {
            c = (c & 1) ? (c >> 1) ^ 0xedb88320 : c >> 1;
        }
        value = (value >> 8) ^ c;
    }
    crc = value;
    return size;
}
