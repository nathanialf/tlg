/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c0a00 (stored by FUN_01005750 FUN_01005790): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01005820 /* derived name */
{
  public:
    virtual Object01005820 *FUN_01005750(void *where); /* derived name */
    virtual Object01005820 *FUN_01005790(void *where); /* derived name */
    virtual void FUN_010057d0(void *argument);         /* derived name */
    virtual const void *FUN_010057e0();                /* derived name */
    virtual void FUN_010057f0(bool deallocate);        /* derived name */
    virtual ~Object01005820();
    virtual void *FUN_01005840(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object01005820::FUN_010057f0(bool deallocate)
{
    this->~Object01005820();
    if (deallocate)
        operator delete(this);
}

Object01005820::~Object01005820() {}

void *Object01005820::FUN_01005840()
{
    return &stored;
}
