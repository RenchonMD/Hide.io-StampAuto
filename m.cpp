bool StampAuto = false;

void (*Emotion)(void *instance, int i);
void (*old_Stamp)(void *instance);
void Stamp(void *instance) {
    if (instance != NULL) {
       if (StampAuto) {
            Emotion(instance, true);
       }
    }
    old_Stamp(instance);
}

HOOK_LIB("libil2cpp.so", "Offset", Stamp, old_Stamp);   
Emotion = (void(*)(void *,int))getAbsoluteAddress("libil2cpp.so", Offset);
