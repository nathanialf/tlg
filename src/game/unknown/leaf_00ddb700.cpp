/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: whether the call at a depth runs a script function (tag 9) */
inline bool isScriptCall(lua_State *s, int level)
{
    return ((*frameBaseSlot(s, level))[-1].type & 0xf) == 9;
}

/* derived name: the next instruction of the call at a depth: null unless
 * it runs a script function, the instruction before it for a call below
 * the running one (unless that is the function's first) */
inline const u32 *callPc(lua_State *s, int level)
{
    if (!isScriptCall(s, level))
        return 0;
    if (s->unknown40 == level)
        return s->unknown38;
    if (level == callDepth(s))
        return s->pc;
    const HksCallInfo *next = &s->callInfos[level + 1];
    const u32 *pc = next->savedPc;
    if (pc && pc != static_cast<HksClosure *>(next->base[-1].value.pointer)->proto->code)
        --pc;
    return pc;
}

/* derived name: Lua's luaF_getlocalname: the name of the n-th local
 * variable live at an instruction */
inline const char *localName(const HksProto *proto, int n, int pcIndex)
{
    const HksDebugInfo *debugInfo = proto->debugInfo;
    if (!debugInfo)
        return 0;
    const int count = debugInfo->localVariableCount;
    if (count < n)
        return 0;
    for (int i = 0; i < count && n > 0; ++i) {
        const HksLocalVariable *variable = &debugInfo->localVariables[i];
        if (variable->startPc <= pcIndex && variable->endPc >= pcIndex)
            --n;
        if (n == 0)
            return variable->name->data;
    }
    return 0;
}

/* derived name: Lua's findlocal: the name of the n-th local variable of the
 * call ar describes, "(*temporary)" for a slot of its frame with no
 * variable's name, else null */
// NONMATCHING: the base tests the call level's sign (64-bit, after its load) before n; the build tests n
// first, and holds one more callee-saved register
const char *FUN_00ddb700(lua_State *s, const lua_Debug *ar, int n)
{
    if (ar->unknown244)
        return 0;
    const int level = ar->i_ci;
    if (level < 0)
        return 0;
    if (n <= 0)
        return 0;
    if (level > callDepth(s))
        return 0;
    if (isScriptCall(s, level)) {
        const HksProto *proto =
            static_cast<HksClosure *>((*frameBaseSlot(s, level))[-1].value.pointer)->proto;
        const u32 *pc = callPc(s, level);
        if (pc) {
            const char *name = localName(proto, n, pc - proto->code);
            if (name)
                return name;
        }
    }
    HksObject *limit;
    if (level == callDepth(s))
        limit = s->top;
    else
        limit = (level + 1 == callDepth(s) ? s->base : s->callInfos[level + 2].base) -
                s->callInfos[level].unknown12 - 1;
    return *frameBaseSlot(s, level) + (n - 1) < limit ? "(*temporary)" : 0;
}
