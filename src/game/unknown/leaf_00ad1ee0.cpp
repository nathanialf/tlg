/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the handler for the marker
 * "Marker.phy_RemoveSoldierParts.enter": FUN_00ad3090 stores its address at
 * 0x582cb08 (lea at 0xad4290), beside the int at 0x582cb00 that holds the
 * result of FUN_013baad0 for that name (its hash from FUN_013bad90, its length
 * 35 in edx). It calls FUN_00ad47b0 with its argument, 1 and 0 (32-bit
 * values, as FUN_00ad1ec0 passes them) as a tail call. The argument's type and
 * the return type are not traced. Owner and meaning unknown. */
struct Object00ad47b0; /* derived name */

void FUN_00ad47b0(Object00ad47b0 *object, int, int); /* derived name */

void FUN_00ad1ee0(Object00ad47b0 *object) /* derived name */
{
    FUN_00ad47b0(object, 1, 0);
}
