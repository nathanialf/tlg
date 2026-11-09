/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39), all four kept: an element declaration constructed in place through
 * its inline finish constructor (0x8ce10) and destroyed in place (0x8ce20);
 * the description through its out-of-line finish constructor (0x8ce40) and
 * its destructor, its declarations' names from the last (0x8ce50). derived
 * names. */
static void finishLoadedObjecthkxVertexDescriptionElementDecl(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexDescriptionElementDecl(flag);
}

static void cleanupLoadedObjecthkxVertexDescriptionElementDecl(void *object)
{
    static_cast<hkxVertexDescriptionElementDecl *>(object)->~hkxVertexDescriptionElementDecl();
}

static void finishLoadedObjecthkxVertexDescription(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexDescription(flag);
}

static void cleanupLoadedObjecthkxVertexDescription(void *object)
{
    static_cast<hkxVertexDescription *>(object)->~hkxVertexDescription();
}

/* The pointers of hkxVertexDescription's two enums, globals the
 * declaration's records read (0x16dc6e0 holds DataType's, 0x16dc6e8
 * DataUsage's), so the records are built when the file is initialized.
 * derived names. */
extern const hkClassEnum *D_16dc6e0;
extern const hkClassEnum *D_16dc6e8;

static hkClassMember D_57c7fc0[6] = {
    {"byteOffset",
     0,
     0,
     hkClassMember::TYPE_UINT32,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxVertexDescriptionElementDecl, byteOffset)),
     0},
    {"type",
     0,
     D_16dc6e0,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT16,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxVertexDescriptionElementDecl, type)),
     0},
    {"usage",
     0,
     D_16dc6e8,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT16,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxVertexDescriptionElementDecl, usage)),
     0},
    {"byteStride",
     0,
     0,
     hkClassMember::TYPE_UINT32,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxVertexDescriptionElementDecl, byteStride)),
     0},
    {"numElements",
     0,
     0,
     hkClassMember::TYPE_UINT8,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxVertexDescriptionElementDecl, numElements)),
     0},
    {"channelID",
     0,
     0,
     hkClassMember::TYPE_STRINGPTR,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxVertexDescriptionElementDecl, channelID)),
     0},
};

extern const hkClass D_57c7ec0;

/* hkxVertexDescription's tables, file-local (D17): its one record, its two
 * enums and their items; the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). */
static const hkClassMember D_16a27a0[1] = {
#include "gen/D_16a27a0.inc"
};
static const hkClassEnum::Item D_16a27d0[5] = {
#include "gen/D_16a27d0.inc"
};
static const hkClassEnum::Item D_16a2820[10] = {
#include "gen/D_16a2820.inc"
};
static const hkClassEnum D_16a28c0[2] = {
#include "gen/D_16a28c0.inc"
};

/* This file's static initializer (0x8cee0): the declaration's records, its
 * reflection (no parent, version 4) and type info (no vtable), then
 * hkxVertexDescription's (its two enums and one member, version 1) and type
 * info. */
const hkClass D_57c7ec0("hkxVertexDescriptionElementDecl", 0,
                        sizeof(hkxVertexDescriptionElementDecl), 0, 0, 0, 0, D_57c7fc0, 6, 0, 0, 0,
                        4);
extern const hkTypeInfo D_57c7f10;
const hkTypeInfo D_57c7f10("hkxVertexDescriptionElementDecl", "!hkxVertexDescription::ElementDecl",
                           finishLoadedObjecthkxVertexDescriptionElementDecl,
                           cleanupLoadedObjecthkxVertexDescriptionElementDecl, 0,
                           sizeof(hkxVertexDescriptionElementDecl));
const hkClass D_57c7f40("hkxVertexDescription", 0, sizeof(hkxVertexDescription), 0, 0, D_16a28c0, 2,
                        D_16a27a0, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57c7f90;
const hkTypeInfo D_57c7f90("hkxVertexDescription", "!hkxVertexDescription",
                           finishLoadedObjecthkxVertexDescription,
                           cleanupLoadedObjecthkxVertexDescription, 0,
                           sizeof(hkxVertexDescription));
