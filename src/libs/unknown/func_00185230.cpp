/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: whether the input stream can be read: its reader's answer,
 * false without one (the hkBool passed through keeps the tail jump,
 * cookbook 25). */
hkBool InputStream::FUN_00185230() const /* derived name */
{
    return reader ? reader->isOk() : hkBool(false);
}
