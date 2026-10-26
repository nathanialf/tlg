/* A texture container read by the renderer's texture loader (JsTex.cpp,
 * FUN_00bd8dd0 and FUN_00bda7a0), through two small out-of-line helpers in
 * the library region (FUN_001a3a70, FUN_001a3a80). derived names
 * throughout: the layout is read from the helpers' loads. */
#ifndef TLG_SCE_GNF_H
#define TLG_SCE_GNF_H

#include "tlg_types.h"

/* A 32-byte texture descriptor: eight 32-bit registers. */
struct GnfTexture /* derived name */
{
    u32 regs[8]; /* derived name */
};

/* The container: an 8-byte header, then the texture descriptors. */
struct GnfContents /* derived name */
{
    u8 unknown0[8];
    GnfTexture textures[1]; /* derived name: as many as the header counts */
};

/* A size and an alignment, returned together in one register. */
struct GnfSizeAlign /* derived name */
{
    u32 size;  /* derived name */
    u32 align; /* derived name */
};

u32 FUN_001a3a70(const GnfContents *contents, u32 index); /* derived name */
/* The pixels' size (the descriptor's last register) and their alignment
 * (two to the power in its second register); the loader at 0xbd9689 keeps
 * the pair. */
GnfSizeAlign FUN_001a3a80(const GnfContents *contents, u32 index); /* derived name */

#endif
