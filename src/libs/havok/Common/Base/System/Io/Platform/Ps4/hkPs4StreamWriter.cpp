/* src/libs/havok/Common/Base/System/Io/Platform/Ps4/hkPs4StreamWriter.cpp: the
 * file its assert names (config/homes.base.txt, FUN_00091ef0). */
#include "tlg_lib_unknown.h"

/* derived names: the stream writer over a Fios file handle at +0xc (vtable
 * address point 0x16a34f0, stored by the opener at 0x91d50: slot 5,
 * FUN_00091ff0, tells whether the handle is valid; slot 6, FUN_00091ef0, writes; slot 7, 0x91fe0, syncs; slot 9,
 * 0x92010, seeks; slot 10 tells the position). The class takes its name
 * from the file. Slot 11 of the vtable 0x16a3560 (another class reading
 * through a Fios handle at +0xc, its slots 7 and 9 seeking) holds the same
 * body. */
class hkPs4StreamWriter : public hkStreamWriter /* derived name */
{
  public:
    /* A new writer over an opened handle, which it closes when it goes
     * (0x91dc4, inline in the opener FUN_00091d50). */
    hkPs4StreamWriter(SceFiosFH fileHandle) : handle(fileHandle), ownsHandle(true) {}

    /* The class allocator: a block of the thread's heap (0x91dc1). */
    static void *operator new(unsigned long numBytes)
    {
        return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
    }

    virtual ~hkPs4StreamWriter();

    /* The reference-counted class delete: the deleting destructor 0x91e30
     * frees at the recorded size, 0x18 by default. */
    static void operator delete(void *object, unsigned long numBytes)
    {
        freeReferencedObject(object, numBytes);
    }

    void FUN_00091fe0();                           /* vtable slot 7; derived name */
    hkBool FUN_00091ff0() const;                   /* vtable slot 5; derived name */
    hkResult FUN_00092010(int offset, int whence); /* vtable slot 9; derived name */
    int FUN_00092030() const;                      /* vtable slot 10; derived name */

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

/* derived names: a writer of a file opened through Fios with the open
 * flags given, or null when the open fails (0x91d50; the file system's
 * slot at 0x1bb9d asks it). The mode is not read. */
hkStreamWriter *FUN_00091d50(const char *path, int mode, int openFlags)
{
    SceFiosFH handle = -1;
    SceFiosOpenParams params = {};
    params.openFlags = openFlags;
    if (sceFiosFHOpenSync(0, &handle, path, &params) != 0) {
        return 0;
    }
    return new hkPs4StreamWriter(handle);
}
