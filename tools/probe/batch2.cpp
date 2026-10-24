// Probe batch 2: alternative source forms for the batch-1 functions that no
// compiler matched as first written.
#include <xmmintrin.h>
typedef long s64; typedef int s32; typedef unsigned short u16; typedef unsigned char u8;

extern "C" {

// 0xdf30 as four explicit row copies instead of a struct copy (memcpy).
struct Mat4 { __m128 r[4]; };
struct Xform { u8 pad[0x10]; Mat4 m; };
void FUN_0000df30(const Xform *x, Mat4 *out)
{
    out->r[0] = x->m.r[0];
    out->r[1] = x->m.r[1];
    out->r[2] = x->m.r[2];
    out->r[3] = x->m.r[3];
}

// 0x104b0 with a pointer-typed second word (an enum/state and a pointer would
// not be merged into one vector store by some compilers).
struct PairP { s64 first; void *second; };
void FUN_000104b0(PairP *r) { r->first = 0; r->second = (void *)2; }

// 0x12120 reading through a struct of s64 outputs rather than an array.
struct Box { u8 pad[8]; s32 lo; s32 pad1; s32 mid; u8 pad2[0xc]; s32 hi; };
struct Extents { s64 a, b, c, d, e, f; };
void FUN_00012120(const Box *b, Extents *out)
{
    s64 x = b->hi - b->lo;
    out->a = x; out->b = x; out->c = x;
    s64 y = b->mid - b->hi;
    out->d = y; out->e = y;
    out->f = b->mid - b->lo;
}

// 0x7180: count read before the virtual call expression.
struct Vt0 { void *f[14]; void (*f14)(void *self, int n); };
struct Dev { Vt0 *vt; };
struct Holder { Dev *dev; u8 pad[0x10]; s32 count; };
int FUN_00007180(Holder *h) { Dev *d = h->dev; d->vt->f14(d, h->count - 1); return 0; }

}
