/* src/include/tlg_game_type.h: the game's run-time type of a component (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_TYPE_H
#define TLG_GAME_TYPE_H

/* derived names: a type is a chain of types linked by their first field;
 * an object's type pointer is compared along the chain with the address a
 * global holds (FUN_00503fb0, FUN_00644eb0, FUN_013937c0) */
#include "tlg_game_name.h"

class Object016b9108; /* derived name */

/* what a type is told of each object made of it (slot 0, called with the
 * new object or null by FUN_00cbc5a0 at 0xcbc775); the other slots are not
 * traced */
class TypeListener00cbc5a0 /* derived name */
{
  public:
    virtual void created(Object016b9108 *object); /* derived name */
};

struct Type00503fb0 {     /* derived name */
    Type00503fb0 *parent; /* +0x0 */
    /* +0x8: makes an object of the type under a name, null for a type that
     * cannot be made (FUN_00cbc5a0: `mov r13, [r13+8]; test r13, r13`, then
     * `call r13` with the type and the name's address) */
    Object016b9108 *(*create)(Type00503fb0 *type, const Name *name);
    /* +0x10: frees an object of the type (FUN_00cb66f0: `mov rax,
     * [rbx+0x18]; mov rdi, rbx; jmp [rax+0x10]`) */
    void (*destroy)(Object016b9108 *object);
    TypeListener00cbc5a0 *listener; /* +0x18 */
    Name name; /* +0x20: the type's name (FUN_00e73a30 hands its string to a script) */
    unsigned char unknown24[8];
    /* +0x2c: bit 1 set for a type whose objects are not copied (FUN_008a9440
     * and the script's "Clone", FUN_00e768a0, make none) */
    unsigned char flags;
    unsigned char unknown2d[0xb];
    /* +0x38: the type's own properties, a table of chains by the name's
     * index modulo the count of chains at +0x40 (FUN_00cb7e20: `div esi`;
     * no table for a count of 0), a parent's looked up after */
    struct PropertyNode00cb7e20 **properties;
    unsigned propertyChains; /* +0x40 */
};

/* the type itself or one it derives from: the type is compared first, then
 * each parent as it is read and before it is tested for the end (0xc1ad02 to
 * 0xc1ad1b: `cmp rax, rcx; je`, then `mov rdx, [rdx]; cmp rdx, rcx; je; test
 * rdx, rdx; jne`). Defined in func_00503fb0.cpp, not inline: the link
 * inlines it at every site, and the shape of 0x9f54b0 (the found arm's
 * `test rdi, rdi; sete al` before the merge) is what the link's passes
 * give over the inlined walk, never what the unit's own pipeline gives. */
bool isKindOf(const Type00503fb0 *t, const Type00503fb0 *type); /* derived name */

#endif
