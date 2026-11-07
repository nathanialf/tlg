/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkResult hkPlatformObjectWriter::FUN_0019aca0(hkStreamWriter *writer, const void *data,
                                              const hkClass &klass, hkRelocationInfo &reloc)
{
    const hkClass *copyClass = &klass;
    if (cache) {
        copyClass = cache->FUN_0019a880(&klass, copier->layoutOut);
    }
    OffsetOnlyStreamWriter counter;
    hkStreamWriter *out = writer;
    if (cache && FUN_00017f40(copyClass->FUN_00004200(), "hkClass") == 0) {
        /* An hkClass object: the class it describes is written in the
         * target layout first, the object itself then only counted. */
        copyClass = cache->FUN_0019a880(&D_57b77f0, copier->layoutOut);
        const hkClass *dataClass =
            cache->FUN_0019a880(static_cast<const hkClass *>(data), copier->layoutOut);
        counter.seek(writer->tell(), 0);
        hkRelocationInfo classReloc;
        copier->FUN_001a35c0(dataClass, klass, writer, *copyClass, classReloc);
        out = &counter;
    }
    copier->FUN_001a35c0(data, klass, out, *copyClass, reloc);
    return out->isOk() ? HK_SUCCESS : HK_FAILURE;
}
