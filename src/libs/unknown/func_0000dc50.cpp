/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkUuidPseudoRandomGenerator's instance pointer and registration (this
 * file's static initializer, 0xdc50: the create function 0xdaf0), then the
 * file's two cleared objects. derived names. */
static hkReferencedObject *D_57b8608;
static SingletonRecord D_57b8610("hkUuidPseudoRandomGenerator", FUN_0000daf0,
                                 reinterpret_cast<void **>(&D_57b8608));
static ClearedPointer0000dc50 D_57b8638;
static ClearedPointer0000dc50 D_57b8630;
