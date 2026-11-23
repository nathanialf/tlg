/* src/include/tlg_game_object0130acb0.h: the class over JsUnknown whose
 * complete destructor is 0x130acb0 (its row _ZN14Object0130acb0D1Ev, D15;
 * JsUnknown.cpp, config/homes.base.txt). Its vtable is the row
 * _ZTV14Object0130acb0 (0x16c3990, config/vtables.derived.base.txt): the
 * destructor stores it, then JsUnknown's with ~JsUnknown's report inlined.
 * The destructors over it run it as a tail call. Every name here is
 * derived. The classes over it start their members at +0x30. */
#ifndef TLG_GAME_OBJECT0130ACB0_H
#define TLG_GAME_OBJECT0130ACB0_H

#include "tlg_types.h"

#include "tlg_game_jsunknown.h"
#include "tlg_game_object05adaaa8.h"

class Object0130acb0 : public JsUnknown /* derived name */
{
  public:
    /* derived name: the constructor every Create* inlines (0x131f450): no
     * private data, +0x28 and +0x2c 0 and -1, the device's count at +0x10090
     * taken up, relaxed: where the new object is not captured (CreateBlob,
     * 0xb98790) the dead store pass removes this vptr store across it */
    explicit Object0130acb0(u32 kind) : JsUnknown(kind)
    {
        privateData20 = nullptr;
        delay = 0;
        unknown2c = -1;
        __atomic_fetch_add(&D_5adaaa8->unknown10090, 1, __ATOMIC_RELAXED);
    }

    /* leaf_0130acb0.cpp: the private data handed back, then JsUnknown's */
    virtual ~Object0130acb0();
    /* slot 2 (0x130af40, leaf_0130acb0.cpp): under the device's mutex, an
     * object with no reference left is given its delay and handed to the
     * device's list of objects deleted later */
    virtual void Destroy();

  private:
    /* +0x20: the object's chain of the device's private data, linked
     * through their next pointers */
    PrivateData01306250 *privateData20;

  public:
    /* +0x28: the frames the device waits before the object is deleted
     * (AddDelayDeleteObject) */
    u32 delay; /* derived name */
    /* +0x2c: the device context's stamp at +0x47ac, written into a buffer
     * by its slot 16 (0x1319760) */
    u32 unknown2c;
};

/* The delay is the frames left of three since the object's stamp, 0 for an
 * object never stamped (the stamp -1 is ahead of every frame), within 0 to
 * 3. */
inline void JsDevice::AddDelayDeleteObject(Object0130acb0 *object)
{
    s64 elapsed = frame - object->unknown2c;
    s64 left = elapsed > 0 ? 3 - elapsed : 0;
    object->delay = left < 0 ? 0 : left > 3 ? 3 : left;
    ANZU_ASSERT(JS_DEVICE_H, 294, m_deleteObjectCount < JsDevice::kDeleteObjectMax);
    for (u32 i = 0; i < m_deleteObjectCount; i++) {
        if (m_deleteObjects[i] == object)
            return;
    }
    m_deleteObjects[m_deleteObjectCount++] = object;
}

#endif
