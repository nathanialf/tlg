/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include <stdarg.h>

/* derived names: an output whose C stream is its first field (FUN_00db61b0,
 * FUN_00de3a70 and FUN_00de43d0 write through it) */
struct Output00d97720 { /* derived name */
    FILE *file;         /* +0x0 */
};

/* derived name: a formatted message written to the output's stream */
void FUN_00d97720(Output00d97720 *output, const char *format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    vfprintf(output->file, format, arguments);
    va_end(arguments);
}
