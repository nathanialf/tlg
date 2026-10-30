/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 10 of hkPackfileWriter's vtable (0x16a6960): a section
 * added by its tag when the tag is new, a copy of the tag kept with its
 * index among the sections. */
void hkPackfileWriter::FUN_0019d0d0(const char *sectionTag)
{
    int index;
    if (sectionTagToIndex.get(sectionTag, &index) == HK_FAILURE) {
        char *tag = FUN_000180c0(sectionTag);
        sectionTagToIndex.insert(tag, sectionTags.getSize());
        sectionTags.pushBack(tag);
    }
}

/* derived name: a section's index by its tag, as slot 10 adds it. */
inline int hkPackfileWriter::sectionIndex(const char *sectionTag)
{
    int index;
    if (sectionTagToIndex.get(sectionTag, &index) == HK_SUCCESS) {
        return index;
    }
    char *tag = FUN_000180c0(sectionTag);
    index = sectionTags.getSize();
    sectionTagToIndex.insert(tag, index);
    sectionTags.pushBack(tag);
    return index;
}

int hkPackfileWriter::FUN_0019cd20(const char *sectionTag)
{
    return sectionIndex(sectionTag);
}

/* derived name: slot 11 of hkPackfileWriter's vtable: an object placed in
 * the section of a tag, by the object's address. */
void hkPackfileWriter::FUN_0019d190(const void *object, const char *sectionTag)
{
    const u32 index = sectionIndex(sectionTag);
    objectToSectionIndex.FUN_000138a0(hkContainerHeapAllocator::get(), hkUlong(object), index);
}

/* Slot 12 (0x19d280): the objects of a class placed in the section of a
 * tag, the section added when it is new (0x19cd20's body inline). derived
 * name. */
void hkPackfileWriter::FUN_0019d280(const hkClass &klass, const char *sectionTag)
{
    const char *className = klass.FUN_00004200();
    classNameToSection.insert(className, sectionIndex(sectionTag));
}
