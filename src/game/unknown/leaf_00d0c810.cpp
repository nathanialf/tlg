/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: up to 32 slots of a name and an int, in two arrays (+0x14,
 * +0x94), the number in use at +0x10 and two masks of the slots (+0x114,
 * +0x118). FUN_00d0c810 sets a slot; it is called from many of the game's
 * units (FUN_0101b840, FUN_0102d160 and on). Neither the slots' meaning nor
 * the owner is traced. */
class Slots00d0c810 /* derived name */
{
  public:
    void set(const Name &name, unsigned index, u32 flags, int value);

  private:
    void setName(unsigned index, Name name)
    {
        names[index] = name;
    }

    u8 unknown0[0x10];
    unsigned count; /* +0x10 */
    Name names[32]; /* +0x14 */
    int values[32]; /* +0x94 */
    u32 mask114;    /* +0x114: bit 1 of the flags clears the slot's bit */
    u32 mask118;    /* +0x118: bit 0 of the flags sets it */
};

/* FUN_00d0c810 */
void Slots00d0c810::set(const Name &name, unsigned index, u32 flags, int value)
{
    const u32 bit = 1u << index;
    if (flags & 1)
        mask118 |= bit;
    if (flags & 2)
        mask114 &= ~bit;
    setName(index, name);
    values[index] = value;
    count = count > index + 1 ? count : index + 1;
}
