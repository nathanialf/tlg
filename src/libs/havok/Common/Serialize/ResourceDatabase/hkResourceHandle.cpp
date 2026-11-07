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
