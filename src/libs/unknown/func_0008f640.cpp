/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: a union-find over numNodes nodes, each its own root (-1
 * in the parents); the state set to 1 once they are. */
UnionFind::UnionFind(UnionFindParents *parents_, int numNodes_) : parents(parents_)
{
    unknown14 = 0;
    numNodes = numNodes_;
    for (int i = 0; i < numNodes; i++) {
        parents->data[i] = -1;
    }
    state = 1;
    numRoots = -1;
}
