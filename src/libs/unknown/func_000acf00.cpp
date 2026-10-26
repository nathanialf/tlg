/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hkMemoryMeshMaterial's vtable (address point
 * 0x16a3930): the vertex format the material works with is the one it is
 * given, copied out (FUN_000270b0 copies the element count at +0x100 and
 * that many 8-byte elements); always a success. */
hkResult hkMemoryMeshMaterial::FUN_000acf00(const hkVertexFormat &format,
                                            hkVertexFormat &formatOut) /* derived name */
{
    FUN_000270b0(&formatOut, &format);
    return HK_SUCCESS;
}
