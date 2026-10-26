/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: reports an error through the error singleton. */
int hkError::FUN_00014cb0(int id, const char *description, const char *file, int line)
{
    return D_57af768->message(MESSAGE_ERROR, id, description, file, line);
}
