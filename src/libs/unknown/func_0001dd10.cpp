/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The codecs' cleanup callbacks, this file's (static, docs/DECISIONS.md
 * D39): nothing to destroy, the empty body the linker folded (0x1c1e0). */
static void cleanupLoadedObjecthkcdStaticTreeCodec3Axis(void *object) /* derived name */ {}

static void cleanupLoadedObjecthkcdStaticTreeCodec3Axis4(void *object) /* derived name */ {}

static void cleanupLoadedObjecthkcdStaticTreeCodec3Axis5(void *object) /* derived name */ {}

static void cleanupLoadedObjecthkcdStaticTreeCodec3Axis6(void *object) /* derived name */ {}

static void cleanupLoadedObjecthkcdStaticTreeCodecRaw(void *object) /* derived name */ {}

/* The codecs' member records, file-local (D17); the rows are written at
 * build time from the user's executable (D18, config/data_schema.base.txt). */
static const hkClassMember D_168fb30[1] = {
#include "gen/D_168fb30.inc"
};
static const hkClassMember D_168fb60[1] = {
#include "gen/D_168fb60.inc"
};
static const hkClassMember D_168fb90[2] = {
#include "gen/D_168fb90.inc"
};
static const hkClassMember D_168fbe0[2] = {
#include "gen/D_168fbe0.inc"
};
static const hkClassMember D_168fc30[1] = {
#include "gen/D_168fc30.inc"
};

/* This file's static initializer (0x1dd10): the static tree's node codecs'
 * reflection, the three-axis codec first and the 4-, 5- and 6-byte ones
 * over it, then the raw codec, each with its type info (no finish callback
 * and no vtable). */
const hkClass D_57ba610("hkcdStaticTreeCodec3Axis", 0, sizeof(hkcdStaticTree::Codec3Axis), 0, 0, 0,
                        0, D_168fb30, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba660;
const hkTypeInfo D_57ba660("hkcdStaticTreeCodec3Axis", "!hkcdStaticTree::Codec3Axis", 0,
                           cleanupLoadedObjecthkcdStaticTreeCodec3Axis, 0,
                           sizeof(hkcdStaticTree::Codec3Axis));
const hkClass D_57ba690("hkcdStaticTreeCodec3Axis4", &D_57ba610,
                        sizeof(hkcdStaticTree::Codec3Axis4), 0, 0, 0, 0, D_168fb60, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba6e0;
const hkTypeInfo D_57ba6e0("hkcdStaticTreeCodec3Axis4", "!hkcdStaticTree::Codec3Axis4", 0,
                           cleanupLoadedObjecthkcdStaticTreeCodec3Axis4, 0,
                           sizeof(hkcdStaticTree::Codec3Axis4));
const hkClass D_57ba710("hkcdStaticTreeCodec3Axis5", &D_57ba610,
                        sizeof(hkcdStaticTree::Codec3Axis5), 0, 0, 0, 0, D_168fb90, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba760;
const hkTypeInfo D_57ba760("hkcdStaticTreeCodec3Axis5", "!hkcdStaticTree::Codec3Axis5", 0,
                           cleanupLoadedObjecthkcdStaticTreeCodec3Axis5, 0,
                           sizeof(hkcdStaticTree::Codec3Axis5));
const hkClass D_57ba790("hkcdStaticTreeCodec3Axis6", &D_57ba610,
                        sizeof(hkcdStaticTree::Codec3Axis6), 0, 0, 0, 0, D_168fbe0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba7e0;
const hkTypeInfo D_57ba7e0("hkcdStaticTreeCodec3Axis6", "!hkcdStaticTree::Codec3Axis6", 0,
                           cleanupLoadedObjecthkcdStaticTreeCodec3Axis6, 0,
                           sizeof(hkcdStaticTree::Codec3Axis6));
const hkClass D_57ba810("hkcdStaticTreeCodecRaw", 0, sizeof(hkcdStaticTree::CodecRaw), 0, 0, 0, 0,
                        D_168fc30, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba860;
const hkTypeInfo D_57ba860("hkcdStaticTreeCodecRaw", "!hkcdStaticTree::CodecRaw", 0,
                           cleanupLoadedObjecthkcdStaticTreeCodecRaw, 0,
                           sizeof(hkcdStaticTree::CodecRaw));
