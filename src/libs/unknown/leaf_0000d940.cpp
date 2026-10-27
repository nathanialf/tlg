/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The stack tracer's destructor: nothing to destroy (slot 0 of its vtable,
 * 0x168d850; the static instance's exit handler, registered at 0x6c05).
 * The body behind the slot at 0x168d870 too, which cites it by address. */
StackTracer::~StackTracer() {}
