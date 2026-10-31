/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The engine's speed is the transmission's, raised by the clutch's slip
 * under the accelerator below the minimum; its torque and resistance come
 * from the curves on each side of the optimal speed, none past the
 * maximum, the resistance scaled down while the transmission turns below
 * the minimum. */
void hknpVehicleDefaultEngine::calcEngineInfo(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleFilteredDriverInput &filteredInfoOutput,
    const hknpVehicleTransmissionOutput &transmissionOut, EngineOutput &engineOutput)
{
    engineOutput.rpm = transmissionOut.transmissionRPM;
    const float acceleratorPedalInput = filteredInfoOutput.acceleratorPedalInput;
    if (engineOutput.rpm < minRPM) {
        const float clutchRPM = acceleratorPedalInput * clutchSlipRPM;
        const float halfMinRPM = minRPM * 0.5f;
        if (engineOutput.rpm < halfMinRPM) {
            engineOutput.rpm = minRPM + clutchRPM;
        } else {
            engineOutput.rpm = minRPM + (engineOutput.rpm - halfMinRPM) * clutchRPM / halfMinRPM;
        }
    }

    float torque;
    float resistance;
    const float deltaRPM = engineOutput.rpm - optRPM;
    if (deltaRPM < 0.0f) {
        const float r = 1.0f / (minRPM - optRPM);
        resistance =
            maxTorque * (resistanceFactorAtOptRPM +
                         deltaRPM * (r * (resistanceFactorAtMinRPM - resistanceFactorAtOptRPM)));
        torque = maxTorque * (deltaRPM * deltaRPM * (r * r * (torqueFactorAtMinRPM - 1.0f)) + 1.0f);
        if (transmissionOut.transmissionRPM < minRPM) {
            resistance *= transmissionOut.transmissionRPM / minRPM;
        }
    } else if (engineOutput.rpm < maxRPM) {
        const float r = 1.0f / (maxRPM - optRPM);
        resistance =
            maxTorque * (resistanceFactorAtOptRPM +
                         deltaRPM * (r * (resistanceFactorAtMaxRPM - resistanceFactorAtOptRPM)));
        torque = maxTorque * (deltaRPM * deltaRPM * (r * r * (torqueFactorAtMaxRPM - 1.0f)) + 1.0f);
    } else {
        engineOutput.rpm = maxRPM;
        resistance = resistanceFactorAtMaxRPM * maxTorque;
        torque = 0.0f;
    }
    engineOutput.torque = acceleratorPedalInput * torque - resistance;
}
