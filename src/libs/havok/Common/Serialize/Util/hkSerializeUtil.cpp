/* src/libs/havok/Common/Serialize/Util/hkSerializeUtil.cpp: the file its
 * report names (config/homes.base.txt, FUN_0017da40). */
#include "tlg_lib_unknown.h"

/* A binary packfile of an object saved to a writer (Havok's
 * hkSerializeUtil::savePackfile): the options copied with the id of every
 * class test the object passes, the serialized-false flag by the save
 * options, a report when an XML packfile is asked for; HK_FAILURE without
 * a writer. derived name. */
hkResult FUN_0017da40(const void *object, const hkClass &klass, hkStreamWriter *writer,
                      const hkPackfileWriter::Options &optionsIn, void *userListener,
                      int saveOptions)
{
    if (!writer) {
        return HK_FAILURE;
    }
    hkPackfileWriter::Options options = optionsIn;
    for (ClassTest *test = D_57c8868; test; test = test->next) {
        if (test->test(object, &klass)) {
            const u16 id = test->id;
            options.classTestIds.pushBack(id);
        }
    }
    if (saveOptions & 2) {
        options.writeSerializedFalse = true;
    }
    if (saveOptions & 1) {
        HK_WARN(0x1d29011f, HK_SERIALIZE_UTIL_CPP, 627,
                "hkSerializeUtil::savePackfile will not save an Xml Packfile as this format can "
                "lose data precision, writing a binary packfile instead. Use the deprecated "
                "packfile writer if you need an Xml Packfile");
    }
    hkBinaryPackfileWriter packfileWriter(options);
    packfileWriter.FUN_0019cc20(object, klass, userListener);
    return packfileWriter.FUN_00183350(writer, &options);
}
