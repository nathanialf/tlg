/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkProcessFactory's registration (this file's static initializer, 0x183f90):
 * the create function 0x183f00, the instance pointer D_57c88e8. */
static SingletonRecord D_57c88f0("hkProcessFactory", FUN_00183f00,
                                 reinterpret_cast<void **>(&D_57c88e8));
