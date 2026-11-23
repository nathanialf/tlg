/* src/include/tlg_sce_pad.h: the pad library's imports the game calls,
 * named from their NIDs (config/imports.base.txt). The parameter names are
 * derived. */
#ifndef TLG_SCE_PAD_H
#define TLG_SCE_PAD_H

#include "tlg_types.h"

/* derived names: the two motors' strengths, 0 to 255 (FUN_00c87210) */
struct PadVibration { /* derived name */
    u8 largeMotor;
    u8 smallMotor;
};

extern "C" {
int scePadClose(int handle);                                              /* FUN_00c66230 */
int scePadResetLightBar(int handle);                                      /* FUN_00c87690 */
int scePadResetOrientation(int handle);                                   /* FUN_00c87800 */
int scePadSetTiltCorrectionState(int handle, bool enable);                /* FUN_00c876e0 */
int scePadSetAngularVelocityDeadbandState(int handle, bool enable);       /* FUN_00c87770 */
int scePadSetVibration(int handle, const struct PadVibration *vibration); /* FUN_00c87210 */
}

#endif
