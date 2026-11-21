/* src/include/tlg_sce_gnm.h: the graphics library's imports the game calls,
 * named from their NIDs (config/imports.base.txt). The parameter names are
 * derived. */
#ifndef TLG_SCE_GNM_H
#define TLG_SCE_GNM_H

extern "C" {
int sceGnmUnmapComputeQueue(unsigned queue); /* FUN_01329890 */
/* writes a dispatch of the given thread groups into `dwords` words of a
 * command buffer; zero when it was written (FUN_01302150) */
int sceGnmDispatchDirect(unsigned *commands, unsigned dwords, unsigned groupsX, unsigned groupsY,
                         unsigned groupsZ, unsigned modifier);
}

#endif
