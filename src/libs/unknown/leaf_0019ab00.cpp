/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the platform object writer's target layout, the one its
 * object copier writes to. */
const Layout00180ef0 &hkPlatformObjectWriter::FUN_0019ab00() const /* derived name */
{
    return copier->layoutOut;
}
