/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 5: the world's streams checked for a thread (the checks are empty
 * in this build, 0x175a80): the first pair with the array at +0xc10, the
 * pair at +0x400, the pair at +0x200 with the array at +0xc20. */
void hknpWorldObject1d0Large::FUN_00151c80(hknpWorld *world, int threadIndex)
{
    FUN_00175a80(world, threadIndex, world->streams260->blocks[0], world->streams260->blocks[1],
                 &world->streams260->arrayC10, 0, 0);
    FUN_00175a80(world, threadIndex, world->streams260->blocks[4], world->streams260->blocks[5], 0);
    FUN_00175a80(world, threadIndex, world->streams260->blocks[2], world->streams260->blocks[3],
                 &world->streams260->arrayC20, 0, 1);
}
