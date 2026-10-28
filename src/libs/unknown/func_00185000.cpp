/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

Object00185000::Object00185000(StreamReader *reader)
{
    if (reader) {
        reader->addReference();
    }
    this->reader = reader;
}
