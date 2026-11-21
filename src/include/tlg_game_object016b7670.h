/* src/include/tlg_game_object016b7670.h: the class whose vtable is at
 * 0x16b7670, a base of game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016B7670_H
#define TLG_GAME_OBJECT016B7670_H

/* derived names: the class whose vtable is at 0x16b7670
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00bc3620
 * and its complete destructor FUN_00bc3780, after its canary set-up; that
 * row named for it, D15). The classes derived from it tail-call that
 * destructor from their own (leaf_00b893e0.cpp, leaf_00b89eb0.cpp,
 * leaf_00bc3b10.cpp, leaf_013c96e0.cpp). The destructor is not written, so
 * nothing here emits the vtable; the class's other slots and its fields are
 * not traced. */
class Object016b7670 /* derived name */
{
  public:
    virtual ~Object016b7670();
};

#endif
