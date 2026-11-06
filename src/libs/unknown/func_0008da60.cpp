/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): kept at 0x8d9e0, 0x8da10 and 0x8da40 beside the initializer (the
 * external link's type info cites the variable's two, folded into them),
 * the environment's cleanup folded by the linker into the shared virtual
 * destructor call 0x2d0. */
static void finishLoadedObjecthkxEnvironmentVariable(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxEnvironmentVariable(flag);
}

static void cleanupLoadedObjecthkxEnvironmentVariable(void *object)
{
    static_cast<hkxEnvironmentVariable *>(object)->~hkxEnvironmentVariable();
}

static void finishLoadedObjecthkxEnvironment(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxEnvironment(flag);
}

static void cleanupLoadedObjecthkxEnvironment(void *object)
{
    static_cast<hkxEnvironment *>(object)->~hkxEnvironment();
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). The environment's cites the variable's
 * class. */
extern const hkClass D_57c80b0;

static const hkClassMember D_16a2950[2] = {
#include "gen/D_16a2950.inc"
};

/* The environment's record lives in another file (its address taken
 * through the GOT; cookbook 481). */
extern const hkClassMember D_16a29a0[];

/* The address of hkxEnvironment's vtable, read from an object finished in a
 * buffer (folded to the address point). derived name. */
static const void *vtableOfhkxEnvironment()
{
    union {
        void *vtable;
        char buffer[sizeof(hkxEnvironment)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxEnvironment(flag);
    return object.vtable;
}

/* This file's static initializer (0x8da60): hkxEnvironment::Variable's
 * reflection (no parent, two members) and type info, then hkxEnvironment's
 * over hkReferencedObject's (one member, version 1) and type info with its
 * vtable. The type infos' names are the base's strings. */
const hkClass D_57c80b0("hkxEnvironmentVariable", 0, sizeof(hkxEnvironmentVariable), 0, 0, 0, 0,
                        D_16a2950, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c8100;
const hkTypeInfo D_57c8100("hkxEnvironmentVariable", "!hkxEnvironment::Variable",
                           finishLoadedObjecthkxEnvironmentVariable,
                           cleanupLoadedObjecthkxEnvironmentVariable, 0,
                           sizeof(hkxEnvironmentVariable));
const hkClass D_57c8130("hkxEnvironment", &D_57b8640, sizeof(hkxEnvironment), 0, 0, 0, 0, D_16a29a0,
                        1, 0, 0, 0, 1);
extern const hkTypeInfo D_57c8180;
const hkTypeInfo D_57c8180("hkxEnvironment", "!hkxEnvironment", finishLoadedObjecthkxEnvironment,
                           cleanupLoadedObjecthkxEnvironment, vtableOfhkxEnvironment(),
                           sizeof(hkxEnvironment));
