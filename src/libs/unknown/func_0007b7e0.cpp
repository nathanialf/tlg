/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

extern const hkClassEnum D_169c480[]; /* derived name: hkpConstraintMotor's one enum, MotorType */
/* The enum's pointer, a global the member record reads (0x16dc658 holds
 * 0x169c480), so the record is built when the file is initialized. derived
 * name. */
extern const hkClassEnum *D_16dc658;

static hkClassMember D_57c3b40[1] = {
    {"type",
     0,
     D_16dc658,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_INT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkpConstraintMotor, type)),
     0},
};

/* This file's static initializer (0x7b7e0): hkpConstraintMotor's reflection
 * over hkReferencedObject's, its enum and its one member. */
const hkClass D_57c3af0("hkpConstraintMotor", &D_57b8640, sizeof(hkpConstraintMotor), 0, 0,
                        D_169c480, 1, D_57c3b40, 1, 0, 0, 0, 0);
