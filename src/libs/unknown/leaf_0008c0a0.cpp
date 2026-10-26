/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkxVertexDescription's finish constructor: its decls are left as loaded,
 * so the body is empty, and the linker's one copy of it is also the body
 * behind 12 empty vtable slots in .data.rel.ro (from 0x16a2630). */
hkxVertexDescription::hkxVertexDescription(hkFinishLoadedObjectFlag flag) : decls(flag) {}
