/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00d338a0, lea at
 * 0xd348d3): calls the member function pointer at +0x10 on the object at
 * +0x20 with the record itself. The object's class is not traced. */
class Target00d332b0; /* derived name */

struct Record00d332b0 { /* derived name */
    u8 unknown0[0x10];
    void (Target00d332b0::*unknown10)(Record00d332b0 *record);
    Target00d332b0 *unknown20;
};

void FUN_00d332b0(Record00d332b0 *record) /* derived name */
{
    (record->unknown20->*record->unknown10)(record);
}
