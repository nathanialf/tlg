/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c2b50 (stored by FUN_01270b70 FUN_01270bb0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01270c40 /* derived name */
{
  public:
    virtual Object01270c40 *FUN_01270b70(void *where); /* derived name */
    virtual Object01270c40 *FUN_01270bb0(void *where); /* derived name */
    virtual void FUN_01270bf0(void *argument);         /* derived name */
    virtual const void *FUN_01270c00();                /* derived name */
    virtual void FUN_01270c10(bool deallocate);        /* derived name */
    virtual ~Object01270c40();
    virtual void *FUN_01270c60(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object01270c40::FUN_01270c10(bool deallocate)
{
    this->~Object01270c40();
    if (deallocate)
        operator delete(this);
}

Object01270c40::~Object01270c40() {}

void *Object01270c40::FUN_01270c60()
{
    return &stored;
}
