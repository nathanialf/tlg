/* src/include/tlg_game_textbuffer00d705f0.h: a text buffer written out to a
 * file (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_TEXTBUFFER00D705F0_H
#define TLG_GAME_TEXTBUFFER00D705F0_H

#include "tlg_libc.h"
#include "tlg_types.h"
#include <stdarg.h>

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

struct Output05938c40 { /* derived name */
    u8 unknown0[0x28];
    Writer05938c40_28 *writer; /* +0x28 */
};

extern Output05938c40 *D_5938c40;

void *FUN_00ca21b0(void *block, u32 size); /* derived name: the block grown to `size` bytes */

/* derived names: a text buffer over a file (+0x0, the file at its first
 * word): its block (+0x8), capacity (+0x10) and length (+0x14).
 * FUN_00d705f0 appends a string: room is made for its length (the buffer
 * written out first when it does not fit and holds something, then the
 * block grown by the larger of the length and the string's when it still
 * does not fit or there is no file), then the bytes copied in at the old
 * length, or at -1 when the block could not grow. FUN_00d706c0 appends a
 * formatted text the same way. */
struct File00d705f0 { /* derived name */
    void *handle;     /* +0x0 */
};

class TextBuffer00d705f0 /* derived name */
{
  public:
    void FUN_00d705f0(const char *text);
    void FUN_00d706c0(const char *format, ...);

  private:
    /* the offset at which `size` more bytes go, the length raised by them;
     * -1 when the block cannot grow */
    u32 reserve(u32 size); /* derived name */

    File00d705f0 *file; /* +0x0 */
    char *block;        /* +0x8 */
    u32 capacity;       /* +0x10 */
    u32 length;         /* +0x14 */
};

inline u32 TextBuffer00d705f0::reserve(u32 size)
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

/* appends a formatted text: at most 4095 characters formatted into a frame
 * buffer of 4096, its last byte cleared, then appended as FUN_00d705f0
 * appends a string, the whole buffer when the format fails. Its callers
 * (FUN_005823a0, FUN_0135b0f0) all pass ", %s". Inline: the link makes
 * the used definition local, IPSCCP folds the one format into it
 * (SCCP.cpp:1720, local linkage) and DeadArgumentElimination leaves the
 * argument unset at the calls; a variadic function is never inlined
 * (InlineFunction.cpp:931), so it stays out of line */
// NONMATCHING: the format folded as the base (whole module); the residual is FUN_00d705f0's: the base
// reads the file's pointer once before the length is tested and tests that register again where the
// block may grow; this build reads it only when the length is set and compares memory the second time
inline void TextBuffer00d705f0::FUN_00d706c0(const char *format, ...)
{
    char text[0x1000];
    text[sizeof(text) - 1] = 0;
    va_list arguments;
    va_start(arguments, format);
    const int written = vsnprintf(text, sizeof(text) - 1, format, arguments);
    va_end(arguments);
    const u32 size = written < 0 ? sizeof(text) : written;
    const u32 offset = reserve(size);
    memcpy(block + offset, text, size);
}

#endif
