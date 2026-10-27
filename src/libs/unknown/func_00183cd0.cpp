/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkDebugDisplay's registration (this file's static initializer, 0x183cd0):
 * the create function 0x183c40, the instance pointer D_57c88c0. */
static SingletonRecord D_57c88c8("hkDebugDisplay", FUN_00183c40,
                                 reinterpret_cast<void **>(&D_57c88c0));
