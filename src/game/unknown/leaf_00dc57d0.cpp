/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: a string marked for the collector unless it is fixed (its
 * length's top bit set), as gcBarrier tests it */
static inline void markString(HksString *string)
{
    if (static_cast<s64>(string->lengthAndFlags) >= 0)
        reinterpret_cast<HksGcObject *>(string)->flags |= 1;
}

/* FUN_00dc57d0: a script function's code marked for the collector with
 * every string it holds (its debug information's two strings, its local
 * variables' and its upvalues' names, its string constants) and the
 * functions defined in it, recursively; returns the count of the objects
 * it went through, the code itself included. derived name */
int FUN_00dc57d0(HksProto *proto)
{
    reinterpret_cast<HksGcObject *>(proto)->flags |= 1;
    int count = 1;
    if (proto->debugInfo) {
        if (HksString *source = proto->debugInfo->source) {
            markString(source);
            ++count;
        }
        if (HksString *name = proto->debugInfo->name) {
            markString(name);
            ++count;
        }
        for (unsigned i = 0; i < proto->debugInfo->localVariableCount; ++i)
            markString(proto->debugInfo->localVariables[i].name);
        count += proto->debugInfo->localVariableCount;
        for (unsigned i = 0; i < proto->debugInfo->upvalueNameCount; ++i)
            markString(proto->debugInfo->upvalueNames[i]);
        count += proto->debugInfo->upvalueNameCount;
    }
    for (unsigned i = 0; i < proto->constantCount; ++i) {
        const HksObject &constant = proto->constants[i];
        if ((constant.type & 0xf) == 4) {
            markString(static_cast<HksString *>(constant.value.pointer));
            ++count;
        }
    }
    for (unsigned i = 0; i < proto->protoCount; ++i)
        count += FUN_00dc57d0(proto->protos[i]);
    return count;
}
