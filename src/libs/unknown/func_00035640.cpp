/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

typedef hkcdStaticMeshTreeBase::PrimitiveDataRunBase<hknpCompressedMeshShapeTreeDataRunData>
    DataRunBase00035640; /* derived name */
typedef hkcdStaticMeshTree<hkcdStaticMeshTreeCommonConfig<u32, u64, 11, 21>,
                           hknpCompressedMeshShapeTreeDataRun>
    MeshTree00035640; /* derived name */

/* derived names: the finish callback of the mesh tree instance's type info
 * (0x57be570): construct the object in place from a loaded image through
 * its out-of-line finish constructor. The linker folded it onto the
 * previous file's equal callback for hknpCompressedMeshShapeTree, 0x34e30. */
static void
finishLoadedObjecthkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun(
    void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_000a9140(static_cast<hknpCompressedMeshShapeTree *>(object), flag);
}

/* The run base's cleanup callback, this file's (static, docs/DECISIONS.md
 * D39): nothing to clean up; the linker folded it into the empty body
 * 0x1c1e0. */
static void
cleanupLoadedObjecthkcdStaticMeshTreeBasePrimitiveDataRunBasehknpCompressedMeshShapeTreeDataRunData(
    void *object) /* derived name */
{
    static_cast<DataRunBase00035640 *>(object)->~DataRunBase00035640();
}

/* derived name: the cleanup callback of the mesh tree instance's type info
 * (0x3575b): the tree destroyed in place, its data runs, shared and packed
 * vertices given back, then the base's destructor; folded onto the previous
 * file's equal callback for hknpCompressedMeshShapeTree, 0x34e40. */
static void
cleanupLoadedObjecthkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun(
    void *object) /* derived name */
{
    static_cast<hknpCompressedMeshShapeTree *>(object)->~hknpCompressedMeshShapeTree();
}

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
    cleanupLoadedObjecthkcdStaticMeshTreeBasePrimitiveDataRunBasehknpCompressedMeshShapeTreeDataRunData,
    0, sizeof(DataRunBase00035640));
const hkClass D_57be520(
    "hkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun",
    &D_57bc310, sizeof(MeshTree00035640), 0, 0, D_1692e20, 1, D_1692d80, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57be570;
const hkTypeInfo D_57be570(
    "hkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun",
    "!hkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun_typename",
    finishLoadedObjecthkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun,
    cleanupLoadedObjecthkcdStaticMeshTreehkcdStaticMeshTreeCommonConfigunsignedintunsignedlonglong1121hknpCompressedMeshShapeTreeDataRun,
    0, sizeof(MeshTree00035640));
