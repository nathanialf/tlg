/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkVersionPatchManager's registration (this file's static initializer, 0x19a400):
 * the create function 0x199f80, the instance pointer D_57c89b8. */
static SingletonRecord D_57c89c0("hkVersionPatchManager", FUN_00199f80,
                                 reinterpret_cast<void **>(&D_57c89b8));
