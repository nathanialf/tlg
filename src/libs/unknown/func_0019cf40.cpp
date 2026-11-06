/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hkPackfileWriter::FUN_0019cf40(const void *object, const hkClass *objectClass)
{
    if (FUN_00017f40(objectClass->FUN_00004200(), "hkClass") != 0) {
        return 1;
    }
    const hkClass *klass = static_cast<const hkClass *>(object);
    const hkClass *known =
        reinterpret_cast<const hkClass *>(map50.FUN_00091900(klass->FUN_00004200(), 0));
    if (!known) {
        map50.FUN_00091690(klass->FUN_00004200(), hkUlong(klass));
        return 1;
    }
    if (klass->FUN_000045c0(0) != known->FUN_000045c0(0)) {
        char assertBuf[512];
        BufferOstream ostr(assertBuf, sizeof(assertBuf));
        ostr.FUN_00008440("Conflicting metadata found for class ")
            .FUN_00008440(klass->FUN_00004200())
            .FUN_00008440(". Perhaps you have called setContents on data which has not been "
                          "updated to the current version.");
        if (hkError::FUN_00014cb0(0x2518721c, assertBuf, HK_PACKFILE_WRITER_CPP, 184)) {
            HK_BREAKPOINT(0);
        }
    }
    map20.insert(hkUlong(klass), hkUlong(int(map20.FUN_00013b30(hkUlong(known), hkUlong(-1)))));
    map68.insert(hkUlong(klass), hkUlong(known));
    return 0;
}
