// Probe batch 3: twelve small functions from the GAME's region of the
// executable (above 0x1a3e00, where the compiler merges constant stores and
// emits cdqe); batches 1 and 2 sampled the library region below it, which an
// older compiler built. See docs/TARGETS.md, "Two compiler generations".
#include <xmmintrin.h>
typedef long s64; typedef int s32; typedef unsigned char u8;
typedef __m128 Vec4;
// Returned through a hidden pointer, not in xmm0/xmm1, so the type is not
// trivially copyable: a math class with its own copy constructor.
struct Float4 { float x, y, z, w; Float4() {} Float4(const Float4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {} };

extern "C" {

struct Sub4ba5f0 { u8 pad[0x50]; Vec4 a; u8 pad2[0x10]; Vec4 b; };
struct Obj4ba5f0 { u8 pad[0x4e0]; Sub4ba5f0 *sub; };
void FUN_004ba5f0(const Obj4ba5f0 *o, Vec4 *a, Vec4 *b) { *a = o->sub->a; *b = o->sub->b; }

struct Obj4ba630 { u8 pad[0xa0]; Float4 pos; };
Float4 FUN_004ba630(const Obj4ba630 *o) { return o->pos; }

struct Tgt639e60 { u8 pad[0x220]; Vec4 v; };
struct Obj639e60 { u8 pad[0x28]; Tgt639e60 *t; u8 pad2[0x23a0 - 0x30]; Vec4 v; };
void FUN_00639e60(const Obj639e60 *o) { o->t->v = o->v; }

struct Tgt778dc0 { u8 pad[0x2110]; Vec4 v; };
struct Obj778dc0 { u8 pad[0x68]; Tgt778dc0 *t; u8 pad2[0x100 - 0x70]; Vec4 v; };
void FUN_00778dc0(const Obj778dc0 *o) { o->t->v = o->v; }

struct Tgt779070 { u8 pad[0xb90]; Vec4 a; Vec4 b; };
struct Obj779070 { u8 pad[0x68]; Tgt779070 *t; };
struct Src779070 { u8 pad[0x80]; Vec4 a; Vec4 b; };
void FUN_00779070(const Obj779070 *o, const Src779070 *s) { o->t->a = s->a; o->t->b = s->b; }
void FUN_007793f0(const Obj779070 *o, const Src779070 *s) { o->t->a = s->a; o->t->b = s->b; }

struct Tgt79a5d0 { u8 pad[0xb90]; Vec4 b; Vec4 a; u8 pad2[0x13c0 - 0xbb0]; Vec4 sa; Vec4 pad3; Vec4 sb; };
struct Obj79a5d0 { u8 pad[0x68]; Tgt79a5d0 *t; };
void FUN_0079a5d0(const Obj79a5d0 *o) { o->t->a = o->t->sa; o->t->b = o->t->sb; }

struct Obj46b3f0;
void FUN_00470da0(Obj46b3f0 *, int);
int FUN_0046b3f0(Obj46b3f0 *o) { FUN_00470da0(o, 1); return 1; }

struct Obj4eee50 { u8 pad[0x250]; u8 flag; };
void FUN_00501450(Obj4eee50 *);
void FUN_004eee50(Obj4eee50 *o) { FUN_00501450(o); o->flag = 1; }

struct Vt583950 { void (*f0)(void *self, void *arg, int n); };
struct Dev583950 { Vt583950 *vt; };
struct Obj583950 { u8 pad[0xf0]; Dev583950 *dev; };
int FUN_00583950(Obj583950 *o, void *arg) { o->dev->vt->f0(o->dev, arg, 1); return 0; }
int FUN_00599980(Obj583950 *o, void *arg) { o->dev->vt->f0(o->dev, arg, 1); return 0; }
int FUN_0059d3b0(Obj583950 *o, void *arg) { o->dev->vt->f0(o->dev, arg, 4); return 0; }

}
