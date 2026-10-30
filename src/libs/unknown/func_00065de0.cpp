/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

Object00065f20::~Object00065f20()
{
    int *parentStorage = parents->data;
    delete unionFind;
    delete parents;
    D_16dc070->temp58->blockFree(parentStorage, numNodes * int(sizeof(int)));
}
