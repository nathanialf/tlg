/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the arrays' sizes, counts and data for the tasks, and how
 * each is accessed: the two of 0x40-byte elements in mode 2, the third in
 * mode 1, with the ids 10, 20 and 30. */
void SolverArrays0003f820::FUN_0003f820(ArrayInfo *infosOut, Access *accessOut) const
{
    infosOut[0].elementSize = sizeof(Element30);
    infosOut[0].numElements = arrayC.getSize();
    infosOut[0].data = arrayC.data;
    infosOut[1].elementSize = sizeof(Element40);
    infosOut[1].numElements = arrayA.getSize();
    infosOut[1].data = arrayA.data;
    infosOut[2].elementSize = sizeof(Element40);
    infosOut[2].numElements = arrayB.getSize();
    infosOut[2].data = arrayB.data;
    accessOut[0].mode = 2;
    accessOut[0].id = 10;
    accessOut[1].mode = 2;
    accessOut[1].id = 20;
    accessOut[2].mode = 1;
    accessOut[2].id = 30;
}
