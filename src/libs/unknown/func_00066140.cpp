/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

extern const hkClassEnum D_1699890[]; /* derived name: hknpShapeTagCodec's one enum, Type */
/* The enum's pointer, a global the member record reads (0x16dc630 holds
 * 0x1699890), so the record is built when the file is initialized. derived
 * name. */
extern const hkClassEnum *D_16dc630;

static hkClassMember D_57c1b50[1] = {
    {"type",
     0,
     D_16dc630,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hknpShapeTagCodec, type)),
     0},
};

/* This file's static initializer (0x66140): hknpShapeTagCodec's reflection
 * over hkReferencedObject's, its enum and its one member, version 1. */
const hkClass D_57c1b00("hknpShapeTagCodec", &D_57b8640, sizeof(hknpShapeTagCodec), 0, 0, D_1699890,
                        1, D_57c1b50, 1, 0, 0, 0, 1);
