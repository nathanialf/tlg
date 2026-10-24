// Probe batch 1: nine small functions of the base executable, written from
// their disassembly, for tools/compiler_probe.sh. Each is named as its row in
// config/functions.base.txt; extern "C" keeps the symbol equal to the name so
// match_check.py --all pairs them. Four of these are matched in src/unknown/;
// the others differ from clang-19's output only in register choice,
// scheduling or memcpy lowering (docs/TARGETS.md).
#include <xmmintrin.h>
typedef long s64; typedef int s32; typedef unsigned short u16; typedef unsigned char u8;

extern "C" {

struct Elem40 { s64 a, b, c, d, e; };
struct Pool { u8 pad[0x28]; Elem40 *items; };
Elem40 *FUN_00004450(Pool *p, int i) { return &p->items[i]; }

struct Five { u8 pad[0x28]; s32 a, b, c, d, e; };
void FUN_00011320(Five *f, int a, int b, int c, int d, int e) { f->a = a; f->b = b; f->c = c; f->d = d; f->e = e; }

struct Node { Node *next; };
struct List { void *pad0; Node *head; u8 pad[0x60]; s64 count; };
void FUN_00014af0(List *l, Node *n) { l->count++; n->next = l->head; l->head = n; }

struct Pair { s64 first, second; };
void FUN_000104b0(Pair *r) { r->first = 0; r->second = 2; }

struct Box { u8 pad[8]; s32 lo; s32 pad1; s32 mid; u8 pad2[0xc]; s32 hi; };
void FUN_00012120(const Box *b, s64 *out)
{
    out[0] = out[1] = out[2] = b->hi - b->lo;
    out[3] = out[4] = b->mid - b->hi;
    out[5] = b->mid - b->lo;
}

struct Mat4 { __m128 r[4]; };
struct Xform { u8 pad[0x10]; Mat4 m; };
void FUN_0000df30(const Xform *x, Mat4 *out) { *out = x->m; }

void FUN_000137c0(Mat4 *a, const Mat4 *b)
{
    for (int i = 0; i < 4; i++) a->r[i] = _mm_sub_ps(a->r[i], b->r[i]);
}

struct Vt0 { void *f0, *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8, *f9, *f10, *f11, *f12, *f13;
             void (*f14)(void *self, int n); };
struct Dev { Vt0 *vt; };
struct Holder { Dev *dev; u8 pad[0x10]; s32 count; };
int FUN_00007180(Holder *h) { h->dev->vt->f14(h->dev, h->count - 1); return 0; }

struct Alloc { void *f0, *f1; void *(*alloc)(void *self, int size); };
struct Arena { Alloc *vt; };
struct Hdr { Arena *owner; s32 size; s32 pad; };
void *FUN_0000bc30(Arena *a, int size)
{
    Hdr *h = (Hdr *)a->vt->alloc(a, size + 0x10);
    h->owner = a; h->size = size;
    return h + 1;
}

struct Thing;
struct Child { u8 pad[0x18]; Thing *t; u8 pad2[0x360 - 0x20]; u16 w; u8 b; };
void FUN_00015ae0(Thing *);
void FUN_00017a60(Child *c) { FUN_00015ae0(c->t); c->w = 0; c->b = 0; }

}
