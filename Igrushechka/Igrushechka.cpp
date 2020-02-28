#include "TXLib.h"

void MoveSharik ();
void DrawSharik (double  x, double  y, double  r);
void Physics    (double* x, double* y, double* vx, double* vy, double dt);

int main()
{
    txCreateWindow (600, 600);
    txSetFillColor (TX_YELLOW);
    txClear ();

    MoveSharik ();
}

void MoveSharik()
{
    double x  = 100, y  = 100, r = 20;
    double vx = 5,   vy = 7;

    txSetColor     (TX_GREEN, 1);
    txSetFillColor (TX_YELLOW);

    double dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
    {
        DrawSharik (x, y, r);

        Physics (&x, &y, &vx, &vy, dt);
    }
}

void DrawSharik (double x, double y, double r)
{
    txCircle (x, y, r);
}

void Physics (double* x, double* y, double* vx, double* vy, double dt)
{
        *x += *vx * dt;
        *y += *vy * dt;

        if (*x > 600) { *vx = - *vx; *x = 600; }
        if (*x <   0) { *vx = - *vx; *x =   0; }
        if (*y > 600) { *vy = - *vy; *y = 600; }
        if (*y <   0) { *vy = - *vy; *y =   0; }
}
