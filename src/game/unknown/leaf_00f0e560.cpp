/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the class whose own destructor 0x13cd310 only stores its
 * vtable (0x16d3670, config/vtables.derived.base.txt), defined inline: the
 * destructors of the classes over it store that vtable last. Its field at
 * +0x8 is not traced. */
class Object013cd310 /* derived name */
{
  public:
    virtual ~Object013cd310() {}

  private:
    u8 unknown8[0x8];
};

/* derived names: the class whose vtable is at 0x16bedb8 (its slot 109,
 * FUN_013d2860), an entry of an intrusive list: at +0x10 the address of the
 * pointer that points to it (the list's head or the previous entry's next)
 * and at +0x18 the next entry. Its destructor (FUN_00f0e560, slot 0) takes
 * it out, the next entry given this one's back link first (`mov rax,
 * [rdi+0x18]; test; je; mov rcx, [rdi+0x10]; mov [rax+0x10], rcx`), then
 * the pointer that pointed to it given the next, and clears both links
 * (one 16-byte store); slot 1 (FUN_00f0e5a0) does the same before operator
 * delete, the clearing and the base's vtable dropped. */
class Object00f0e560 : public Object013cd310 /* derived name */
{
  public:
    virtual ~Object00f0e560();

  private:
    Object00f0e560 **link10; /* +0x10 */
    Object00f0e560 *next18;  /* +0x18 */
};

/* FUN_00f0e560 */
// NONMATCHING: the base's vtable stored last (`lea rcx, [0x16d3680]; mov [rdi], rcx` at 0xf0e591):
// Object013cd310's destructor has an empty body, which clang skips the store for
// (CanSkipVTablePointerInitialization), and its own out-of-line copy 0x13cd310 stores it too: what
// its body or fields hold is not known. FUN_00f0e5a0, the deleting destructor, drops the store and
// is equal.
Object00f0e560::~Object00f0e560()
{
    if (next18)
        next18->link10 = link10;
    if (link10)
        *link10 = next18;
    link10 = 0;
    next18 = 0;
}
