/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_math.h"
#include "tlg_libc.h"

/* derived names: the component of the type D_57db090 points to, read for
 * its two vectors at +0x160 and +0x170 */
struct Source007b2d50 : Component00503fb0 /* derived name */
{
    u8 unknown8c[0xd4];
    Float4 unknown160; /* +0x160 */
    Float4 unknown170; /* +0x170 */
};

/* derived names: the component of the type D_57d9d20 points to; slot 23
 * is handed the amount and the two vectors */
class Target007b2d50 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; not traced */
    virtual void slot18(); /* derived name; not traced */
    virtual void slot19(); /* derived name; not traced */
    virtual void slot20(); /* derived name; not traced */
    virtual void slot21(); /* derived name; not traced */
    virtual void slot22(); /* derived name; not traced */
    virtual void slot23(float amount, const Float4A &first,
                        const Float4A &second); /* derived name */
};

/* derived names: the object of the class whose vtable is at 0x16adf60
 * (tlg_game_object016adf60.h) as slot 11 reads it: the node at +0x28, an
 * int at +0x30 that must be non-zero, one at +0xe0 that must be zero, the
 * mark at +0xf0 and the two vectors kept at +0x100 and +0x110 */
struct Object007b2d50 /* derived name */
{
    u8 unknown0[0x28];
    Object016b85e0 *node; /* +0x28 */
    int unknown30;        /* +0x30 */
    u8 unknown34[0xac];
    int unknowne0; /* +0xe0 */
    u8 unknowne4[0xc];
    int unknownf0; /* +0xf0 */
    u8 unknownf4[0xc];
    Float4A unknown100; /* +0x100 */
    Float4A unknown110; /* +0x110 */
};

extern const Type00503fb0 *D_57db090; /* derived name */
extern const Type00503fb0 *D_57d9d20; /* derived name */

/* derived name: slot 11 of the vtable at 0x16adf60: for an amount of
 * 0.00001 or more, the two vectors of the node's source component kept and
 * handed with the amount to the target component's slot 23 */
// The second search's three drops are SimplifyCFG's copies of hasComponent's answer (the D94 signature).
// The moves before the drops (`mov rdi, r14` at 0x7b2e08, `mov rsi, r15; mov rdx, r13` at 0x7b2efe) are
// the post-RA rule's for a locked decrement
// (tools/patches/llvm-3.7.1-lockdec-02-postra-locked-dec-last.patch, D97).
void FUN_007b2d50(Object007b2d50 *self, float amount) /* derived name */
{
    if (self->unknown30 == 0 || fabsf(amount) < 0.00001f || self->unknowne0 != 0)
        return;
    self->unknownf0 = 1;
    Object016b85e0 *node = self->node;
    if (!node)
        return;
    Source007b2d50 *source = static_cast<Source007b2d50 *>(node->component(D_57db090));
    const Float4 first = source->unknown160;
    const Float4 second = source->unknown170;
    self->unknown110.set(first.x, first.y, first.z, first.w);
    self->unknown100.set(second.x, second.y, second.z, second.w);
    if (!node->hasComponent(D_57d9d20))
        return;
    reinterpret_cast<Target007b2d50 *>(node->component(D_57d9d20))
        ->slot23(amount, self->unknown110, self->unknown100);
}
