/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the router becomes the calling thread's. */
// NONMATCHING: the compiler's general-dynamic access (leaq x@tlsgd, callq __tls_get_addr) is the base's initial-exec form after the linker's GD-to-IE relaxation, which the gate does not model yet (docs/NOTES.md, Round 24)
void FUN_0000bb40(hkMemoryRouter *router) /* derived name */
{
    D_16dc070 = router;
}
