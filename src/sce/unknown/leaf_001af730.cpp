/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_sce_record001af730.h"

/* derived name: clears the record but +0x34 (tlg_sce_record001af730.h) */
void FUN_001af730(Record001af730 *record) /* derived name */
{
    for (int i = 0; i < 13; ++i) {
        record->unknown0[i] = 0;
    }
    for (int i = 0; i < 18; ++i) {
        record->unknown38[i] = 0;
    }
}
