/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkDefaultClassNameRegistry's registration (this file's static initializer, 0x184fb0):
 * the create function 0x184f40, the instance pointer D_57c8960. */
static SingletonRecord D_57c8968("hkDefaultClassNameRegistry", FUN_00184f40,
                                 reinterpret_cast<void **>(&D_57c8960));
