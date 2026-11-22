/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_mutex.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16bdb40 (config/vtables.derived.base.txt): it stores the vtable and
 * destroys the mutex member at +0x110, whose destructor (leaf_013847e0.cpp)
 * the module inlines; slot 8, FUN_00e5bc80, opens a handle for its argument
 * through slot 3 (with mode 0, "rb"), takes slot 7's answer for it and closes it
 * through slot 4, null without a handle. A handle holds a C stream
 * (FUN_00de9a00's file handle): slot 7, FUN_00e5bc30, gives its size (the
 * position restored), slot 12, FUN_00e5bd70, opens a handle as slot 8 does
 * and returns slot 9's answer for it and a record, the record cleared and 0
 * without a handle, slot 14, FUN_00e5bde0, classifies a path by stat (1 a
 * directory, 0 a regular file, -1 otherwise or when stat fails), slot 15, FUN_00e5be90, reads size bytes at an offset
 * into a buffer, 1 when the seek succeeds (else 0), slot 4, FUN_00e5bb40, closes
 * a handle's stream and gives the handle back to the pool, slot 9, FUN_00e5bcd0,
 * fills the record from fstat, slot 19, FUN_00e5bf20, copies a file and slot
 * 21, FUN_00e5c690, makes a path's directories. The other members and slots are
 * not traced. The destructor is
 * the class's key function, so this file emits the vtable. */
struct FileHandle00e5b7e0 /* derived name */
{
    union {
        FILE *file; /* +0x0 */
        u32 next;   /* +0x0: the next free handle's index, while it is free */
    };
};

/* derived names: the class's 32 handles and their free list under a
 * recursive lock (+0x8 to +0x128 of the object): the count in use, the first
 * free handle's index (0xffffffff with none), the handles, the lock. A handle
 * is given back by its index, the list's head stored in it (slot 4,
 * 0xe5bb40, and slot 3 when its file does not open). */
struct HandlePool00e5b7e0 /* derived name */
{
    /* the first free handle taken off the list, null with none (slot 3) */
    FileHandle00e5b7e0 *acquire()
    {
        lock.lock();
        if (firstFree == 0xffffffff) {
            lock.unlock();
            return 0;
        }
        const u32 index = firstFree;
        firstFree = handles[index].next;
        ++used;
        lock.unlock();
        return &handles[index];
    }

    void release(FileHandle00e5b7e0 *handle)
    {
        lock.lock();
        const u32 index = u32(handle - handles);
        handles[index].next = firstFree;
        firstFree = index;
        --used;
        lock.unlock();
    }

    int used;                       /* +0x0 */
    u32 firstFree;                  /* +0x4 */
    FileHandle00e5b7e0 handles[32]; /* +0x8 */
    Mutex013847e0 lock;             /* +0x108 */
};

/* derived names: 0x20 bytes slot 9 fills for a handle from fstat, cleared
 * by slot 9 and slot 12 when there is no status (one 32-byte store) */
struct Record00e5b7e0 {
    time_t changed;  /* +0x0: the status change time (st_ctim) */
    time_t accessed; /* +0x8: st_atim */
    time_t modified; /* +0x10: st_mtim */
    int access;      /* +0x18: 1 the owner may read, 2 write */
};

class Object00e5b7e0 /* derived name */
{
  public:
    virtual ~Object00e5b7e0();
    virtual void *slot2(const char *path, u32 *size);              /* derived name */
    virtual FileHandle00e5b7e0 *slot3(const char *path, int mode); /* derived name */
    virtual void slot4(FileHandle00e5b7e0 *handle);                /* derived name */
    virtual void slot5();                                          /* derived name; not traced */
    virtual void slot6();                                          /* derived name; not traced */
    virtual long slot7(FileHandle00e5b7e0 *handle);                /* derived name */
    virtual long slot8(const char *path);                          /* derived name */
    virtual int slot9(FileHandle00e5b7e0 *handle, Record00e5b7e0 *record); /* derived name */
    virtual void slot10();                                        /* derived name; not traced */
    virtual void slot11();                                        /* derived name; not traced */
    virtual int slot12(const char *path, Record00e5b7e0 *record); /* derived name */
    virtual void slot13();                                        /* derived name; not traced */
    virtual int slot14(const char *path);                         /* derived name */
    virtual int slot15(FileHandle00e5b7e0 *handle, unsigned offset, void *buffer,
                       size_t size);                                 /* derived name */
    virtual void slot16();                                           /* derived name; not traced */
    virtual void slot17();                                           /* derived name; not traced */
    virtual void slot18();                                           /* derived name; not traced */
    virtual int slot19(const char *destination, const char *source); /* derived name */
    virtual void slot20();                                           /* derived name; not traced */
    virtual int slot21(const char *path, int flags);                 /* derived name */

  private:
    HandlePool00e5b7e0 handles; /* +0x8 */
};

// NONMATCHING (the deleting destructor FUN_00e5b830 only): DeadStoreElimination's
// handleFree removes the inlined mutex destructor's two clearing stores before
// operator delete; the base keeps them (also at 0xa07ac7 and 0xcf1be7, the same
// member before a delete), a question of where the cross-file inlining ran.
Object00e5b7e0::~Object00e5b7e0() {}

// NONMATCHING: register assignment only: the base holds the index's mask in rcx and the
// free list's head in edx (0xe5bb92, 0xe5bb9c), the build the other way round
void Object00e5b7e0::slot4(FileHandle00e5b7e0 *handle)
{
    if (!handle)
        return;
    fclose(handle->file);
    handles.release(handle);
}

/* Slot 2: the whole file at a path read into a block of the thread's heap
 * (aligned to 32, at least one byte), a 0 stored after its end, its size
 * stored through size; null when the file does not open or its read falls
 * short (the block released), the size then kept. */
void *Object00e5b7e0::slot2(const char *path, u32 *size)
{
    FILE *file = fopen(path, "rb");
    u32 length = 0;
    char *buffer = 0;
    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = static_cast<char *>(allocateBlock(length > 1 ? length : 1, 0x20));
        buffer[length] = 0;
        if (length && buffer && fread(buffer, length, 1, file) != 1) {
            FUN_00ebf3f0(buffer);
            buffer = 0;
        }
        fclose(file);
    }
    *size = length;
    return buffer;
}

/* derived name: the streams' modes by slot 3's mode: "rb", "wb", "rb+",
 * "ab+" */
extern const char *const D_16bdc40[4];

/* Slot 3: a handle for the file at a path opened in one of four modes (the
 * mode's low two bits), null when no handle is free or the file does not
 * open (the handle then given back). */
// NONMATCHING: the inlined release only, slot 4's register assignment (the index's mask in rcx
// and the free list's head in edx at 0xe5bad9, the build the other way round); 76/80
FileHandle00e5b7e0 *Object00e5b7e0::slot3(const char *path, int mode)
{
    FileHandle00e5b7e0 *handle = handles.acquire();
    if (!handle)
        return 0;
    FILE *file = fopen(path, D_16bdc40[mode & 3]);
    if (!file) {
        handles.release(handle);
        return 0;
    }
    handle->file = file;
    return handle;
}

long Object00e5b7e0::slot7(FileHandle00e5b7e0 *handle)
{
    FILE *file = handle->file;
    const long position = ftell(file);
    fseek(file, 0, SEEK_END);
    const long size = ftell(file);
    fseek(file, position, SEEK_SET);
    return size;
}

long Object00e5b7e0::slot8(const char *path)
{
    FileHandle00e5b7e0 *handle = slot3(path, 0);
    if (!handle)
        return 0;
    const long result = slot7(handle);
    slot4(handle);
    return result;
}

// NONMATCHING: the write bit's conditional store: the base stores the read bit, then tests and
// stores again (0xe5bd45, 0xe5bd4d); the build makes one store of a select (the class of two
// stores in two arms)
int Object00e5b7e0::slot9(FileHandle00e5b7e0 *handle, Record00e5b7e0 *record)
{
    struct stat status;
    if (fstat(fileno(handle->file), &status) != 0) {
        memset(record, 0, sizeof *record);
        return 0;
    }
    record->changed = status.st_ctim.tv_sec;
    record->accessed = status.st_atim.tv_sec;
    record->modified = status.st_mtim.tv_sec;
    record->access = (status.st_mode & S_IRUSR) ? 1 : 0;
    if (status.st_mode & S_IWUSR)
        record->access |= 2;
    return 1;
}

int Object00e5b7e0::slot12(const char *path, Record00e5b7e0 *record)
{
    FileHandle00e5b7e0 *handle = slot3(path, 0);
    if (!handle) {
        memset(record, 0, sizeof *record);
        return 0;
    }
    const int result = slot9(handle, record);
    slot4(handle);
    return result;
}

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

/* derived name: the copy's buffer (0x598cf40, 64 KiB in .bss, read into and
 * written from by slot 19 only) */
static u8 D_598cf40[0x10000];

/* Slot 19: a file copied: the source opened for reading first, then the
 * destination's directories made (slot 21, flags 3) and the destination
 * opened for writing; 64 KiB blocks until the source's end, 0 when a block
 * is not written whole, 0 when a file does not open or the directories are
 * not made. */
int Object00e5b7e0::slot19(const char *destination, const char *source)
{
    FILE *in = fopen(source, "rb");
    if (!in)
        return 0;
    int result = 0;
    if (slot21(destination, 3)) {
        FILE *out = fopen(destination, "wb");
        if (out) {
            result = 1;
            while (!feof(in)) {
                const size_t size = fread(D_598cf40, 1, sizeof D_598cf40, in);
                if (fwrite(D_598cf40, 1, size, out) != size) {
                    result = 0;
                    break;
                }
            }
            fclose(out);
        }
    }
    fclose(in);
    return result;
}

/* Slot 21: the directories of a path made: the path copied (at most 0x3ff
 * characters); with flag 2 its last part cut at the last '/' (or '\\'; the
 * whole path when it has neither); with flag 1 each leading directory made
 * in turn, a '/' after a ':' (a device's name) skipped; then the path
 * itself. 1 when made or there already (EEXIST), 0 otherwise, 1 for an empty
 * path. */
// NONMATCHING: the loop's return of 0: the base sets it in a block of its own on the loop's exit
// edge (`xor eax, eax; jmp` at 0xe5c81f; PHIElimination splits a loop-exiting edge only when the
// value is live past the phis), the build sets it before the errno compare in the loop
int Object00e5b7e0::slot21(const char *path, int flags)
{
    char directory[0x400];
    char copy[0x400];
    char parent[0x400];
    memset(directory, 0, sizeof directory);
    strncpy(directory, path, sizeof directory - 1);
    if (flags & 2) {
        strcpy(copy, directory);
        char *slash = strrchr(copy, '/');
        if (!slash)
            slash = strrchr(copy, '\\');
        if (!slash)
            slash = copy;
        *slash = 0;
        strcpy(directory, copy);
    }
    if (flags & 1) {
        if (directory[0] == 0)
            return 1;
        for (long i = 0; directory[i] != 0; ++i) {
            if (i > 0 && directory[i] == '/' && directory[i - 1] != ':') {
                strncpy(parent, directory, i);
                parent[i] = 0;
                if (mkdir(parent, 0777) != 0 && errno != EEXIST)
                    return 0;
            }
        }
    }
    if (directory[0] == 0)
        return 1;
    if (mkdir(directory, 0777) != 0 && errno != EEXIST)
        return 0;
    return 1;
}

/* derived name: an entry of the directory listings the class builds (slot
 * 20's 0xe5c4a6 and 0xe5c63b, and 0xe5ea5a to 0xe5ef10), 40 bytes: an int,
 * the entry's name and its status record, copied whole (`vmovups ymm`) */
struct Entry00e5c8b0 { /* derived name */
    int unknown0;
    Name name;             /* +0x4 */
    Record00e5b7e0 record; /* +0x8 */
};

/* FUN_00e5c8b0 */
template void Array05943280<Entry00e5c8b0>::push(const Entry00e5c8b0 &);
