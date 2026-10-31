/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

typedef hkcdStaticMeshTreeBase::PrimitiveDataRunBase<hknpCompressedMeshShapeTreeDataRunData>
    DataRunBase00035640; /* derived name */
typedef hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<u32, u64, 11, 21>,
                           hknpCompressedMeshShapeTreeDataRun>
    MeshTree00035640; /* derived name */

/* The run base's cleanup callback: nothing to clean up (the linker folded
 * it into the empty body 0x1c1e0; D15's round 57 addendum). */
void FUN_0001c1e0(void *object) {}

/* The mesh tree instance's callbacks, folded by the linker onto
 * hknpCompressedMeshShapeTree's (func_00034e30.cpp, func_00034e40.cpp; the
 * same bodies, D15's addenda). */
void FUN_00034e30(void *object, int finishing);
void FUN_00034e40(void *object);

extern const hkClassMember D_1692d00[]; /* derived name: the run base's records */
extern const hkClassMember D_1692d80[]; /* derived name: the mesh tree instance's records */
extern const hkClassEnum D_1692e20[];   /* derived name: its one enum */

/* This file's static initializer (0x35640): the reflection and type info of
 * the compressed mesh's run base instance (no parent, three members), then
 * of the mesh tree instance over hkcdStaticMeshTreeBase's (one enum, three
 * members), neither with a vtable. The type infos' names are the base's
 * strings. */
const hkClass
    D_57be4a0("hkcdStaticMeshTreeBasePrimitiveDataRunBasehknpCompressedMeshShapeTreeDataRunData", 0,
              sizeof(DataRunBase00035640), 0, 0, 0, 0, D_1692d00, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57be4f0;
const hkTypeInfo D_57be4f0(
    "hkcdStaticMeshTreeBasePrimitiveDataRunBasehknpCompressedMeshShapeTreeDataRunData",
    "!hkcdStaticMeshTreeBasePrimitiveDataRunBasehknpCompressedMeshShapeTreeDataRunData_typename", 0,
    FUN_0001c1e0, 0, sizeof(DataRunBase00035640));
const hkClass D_57be520(
    "hkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun",
    &D_57bc310, sizeof(MeshTree00035640), 0, 0, D_1692e20, 1, D_1692d80, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57be570;
const hkTypeInfo D_57be570(
    "hkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun",
    "!hkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun_typename",
    FUN_00034e30, FUN_00034e40, 0, sizeof(MeshTree00035640));
