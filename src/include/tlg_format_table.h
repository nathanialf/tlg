/* A table of 32 packed 32-bit format words, indexed by a format number below
 * 32, that FUN_001a7060, FUN_001a7090, FUN_001a70c0, FUN_001a70f0, FUN_001a7120
 * and FUN_001a72a0 read one bit range each of (bits 22 to 24, ..., 27 to
 * 31). derived names throughout: the fields are not traced past their bits. */
#ifndef TLG_FORMAT_TABLE_H
#define TLG_FORMAT_TABLE_H

#include "tlg_types.h"

struct FormatWord001a72a0 { /* derived name */
    u32 bits;               /* derived name */
};

/* A table of 16 packed 32-bit words, indexed by the number FUN_001a3c50
 * stores, that FUN_001a7180, FUN_001a71f0, FUN_001a72f0 and FUN_001a7360 read
 * two-bit fields of (bits 0 to 7 and 8 to 13). derived names throughout. */
struct FieldWord001a7180 { /* derived name */
    u32 bits;              /* derived name */
};

#endif
