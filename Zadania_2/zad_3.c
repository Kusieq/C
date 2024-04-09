#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point;

typedef struct{
    Point a;
    Point b;
}Rectangle;

void ZmianaPunktu(Point *p)
{
    p -> x = 10;
    p -> y = 5;
}
void SprawdzenieWartosci(int *x)
{
    if(x < 0)
    {
        *x = *x * -1;
    }
}
void PoleObwod(Rectangle r)
{
    int pole = (r.a.x - r.b.x) * (r.a.y - r.b.y);
    SprawdzenieWartosci(&pole);

    int obw = ((r.a.x - r.b.x) * 2) + ((r.a.y - r.b.y)*2);
    SprawdzenieWartosci(&obw);

    printf("\n\nPole wynosi: %d\nObwod wynosi: %d",pole,obw);
}
int main()
{
    Point p1;
    p1.x = 4;
    p1.y = 2;
    printf("Przed zmiana: \nx - %d\ny - %d",p1.x, p1.y);
    ZmianaPunktu(&p1);
    printf("\nPo zmianie: \nx - %d\ny - %d",p1.x, p1.y);
    Point p2;
    p2.x = 2;
    p2.y = 3;

    Rectangle r;
    r.a = p1;
    r.b = p2;

    PoleObwod(r);

    return 0;
}
