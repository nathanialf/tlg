/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the character sink at +0x8 of the vtable 0x16a9dc8's class
 * (leaf_0047e320.cpp's member): slot 3 takes one character */
class Writer0047e3a0 /* derived name */
{
  public:
    virtual void slot0();    /* derived name; not traced */
    virtual void slot1();    /* derived name; not traced */
    virtual void slot2();    /* derived name; not traced */
    virtual void put(int c); /* derived name */
};

/* derived names: slots 7 and 8 of the vtable at 0x16a9dc8 (stored by
 * FUN_0047a6e0, FUN_0047dd70 and FUN_0047de60; home vm-core.cpp): a block
 * opened and closed in the text the sink is given, a line break as "\r\n",
 * the line indented by one tab per level of the depth at +0x10. */
struct Object0047e3a0 { /* derived name */

    void newline()
    {
        out->put('\r');
        out->put('\n');
    }

    u8 unknown0[8];
    Writer0047e3a0 *out; /* +0x8 */
    int depth;           /* +0x10 */
};

/* derived names: a new line, the brace, and a new line one level deeper */
void FUN_0047e3a0(Object0047e3a0 *self) /* derived name */
{
    self->newline();
    for (int i = 0; i < self->depth; ++i)
        self->out->put('\t');
    self->out->put('{');
    self->newline();
    ++self->depth;
    for (int i = 0; i < self->depth; ++i)
        self->out->put('\t');
}

/* derived names: a new line one level back out and the closing brace */
void FUN_0047e450(Object0047e3a0 *self) /* derived name */
{
    self->newline();
    --self->depth;
    for (int i = 0; i < self->depth; ++i)
        self->out->put('\t');
    self->out->put('}');
}
