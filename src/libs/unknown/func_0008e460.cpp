/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x8c0a0. */
static void cleanupLoadedObjecthkPackfileSectionHeader(void *object) /* derived name */
{
    static_cast<hkPackfileSectionHeader *>(object)->~hkPackfileSectionHeader();
}

/* This file's static initializer (0x8e460): hkPackfileSectionHeader's reflection, no parent,
 * its members, version 1, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57c8330("hkPackfileSectionHeader", 0, sizeof(hkPackfileSectionHeader), 0, 0, 0, 0,
                        D_16a2dd0, 10, 0, 0, 0, 1);
extern const hkTypeInfo D_57c8380;
const hkTypeInfo D_57c8380("hkPackfileSectionHeader", "!hkPackfileSectionHeader", 0,
                           cleanupLoadedObjecthkPackfileSectionHeader, 0,
                           sizeof(hkPackfileSectionHeader));
