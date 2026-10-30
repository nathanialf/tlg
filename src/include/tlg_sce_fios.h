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
struct SceFiosOpAttr;       /* derived name: the operation's attributes, null for the defaults */
typedef int SceFiosOp;      /* derived name: a 32-bit asynchronous operation */

/* A path's status (derived names): its size, three dates and its flags,
 * bit 0 of which the file system's slot 9 turns into the entry's kind (read at
 * 0x1bc3a); 0x50 bytes on the caller's stack. */
struct SceFiosStat {
    SceFiosOffset fileSize;
    long accessDate;
    long modificationDate;
    long creationDate;
    unsigned int statFlags;
    unsigned char reserved[0x2c];
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

extern "C" {
int sceFiosFHOpenSync(const SceFiosOpAttr *attr, SceFiosFH *fh, const char *path,
                      const SceFiosOpenParams *params);
int sceFiosStatSync(const SceFiosOpAttr *attr, const char *path, SceFiosStat *stat);
SceFiosOffset sceFiosFHTell(SceFiosFH fh);
SceFiosOffset sceFiosFHSeek(SceFiosFH fh, SceFiosOffset offset, int whence);
int sceFiosFHSyncSync(const SceFiosOpAttr *attr, SceFiosFH fh);
int sceFiosFHCloseSync(const SceFiosOpAttr *attr, SceFiosFH fh);
int sceFiosDHCloseSync(const SceFiosOpAttr *attr, SceFiosDH dh);
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
int sceFiosFileDeleteSync(const SceFiosOpAttr *attr, const char *path);
int sceFiosDirectoryCreate(const SceFiosOpAttr *attr, const char *path);
}

#endif
