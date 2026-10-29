/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The cleanup callback of the material free-list array's type info
 * (0x57c08b8, set at 0x3f12b): the array destroyed in place, each material
 * in use losing its name, then the storage given back. */
void FUN_0003eef0(void *object) /* derived name */
{
    typedef hkFreeListArray<hknpMaterial, hknpMaterialId, 8, hknpMaterialFreeListArrayOperations>
        MaterialArray;
    static_cast<MaterialArray *>(object)->~MaterialArray();
}
