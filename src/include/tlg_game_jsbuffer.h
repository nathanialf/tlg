/* src/include/tlg_game_jsbuffer.h: the render's buffer (render/ps4/JsBuffer.cpp,
 * the file its reports name). The class is named for its file, as
 * JsUnknown.cpp holds ~JsUnknown and JsView.cpp ~JsView; its vtable is the
 * row _ZTV8JsBuffer (0x16c37e0, config/vtables.derived.base.txt). The
 * description's fields and the usage values are named by the report of
 * IsGarlic; the other fields are not traced. */
#ifndef TLG_GAME_JSBUFFER_H
#define TLG_GAME_JSBUFFER_H

#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_object016c3be0.h"

/* The buffer's source file, as the reports name it (0x15cbc61). */
#define JS_BUFFER_CPP /* derived name */                                                           \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsBuffer.cpp"

/* the usages, as IsGarlic's check names the first and the last (the check
 * is `Usage < 4`, the test `Usage < 3`) */
enum JsUsage /* derived name */
{
    JS_USAGE_DEFAULT = 0,
    JS_USAGE_IMMUTABLE = 1, /* derived name */
    JS_USAGE_DYNAMIC = 2,   /* derived name */
    JS_USAGE_STAGING = 3,
};

/* the CPU's read access (the bit IsGarlic tests, `and eax, 0x20000`) */
enum { JS_CPU_ACCESS_READ = 0x20000 }; /* derived name */

/* derived names but Usage: the buffer's description at +0x180 */
struct JsBufferDesc /* derived name */
{
    u32 ByteWidth;      /* +0x0, not traced */
    JsUsage Usage;      /* +0x4 */
    u32 BindFlags;      /* +0x8, not traced */
    u32 CPUAccessFlags; /* +0xc */
};

class JsBuffer : public Object016c3be0
{
  public:
    /* slots 0 and 1 (0x12ff060, 0x12ff1a0) */
    virtual ~JsBuffer();

    /* whether the buffer's memory is the Garlic heap's: all but a staging
     * buffer the CPU reads (JsBuffer.cpp:21) */
    bool IsGarlic() const
    {
        ANZU_ASSERT(JS_BUFFER_CPP, 21,
                    (desc.Usage >= JS_USAGE_DEFAULT) && (desc.Usage <= JS_USAGE_STAGING));
        if (desc.Usage < JS_USAGE_STAGING)
            return true;
        return (desc.CPUAccessFlags & JS_CPU_ACCESS_READ) == 0;
    }

  private:
    u8 unknown128[0x180 - 0x128];
    JsBufferDesc desc; /* +0x180 */
};

#endif
