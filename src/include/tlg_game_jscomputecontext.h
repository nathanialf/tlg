/* src/include/tlg_game_jscomputecontext.h: the render's compute context
 * (render/ps4/JsComputeContext.cpp, as its reports name the file). The class
 * name is its constructor's report (FUN_012ffc30, "JsComputeContext"); the
 * methods are named by their own reports, the constants and parameters by the
 * reports' conditions. Its vtable is the row _ZTV16JsComputeContext
 * (0x16c3808, config/vtables.derived.base.txt), stored by FUN_012ffc30 and
 * the destructors. The slots written are declared virtual in their order
 * (each with its number from the address point 0x16c3818); the
 * destructor is the key function (leaf_013001f0.cpp). */
#ifndef TLG_GAME_JSCOMPUTECONTEXT_H
#define TLG_GAME_JSCOMPUTECONTEXT_H

#include "tlg_types.h"

#include "tlg_game_commandbuffer.h"
#include "tlg_game_jsrender.h"
#include "tlg_game_object016c3be0.h"

/* The compute context's source file, as the reports name it (0x15cbea5). */
#define JS_COMPUTE_CONTEXT_CPP /* derived name */                                                  \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsComputeContext.cpp"

class Object016c3be0;

/* derived names: a mapped resource's memory and pitches (16 bytes; AsyncMap
 * fills it) */
struct JsMappedSubresource {
    void *pData;
    u32 RowPitch;
    u32 DepthPitch;
};

/* derived names: the dimensions AsyncMap tells apart; the check names the
 * first */
enum JsResourceDimension {
    JS_RESOURCE_DIMENSION_UNKNOWN = 0,
    JS_RESOURCE_DIMENSION_BUFFER = 1, /* derived name */
};

/* derived names: the targets slots 4, 12 and 13 forward to (their own
 * slots 3, 4 and 5), the pointers slots 7 and 35 store, the member slot 11
 * hands to FUN_0132f9a0 */
class Target01303c60;
class Target01303c80;
class Target01303ca0;
struct Target013007d0;
struct Target01496ad0;

struct Member01302150 {  /* derived name */
    u8 unknown0[0x1978]; /* not traced */
};

class JsComputeContext : public Object0130acb0
{
  public:
    /* slots 0 and 1 (0x13001f0, 0x13002e0; the deleting one inlines it) */
    virtual ~JsComputeContext();

    /* slot 4 (0x1303c60): the target's slot 3 called with the context */
    virtual void Begin(Target01303c60 *target); /* derived name */
    /* slot 5 (0x16c3840) */
    virtual void CSSetConstantBuffers(u32 StartSlot, u32 NumBuffers,
                                      JsBuffer *const *ppConstantBuffers);
    /* slot 6 (0x16c3848) */
    virtual void CSSetSamplers(u32 StartSlot, u32 NumSamplers, JsSamplerState *const *ppSamplers);
    /* slot 7 (0x13007d0) */
    virtual void setUnknown1d10(Target013007d0 *value); /* derived name */
    /* slot 8 (0x16c3858) */
    virtual void CSSetShaderResources(u32 StartSlot, u32 NumViews,
                                      JsShaderResourceView *const *ppShaderResourceViews);
    /* slot 9 (0x16c3860) */
    virtual void CSSetUnorderedAccessViews(u32 StartSlot, u32 NumUAVs,
                                           JsUnorderedAccessView *const *ppUnorderedAccessViews,
                                           const u32 *pUAVInitialCounts);
    /* slot 11 (0x1302150): a dispatch of the groups, counted */
    virtual void Dispatch(u32 groupsX, u32 groupsY, u32 groupsZ); /* derived name */
    /* slot 12 (0x1303c80): the target's slot 4 */
    virtual void End(Target01303c80 *target); /* derived name */
    /* slot 13 (0x1303ca0): the target's slot 5, -2 without one */
    virtual int GetData(Target01303ca0 *target, void *first, void *second,
                        void *third); /* derived name */
    /* slot 16 (0x1302210): FUN_01302220 with the first and third arguments */
    virtual void slot16(void *first, void *second, void *third); /* derived name */
    /* slot 17 (0x13026f0): FUN_01302700 */
    virtual void slot17(); /* derived name */
    /* slots 18 and 19 (0x13025c0, 0x13024a0): a subresource mapped as
     * AsyncMap maps it (leaf_013025c0.cpp, leaf_013024a0.cpp) */
    virtual int slot18(Object016c3be0 *resource, u32 subresource, u32 mapType, u32 mapFlags,
                       JsMappedSubresource *mapped); /* derived name */
    virtual int slot19(Object016c3be0 *resource, u32 subresource, u32 mapType, u32 mapFlags,
                       void *unused, JsMappedSubresource *mapped); /* derived name */
    /* slot 20 (0x1303cc0): every shader resource unbound */
    virtual void clearShaderResources(); /* derived name */
    /* slot 23 (0x1303bd0): the packet setting register 0x215 */
    virtual void setRegister215(u32 low, u32 middle, u32 high); /* derived name */
    /* slot 25 (0x13026e0): empty */
    virtual void slot25(); /* derived name */
    /* slot 28 (0x1303ce0): a seven-word packet carrying a 64-bit value */
    virtual void slot28(u64 value); /* derived name */
    /* slot 29 (0x16c3900): occlusion queries are not supported here; the
     * check fails unconditionally (JsComputeContext.cpp:754) */
    virtual void BeginOcclusion();
    /* slot 30 (0x16c3908): likewise (JsComputeContext.cpp:761) */
    virtual void EndOcclusion();
    /* slot 33 (0x1496a00): a push marker */
    virtual void PushMarker(const char *marker); /* derived name */
    /* slot 34 (0x1496a80): the marker closed */
    virtual void PopMarker(); /* derived name */
    /* slots 35 and 36 (0x1496ad0, 0x1496ae0) */
    virtual void setUnknown2318(Target01496ad0 *value); /* derived name */
    virtual Target01496ad0 *getUnknown2318() const;     /* derived name */

    /* a GPU label yielded on until it reads 0x10 (called directly) */
    static void StallUntilSignaled(volatile u64 *handle);
    /* a resource's memory and pitches (called directly) */
    static void AsyncMap(Object016c3be0 *resource, JsMappedSubresource *mapped);

  private:
    /* derived names: an entry handed back to the object 0x5adaaa8 points
     * at, the pointer read before the entry's test (to its list at +0x100e8
     * or +0x100b8) */
    static void returnEntryE8(void *entry)
    {
        Object05adaaa8 *owner = D_5adaaa8;
        if (entry) {
            FUN_0131e2d0(owner->unknown100e8, entry);
            __sync_fetch_and_add(&owner->unknown100b0, 1);
        }
    }

    static void returnEntryB8(void *entry)
    {
        Object05adaaa8 *owner = D_5adaaa8;
        if (entry) {
            FUN_0131e2d0(owner->unknown100b8, entry);
            __sync_fetch_and_add(&owner->unknown100a0, 1);
        }
    }

    u8 unknown30[0x34 - 0x30];
    int dispatches; /* +0x34 (derived name) */
    u8 unknown38[4];
    u32 groups; /* +0x3c: the groups dispatched (derived name) */
    u8 unknown40[0x20];
    CommandBuffer01496a80 commands; /* +0x60 (derived name) */
    u32 unknown88;                  /* +0x88: bit 0 in the dispatch's modifier */
    u8 unknown8c[0x14];
    Member01302150 memberA0; /* +0xa0: handed to FUN_0132f9a0 */
    u8 unknown1a18;          /* +0x1a18 */
    u8 unknown1a19[0x1c7c - 0x1a19];
    bool unknown1c7c; /* +0x1c7c */
    u8 unknown1c7d[0x1cd8 - 0x1c7d];
    /* derived names: entries the destructor hands back, +0x1ce8 and
     * +0x1cf8 to the list at +0x100e8, the others to the one at +0x100b8 */
    void *entry1cd8; /* +0x1cd8 */
    u8 unknown1ce0[8];
    void *entry1ce8; /* +0x1ce8 */
    u8 unknown1cf0[8];
    void *entry1cf8;             /* +0x1cf8 */
    void *entry1d00;             /* +0x1d00 */
    void *entry1d08;             /* +0x1d08 */
    Target013007d0 *unknown1d10; /* +0x1d10: stored by slot 7 */
    /* derived names, each array from the method that fills it */
    JsShaderResourceView
        *m_shaderResources[JS_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT];           /* +0x1d18 */
    JsUnorderedAccessView *m_unorderedAccessViews[JS_PS_CS_UAV_REGISTER_COUNT];  /* +0x2118 */
    u32 m_initialCounts[JS_PS_CS_UAV_REGISTER_COUNT];                            /* +0x2158 */
    JsSamplerState *m_samplers[JS_COMMONSHADER_SAMPLER_SLOT_COUNT];              /* +0x2178 */
    JsBuffer *m_constantBuffers[JS_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT]; /* +0x21f8 */
    u8 unknown2270[0x2318 - 0x2270];
    Target01496ad0 *unknown2318; /* +0x2318: stored by slot 35, returned by slot 36 */
};

#endif
