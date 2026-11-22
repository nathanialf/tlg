/* src/include/tlg_game_object016bdc60.h: the class whose vtable is at 0x16bdc60
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BDC60_H
#define TLG_GAME_OBJECT016BDC60_H

#include "tlg_game_block.h"
#include "tlg_libc.h"
#include "tlg_sce_fios.h"
#include "tlg_types.h"

/* derived names: one archive of the table at 0x179ed60 (seven of 0x50
 * bytes) the file system mounts once its content chunk is there: its slot
 * in the file system's buffers and handles, its chunk, its path and whether
 * it has been tried */
struct Archive0179ed60 { /* derived name */
    int slot;            /* +0x0 */
    bool enabled;        /* +0x4 */
    u8 unknown5[3];
    int chunk;       /* +0x8: a byte of Chunks05938c40's present */
    char path[0x40]; /* +0xc */
    bool mounted;    /* +0x4c: set once its mount is tried */
    bool mountable;  /* +0x4d */
    u8 unknown4e[2];
};

extern Archive0179ed60 D_179ed60[7];

/* derived names: a path's dates in seconds and two of its flags, as the
 * file system's slots 9 and 10 fill it (0x20 bytes, cleared as one block
 * when the status is not read). */
struct FileInfo016bdc60 { /* derived name */
    u64 created;          /* +0x0: the status's creationDate over 1e9 */
    u64 accessed;         /* +0x8: accessDate over 1e9 */
    u64 modified;         /* +0x10: modificationDate over 1e9 */
    u32 flags;            /* +0x18: bit 0 the status's bit 1, bit 1 its bit 2 */
    u32 unknown1c;
};

/* derived names: the class whose vtable is at 0x16bdc60
 * (config/vtables.derived.base.txt, stored by FUN_00e5c990 FUN_00e5d180): a
 * file system over Sony's Fios (every slot reaches a sceFios import; the
 * destructor 0xe5d180 ends with sceFiosTerminate). Its paths are its
 * directory at +0x1d0 followed by a name in lower case (makePath, inlined in
 * every slot that takes a name). Its constructor (0x78c bytes) and
 * destructor are not written; the handle lists the destructor releases
 * (+0xa4, the 32 lists at +0xb0, +0x1b0 to +0x1c8) are not traced. */
class Object016bdc60 /* derived name */
{
  public:
    virtual ~Object016bdc60();

    void *FUN_00e5d2e0(const char *name, u32 *size) const;
    void FUN_00e5d9a0(const char *name);
    int FUN_00e5dac0(const char *name) const;
    SceFiosSize FUN_00e5dbc0(const char *name) const;
    int FUN_00e5dcd0(SceFiosFH fh, FileInfo016bdc60 *info) const;
    int FUN_00e5ddc0(const char *name, FileInfo016bdc60 *info) const;
    int FUN_00e5df70(const char *name) const;
    int FUN_00e5f270(const char *name) const;

  private:
    /* The directory, its first 62 characters, then the name lower-cased
     * from the directory's length on, in a buffer of size bytes cleared
     * first; the copy stops at the name's end or the buffer's. */
    void makePath(char *path, size_t size, const char *name) const
    {
        memset(path, 0, size);
        const unsigned length = strlen(directory);
        strncpy(path, directory, 0x3e);
        for (unsigned i = length; i < size; ++i, ++name) {
            const int c = tolower(*name);
            if (!c)
                break;
            path[i] = c;
        }
    }

    int unknown8; /* +0x8: set to 1 by slot 25 (FUN_00e5d2d0) for 99 */
    u8 unknownc[4];
    SceFiosBuffer buffers[7]; /* +0x10: the archives' mount buffers, by their slot */
    SceFiosFH archives[7];    /* +0x80: the mounted archives, by their slot */
    u8 unknown9c[0x134];
    char directory[0x40];  /* +0x1d0; its extent not traced */
    char mountPoint[0x40]; /* +0x210: where the archives are mounted; its extent not traced */
};

#endif
