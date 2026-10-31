/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpExternMeshShape's finish callback (func_0006c440.cpp). derived
 * name. */
void FUN_0006c440(void *object, int finishing);

/* hknpExternMeshShape's cleanup callback: the virtual destructor (the
 * shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_169abc0[]; /* derived name: hknpExternMeshShape's records */
extern const hkClassEnum D_169ac30[];   /* derived name: its one enum */

/* The address of hknpExternMeshShape's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhknpExternMeshShape() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpExternMeshShape)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpExternMeshShape(flag);
    return object.vtable;
}

// NONMATCHING: 3 of 67 with both callbacks external (D15): their GOT
// loads move greedy's choices (the guard's address in r15, a third
// callee-saved register); with both callbacks static (lea, as the base's
// file had them before the linker folded the cleanup into 0x2d0) it is 63
// of 65, the two left the local displacements a separate section per
// function would relocate (docs/NOTES.md, Round 69A: for the supervisor).
/* This file's static initializer (0x6c470): hknpExternMeshShape's
 * reflection over hknpCompositeShape's (its one enum and two members,
 * version 1) and type info, then hknpExternMeshShape::Geometry's
 * reflection over hkReferencedObject's (no members; abstract, no type
 * info). */
const hkClass D_57c2898("hknpExternMeshShape", &D_57c2cf8, sizeof(hknpExternMeshShape), 0, 0,
                        D_169ac30, 1, D_169abc0, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57c28e8;
const hkTypeInfo D_57c28e8("hknpExternMeshShape", "!hknpExternMeshShape", FUN_0006c440,
                           FUN_000002d0, vtableOfhknpExternMeshShape(),
                           sizeof(hknpExternMeshShape));
const hkClass D_57c2848("hknpExternMeshShapeGeometry", &D_57b8640,
                        sizeof(hknpExternMeshShape::Geometry), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
