/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_mutex.h"
#include "tlg_libc.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16bdb40 (config/vtables.derived.base.txt): it stores the vtable and
 * destroys the mutex member at +0x110, whose destructor (leaf_013847e0.cpp)
 * the module inlines; slot 8, FUN_00e5bc80, opens a handle for its argument
 * through slot 3 (with 0), takes slot 7's answer for it and closes it
 * through slot 4, null without a handle. A handle holds a C stream
 * (FUN_00de9a00's file handle): slot 7, FUN_00e5bc30, gives its size (the
 * position restored), slot 12, FUN_00e5bd70, opens a handle as slot 8 does
 * and returns slot 9's answer for it and a record, the record cleared and 0
 * without a handle, slot 14, FUN_00e5bde0, classifies a path by stat (1 a
 * directory, 0 a regular file, -1 otherwise or when stat fails), slot 15, FUN_00e5be90, reads size bytes at an offset
 * into a buffer, 1 when the seek succeeds (else 0). The other members and slots are
 * not traced. The destructor is
 * the class's key function, so this file emits the vtable. */
struct FileHandle00e5b7e0 /* derived name */
{
    FILE *file; /* +0x0 */
};

/* derived name: 0x20 bytes slot 9 fills for a handle, cleared by slot 12
 * when no handle opens (one 32-byte store); not traced */
struct Record00e5b7e0 {
    u8 unknown0[0x20];
};

class Object00e5b7e0 /* derived name */
{
  public:
    virtual ~Object00e5b7e0();
    virtual void slot2();                                      /* derived name; not traced */
    virtual FileHandle00e5b7e0 *slot3(void *key, int unknown); /* derived name; not traced */
    virtual void slot4(FileHandle00e5b7e0 *handle);            /* derived name; not traced */
    virtual void slot5();                                      /* derived name; not traced */
    virtual void slot6();                                      /* derived name; not traced */
    virtual long slot7(FileHandle00e5b7e0 *handle);            /* derived name */
    virtual long slot8(void *key);                             /* derived name */
    virtual int slot9(FileHandle00e5b7e0 *handle,
                      Record00e5b7e0 *record);             /* derived name; not traced */
    virtual void slot10();                                 /* derived name; not traced */
    virtual void slot11();                                 /* derived name; not traced */
    virtual int slot12(void *key, Record00e5b7e0 *record); /* derived name */
    virtual void slot13();                                 /* derived name; not traced */
    virtual int slot14(const char *path);                  /* derived name */
    virtual int slot15(FileHandle00e5b7e0 *handle, unsigned offset, void *buffer,
                       size_t size); /* derived name */

  private:
    u8 unknown8[0x108];
    Mutex013847e0 unknown110; /* +0x110 */
};

// NONMATCHING (the deleting destructor FUN_00e5b830 only): DeadStoreElimination's
// handleFree removes the inlined mutex destructor's two clearing stores before
// operator delete; the base keeps them (also at 0xa07ac7 and 0xcf1be7, the same
// member before a delete), a question of where the cross-file inlining ran.
Object00e5b7e0::~Object00e5b7e0() {}

long Object00e5b7e0::slot7(FileHandle00e5b7e0 *handle)
{
    FILE *file = handle->file;
    const long position = ftell(file);
    fseek(file, 0, SEEK_END);
    const long size = ftell(file);
    fseek(file, position, SEEK_SET);
    return size;
}

long Object00e5b7e0::slot8(void *key)
{
    FileHandle00e5b7e0 *handle = slot3(key, 0);
    if (!handle)
        return 0;
    const long result = slot7(handle);
    slot4(handle);
    return result;
}

int Object00e5b7e0::slot12(void *key, Record00e5b7e0 *record)
{
    FileHandle00e5b7e0 *handle = slot3(key, 0);
    if (!handle) {
        memset(record, 0, sizeof *record);
        return 0;
    }
    const int result = slot9(handle, record);
    slot4(handle);
    return result;
}

// NONMATCHING: block placement: the build duplicates the -1 block into stat's
// failure arm (`je` over `mov eax, -1; jmp`), the base falls through to the mode
// tests and keeps one -1 block at the end (placement's tail duplication; the
// shape -tail-dup-placement=false gives, which this branch's flags do not have)
int Object00e5b7e0::slot14(const char *path)
{
    struct stat status;
    if (stat(path, &status) == 0) {
        if (status.st_mode & S_IFDIR)
            return 1;
        if (status.st_mode & S_IFREG)
            return 0;
    }
    return -1;
}

int Object00e5b7e0::slot15(FileHandle00e5b7e0 *handle, unsigned offset, void *buffer, size_t size)
{
    FILE *file = handle->file;
    if (fseek(file, offset, SEEK_SET) != 0)
        return 0;
    fread(buffer, 1, size, file);
    return 1;
}
