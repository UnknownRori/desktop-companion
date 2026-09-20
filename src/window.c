#if defined(_WIN32)

#define WIN32_MEAN_AND_LEAN
#define NOGDI

#include <windows.h>

extern void* GetWindowHandle(void);

void force_ontop(void)
{
    HWND hwnd = (HWND)GetWindowHandle();

    SetWindowPos(
        hwnd, 
        HWND_TOPMOST, 
        0, 0,
        0, 0, 
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE
    );
}
#else
void force_ontop(void) {}
#endif
