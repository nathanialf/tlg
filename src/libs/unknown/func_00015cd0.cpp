/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Each block destroyed and then given back: the free's own null test stays
 * after the entries' loop (a delete expression would test before it, where
 * the loop's test settles it). */
Object00015700::~Object00015700()
{
    while (firstBlock) {
        Block *block = firstBlock;
        Block *next = block->next;
        block->~Block();
        Block::operator delete(block, sizeof(Block));
        firstBlock = next;
    }
}
