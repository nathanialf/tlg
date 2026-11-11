/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16aabe0 (stored by FUN_00506910 FUN_00506950): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object005069d0 /* derived name */
{
  public:
    virtual Object005069d0 *FUN_00506910(void *where); /* derived name */
    virtual Object005069d0 *FUN_00506950(void *where); /* derived name */
    virtual void FUN_005065e0(void *argument);         /* derived name */
    virtual const void *FUN_00506990();                /* derived name */
    virtual void FUN_005069a0(bool deallocate);        /* derived name */
    virtual ~Object005069d0();
    virtual void *FUN_005069f0(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object005069d0::FUN_005069a0(bool deallocate)
{
    this->~Object005069d0();
    if (deallocate)
        operator delete(this);
}

Object005069d0::~Object005069d0() {}

void *Object005069d0::FUN_005069f0()
{
    return &stored;
}
