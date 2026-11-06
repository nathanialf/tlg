/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x8c0a0. */
static void cleanupLoadedObjecthkPackfileHeader(void *object) /* derived name */
{
    static_cast<hkPackfileHeader *>(object)->~hkPackfileHeader();
}

/* This file's static initializer (0x8e380): hkPackfileHeader's reflection, no parent,
 * its members, version 2, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57c82b0("hkPackfileHeader", 0, sizeof(hkPackfileHeader), 0, 0, 0, 0, D_16a2bc0, 13,
                        0, 0, 0, 2);
extern const hkTypeInfo D_57c8300;
const hkTypeInfo D_57c8300("hkPackfileHeader", "!hkPackfileHeader", 0,
                           cleanupLoadedObjecthkPackfileHeader, 0, sizeof(hkPackfileHeader));
