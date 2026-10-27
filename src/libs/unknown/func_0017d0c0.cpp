/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpCallbackConstraintMotor::hkpCallbackConstraintMotor(CallbackType callbackType,
                                                       CalcMotorDataCallbackFunc callbackFunc)
{
    this->callbackType = callbackType;
    type = TYPE_CALLBACK;
    minForce = -1000000.0f;
    maxForce = 1000000.0f;
    this->callbackFunc = callbackFunc;
}
