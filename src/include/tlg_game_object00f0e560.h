/* src/include/tlg_game_object00f0e560.h: the game's intrusive list entry
 * over the class at 0x16d3670 (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT00F0E560_H
#define TLG_GAME_OBJECT00F0E560_H

#include "tlg_types.h"

/* derived names: the class whose own destructor 0x13cd310 only stores its
 * vtable (0x16d3670, config/vtables.derived.base.txt), defined inline: the
 * destructors of the classes over it store that vtable last. Its int at
 * +0xc is a handle of the sound runtime in Object016beae0 (leaf_00ebf4d0.cpp);
 * the field at +0x8 is not traced. */
class Object013cd310 /* derived name */
{
  public:
    virtual ~Object013cd310() {}

  protected:
    u8 unknown8[0x4];
    int unknownc; /* +0xc */
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

#endif
