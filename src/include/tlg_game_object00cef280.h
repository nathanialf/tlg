/* src/include/tlg_game_object00cef280.h: the class whose vtable is at
 * 0x16b9850, a base (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT00CEF280_H
#define TLG_GAME_OBJECT00CEF280_H

#include "tlg_types.h"

/* derived names: a class whose vtable is at 0x16b9850 (stored by FUN_00cef280
 * FUN_00eb1170 FUN_00eb13f0): slot 0, FUN_00cef280, the complete destructor,
 * slot 1, FUN_00cef290, the deleting one (operator delete of the object). The
 * complete destructor stores the vptr and returns, the shape of a body holding
 * a statement that emits nothing (D16); that statement is not recovered, so
 * the body (leaf_00cef280.cpp) is empty and FUN_00cef280 stays unclaimed (its
 * vtable is not named either). The deleting destructor is the same either way:
 * dead store elimination drops the vptr store before operator delete. The
 * constructor, inlined in Object016be818's (FUN_00eb1170), sets +0x8 to -1 and
 * +0x10 to null. */
class Object00cef280 /* derived name */
{
  public:
    virtual ~Object00cef280();

    int unknown8;    /* +0x8: -1 from the constructor; not traced */
    void *unknown10; /* +0x10: null from the constructor; not traced */
};

#endif
