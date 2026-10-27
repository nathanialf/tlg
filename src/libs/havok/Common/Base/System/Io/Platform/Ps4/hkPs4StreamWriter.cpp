/* src/libs/havok/Common/Base/System/Io/Platform/Ps4/hkPs4StreamWriter.cpp: the
 * file its assert names (config/homes.base.txt, FUN_00091ef0). */
#include "tlg_hk_reflect.h"
#include "tlg_sce_fios.h"
#include "tlg_types.h"

/* derived names: the stream writer over a Fios file handle at +0xc (vtable
 * address point 0x16a34f0, stored by the opener at 0x91d50: slot 5,
 * FUN_00091ff0, tells whether the handle is valid; slot 6, FUN_00091ef0, writes; slot 7, 0x91fe0, syncs; slot 9,
 * 0x92010, seeks; slot 10 tells the position). The class takes its name
 * from the file. Slot 11 of the vtable 0x16a3560 (another class reading
 * through a Fios handle at +0xc, its slots 7 and 9 seeking) holds the same
 * body. */
class hkPs4StreamWriter /* derived name */
{
  public:
    virtual ~hkPs4StreamWriter();

    void FUN_00091fe0();                           /* vtable slot 7; derived name */
    hkBool FUN_00091ff0() const;                   /* vtable slot 5; derived name */
    hkResult FUN_00092010(int offset, int whence); /* vtable slot 9; derived name */
    int FUN_00092030() const;                      /* vtable slot 10; derived name */

    u8 unknown8[4];
    SceFiosFH handle; /* derived name */
    /* Whether the writer closes the handle (the destructor 0x91eb0 tests
     * it). derived name. */
    bool ownsHandle;
};

hkPs4StreamWriter::~hkPs4StreamWriter()
{
    if (handle >= 0 && ownsHandle) {
        sceFiosFHCloseSync(0, handle);
        handle = -1;
    }
}

/* Flush: wait until what was written reaches the file, when the handle is
 * valid. */
void hkPs4StreamWriter::FUN_00091fe0() /* derived name */
{
    if (handle >= 0) {
        sceFiosFHSyncSync(0, handle);
    }
}

hkBool hkPs4StreamWriter::FUN_00091ff0() const /* derived name */
{
    return handle >= 0;
}

/* Seek: the handle's new offset is -1 when the seek failed. */
hkResult hkPs4StreamWriter::FUN_00092010(int offset, int whence) /* derived name */
{
    return sceFiosFHSeek(handle, offset, whence) == -1 ? HK_FAILURE : HK_SUCCESS;
}

int hkPs4StreamWriter::FUN_00092030() const /* derived name */
{
    return sceFiosFHTell(handle);
}
