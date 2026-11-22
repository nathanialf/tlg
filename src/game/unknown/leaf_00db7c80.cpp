/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hks_obj_setfenv (the name from its assertion message): the environment
 * of a userdata, a thread (its globals), a script function or a C function
 * set to a table, the collector's barrier passed for the object; 0 for any
 * other value; the call timed */
int FUN_00db7c80(lua_State *s, const HksObject *object, const HksObject *env)
{
    HksApiTimer timer(s);
    if (!((env->type & 0xf) == 5 || (env->type & 0xf) == 12)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xac100170, "hks_obj_istable(env)", "hks_obj_setfenv", "table expected on stack",
               HKS_OBJECT_FILE, 196);
        __builtin_trap();
    }
    int result = 0;
    switch (object->type & 0xf) {
    case 9:
        static_cast<HksClosure *>(object->value.pointer)->environment = env->value.pointer;
        result = 1;
        gcBarrier(s, static_cast<HksGcObject *>(object->value.pointer), env);
        break;
    case 10:
        static_cast<HksCClosure *>(object->value.pointer)->environment = env->value.pointer;
        result = 1;
        gcBarrier(s, static_cast<HksGcObject *>(object->value.pointer), env);
        break;
    case 7: {
        HksUserdata *userdata = static_cast<HksUserdata *>(object->value.pointer);
        userdata->environment = env->value.pointer;
        result = 1;
        gcBarrier(s, reinterpret_cast<HksGcObject *>(userdata), env);
        break;
    }
    case 8:
        static_cast<lua_State *>(object->value.pointer)->globalTable = *env;
        result = 1;
        gcBarrier(s, static_cast<HksGcObject *>(object->value.pointer), env);
        break;
    }
    return result;
}
