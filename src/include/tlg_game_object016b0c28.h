/* src/include/tlg_game_object016b0c28.h: the class of the vtable at
 * 0x16b0c28 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0C28_H
#define TLG_GAME_OBJECT016B0C28_H

/* derived names: a class of one pointer, its vtable, whose destructor does
 * nothing (slot 0 the complete destructor 0x912720, slot 1 the deleting one
 * 0x912730) and whose slot 2 is FUN_00911780, not yet read. One instance is
 * static, at 0x58200b8, built by FUN_009114c0. */
class Object016b0c28 /* derived name */
{
  public:
    /* written out: the static instance's vtable is stored when its unit's
     * initializer runs (`lea rax, [0x16b0c38]; mov [0x58200b8], rax`), where
     * an implicit constructor leaves it in the data */
    Object016b0c28() {}

    virtual ~Object016b0c28();
    virtual void unknown2(); /* 0x911780: the arguments are not traced */
};

#endif
