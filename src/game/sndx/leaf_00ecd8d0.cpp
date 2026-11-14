/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback whose address FUN_00ec9630 stores in a request it
 * builds on its stack (lea at 0xec9a52): unless the request's flags at +0x20
 * have a bit of 0xc, passes the record at +0x8 to FUN_00f05e30 when a bit of
 * 0x3 is set, then that record and the pointer at +0x0 to FUN_00f06160;
 * returns 0. The types and the callees' return types are not traced. */
struct Request00ecd8d0 { /* derived name */
    void *unknown0;
    void *unknown8;
    u8 unknown10[0x10];
    unsigned unknown20;
};

void FUN_00f05e30(void *record);              /* derived name */
void FUN_00f06160(void *record, void *value); /* derived name */

int FUN_00ecd8d0(Request00ecd8d0 *request) /* derived name */
{
    unsigned flags = request->unknown20;
    if ((flags & 0xc) == 0) {
        void *record = request->unknown8;
        if (flags & 0x3) {
            FUN_00f05e30(record);
        }
        FUN_00f06160(record, request->unknown0);
    }
    return 0;
}
