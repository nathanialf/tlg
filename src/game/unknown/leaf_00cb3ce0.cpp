/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 6 of the vtable at 0x16b9048 (its pointer at
 * 0x16b9088), stored by FUN_00cb3170 and FUN_013ad610: returns the pointer at
 * +0x48 when the record the pointer at +0x40 holds is present with its ints
 * at +0x50 and +0x30 both nonzero; otherwise, of the record the pointer at
 * +0x38 holds, the pointer at +0x88 when it is not null, else the one at
 * +0x80. The pointers' types are not traced. Class and method unknown. */
struct Object00cb3ce0_40 /* derived name */
{
    unsigned char unknown0[0x30];
    int unknown30; /* +0x30 */
    unsigned char unknown34[0x1c];
    int unknown50; /* +0x50 */
};

struct Object00cb3ce0_38 /* derived name */
{
    unsigned char unknown0[0x80];
    void *unknown80; /* +0x80 */
    void *unknown88; /* +0x88 */
};

struct Object00cb3ce0 /* derived name */
{
    unsigned char unknown0[0x38];
    Object00cb3ce0_38 *unknown38; /* +0x38 */
    Object00cb3ce0_40 *unknown40; /* +0x40 */
    void *unknown48;              /* +0x48 */
};

void *FUN_00cb3ce0(const Object00cb3ce0 *self) /* derived name */
{
    const Object00cb3ce0_40 *active = self->unknown40;
    if (active && active->unknown50 && active->unknown30)
        return self->unknown48;
    const Object00cb3ce0_38 *other = self->unknown38;
    return other->unknown88 ? other->unknown88 : other->unknown80;
}
