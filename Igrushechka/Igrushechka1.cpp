#include "TXLib.h"

void MoveSharik  ();
void DrawSharik (double x, double y, double r, COLORREF ConturSharik, COLORREF ColorSharik);
void Physics1    (double* x, double* y, double* vx, double* vy, double dt, double r);
void Physics2   (double* x, double* y, double* vx, double* vy, double dt, double r);
double Distance (double x1, double y1, double x2, double y2);

int main()
{
    txCreateWindow (600, 600);
    MoveSharik ();
    return 0;
}

void MoveSharik()
{
    double x1  = random (1, 599), y1  = random (1, 599), r1 = 10;
    double x2  = random (1, 599), y2  = random (1, 599), r2 = 20;
    double vx  = 5,   vy  = 7;

    double dt = 4, n = 30;

    txBegin ();

    while (!txGetAsyncKeyState (VK_SPACE))
    {
        txSetFillColor (TX_LIGHTGREEN);
        txClear ();

        DrawSharik (x1, y1, r1, TX_LIGHTMAGENTA, TX_PINK);
        Physics1 (&x1, &y1, &vx, &vy, dt, r1);

        DrawSharik (x2, y2, r2, TX_GREY, TX_CYAN);
        Physics2 (&x2, &y2, &vx, &vy, dt, r2);

        double dist12 = Distance (x1, y1, x2, y2);
        if (dist12 <= r1 + r2)
        {
            printf ("���������� ����� ��������: %0.2f\n", dist12);
            printf ("����� ��������: %0.2f", r1 + r2);
            break;

        }

        txSleep (n);
    }
    txEnd ();
}

void DrawSharik (double x, double y, double r, COLORREF ConturSharik, COLORREF ColorSharik)
{
    txSetColor     (ConturSharik, 2);
    txSetFillColor (ColorSharik);

    txCircle (x, y, r);
}

void Physics1 (double* x, double* y, double* vx, double* vy, double dt, double r)
{
    if (txGetAsyncKeyState (VK_LEFT))  (*x) -= 25;
    if (txGetAsyncKeyState (VK_RIGHT)) (*x) += 15;
    if (txGetAsyncKeyState (VK_DOWN))  (*y) += 25;
    if (txGetAsyncKeyState (VK_UP))    (*y) -= 15;

    if (*x > 600) { *vx = - *vx; *x = 600; }
    if (*x <   0) { *vx = - *vx; *x =   0; }
    if (*y > 600) { *vy = - *vy; *y = 600; }
    if (*y <   0) { *vy = - *vy; *y =   0; }

}

void Physics2 (double* x, double* y, double* vx, double* vy, double dt, double r)
{
    *x += *vx * dt;
    *y += *vy * dt;

    if (*x + r > 600 && *vx > 0) { *vx = - *vx; *x = 600 - r; }
    if (*x - r <   0 && *vx < 0) { *vx = - *vx; *x =   0 + r; }
    if (*y + r > 600 && *vy > 0) { *vy = - *vy; *y = 600 - r; }
    if (*y - r <   0 && *vy < 0) { *vy = - *vy; *y =   0 + r; }
}

double Distance (double x1, double y1, double x2, double y2)
{
    double dist = sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return dist;
}
