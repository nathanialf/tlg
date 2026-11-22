/* src/include/tlg_sce_record001af730.h: a 0x80-byte record of the shader
 * binary reader's SDK object (0x1af730 to 0x1afa10, its own CIE in
 * .eh_frame; src/sce/unknown/). Every name here is derived. */
#ifndef TLG_SCE_RECORD001AF730_H
#define TLG_SCE_RECORD001AF730_H

#include "tlg_types.h"

/* derived names: FUN_001af730 clears it but its u32 at +0x34; its destructor
 * (0x1af750) is empty and out of line, so the game's classes that hold one
 * (at +0x30: FUN_01304b00, FUN_0131f080, FUN_01326700) call it from theirs;
 * the 1-byte body is also the target of 3793 vtable slots, the linker's fold
 * of the empty functions. The fields are not traced. */
struct Record001af730 { /* derived name */
    ~Record001af730();

    u32 unknown0[13];
    u32 unknown34;
    u32 unknown38[18];
};

#endif
