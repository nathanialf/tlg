/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an entry of a palette: a colour's three bytes and its
 * index, 0xff ending the palette (16 bytes each) */
struct PaletteEntry01346910 { /* derived name */
    u8 red;
    u8 green;
    u8 blue;
    u8 index; /* +0x3 */
    u8 unknown4[0xc];
};

struct Colour01346910 { /* derived name */
    float red;
    float green;
    float blue;
};

/* derived names: the class whose vtable is at 0x16c7250
 * (config/vtables.derived.base.txt, stored by FUN_0021c350): slot 0
 * (0x1346910) gives a colour's value: the index of the first palette entry
 * whose three bytes are each within one of the colour's (each channel times
 * 255, truncated to a byte), 0xff without one, masked to the low `bits` bits
 * (+0x1c, the mask a byte) and shifted up by `shift` (+0x18). The other
 * fields are not traced. */
class Object016c7250 /* derived name */
{
  public:
    virtual u32 FUN_01346910(const Colour01346910 &colour) const;

  private:
    u8 unknown8[0x10];
    u8 shift18; /* +0x18 */
    u8 unknown19[0x3];
    u8 bits1c; /* +0x1c */
    u8 unknown1d[0x3];
    const PaletteEntry01346910 *palette20; /* +0x20 */
};

u32 Object016c7250::FUN_01346910(const Colour01346910 &colour) const
{
    unsigned index = 0xff;
    const PaletteEntry01346910 *palette = palette20;
    if (palette && palette[0].index != 0xff) {
        const int red = u8(colour.red * 255.0f);
        const int green = u8(colour.green * 255.0f);
        const int blue = u8(colour.blue * 255.0f);
        for (unsigned i = 0; palette[i].index != 0xff; ++i) {
            const PaletteEntry01346910 &entry = palette[i];
            if (entry.red >= red - 1 && entry.red <= red + 1 && entry.green >= green - 1 &&
                entry.green <= green + 1 && entry.blue >= blue - 1 && entry.blue <= blue + 1) {
                index = entry.index;
                break;
            }
        }
    }
    const u8 mask = (1 << bits1c) - 1;
    return (index & mask) << shift18;
}
