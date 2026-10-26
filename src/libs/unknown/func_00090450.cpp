/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A block stream's writer (derived name), 0x28 bytes: the stream it writes
 * (null until bound; 0x938a0 binds it and loads the stream's last block as
 * the current one), the current block, the byte offset in it, the number of
 * elements written to it, and the allocator the blocks come from. Its
 * finalize 0x93a10 writes the current block's header (or frees an empty
 * one) and clears the current block; every stack writer in the region is
 * finalized before it goes out of scope (0x3fa03, 0x64777, 0x6d20b), and
 * the command writers held at +0x390 of their owner are finalized through
 * their member at +0x10 (0x170078, 0x170507). */
struct hkBlockStreamWriter /* derived name */
{
    void *blockStream;      /* derived name */
    void *currentBlock;     /* derived name */
    int currentByteOffset;  /* derived name */
    int currentNumElements; /* derived name */
    void *allocator;        /* derived name */
};

/* A command stream writer (vtable 0x16a3370, ruled hkBlockStreamCommandWriter,
 * D14), 0x38 bytes: constructor 0x904c0 (called at 0x167f1b on a 0x38-byte
 * block, stores 0xffff0001 at +8 and clears the writer's stream), deleting
 * destructor 0x90460 (frees the size kept in the high half of +8). Slot 5
 * (0x904f0) appends a record whose padded byte size is the u16 at its start
 * to the writer (0x939c0 opens a new 0xfe0-byte block); 0x938a0 binds the
 * writer at 0x167f35. */
class hkBlockStreamCommandWriter : public hkReferencedObject /* derived name */
{
  public:
    virtual ~hkBlockStreamCommandWriter();

    hkBlockStreamWriter writer; /* derived name */
};

hkBlockStreamCommandWriter::~hkBlockStreamCommandWriter()
{
    /* The writer was finalized (or never bound) before its owner releases
     * the command writer. */
    HK_ASSERT(0, writer.blockStream == 0 || writer.currentBlock == 0); /* derived assert */
}
