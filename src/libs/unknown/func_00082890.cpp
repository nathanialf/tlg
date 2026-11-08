/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The constraint's info from its atoms (Havok's getConstraintInfoUtil by
 * its shape): the atoms kept, the counts cleared and the jacobian header
 * added, then each atom's schema size, solver results and temporaries by
 * its type; padding skipped to the next 16 bytes, a bridge or a modifier
 * ends the walk. */
/* NONMATCHING: 732 bytes against 716, every case's arithmetic and step the
 * base's: left, the padding's edge and the block layout. The base goes from
 * the padding's alignment straight back to the switch, with no bound test
 * (0x828d0 falls into 0x828d8); here the continue goes through the loop's
 * test. Measured: a goto back to the switch gives that edge and 13 lines
 * left (the latch after the 16-byte step block and two tails BranchFolding
 * merges here), but it is not the developer's form until a loop that
 * reaches SimplifyCFG with the type test folded into the switch is found
 * (a while over the padding before the switch keeps a separate test and a
 * switch from 1). NOTES Round 81A. */
void hkpConstraintData::FUN_00082890(const void *atoms, int sizeOfAtoms, ConstraintInfo &infoOut)
{
    infoOut.atoms = atoms;
    infoOut.sizeOfAllAtoms = sizeOfAtoms;
    infoOut.clear();
    infoOut.addHeader();
    const char *const atomsEnd =
        hkAddByteOffsetConst(static_cast<const char *>(atoms), sizeOfAtoms);
    for (const char *atom = static_cast<const char *>(atoms); atom < atomsEnd;) {
        switch (reinterpret_cast<const hkpConstraintAtom *>(atom)->type) {
        case hkpConstraintAtom::TYPE_INVALID:
            atom = reinterpret_cast<const char *>((hkUlong(atom) + 15) & ~hkUlong(15));
            continue;
        case hkpConstraintAtom::TYPE_BRIDGE:
            return;
        case hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS:
            atom += 144;
            break;
        case hkpConstraintAtom::TYPE_SET_LOCAL_TRANSLATIONS:
            atom += 48;
            break;
        case hkpConstraintAtom::TYPE_SET_LOCAL_ROTATIONS:
            atom += 112;
            break;
        case hkpConstraintAtom::TYPE_BALL_SOCKET: {
            const int schemaSize = hkMath::max2(144, 64);
            infoOut.add(schemaSize, hkMath::max2(3, 3), hkMath::max2(3, 3));
            infoOut.unknown1c += 128 - schemaSize;
            atom += 16;
            break;
        }
        case hkpConstraintAtom::TYPE_STIFF_SPRING:
            infoOut.add(64, 1, 1);
            infoOut.unknown1c += 64;
            atom += 32;
            break;
        case hkpConstraintAtom::TYPE_LIN:
            infoOut.add(48, 1, 1);
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_LIN_SOFT:
            infoOut.add(64, 1, 1);
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_LIN_LIMIT:
            infoOut.add(64, 1, 1);
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_LIN_FRICTION:
            infoOut.add(64, 2, 2);
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_LIN_MOTOR:
            infoOut.add(80, 2, 2);
            atom += 32;
            break;
        case hkpConstraintAtom::TYPE_2D_ANG:
            infoOut.add(64, 2, 2);
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_ANG: {
            const int numAxes =
                reinterpret_cast<const hkpAngConstraintAtom *>(atom)->numConstrainedAxes;
            infoOut.add(numAxes * 32, numAxes, numAxes);
            atom += 16;
            break;
        }
        case hkpConstraintAtom::TYPE_ANG_LIMIT:
            infoOut.add(48, 1, 1);
            atom += 32;
            break;
        case hkpConstraintAtom::TYPE_TWIST_LIMIT:
            infoOut.add(48, 1, 1);
            atom += 32;
            break;
        case hkpConstraintAtom::TYPE_CONE_LIMIT:
            infoOut.add(48, 1, 1);
            atom += 32;
            break;
        case hkpConstraintAtom::TYPE_ANG_FRICTION: {
            const int numAxes =
                reinterpret_cast<const hkpAngFrictionConstraintAtom *>(atom)->numFrictionAxes;
            infoOut.add(numAxes * 48, 2 * numAxes, 2 * numAxes);
            atom += 16;
            break;
        }
        case hkpConstraintAtom::TYPE_ANG_MOTOR:
            infoOut.add(64, 2, 2);
            atom += 32;
            break;
        case hkpConstraintAtom::TYPE_RAGDOLL_MOTOR:
            infoOut.add(192, 6, 6);
            atom += 96;
            break;
        case hkpConstraintAtom::TYPE_PULLEY:
            infoOut.add(64, 1, 1);
            atom += 64;
            break;
        case hkpConstraintAtom::TYPE_RACK_AND_PINION:
            infoOut.add(64, 1, 1);
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_COG_WHEEL:
            infoOut.add(64, 1, 1);
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_SETUP_STABILIZATION:
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_3D_ANG:
            infoOut.add(48, 3, 3);
            infoOut.unknown1c += 48;
            atom += 16;
            break;
        case hkpConstraintAtom::TYPE_DEFORMABLE_3D_LIN:
            infoOut.add(128, 3, 3);
            infoOut.unknown1c += 64;
            atom += 96;
            break;
        case hkpConstraintAtom::TYPE_DEFORMABLE_3D_ANG:
            infoOut.add(128, 3, 3);
            infoOut.unknown1c += 64;
            atom += 96;
            break;
        case hkpConstraintAtom::TYPE_OVERWRITE_PIVOT:
            break;
        case hkpConstraintAtom::TYPE_WHEEL_FRICTION:
            infoOut.sizeOfSchemas += 112;
            infoOut.numSolverElemTemps += 2;
            atom += 64;
            break;
        case hkpConstraintAtom::TYPE_ELLIPTICAL_LIMIT:
            infoOut.add(112, 2, 2);
            atom += 48;
            break;
        case hkpConstraintAtom::TYPE_CONTACT:
            break;
        case hkpConstraintAtom::TYPE_MODIFIER_SOFT_CONTACT:
        case hkpConstraintAtom::TYPE_MODIFIER_MASS_CHANGER:
        case hkpConstraintAtom::TYPE_MODIFIER_VISCOUS_SURFACE:
        case hkpConstraintAtom::TYPE_MODIFIER_MOVING_SURFACE:
        case hkpConstraintAtom::TYPE_MODIFIER_IGNORE_CONSTRAINT:
            return;
        default:
            break;
        }
    }
}
