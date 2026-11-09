/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: three functions on the file's own flag at 0x583262c (direct
 * RIP-relative accesses: internal linkage, docs/DECISIONS.md D17), which
 * FUN_00b127e0 also clears (0xb1296b). FUN_00b10ec0 stores the addresses of
 * FUN_00b108b0 and FUN_00b108c0 (lea at 0xb11f47 and 0xb11f64) and of
 * FUN_00b108d0 (lea at 0xb12037, stored at 0x5832398) into its records; none
 * of the three reads an argument, and no call shows its parameters. Owner and
 * meaning unknown. */
static bool D_583262c;

void FUN_00b108b0() /* derived name */
{
    D_583262c = true;
}

void FUN_00b108c0() /* derived name */
{
    D_583262c = false;
}

// NONMATCHING: FUN_00b108d0, the base masks the load (`mov al, [rip]; and al, 1`,
// 9 bytes) and 4.0.0 returns it bare (7 bytes): GlobalOpt shrinks this static to
// an i1 (stores of true and false only) and 3.9 and later return an i1 load
// unmasked; 3.7.1 and 3.8.1 give the base bytes from this source. The base has 8
// more masked byte-global loads (0x5946608 read from many files, one store of 1),
// a region-wide question (the loads, the visibility of direct globals).
bool FUN_00b108d0() /* derived name */
{
    return D_583262c;
}
