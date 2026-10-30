/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkBinaryPackfileWriter::FUN_00181d00(PackfileSaveContext00181dc0 &context,
                                          const hkClass &klass, int sectionStart) const
{
    u32 signature = klass.FUN_000045c0(0);
    if (context.byteSwap) {
        signature = (signature >> 24) | ((signature >> 8) & 0xff00) |
                    ((signature << 8) & 0xff0000) | (signature << 24);
    }
    char record[5];
    record[4] = '\t';
    *reinterpret_cast<u32 *>(record) = signature;
    context.writer->write(record, 5);
    const char *name = klass.FUN_00004200();
    context.classNameOffsets.FUN_00091690(name, context.writer->tell() - sectionStart);
    context.writer->write(name, FUN_00017fe0(name) + 1);
}
