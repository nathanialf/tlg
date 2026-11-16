/* src/include/tlg_sce_pad.h: the pad library's imports the game calls,
 * named from their NIDs (config/imports.base.txt). The parameter names are
 * derived. */
#ifndef TLG_SCE_PAD_H
#define TLG_SCE_PAD_H

extern "C" {
int scePadResetLightBar(int handle);    /* FUN_00c87690 */
int scePadResetOrientation(int handle); /* FUN_00c87800 */
}

#endif
