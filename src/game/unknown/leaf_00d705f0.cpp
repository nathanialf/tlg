/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: what a buffer's full contents are written out through:
 * slot 18 of the object at +0x28 of the one the pointer at 0x5938c40 holds,
 * with the buffer's file, its bytes and their count */
class Writer05938c40_28 /* derived name */
{
  public:
    virtual void slot0();                                            /* derived name; not traced */
    virtual void slot1();                                            /* derived name; not traced */
    virtual void slot2();                                            /* derived name; not traced */
    virtual void slot3();                                            /* derived name; not traced */
    virtual void slot4();                                            /* derived name; not traced */
    virtual void slot5();                                            /* derived name; not traced */
    virtual void slot6();                                            /* derived name; not traced */
    virtual void slot7();                                            /* derived name; not traced */
    virtual void slot8();                                            /* derived name; not traced */
    virtual void slot9();                                            /* derived name; not traced */
    virtual void slot10();                                           /* derived name; not traced */
    virtual void slot11();                                           /* derived name; not traced */
    virtual void slot12();                                           /* derived name; not traced */
    virtual void slot13();                                           /* derived name; not traced */
    virtual void slot14();                                           /* derived name; not traced */
    virtual void slot15();                                           /* derived name; not traced */
    virtual void slot16();                                           /* derived name; not traced */
    virtual void slot17();                                           /* derived name; not traced */
    virtual void write(void *file, const char *bytes, size_t count); /* derived name; slot 18 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x28];
    Writer05938c40_28 *writer; /* +0x28 */
};

extern Object05938c40 *D_5938c40;

void *FUN_00ca21b0(void *block, u32 size); /* derived name: the block grown to `size` bytes */

/* derived names: a text buffer over a file (+0x0, the file at its first
 * word): its block (+0x8), capacity (+0x10) and length (+0x14).
 * FUN_00d705f0 appends a string: room is made for its length (the buffer
 * written out first when it does not fit and holds something, then the
 * block grown by the larger of the length and the string's when it still
 * does not fit or there is no file), then the bytes copied in at the old
 * length, or at -1 when the block could not grow. */
struct File00d705f0 { /* derived name */
    void *handle;     /* +0x0 */
};

class TextBuffer00d705f0 /* derived name */
{
  public:
    void FUN_00d705f0(const char *text);

  private:
    /* the offset at which `size` more bytes go, the length raised by them;
     * -1 when the block cannot grow */
    u32 reserve(u32 size) /* derived name */
    {
        u32 offset = length;
        if (size) {
            if (offset + size > capacity) {
                if (offset && file) {
                    D_5938c40->writer->write(file->handle, block, offset);
                    length = 0;
                    offset = 0;
                }
                if (capacity < size || !file) {
                    capacity += offset < size ? size : offset;
                    block = static_cast<char *>(FUN_00ca21b0(block, capacity));
                    if (!block)
                        return -1;
                }
            }
            length += size;
        }
        return offset;
    }

    File00d705f0 *file; /* +0x0 */
    char *block;        /* +0x8 */
    u32 capacity;       /* +0x10 */
    u32 length;         /* +0x14 */
};

// NONMATCHING: the file's pointer: the base reads it once before the length is tested (`mov rcx,
// [rbx]; test r12d, r12d; je`) and tests that register again where the block may grow; this build
// reads it only when the length is set and compares memory (`cmp qword [rbx], 0`) at the second test
void TextBuffer00d705f0::FUN_00d705f0(const char *text)
{
    const u32 size = strlen(text);
    const u32 offset = reserve(size);
    memcpy(block + offset, text, size);
}
