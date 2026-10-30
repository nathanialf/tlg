/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Each data type's size, file-local (D17); the rows are written at build
 * time from the user's executable (D18, config/data_schema.base.txt). */
static const hkVertexFormat::ComponentSize D_14b8101[12] = {
#include "gen/D_14b8101.inc"
};

// NONMATCHING: equal but for the second loop's guard: the base tests the count once (`test ebx,
// ebx; jle` before the first loop, the second entered straight from the first's exit), this
// compile keeps the second loop's own guard; and the size table's address is the index register
// of its load here, the base register in the base (NOTES Round 63B).
void hkMemoryMeshVertexBuffer::FUN_000273c0(const hkVertexFormat &newFormat)
{
    FUN_000270b0(&format, &newFormat);
    numVertices = 0;
    const int numElements = newFormat.numElements;
    int offset = 0;
    int alignment = 4;
    for (int i = 0; i < numElements; i++) {
        const hkVertexFormat::Element &element = newFormat.elements[i];
        if (element.dataType == hkVertexFormat::TYPE_VECTOR4) {
            elementOffsets[i] = offset;
            offset += element.numValues * 16;
            alignment = 16;
        }
    }
    for (int i = 0; i < numElements; i++) {
        const hkVertexFormat::Element &element = newFormat.elements[i];
        if (element.dataType != hkVertexFormat::TYPE_VECTOR4) {
            elementOffsets[i] = offset;
            const int size = element.dataType == hkVertexFormat::TYPE_ARGB32
                                 ? 4
                                 : D_14b8101[element.dataType].numBytes * element.numValues;
            offset = (offset + size + 3) & ~3;
        }
    }
    vertexStride = (offset + alignment - 1) & -alignment;
    isSharable = newFormat.FUN_00027240() == hkVertexFormat::SHARING_ALL_SHARED;
}
