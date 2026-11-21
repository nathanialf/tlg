/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: the class whose vtable is at 0x16b1308
 * (config/vtables.derived.base.txt; stored by FUN_00961800), over
 * Class137ba70: the objects its slot 5 passes the call on to (+0x40, +0x78
 * to +0xa0) and an array of counted references at +0x48. Its destructor
 * (slot 0, 0x137ead0) is not written. */
class Object016b1308 : public Class137ba70 /* derived name */
{
  public:
    virtual ~Object016b1308();
    void FUN_0137ba50();

  private:
    Class137ba70 *child40;                                 /* +0x40 */
    Array05943280<Ref00503fb0<Object016b9108>> children48; /* +0x48 */
    u8 unknown60[0x18];
    Class137ba70 *child78; /* +0x78 */
    Class137ba70 *child80; /* +0x80 */
    Class137ba70 *child88; /* +0x88 */
    Class137ba70 *child90; /* +0x90 */
    Class137ba70 *child98; /* +0x98 */
    Class137ba70 *childa0; /* +0xa0 */
};

/* derived names: slot 5 of the vtable at 0x16b1308: the call passed on to
 * each object it holds, the array's each held by a copy of its reference
 * while it is called, the object at +0x90 last. */
void Object016b1308::FUN_0137ba50()
{
    if (childa0)
        childa0->FUN_0137ba50();
    if (child98)
        child98->FUN_0137ba50();
    if (child78)
        child78->FUN_0137ba50();
    if (child40)
        child40->FUN_0137ba50();
    if (child80)
        child80->FUN_0137ba50();
    if (child88)
        child88->FUN_0137ba50();
    const unsigned count = children48.size();
    for (unsigned i = 0; i < count; ++i) {
        Ref00503fb0<Object016b9108> child(children48.at(i));
        if (child.get())
            static_cast<Class137ba70 *>(child.get())->FUN_0137ba50();
    }
    if (child90)
        child90->FUN_0137ba50();
}
