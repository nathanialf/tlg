/* src/libs/havok/Common/Serialize/ResourceDatabase/hkResourceHandle.cpp:
 * the file its warning names (config/homes.base.txt, FUN_0017f770). */
#include "tlg_lib_unknown.h"

/* The file hkResourceHandle.cpp's reports name (the string at 0x14cb7d6). */
#define HK_RESOURCE_HANDLE_CPP                                                                     \
    "Y:\\NightlyJobs\\20141121-01\\Source\\Common\\Serialize\\ResourceDatabase\\hkResourceHandle.cpp"

void hkMemoryResourceHandle::FUN_0017f480(hkArray<Link> &linksOut) const
{
    linksOut.size = 0;
    linksOut.reserve(references.getSize());
    for (int i = 0; i < references.getSize(); i++) {
        Link &link = *linksOut.expandByUnchecked(1);
        void *object = variant.object;
        const char *memberName = references[i].memberName.cString();
        const hkClass *klass = FUN_000902f0(&variant);
        const hkClassMember *member;
        const char *dot;
        while ((dot = FUN_00018060(memberName, '.')) != HK_NULL) {
            char buffer[512];
            const int length = int(dot - memberName);
            FUN_00017e70(buffer, memberName, length);
            buffer[length] = 0;
            memberName += length + 1;
            member = klass->FUN_00004470(buffer);
            if (!member) {
                goto memberNotFound;
            }
            if (member->type != hkClassMember::TYPE_STRUCT) {
                char assertBuf[512];
                BufferOstream ostr(assertBuf, sizeof(assertBuf));
                ostr.FUN_00008440("Member is not of type struct : ").FUN_00008440(buffer);
                hkError::FUN_00014c70(0xf032edfe, assertBuf, HK_RESOURCE_HANDLE_CPP, 128);
                goto memberNotFound;
            }
            klass = FUN_00004250(member);
            object = hkAddByteOffset(object, member->offset);
        }
        member = klass->FUN_00004470(memberName);
        if (member) {
            link.memberName = memberName;
            link.memberAccessor = hkClassMemberAccessor(object, member);
            link.externalId = references[i].externalId.cString();
            continue;
        }
    memberNotFound:
        linksOut.popBack();
        char assertBuf[512];
        BufferOstream ostr(assertBuf, sizeof(assertBuf));
        ostr.FUN_00008440("Cannot find member : ").FUN_00008440(memberName);
        hkError::FUN_00014c70(0xf032edf1, assertBuf, HK_RESOURCE_HANDLE_CPP, 146);
    }
}

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

void hkMemoryResourceContainer::FUN_0017f9b0(const hkResourceMap *map)
{
    hkArray<hkResourceHandle *> handles;
    FUN_0017fa60(handles);
    for (int i = 0; i < handles.size; i++) {
        handles[i]->FUN_0017f770(map);
    }
}

void hkResourceContainer::FUN_0017fa60(hkArray<hkResourceHandle *> &handlesOut)
{
    for (hkResourceContainer *child = FUN_001806b0(HK_NULL, HK_NULL); child;
         child = FUN_001806b0(HK_NULL, child)) {
        child->FUN_0017fa60(handlesOut);
    }
    for (hkResourceHandle *handle = FUN_0017ff90(HK_NULL, HK_NULL, HK_NULL); handle;
         handle = FUN_0017ff90(HK_NULL, HK_NULL, handle)) {
        handlesOut.pushBack(handle);
    }
}

/* hkMemoryResourceContainer's finish constructor: the name finished out of
 * line; a loaded container's children get their parent back. */
hkMemoryResourceContainer::hkMemoryResourceContainer(hkFinishLoadedObjectFlag flag)
    : hkResourceContainer(flag), name(flag), resourceHandles(flag), children(flag)
{
    if (flag.finishing) {
        for (int i = 0; i < children.getSize(); i++) {
            children[i]->parent = this;
        }
    }
}

/* The memory resource container destroyed (the compiler's D0 at 0x17fbd0
 * and D1 at 0x17fc20): the members only, the children and the resources
 * from the last, then the name. */
hkMemoryResourceContainer::~hkMemoryResourceContainer() {}

hkResourceHandle *hkMemoryResourceContainer::FUN_0017fdb0(const char *handleName,
                                                          hkReferencedObject *object,
                                                          const hkClass *klass)
{
    hkMemoryResourceHandle *handle = new hkMemoryResourceHandle();
    handle->FUN_0017d550(handleName);
    handle->FUN_0017f320(object, klass);
    resourceHandles.pushBack(handle);
    handle->removeReference();
    return handle;
}

/* Whether a handle's name is the one given (its name written into a buffer
 * of its own, given back before the answer is used, 0x180063). derived
 * name. */
static inline bool hasName(const hkResourceHandle *handle, const char *name)
{
    hkStringBuf buffer;
    return FUN_00017f40(name, handle->getName(buffer)) == 0;
}

// NONMATCHING: equal under D42's compiler; claimed when the patch lands. One loop with the name
// and the class tested inside; the base holds it twice, chosen by `objectName`, the non-trivial
// unswitch of docs/DECISIONS.md D42, which spends the compile's budget before 0x1806b0's search
// loop (left whole in the base). Under the gate's compiler: one loop, 522 bytes against 601.
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
    for (; i < resourceHandles.getSize(); i++) {
        hkResourceHandle *handle = resourceHandles[i];
        if (objectName && !hasName(handle, objectName)) {
            continue;
        }
        if (klass) {
            const hkClass *objectClass = handle->getClass();
            if (objectClass != klass && !klass->FUN_00004270(objectClass)) {
                if (objectName) {
                    char assertBuf[512];
                    BufferOstream ostr(assertBuf, sizeof(assertBuf));
                    ostr.FUN_00008440("Class mismatch, cannot resolve link: ")
                        .FUN_00008440(klass->FUN_00004200())
                        .FUN_00008440(" != ")
                        .FUN_00008440(objectClass->FUN_00004200());
                    hkError::FUN_00014c70(0xf034ed22, assertBuf, HK_RESOURCE_HANDLE_CPP, 317);
                    return HK_NULL;
                }
                continue;
            }
        }
        return handle;
    }
    return HK_NULL;
}

void hkMemoryResourceContainer::FUN_001801f0(hkResourceHandle *handle) /* derived name */
{
    const int index = resourceHandles.indexOf(static_cast<hkMemoryResourceHandle *>(handle));
    if (index >= 0) {
        resourceHandles.removeAtAndCopy(index);
    }
}

// NONMATCHING: 492 bytes against 508. The base keeps the found child in
// %r12, the register the new container takes, so both paths return through
// one `mov rax, r12`; it takes the new container's count word and parent
// field as addresses once (`lea rbx, [r12 + 8]`, `lea r13, [r12 + 0x18]`) for
// every count change and the parent's store; the append's null test and
// store come in another order (docs/NOTES.md, Round 75B).
hkResourceContainer *hkMemoryResourceContainer::FUN_00180360(const char *containerName)
{
    hkResourceContainer *container = FUN_001806b0(containerName, HK_NULL);
    if (!container) {
        hkRefPtr<hkMemoryResourceContainer> created = new hkMemoryResourceContainer(containerName);
        children.pushBack(created);
        created->releaseReference();
        created->parent = this;
        container = created;
    }
    return container;
}

void hkMemoryResourceContainer::FUN_00180560(hkMemoryResourceContainer *child)
{
    const int index = children.indexOf(child);
    if (index >= 0) {
        children.removeAt(index);
    }
}

hkMemoryResourceContainer *
hkMemoryResourceContainer::FUN_001806b0(const char *childName, const hkResourceContainer *previous)
{
    int i = 0;
    if (previous) {
        while (i < children.getSize()) {
            if (children[i++] == previous) {
                break;
            }
        }
    }
    while (i < children.getSize()) {
        hkMemoryResourceContainer *child = children[i++];
        if (!childName || FUN_00017f40(childName, child->name.cString()) == 0) {
            return child;
        }
    }
    return 0;
}
