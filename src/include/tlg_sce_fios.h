/* The Sony Fios file functions the executable imports, declared here because
 * the build is freestanding (-nostdinc). Each name is the import's verified
 * NID name (tools/nid_names.py), reached through its PLT stub; the parameter
 * types are read from the calls in the base. */
#ifndef TLG_SCE_FIOS_H
#define TLG_SCE_FIOS_H

typedef int SceFiosFH;      /* derived name: a 32-bit file handle */
typedef int SceFiosDH;      /* derived name: a 32-bit directory handle */
typedef long SceFiosOffset; /* derived name: a 64-bit file offset */
typedef long SceFiosSize;   /* derived name: a 64-bit byte count */

/* derived names: an operation's attributes, null for the defaults; 0x30
 * bytes, cleared by the game before it sets the flags at +0x18 (0xe5d2e0) */
struct SceFiosOpAttr {
    long deadline;
    void *callback;
    void *callbackContext;
    int priority : 8;
    unsigned int opFlags : 24;
    unsigned int userTag;
    void *userPointer;
    void *reserved;
};

typedef int SceFiosOp; /* derived name: a 32-bit asynchronous operation */

/* A path's status (derived names): its size, three dates and its flags,
 * bit 0 of which the file system's slot 9 turns into the entry's kind (read at
 * 0x1bc3a); 0x50 bytes on the caller's stack. The dates are unsigned
 * nanoseconds (the game's 0xe5dcd0 divides them by 1e9 unsigned). */
struct SceFiosStat {
    SceFiosOffset fileSize;
    unsigned long accessDate;
    unsigned long modificationDate;
    unsigned long creationDate;
    unsigned int statFlags;
    unsigned char reserved[0x2c];
};

/* A directory's entry as the listing reads it (derived names): its size and
 * flags, then the offset of its name in its full path, the path from +0x18
 * (the listing's slot 5 reads the offset at +0x10, 0x1beea); 0x418 bytes on
 * the caller's stack. */
struct SceFiosDirEntry {
    SceFiosOffset fileSize;
    unsigned int statFlags;
    unsigned short nameLength;
    unsigned short fullPathLength;
    unsigned short offsetToName;
    unsigned short reserved[3];
    char fullPath[1024];
};

/* A file open's parameters (derived names): the open flags in the low 16
 * bits at +0, 1 to read (the writer's opener stores its int's low 16 bits
 * into the zeroed word, 0x91d84), then zeros; 24 bytes on the caller's
 * stack (0x931a0). */
struct SceFiosOpenParams {
    unsigned int openFlags : 16;
    unsigned int unknown2 : 16;
    unsigned int reserved4;
    void *buffer;
    SceFiosSize bufferLength;
};

/* A buffer by its pointer and length (derived names), passed by value in
 * two registers (0xe5f590). */
struct SceFiosBuffer {
    void *pointer;
    unsigned long length;
};

extern "C" {
int sceFiosFHOpenSync(const SceFiosOpAttr *attr, SceFiosFH *fh, const char *path,
                      const SceFiosOpenParams *params);
int sceFiosStatSync(const SceFiosOpAttr *attr, const char *path, SceFiosStat *stat);
/* Whether a file exists at the path (its NID verified as "sceFiosFileExistsSync";
 * the game's 0xe5dac0 and 0xe5f270 pass a null attribute). */
bool sceFiosFileExistsSync(const SceFiosOpAttr *attr, const char *path);
bool sceFiosDirectoryExistsSync(const SceFiosOpAttr *attr, const char *path);
SceFiosOffset sceFiosFHTell(SceFiosFH fh);
SceFiosSize sceFiosFHGetSize(SceFiosFH fh);
SceFiosOffset sceFiosFHSeek(SceFiosFH fh, SceFiosOffset offset, int whence);
int sceFiosFHSyncSync(const SceFiosOpAttr *attr, SceFiosFH fh);
int sceFiosFHCloseSync(const SceFiosOpAttr *attr, SceFiosFH fh);
int sceFiosDHCloseSync(const SceFiosOpAttr *attr, SceFiosDH dh);
int sceFiosDHReadSync(const SceFiosOpAttr *attr, SceFiosDH dh, SceFiosDirEntry *entry);
/* A directory opened into a buffer of length bytes for its entries; with no
 * buffer the operation's actual count is the size the listing needs (0x1bd31). */
SceFiosOp sceFiosDHOpen(const SceFiosOpAttr *attr, SceFiosDH *dh, const char *path, void *buffer,
                        SceFiosSize length);
int sceFiosDHOpenSync(const SceFiosOpAttr *attr, SceFiosDH *dh, const char *path, void *buffer,
                      SceFiosSize length);
int sceFiosOpWait(SceFiosOp op);
SceFiosSize sceFiosOpGetActualCount(SceFiosOp op);
void sceFiosOpDelete(SceFiosOp op);
SceFiosSize sceFiosFHReadSync(const SceFiosOpAttr *attr, SceFiosFH fh, void *buffer,
                              SceFiosSize length);
SceFiosSize sceFiosFHWriteSync(const SceFiosOpAttr *attr, SceFiosFH fh, const void *buffer,
                               SceFiosSize length);
int sceFiosFileDeleteSync(const SceFiosOpAttr *attr, const char *path);
int sceFiosDeleteSync(const SceFiosOpAttr *attr, const char *path);
SceFiosSize sceFiosArchiveGetMountBufferSizeSync(const SceFiosOpAttr *attr, const char *path,
                                                 const SceFiosOpenParams *params);
int sceFiosArchiveMountSync(const SceFiosOpAttr *attr, SceFiosFH *fh, const char *path,
                            const char *mountPoint, SceFiosBuffer buffer,
                            const SceFiosOpenParams *params);
SceFiosSize sceFiosFileReadSync(const SceFiosOpAttr *attr, const char *path, void *buffer,
                                SceFiosSize length, SceFiosOffset offset);
SceFiosSize sceFiosFileGetSizeSync(const SceFiosOpAttr *attr, const char *path);
int sceFiosFHStatSync(const SceFiosOpAttr *attr, SceFiosFH fh, SceFiosStat *stat);
int sceFiosDirectoryCreate(const SceFiosOpAttr *attr, const char *path);
int sceFiosDirectoryCreateSync(const SceFiosOpAttr *attr, const char *path);
/* An error code's text written into a buffer of size bytes (FUN_00e5e6a0). */
const char *sceFiosDebugDumpError(int err, char *buffer, unsigned long size);
}

#endif
