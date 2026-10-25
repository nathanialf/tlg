/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: hkVertexFormat's default constructor, run on the
 * vertexFormat member by the constructors of hkMultipleVertexBuffer (0x24fe7)
 * and of hkMemoryMeshVertexBuffer (0x272d4, 0x27879), and on locals
 * (0x25966, 0xae100); the elements are left as they are. */
void FUN_000270a0(hkVertexFormat *self) /* derived name */
{
    self->numElements = 0;
}
