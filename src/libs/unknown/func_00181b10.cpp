/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkBinaryPackfileWriter::hkBinaryPackfileWriter(const Options &options) : hkPackfileWriter(options)
{
    FUN_0019d0d0(D_16dcb70);
    FUN_0019d280(D_57b77f0, D_16dcbb8);
    FUN_0019d280(D_57b7d18, D_16dcbb8);
    FUN_0019d280(D_57b93e0, D_16dcbb8);
    FUN_0019d280(D_57b92c0, D_16dcbb8);
}

/* The destructor (0x181bf0): nothing of its own, hkPackfileWriter's follows;
 * the deleting destructor 0x181ba0 frees 0x140 bytes by default. Defined
 * here, in the constructor's file: the class's key function, so the file
 * emits the vtable and the constructor's slot 10 call folds to 0x19d0d0
 * (docs/DECISIONS.md D37). */
hkBinaryPackfileWriter::~hkBinaryPackfileWriter() {}
