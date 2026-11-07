/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 492 bytes against 508. The base keeps the found child in
// %r12, the register the new container takes, so both paths return through
// one `mov rax, r12`; it takes the new container's count word and parent
// field as addresses once (`lea rbx, [r12 + 8]`, `lea r13, [r12 + 0x18]`) for
// every count change and the parent's store; the append's null test and
// store come in another order (docs/NOTES.md, Round 75B).
hkResourceContainer *hkMemoryResourceContainer::FUN_00180360(const char *containerName)
{
    hkResourceContainer *container = FUN_001806b0(containerName, HK_NULL);
    if (!container) {
        hkRefPtr<hkMemoryResourceContainer> created = new hkMemoryResourceContainer(containerName);
        children.pushBack(created);
        created->releaseReference();
        created->parent = this;
        container = created;
    }
    return container;
}
