/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the address of the read-only table at 0x15251ec (its
 * first words read as the floats 0, 0.45, 0.4, 0.4, 1.0); slot 2 of the vtable
 * at 0x16b8980 (its pointer at 0x16b89a0), no storing constructor listed,
 * whose slot 1 is PlainPolymorphic's deleting destructor. The table's layout
 * is not traced; it is referenced as the data it is (D8 addendum, D10). Class
 * and method unknown. */
extern const float D_15251ec[];

struct Object013aab40;

const float *FUN_013aab40(const Object013aab40 *self) /* derived name */
{
    return D_15251ec;
}
