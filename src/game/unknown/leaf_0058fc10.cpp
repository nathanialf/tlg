/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_log.h"
#include "tlg_game_name.h"

/* derived names: the larger and the smaller of two values (`cmovge`,
 * `cmovle`; `vmaxss`, `vminss` with the bound as the memory operand) */
template <class T> static inline T maximum(T a, T b)
{
    return a >= b ? a : b;
}

template <class T> static inline T minimum(T a, T b)
{
    return a <= b ? a : b;
}

/* derived names: the handler of node kind 32 in the table at +0x44a0 of
 * FUN_00525530's object: the FlowAccumulator (the name its messages give
 * it) its argument refers to is made the current node and its record (the
 * one FUN_0058f910 has the device fill) and state byte found; the owner's
 * value, read by its type, is added to the record's value of the node's
 * kind (a record seen the first time takes the node's default first, when
 * the node has one, and its state becomes 1; a state past 1 adds nothing),
 * the sum clamped to the node's minimum and maximum when it has them, a
 * message written when the node asks for one, and each child of the node
 * dispatches the node it holds at +0x38 with the sum as the owner's value.
 * Returns 0. Handler unknown. */
// NONMATCHING: 1,256 bytes against 1,304. The value type's tests are the base's (0, 7, 4: case 4
// written first, its block the switch's next one, SelectionDAGBuilder.cpp:7938-7948 swaps it to
// the end; round 589E). Then the state's tests: the base tests 0 first, then 1 (0x58fd49,
// 0x58fd6c), this build 1 first (the two ifs made one switch whose case 0 block follows it);
// and the node held in r13 where the build uses r12.
int FUN_0058fc10(ValueOwner583950 *self, NamedNode583950 *arg) /* derived name */
{
    ParentNode583950Kind32 *node = static_cast<ParentNode583950Kind32 *>(arg->target);
    Record583950Kind32 *record = self->cursor.select(node)
                                     ? reinterpret_cast<Record583950Kind32 *>(self->cursor.value())
                                     : 0;
    u8 *state = self->selectState(node);

    int inInt = 0;
    float inFloat = 0.0f;
    float inX = 0.0f;
    float inY = 0.0f;
    float inZ = 0.0f;
    switch (self->valueType) {
    case 4:
        inFloat = self->floatValue;
        break;
    case 0:
        inInt = self->intValue;
        break;
    case 7:
        inX = self->vector.x;
        inY = self->vector.y;
        inZ = self->vector.z;
        break;
    }

    u8 accumulated = *state;
    if (accumulated == 0) {
        if (node->flags & 1) {
            switch (node->kind) {
            case 0:
                record->floatValue = node->floatDefault;
                break;
            case 1:
                record->intValue = node->intDefault;
                break;
            case 2:
                record->vector = node->vectorDefault;
                break;
            }
        }
        *state = accumulated = 1;
    }
    if (accumulated == 1) {
        switch (node->kind) {
        case 0:
            record->floatValue += inFloat;
            break;
        case 1:
            record->intValue += inInt;
            break;
        case 2:
            record->vector.x += inX;
            record->vector.y += inY;
            record->vector.z += inZ;
            break;
        }
        if (node->flags & 2) {
            switch (node->kind) {
            case 0:
                record->floatValue = maximum(record->floatValue, node->floatMinimum);
                break;
            case 1:
                record->intValue = maximum(record->intValue, node->intMinimum);
                break;
            case 2:
                record->vector.x = maximum(record->vector.x, node->vectorMinimum.x);
                record->vector.y = maximum(record->vector.y, node->vectorMinimum.y);
                record->vector.z = maximum(record->vector.z, node->vectorMinimum.z);
                break;
            }
        }
        if (node->flags & 4) {
            switch (node->kind) {
            case 0:
                record->floatValue = minimum(record->floatValue, node->floatMaximum);
                break;
            case 1:
                record->intValue = minimum(record->intValue, node->intMaximum);
                break;
            case 2:
                record->vector.x = minimum(record->vector.x, node->vectorMaximum.x);
                record->vector.y = minimum(record->vector.y, node->vectorMaximum.y);
                record->vector.z = minimum(record->vector.z, node->vectorMaximum.z);
                break;
            }
        }
    }
    if (node->debugFlags & 1) {
        const char *name = D_17ac870[node->name.index].string0;
        switch (node->kind) {
        case 0:
            FUN_00c831d0(0, "FlowAccumulator(%s) : (in_value => accF) : %f => %f\n", name, inFloat,
                         record->floatValue);
            break;
        case 1:
            FUN_00c831d0(0, "FlowAccumulator(%s) : (in_value => accI) : %d => %d\n", name, inInt,
                         record->intValue);
            break;
        case 2:
            record->vector.x = minimum(record->vector.x, node->vectorMaximum.x);
            record->vector.y = minimum(record->vector.y, node->vectorMaximum.y);
            record->vector.z = minimum(record->vector.z, node->vectorMaximum.z);
            FUN_00c831d0(0, "FlowAccumulator(%s) : (in_value => accV) : ", name);
            break;
        }
    }

    Node583950 **end = node->children + node->count;
    switch (node->kind) {
    case 0:
        for (Node583950 **child = node->children; child != end; ++child) {
            self->valueType = 4;
            self->floatValue = record->floatValue;
            self->dispatch((*child)->child38);
        }
        break;
    case 1:
        for (Node583950 **child = node->children; child != end; ++child) {
            self->valueType = 0;
            self->intValue = record->intValue;
            self->dispatch((*child)->child38);
        }
        break;
    case 2:
        for (Node583950 **child = node->children; child != end; ++child) {
            self->valueType = 7;
            self->vector = record->vector;
            self->dispatch((*child)->child38);
        }
        break;
    }
    return 0;
}
