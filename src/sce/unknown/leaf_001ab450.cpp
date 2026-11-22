/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

/* derived names: stores 8 in the ints at +0x2c and +0x30 (one 64-bit store),
 * then calls FUN_001ab470 on the object as a tail call; no caller or pointer
 * slot found. The callee's return type is not traced. Class and method
 * unknown. */
struct Object001ab450 { /* derived name */
    u8 unknown0[0x2c];
    int unknown2c;
    int unknown30;
};

void FUN_001ab470(Object001ab450 *self); /* derived name */

void FUN_001ab450(Object001ab450 *self) /* derived name */
{
    self->unknown2c = 8;
    self->unknown30 = 8;
    FUN_001ab470(self);
}
