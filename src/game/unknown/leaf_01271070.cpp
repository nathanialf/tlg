/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c2c90 (stored by FUN_01270fa0 FUN_01270fe0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01271070 /* derived name */
{
  public:
    virtual Object01271070 *FUN_01270fa0(void *where); /* derived name */
    virtual Object01271070 *FUN_01270fe0(void *where); /* derived name */
    virtual void FUN_01271020(void *argument);         /* derived name */
    virtual const void *FUN_01271030();                /* derived name */
    virtual void FUN_01271040(bool deallocate);        /* derived name */
    virtual ~Object01271070();
    virtual void *FUN_01271090(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object01271070::FUN_01271040(bool deallocate)
{
    this->~Object01271070();
    if (deallocate)
        operator delete(this);
}

Object01271070::~Object01271070() {}

void *Object01271070::FUN_01271090()
{
    return &stored;
}
