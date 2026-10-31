/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void RefArrays0005a230::FUN_0006c110(const hkCommand &command, hkOstream &stream) const
{
    switch (command.secondaryType) {
    case 0:
        reinterpret_cast<const hknpTriggerEvent &>(command).FUN_00040b70(world, stream);
        break;
    case 1:
        reinterpret_cast<const hknpManifoldEvent &>(command).FUN_00040a20(world, stream);
        break;
    case 2:
        reinterpret_cast<const hknpContactImpulseEvent &>(command).FUN_0003da50(world, stream);
        break;
    case 3:
        reinterpret_cast<const hknpContactImpulseClippedEvent &>(command).FUN_0003dc30(world,
                                                                                       stream);
        break;
    case 4:
        reinterpret_cast<const hknpBinaryBodyDebugEvent &>(command).FUN_001554f0(world, stream);
        break;
    case 10:
        reinterpret_cast<const hknpBodyActivationEvent &>(command).FUN_00155430(world, stream);
        break;
    case 11:
        reinterpret_cast<const hknpBodyExitedBroadPhaseEvent &>(command).FUN_00155490(world,
                                                                                      stream);
        break;
    case 12:
        reinterpret_cast<const hknpLinearIntegrationClippedCommand &>(command).FUN_0003ddd0(world,
                                                                                            stream);
        break;
    case 13:
        reinterpret_cast<const hknpBodyBreachedExpandedAabbEvent &>(command).FUN_001554c0(world,
                                                                                          stream);
        break;
    case 14:
        reinterpret_cast<const hknpUnaryBodyDebugEvent &>(command).FUN_00155550(world, stream);
        break;
    case 20:
        reinterpret_cast<const hknpConstraintForceEvent &>(command).FUN_0003ddb0(world, stream);
        break;
    case 21:
        reinterpret_cast<const hknpConstraintForceExceededEvent &>(command).FUN_0003ddc0(world,
                                                                                         stream);
        break;
    case 22:
        reinterpret_cast<const hknpReservedEvent &>(command).FUN_00040be0(world, stream);
        break;
    case 23:
        reinterpret_cast<const hknpReservedEvent1 &>(command).FUN_00040be0(world, stream);
        break;
    case 24:
        reinterpret_cast<const hknpReservedEvent2 &>(command).FUN_00040be0(world, stream);
        break;
    case 25:
        reinterpret_cast<const hknpReservedEvent3 &>(command).FUN_00040be0(world, stream);
        break;
    }
}
