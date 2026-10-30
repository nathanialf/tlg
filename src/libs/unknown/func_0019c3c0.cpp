/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hkPackfileWriter's vtable (0x16a6960): the
 * contents added to the "__data__" section, their class the one the vtable
 * class registry finds for the object when the class has a vtable, then
 * the indices the pointer map gave the object and its class kept. */
void hkPackfileWriter::FUN_0019c3c0(const void *object, const hkClass &klass,
                                    const hkVtableClassRegistry *registry, void *argument4)
{
    const hkVtableClassRegistry *classRegistry = registry ? registry : D_57c8898->FUN_0017e990();
    const hkClass *contentsClass = &klass;
    if (FUN_000045a0(&klass)) {
        contentsClass = classRegistry->FUN_00184420(object);
    }
    FUN_0019c480(object, *contentsClass, registry, argument4, D_16dcbb0);
    contentsIndex = int(map20.FUN_00013b30(hkUlong(object), hkUlong(-1)));
    contentsClassIndex = int(map20.FUN_00013b30(hkUlong(contentsClass), hkUlong(-1)));
}
