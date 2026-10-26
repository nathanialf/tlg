/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A test registers itself at the head of the list as it is built. */
ClassTest::ClassTest(u16 id, const char *name, Function test) : id(id), name(name), test(test)
{
    next = D_57c8868;
    D_57c8868 = this;
}
