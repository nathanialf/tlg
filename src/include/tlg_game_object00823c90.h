/* src/include/tlg_game_object00823c90.h: the class FUN_00823c90 is given
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT00823C90_H
#define TLG_GAME_OBJECT00823C90_H

#include "tlg_game_array.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose slot 16 (FUN_0134d780 in the vtables at
 * 0x16a8830 and 0x16c7608, FUN_01360430 in those at 0x16ac180 and
 * 0x16cb520) hands its string to FUN_00823c90: the objects at +0x270 (their
 * count at +0x278), each compared by its name at +0xc (`cmp [rdx+0xc],
 * r14d`), and slot 15 (`call [rax+0x78]`) run when one is named. Slots 2 to
 * 14 and the rest of the class are not traced. */
class Object00823c90 /* derived name */
{
  public:
    virtual ~Object00823c90();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(); /* derived name: run when a name is found */

    u8 unknown8[0x268];
    Array05943280<Object016b9108 *> objects; /* +0x270 */
};

/* derived name: 1 when one of the objects has the name the string makes
 * (interned as a copy), after slot 15 ran; else 0 (0x823c90) */
int FUN_00823c90(Object00823c90 *self, const char *string);

/* derived name: not traced (0x134d0e0) */
void FUN_0134d0e0(Object00823c90 *self);

#endif
