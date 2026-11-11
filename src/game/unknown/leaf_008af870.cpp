/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af5f0 (stored by FUN_008af7a0 FUN_008af7e0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008af870 /* derived name */
{
  public:
    virtual Object008af870 *FUN_008af7a0(void *where); /* derived name */
    virtual Object008af870 *FUN_008af7e0(void *where); /* derived name */
    virtual void FUN_008af820(void *argument);         /* derived name */
    virtual const void *FUN_008af830();                /* derived name */
    virtual void FUN_008af840(bool deallocate);        /* derived name */
    virtual ~Object008af870();
    virtual void *FUN_008af890(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008af870::FUN_008af840(bool deallocate)
{
    this->~Object008af870();
    if (deallocate)
        operator delete(this);
}

Object008af870::~Object008af870() {}

void *Object008af870::FUN_008af890()
{
    return &stored;
}
