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

// NONMATCHING: the virtual member pointer's slot load is `[rcx + rdx - 1]` (the pointer's value the base register) in the base, `[rdx + rcx - 1]` (the vtable) in the compile; every instruction else equal. The prebuilt 3.6.2 and 3.8.1 compile this source to the base's bytes, 3.9.1 and 4.0.0 to the compile's, with the same IR after CodeGenPrepare under 3.8.1 and 4.0.0: a selection-DAG change of 3.9 (a 4.0.0-line question)
void FUN_00d332b0(Record00d332b0 *record) /* derived name */
{
    (record->unknown20->*record->unknown10)(record);
}
