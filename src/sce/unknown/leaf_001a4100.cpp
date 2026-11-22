/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

/* derived names: FUN_001a3e00 with a null first argument and its own six after
 * it, its result returned (the sixth goes on the stack). No direct caller or
 * pointer to it is found. The types are not traced. */
int FUN_001a3e00(void *context, void *a, u32 b, u32 c, u32 d, u32 e, u32 f); /* derived name */

int FUN_001a4100(void *a, u32 b, u32 c, u32 d, u32 e, u32 f) /* derived name */
{
    return FUN_001a3e00(0, a, b, c, d, e, f);
}
