/* src/include/tlg_game_jsrender.h: what the render's contexts share: the
 * binding counts their checks compare against (each from its `cmp`, named by
 * the checks' conditions) and the bound objects, named by their own source
 * files (JsBuffer.cpp, JsSamplerState.cpp, JsShaderResourceView.cpp,
 * JsUnorderedAccessView.cpp). */
#ifndef TLG_GAME_JSRENDER_H
#define TLG_GAME_JSRENDER_H

#include "tlg_types.h"

/* The render's boolean, as a check's condition spells it (0x1303110). */
#define FALSE 0

/* The binding counts the checks compare against (each from its `cmp`). */
enum {
    JS_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT = 15, /* 0x13003f6 */
    JS_COMMONSHADER_SAMPLER_SLOT_COUNT = 16,             /* 0x13005f6 */
    JS_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT = 128,     /* 0x1300806 */
    JS_PS_CS_UAV_REGISTER_COUNT = 8,                     /* 0x1300b2a */
};

/* The Gnmx library's constant update engine's resource count, as
 * CSSetShaderResources's check names it. */
namespace sce
{
namespace Gnmx
{
namespace LightweightConstantUpdateEngine
{
const int kMaxResourceCount = 128; /* 0x1300a28 */
}
} // namespace Gnmx
} // namespace sce

class JsBuffer;
class JsSamplerState;
class JsShaderResourceView;

/* the unordered access view as the compute context reaches it: the initial
 * count at +0x88 */
class JsUnorderedAccessView
{
  public:
    u8 unknown0[0x88];
    u32 initialCount; /* derived name; +0x88 */
};

#endif
