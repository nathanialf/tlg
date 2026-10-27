/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkHardwareInfo's registration (this file's static initializer, 0x8fdc0):
 * the create function 0x8faf0, the instance pointer D_57c8728. */
static SingletonRecord D_57c8730("hkHardwareInfo", FUN_0008faf0,
                                 reinterpret_cast<void **>(&D_57c8728));
