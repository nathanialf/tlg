/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* This file's static initializer (0x17f080): the registry over the static
 * class list, then hkBuiltinTypeRegistry's registration (the create
 * function 0x17ef90, the instance pointer D_57c8898). The registry's
 * destructor is inline and empty, so no exit registration is kept
 * (cookbook 112). */
hkStaticClassNameRegistry D_57c8870(D_16c9060, -1, "hk_2014.2.0-r1");

static SingletonRecord D_57c88a0("hkBuiltinTypeRegistry", FUN_0017ef90,
                                 reinterpret_cast<void **>(&D_57c8898));
