/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: a record set from its arguments, its int at +0xc made -1;
 * a kind of 11 sets bit 0 of the flags. FUN_00e744c0 sets one with a name
 * made from a string, the empty name second and no pointer. The fields'
 * meanings are not traced. */
class Record00cb7c20 /* derived name */
{
  public:
    void set(const Name &name, int kind, int value, u32 flags, int unknown, const Name &other,
             void *pointer);

  private:
    int kind;      /* +0x0 */
    u32 flags;     /* +0x4 */
    int unknown8;  /* +0x8 */
    int unknownc;  /* +0xc */
    int value;     /* +0x10 */
    Name name;     /* +0x14 */
    Name other;    /* +0x18 */
    void *pointer; /* +0x20 */
};

/* FUN_00cb7c20 */
void Record00cb7c20::set(const Name &name, int kind, int value, u32 flags, int unknown,
                         const Name &other, void *pointer)
{
    this->kind = kind;
    this->flags = flags | (kind == 11);
    unknown8 = unknown;
    unknownc = -1;
    this->value = value;
    this->name = name;
    this->other = other;
    this->pointer = pointer;
}
