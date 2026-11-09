/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the handler for the marker
 * "Marker.phy_DetachAndParticleParts.enter": FUN_00ad3090 stores its address at
 * 0x582caf8 (lea at 0xad425c), beside the int at 0x582caf0 that holds the
 * result of FUN_013baad0 for that name (its hash from FUN_013bad90, its length
 * 39 in edx). It calls FUN_00ad47b0 with its argument, 0 and 1 (32-bit
 * values, as FUN_00ad1ec0 passes them) as a tail call. The argument's type and
 * the return type are not traced. Owner and meaning unknown. */
struct Object00ad47b0; /* derived name */

void FUN_00ad47b0(Object00ad47b0 *object, int, int); /* derived name */

void FUN_00ad1ed0(Object00ad47b0 *object) /* derived name */
{
    FUN_00ad47b0(object, 0, 1);
}
