/* src/include/tlg_game_object05989c08.h: the object the pointer at
 * 0x5989c08 holds (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT05989C08_H
#define TLG_GAME_OBJECT05989C08_H

#include "tlg_types.h"
#include "tlg_sce_kernel.h"

/* derived names: slot 10 returns an int (FUN_00b34440); +0xf0 and +0xf8
 * are called, when set, by each game thread as it starts, with the thread
 * and its thread-local int at 0x16dc0b0, and as it ends, with the thread
 * (FUN_00d6db10); FUN_00d6b0a0 clears the pointer. */
class Object05989c08 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
    virtual int slot10(); /* derived name; not traced */

    u8 unknown8[0xe8];
    void (*threadStarted)(pthread_t thread, int value); /* +0xf0 */
    void (*threadEnded)(pthread_t thread);              /* +0xf8 */
};

extern Object05989c08 *D_5989c08;

#endif
