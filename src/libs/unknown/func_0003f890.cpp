/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The solver's arrays walked under the "Stinit" timer (0x3fa40 and
 * 0x16e5bc call it with the three of SolverArrays0003f820): two writers
 * appending to the two streams over the context's cache, and each element
 * that starts a list of nodes handed run by run to the world's object of
 * the run's key (slot 5), which reserves the run's room in the writers.
 * The second argument is not read. derived name. */
void FUN_0003f890(hknpWorldContextPool::Context *context, void *argument,
                  const SolverArrays0003f820::ArrayInfo *arrays, int numArrays,
                  hkBlockStream *streamA, hkBlockStream *streamB)
{
    hknpModifierManager *manager = context->world->modifierManager;
    hkBlockStreamWriter writerA;
    writerA.FUN_000938c0(context->cache250, streamA);
    hkBlockStreamWriter writerB;
    writerB.FUN_000938c0(context->cache250, streamB);
    hkBlockStreamWriter *writers[8] = {&writerB, &writerA};
    for (int i = 0; i < numArrays; i++) {
        const SolverArrays0003f820::ArrayInfo &info = arrays[i];
        for (int j = 0; j < info.numElements; j++) {
            hknpWorldObject388Node *node = reinterpret_cast<hknpWorldObject388Node *>(
                static_cast<char *>(info.data) + info.elementSize * j);
            if (node->count) {
                do {
                    hknpWorldObject380 *object =
                        static_cast<hknpWorldObject380 *>(manager->objects4e0[node->key]);
                    node = object->FUN_0002d790(node, writers);
                } while (node);
            }
        }
    }
    writerB.FUN_00093a10();
    writerA.FUN_00093a10();
}
