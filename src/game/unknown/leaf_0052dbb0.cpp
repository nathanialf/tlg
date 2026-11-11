/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16ab3a8 (stored by FUN_0052c710 FUN_0052d4f0 FUN_0052db10): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object0052dbb0 /* derived name */
{
  public:
    virtual Object0052dbb0 *FUN_0052d4f0(void *where); /* derived name */
    virtual Object0052dbb0 *FUN_0052db10(void *where); /* derived name */
    virtual void FUN_0052db50(void *argument);         /* derived name */
    virtual const void *FUN_0052db70();                /* derived name */
    virtual void FUN_0052db80(bool deallocate);        /* derived name */
    virtual ~Object0052dbb0();
    virtual void *FUN_0052dbd0(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object0052dbb0::FUN_0052db80(bool deallocate)
{
    this->~Object0052dbb0();
    if (deallocate)
        operator delete(this);
}

Object0052dbb0::~Object0052dbb0() {}

void *Object0052dbb0::FUN_0052dbd0()
{
    return &stored;
}
