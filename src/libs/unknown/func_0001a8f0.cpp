/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkFileSystem's registration (this file's static initializer, 0x1a8f0): no
 * create function, the instance pointer D_57b9b70. */
static SingletonRecord D_57b9b78("hkFileSystem", 0, reinterpret_cast<void **>(&D_57b9b70));
