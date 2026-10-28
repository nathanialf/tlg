/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

namespace
{
/* A directory listing of the Fios file system (vtable 0x168eb00, local to
 * the file: its address point 0x168eb10 taken by one bare lea), 0x38 bytes:
 * built by the file system's slot 10 (0x1bc80) over sceFiosDHOpen, which
 * sizes the entry buffer, and sceFiosDHOpenSync, which opens the handle into
 * it; slot 5 (0x1be80) reads the next entry that passes the pattern. Slots 0
 * and 1 are its destructors (0x1c010, 0x1bdd0), slots 2 to 4
 * hkReferencedObject's. The file system's slot 10 and slot 5 belong in this
 * file with it. derived names. */
class DirectoryIterator0001bc80 : public hkReferencedObject
{
  public:
    /* The listing opened twice: once with no buffer to learn the size its
     * entries need, then into a buffer of that size from the thread's heap. */
    DirectoryIterator0001bc80(FiosFileSystem *owner, const char *top, const char *wildcard)
        : fileSystem(owner), path(top), pattern(wildcard)
    {
        SceFiosDH probe = 0;
        const SceFiosOp op = sceFiosDHOpen(0, &probe, top, 0, 0);
        sceFiosOpWait(op);
        sceFiosDHCloseSync(0, probe);
        const int size = int(sceFiosOpGetActualCount(op));
        sceFiosOpDelete(op);
        buffer = FUN_0000bc30(*D_16dc070->temp58, size);
        opened = sceFiosDHOpenSync(0, &handle, top, buffer, size) == 0;
    }

    virtual ~DirectoryIterator0001bc80();

    /* Slot 5: the next entry whose name passes the pattern, into entry;
     * false at the end of the listing. */
    virtual bool FUN_0001be80(FileSystemEntry &entry);

    static void *operator new(unsigned long numBytes)
    {
        return D_16dc070->temp58->blockAlloc(static_cast<int>(numBytes));
    }

    static void operator delete(void *object, unsigned long numBytes)
    {
        freeReferencedObject(object, numBytes);
    }

    hkBool opened;              /* sceFiosDHOpenSync returned 0 */
    FiosFileSystem *fileSystem; /* the entries' file system */
    hkStringPtr path;           /* the directory listed */
    hkStringPtr pattern;        /* the names' pattern (FUN_0001a770) */
    SceFiosDH handle;           /* zero once closed */
    void *buffer;               /* the entries' buffer, from the thread's heap */
};

/* The destructor (0x1c010): the handle closed while open, the entry buffer
 * back to the thread's heap. */
DirectoryIterator0001bc80::~DirectoryIterator0001bc80()
{
    if (handle != 0) {
        sceFiosDHCloseSync(0, handle);
        handle = 0;
    }
    if (buffer != 0) {
        FUN_0000bc80(*D_16dc070->temp58, buffer);
    }
}
} // namespace

/* Slot 10 of the file system (0x1bc80; the stack canary for the probe's
 * handle): the listing, given up when it did not open. */
// NONMATCHING: 33 of 96 instructions; the base keeps the path in r14 and the
// result in r12 (zeroed before sceFiosDHOpen, the opened block first with
// `mov r12, rbx`), the compile keeps the path in r12 and the result in rbx
// (330 bytes against 336). Not worked yet (round 46 wrote it so the class's
// vtable and destructors are emitted).
hkReferencedObject *FiosFileSystem::FUN_0001bc80(const char *path, const char *pattern)
{
    const char *top = FUN_00017fe0(path) ? path : ".";
    DirectoryIterator0001bc80 *iterator = new DirectoryIterator0001bc80(this, top, pattern);
    if (iterator->opened) {
        return iterator;
    }
    delete iterator;
    return 0;
}
