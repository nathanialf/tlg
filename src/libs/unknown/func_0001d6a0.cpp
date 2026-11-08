/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING (the initializer 0x1d6a0, its callbacks 0x1d620 and 0x1d680
// still claimed from their own files): 104 of 110, size equal; three
// registers of the node's type info and the solid's class: the base has the
// node's finish in r9, the solid's members in rcx and the node's cleanup in
// rbx, here rbx, r9 and rcx: greedy's evictions (a78/llvm33dbg llc
// -debug-only=regalloc: the finish's LEA evicts the solid's name from RBX,
// the cleanup's evicts the members from RCX); NOTES "Round 78A".
/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the node storage's finish kept beside the initializer (0x1d620),
 * the solid's finish (0x1d680) a jump to its out-of-line finish
 * constructor; the node's finish and cleanup, both empty, folded by the
 * linker into the empty body 0x1c1e0, the other two cleanups into the
 * shared virtual destructor call 0x2d0. The node storage's inline
 * destructors are emitted here with its vtable (0x1d4c0, 0x1d550). */
static void finishLoadedObjecthkcdPlanarSolidNodeStorage(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarSolid::NodeStorage(flag);
}

static void cleanupLoadedObjecthkcdPlanarSolidNodeStorage(void *object)
{
    static_cast<hkcdPlanarSolid::NodeStorage *>(object)->~NodeStorage();
}

static void finishLoadedObjecthkcdPlanarSolidNode(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarSolid::Node(flag);
}

static void cleanupLoadedObjecthkcdPlanarSolidNode(void *object)
{
    static_cast<hkcdPlanarSolid::Node *>(object)->~Node();
}

static void finishLoadedObjecthkcdPlanarSolid(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarSolid(flag);
}

static void cleanupLoadedObjecthkcdPlanarSolid(void *object)
{
    static_cast<hkcdPlanarSolid *>(object)->~hkcdPlanarSolid();
}

/* The address of each class's vtable, read from an object finished in a
 * buffer (folded to the address point for the node storage; the solid's
 * finish constructor is out of line). derived names. */
static const void *vtableOfhkcdPlanarSolidNodeStorage()
{
    union {
        void *vtable;
        char buffer[sizeof(hkcdPlanarSolid::NodeStorage)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdPlanarSolid::NodeStorage(flag);
    return object.vtable;
}

static const void *vtableOfhkcdPlanarSolid()
{
    union {
        void *vtable;
        char buffer[sizeof(hkcdPlanarSolid)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdPlanarSolid(flag);
    return object.vtable;
}

extern const hkClass D_57ba290; /* hkcdPlanarGeometryPlanesCollection's hkClass */
extern const hkClass D_57ba310;
extern const hkClass D_57ba360;

/* The classes' member records and the solid's enums with their items,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). */
static const hkClassMember D_168f620[3] = {
#include "gen/D_168f620.inc"
};
static const hkClassMember D_168f720[10] = {
#include "gen/D_168f720.inc"
};
static const hkClassMember D_168f6a0[3] = {
#include "gen/D_168f6a0.inc"
};
static const hkClassEnum::Item D_168f8b0[4] = {
#include "gen/D_168f8b0.inc"
};
static const hkClassEnum::Item D_168f8f0[6] = {
#include "gen/D_168f8f0.inc"
};
static const hkClassEnum D_168f950[2] = {
#include "gen/D_168f950.inc"
};

/* This file's static initializer (0x1d6a0): the node storage's reflection
 * over hkReferencedObject's (three members) and type info, the node's (ten
 * members, no vtable), then hkcdPlanarSolid's over hkcdPlanarEntity's (two
 * enums, three members). The type infos' names are the base's strings. */
const hkClass D_57ba360("hkcdPlanarSolidNodeStorage", &D_57b8640,
                        sizeof(hkcdPlanarSolid::NodeStorage), 0, 0, 0, 0, D_168f620, 3, 0, 0, 0, 1);
extern const hkTypeInfo D_57ba3b0;
const hkTypeInfo D_57ba3b0("hkcdPlanarSolidNodeStorage", "!hkcdPlanarSolid::NodeStorage",
                           finishLoadedObjecthkcdPlanarSolidNodeStorage,
                           cleanupLoadedObjecthkcdPlanarSolidNodeStorage,
                           vtableOfhkcdPlanarSolidNodeStorage(),
                           sizeof(hkcdPlanarSolid::NodeStorage));
const hkClass D_57ba310("hkcdPlanarSolidNode", 0, sizeof(hkcdPlanarSolid::Node), 0, 0, 0, 0,
                        D_168f720, 10, 0, 0, 0, 1);
extern const hkTypeInfo D_57ba3e0;
const hkTypeInfo D_57ba3e0("hkcdPlanarSolidNode", "!hkcdPlanarSolid::Node",
                           finishLoadedObjecthkcdPlanarSolidNode,
                           cleanupLoadedObjecthkcdPlanarSolidNode, 0,
                           sizeof(hkcdPlanarSolid::Node));
extern const hkClass D_57ba410;
const hkClass D_57ba410("hkcdPlanarSolid", &D_57ba190, sizeof(hkcdPlanarSolid), 0, 0, D_168f950, 2,
                        D_168f6a0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba460;
const hkTypeInfo D_57ba460("hkcdPlanarSolid", "!hkcdPlanarSolid", finishLoadedObjecthkcdPlanarSolid,
                           cleanupLoadedObjecthkcdPlanarSolid, vtableOfhkcdPlanarSolid(),
                           sizeof(hkcdPlanarSolid));
