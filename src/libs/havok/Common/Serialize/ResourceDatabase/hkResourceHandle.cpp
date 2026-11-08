/* src/libs/havok/Common/Serialize/ResourceDatabase/hkResourceHandle.cpp:
 * the file its warning names (config/homes.base.txt, FUN_0017f770). */
#include "tlg_lib_unknown.h"

/* The file hkResourceHandle.cpp's reports name (the string at 0x14cb7d6). */
#define HK_RESOURCE_HANDLE_CPP                                                                     \
    "Y:\\NightlyJobs\\20141121-01\\Source\\Common\\Serialize\\ResourceDatabase\\hkResourceHandle.cpp"

void hkResourceHandle::FUN_0017f770(const hkResourceMap *map)
{
    hkArray<Link> links;
    FUN_0017f480(links);

    for (int i = links.size - 1; i >= 0; i--) {
        Link &link = links[i];
        const hkClass *foundClass;
        void *foundObject = map->findObjectByName(link.externalId, &foundClass);
        if (!foundObject) {
            continue;
        }

        hkClassMemberAccessor &member = link.memberAccessor;
        const hkClassMember &classMember = member.FUN_00004250();
        const hkClass *linkClass = FUN_00004250(&classMember);
        if (!linkClass->FUN_00004270(foundClass) && foundClass != linkClass) {
            char assertBuf[512];
            BufferOstream ostr(assertBuf, sizeof(assertBuf));
            ostr.FUN_00008440("Class mismatch, cannot resolve link: ")
                .FUN_00008440(foundClass->FUN_00004200())
                .FUN_00008440(" != ")
                .FUN_00008440(linkClass->FUN_00004200());
            hkError::FUN_00014c70(0xf034ed21, assertBuf, HK_RESOURCE_HANDLE_CPP, 178);
            continue;
        }

        if (foundObject == FUN_00007f80()) {
            break;
        }
        member.FUN_001841d0(0) = foundObject;
        FUN_0017f3e0(classMember.name);
    }
}

/* Whether a handle's name is the one given (its name written into a buffer
 * of its own, given back before the answer is used, 0x180063). derived
 * name. */
static inline bool hasName(const hkResourceHandle *handle, const char *name)
{
    hkStringBuf buffer;
    return FUN_00017f40(name, handle->getName(buffer)) == 0;
}

// NONMATCHING: 18 of 152, size 560 against 601: D21's unswitch shape (a fifth witness, reported,
// not worked further): the base tests `i < size` once after the previous handle's search, then
// the name, and runs one of two copies of the loop (with the name compared; without it, the
// class test's null case taken out of the loop as a trivial unswitch), the shape a non-trivial
// unswitch of the loop-invariant `objectName` gives; one loop with the name tested inside
// compiles to one loop (3.3's LoopUnswitch refuses the non-trivial condition at -O2,
// LoopUnswitch.cpp:651), and the two loops written out test the name before each guard.
// NOTES Round 79A.
hkResourceHandle *hkMemoryResourceContainer::FUN_0017ff90(const char *objectName,
                                                          const hkClass *klass,
                                                          const hkResourceHandle *previous)
{
    int i = 0;
    if (previous) {
        while (i < resourceHandles.getSize()) {
            if (resourceHandles[i++] == previous) {
                break;
            }
        }
    }
    if (objectName) {
        for (; i < resourceHandles.getSize(); i++) {
            hkResourceHandle *handle = resourceHandles[i];
            if (!hasName(handle, objectName)) {
                continue;
            }
            if (klass) {
                const hkClass *objectClass = handle->getClass();
                if (objectClass != klass && !klass->FUN_00004270(objectClass)) {
                    char assertBuf[512];
                    BufferOstream ostr(assertBuf, sizeof(assertBuf));
                    ostr.FUN_00008440("Class mismatch, cannot resolve link: ")
                        .FUN_00008440(klass->FUN_00004200())
                        .FUN_00008440(" != ")
                        .FUN_00008440(objectClass->FUN_00004200());
                    hkError::FUN_00014c70(0xf034ed22, assertBuf, HK_RESOURCE_HANDLE_CPP, 317);
                    return HK_NULL;
                }
            }
            return handle;
        }
    } else {
        for (; i < resourceHandles.getSize(); i++) {
            hkResourceHandle *handle = resourceHandles[i];
            if (!klass) {
                return handle;
            }
            const hkClass *objectClass = handle->getClass();
            if (objectClass == klass || klass->FUN_00004270(objectClass)) {
                return handle;
            }
        }
    }
    return HK_NULL;
}
