/* src/include/tlg_game_command003e4440.h: the commands the script C
 * functions FUN_003e12d0 to FUN_003e38e0 make and append to their object's
 * list (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_COMMAND003E4440_H
#define TLG_GAME_COMMAND003E4440_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_hks.h"
#include "tlg_math.h"

/* derived names: a reader of one argument of the frame for the readers
 * below (as leaf_002c40a0.cpp's), its index the argument's offset from the
 * first less the count of arguments */
struct ArgumentReader003e4440 { /* derived name */

    explicit ArgumentReader003e4440(lua_State *state_, int argument = 0)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = argument - (int)((unsigned long)((char *)state_->top - (char *)state_->base) /
                                 sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

void FUN_00c8c290(ArgumentReader003e4440 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8edb0(ArgumentReader003e4440 *reader, Float4A *vector);         /* derived name */
void FUN_00c8d080(ArgumentReader003e4440 *reader, long *value);             /* derived name */
void FUN_00c8d380(ArgumentReader003e4440 *reader, float *value);            /* derived name */

/* derived names: a command: a counted object that is not of the root class
 * (no call of the root's constructor; tlg_game_object016b9108.h's counted
 * base), with two members of its own stored before the vptr of the class
 * made (`mov dword [r14+0xc], 0x80000000; mov dword [r14+0x10], 0` at
 * 0x3e13cb, then `mov [r14], rax`): the word at +0xc is never read by the
 * makers, the int at +0x10 is the value each one reads last or third from
 * its arguments. Slot 3 is the command's own function (an empty body in
 * each class made here: FUN_003e3be0 and on). */
class Command003e4440 : public Counted00c14bc0 /* derived name */
{
  public:
    Command003e4440() : unknownc(0x80000000), unknown10(0) {}

    virtual void slot3(); /* derived name */

    unsigned unknownc; /* +0xc */
    int unknown10;     /* +0x10 */
};

/* derived names: the object a command is appended to, of the type the
 * pointer at 0x5829020 holds: its commands at +0x450 */
class Holder003e4440 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x42c];
    Array05943280<Ref00503fb0<Command003e4440>> commands; /* +0x450 */
};

/* derived names: the object the pointer at 0x5938c40 holds, as the makers
 * read it: no command is made unless bit 3 at +0x6c of the object at +0xe8
 * is set and the int at +0x1f4 is not zero */
struct State003e4440 { /* derived name */
    u8 unknown0[0x6c];
    u8 flags6c; /* +0x6c */
};

struct Game003e4440 { /* derived name */
    u8 unknown0[0xe8];
    State003e4440 *unknowne8; /* +0xe8 */
    u8 unknownf0[0x104];
    int unknown1f4; /* +0x1f4 */
};

extern Game003e4440 *D_5938c40;
extern Type00503fb0 *D_5829020; /* derived name: the holder's type */

/* the class of the vtable at 0x16a8f58 (FUN_003e12d0 makes it): two
 * vectors */
class Object016a8f58 : public Command003e4440 /* derived name */
{
  public:
    virtual void slot3(); /* derived name; FUN_003e3be0 */

    Float4A unknown20; /* +0x20 */
    Float4A unknown30; /* +0x30 */
};

/* the classes of the vtables at 0x16a8f88 and 0x16a8fb8 (FUN_003e1560 and
 * FUN_003e1850 make them): two vectors and a float, cleared by the
 * constructor after the vptr is stored (`mov dword [r14+0x40], 0` at
 * 0x3e1672) */
class Object016a8f88 : public Command003e4440 /* derived name */
{
  public:
    Object016a8f88() : unknown40(0.0f) {}

    virtual void slot3(); /* derived name; FUN_003e3bf0 */

    Float4A unknown20; /* +0x20 */
    Float4A unknown30; /* +0x30 */
    float unknown40;   /* +0x40 */
};

class Object016a8fb8 : public Command003e4440 /* derived name */
{
  public:
    Object016a8fb8() : unknown40(0.0f) {}

    virtual void slot3(); /* derived name; FUN_003e3c00 */

    Float4A unknown20; /* +0x20 */
    Float4A unknown30; /* +0x30 */
    float unknown40;   /* +0x40 */
};

#endif
