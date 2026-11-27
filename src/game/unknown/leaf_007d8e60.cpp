/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: a reader of the frame's first argument for FUN_00c91140
 * (as leaf_003e7260.cpp's). */
struct ArgumentReader00c8c290 { /* derived name */

    explicit ArgumentReader00c8c290(lua_State *state_)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index =
            -(int)((unsigned long)((char *)state_->top - (char *)state_->base) / sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

void FUN_00c91140(ArgumentReader00c8c290 *reader, Name *name); /* derived name */

/* derived names: an object reached from the pointer at 0x57ca570 (its
 * pointer at +0x28 to the object's pointer) whose base at +0x68 answers an
 * int for a string through its slot 6 (`mov rax, [rdi+0x68]; add rdi,
 * 0x68; call [rax+0x30]`); the slots before it, the first base and the rest
 * of the classes are not traced */
class Head007d8e60
{ /* derived name */
  public:
    virtual ~Head007d8e60();

  private:
    u8 unknown8[0x60];
};

class Table007d8e60
{ /* derived name */
  public:
    virtual void slot0();                 /* derived name */
    virtual void slot1();                 /* derived name */
    virtual void slot2();                 /* derived name */
    virtual void slot3();                 /* derived name */
    virtual void slot4();                 /* derived name */
    virtual void slot5();                 /* derived name */
    virtual int find(const char *string); /* derived name: slot 6 */
};

class Object007d8e60 : public Head007d8e60, public Table007d8e60
{ /* derived name */
};

struct Holder057ca570 { /* derived name */
    u8 unknown0[0x28];
    Object007d8e60 **object28; /* +0x28 */
};

extern Holder057ca570 *D_57ca570;

/* derived names: a script C function: reads its first argument as a Name
 * (FUN_00c91140) and pushes, as a number, what the table at +0x68 of the
 * object answers for the name's string; returns 1 */
int FUN_007d8e60(lua_State *state) /* derived name */
{
    Name name;
    ArgumentReader00c8c290 reader(state);
    FUN_00c91140(&reader, &name);
    pushNumber(state, (*D_57ca570->object28)->find(name.string()));
    return 1;
}
