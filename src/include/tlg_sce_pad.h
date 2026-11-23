/* src/include/tlg_sce_pad.h: the pad library's imports the game calls,
 * named from their NIDs (config/imports.base.txt). The parameter names are
 * derived. */
#ifndef TLG_SCE_PAD_H
#define TLG_SCE_PAD_H

extern "C" {
int scePadClose(int handle);                                        /* FUN_00c66230 */
int scePadResetLightBar(int handle);                                /* FUN_00c87690 */
int scePadResetOrientation(int handle);                             /* FUN_00c87800 */
int scePadSetTiltCorrectionState(int handle, bool enable);          /* FUN_00c876e0 */
int scePadSetAngularVelocityDeadbandState(int handle, bool enable); /* FUN_00c87770 */
}

#endif
