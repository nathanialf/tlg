/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkDummySingleton's registration (this file's static initializer, 0x9c50):
 * the create function 0x9c20, the instance pointer D_57b80c8. */
static SingletonRecord D_57b80d0("hkDummySingleton", FUN_00009c20,
                                 reinterpret_cast<void **>(&D_57b80c8));
