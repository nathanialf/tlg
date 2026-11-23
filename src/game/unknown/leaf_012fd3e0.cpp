/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived name: the count of components of each surface format
 * (leaf_012fd020.cpp) */
extern const int D_15252d0[61];

/* derived names: the channel order of a data format, the inverse of
 * FUN_012fd020 (leaf_012fd020.cpp): the format's count of components and
 * its four channel selects (x from bit 12, y from 15, z from 18, w from 21)
 * matched against each order's selects; false for a format past the table,
 * a count with no orders or selects of no order, else the order stored
 * where asked for (called by FUN_012fbda0, FUN_01307080 and FUN_0131fea0).
 * The selects of an order of three or four components come out of the
 * compiler in another order than written (0x12fd4fe to 0x12fd5a1): their
 * and is reassociated, the last test written first. */
bool FUN_012fd3e0(u32 dataFormat, int *channelOrder) /* derived name */
{
    u32 format = dataFormat & 0xff;
    if (format <= 60) {
        int count = D_15252d0[format];
        if (count >= 1 && count <= 4) {
            u32 x = dataFormat >> 12 & 7;
            u32 y = dataFormat >> 15 & 7;
            u32 z = dataFormat >> 18 & 7;
            u32 w = dataFormat >> 21 & 7;
            int order;
            if (count == 1) {
                if (x == 4)
                    order = 0;
                else if (y == 4)
                    order = 1;
                else if (z == 4)
                    order = 2;
                else if (w == 4)
                    order = 3;
                else
                    return false;
            } else if (count == 2) {
                if (x == 4 && y == 5)
                    order = 0;
                else if (x == 4 && w == 5)
                    order = 1;
                else if (y == 4 && x == 5)
                    order = 2;
                else if (w == 4 && x == 5)
                    order = 3;
                else
                    return false;
            } else if (count == 3) {
                if (x == 4 && y == 5 && z == 6)
                    order = 0;
                else if (x == 4 && y == 5 && w == 6)
                    order = 1;
                else if (z == 4 && y == 5 && x == 6)
                    order = 2;
                else if (w == 4 && y == 5 && x == 6)
                    order = 3;
                else
                    return false;
            } else {
                if (x == 4 && y == 5 && z == 6 && w == 7)
                    order = 0;
                else if (z == 4 && y == 5 && x == 6 && w == 7)
                    order = 1;
                else if (w == 4 && z == 5 && y == 6 && x == 7)
                    order = 2;
                else if (w == 4 && x == 5 && y == 6 && z == 7)
                    order = 3;
                else
                    return false;
            }
            if (channelOrder)
                *channelOrder = order;
            return true;
        }
    }
    return false;
}
