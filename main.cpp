#include <stdio.h>

short n, x, y;

struct Point
{
    short x;
    short y;
};

Point points[50];

char GetCrossProduct(const Point& p1, const Point& p2, const Point& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - 
           (p2.y - p1.y) * (p3.x - p1.x);
}

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (short i = 0; i < n; ++i)
        {
            Point& point = points[i];
            scanf("%hd %hd", &point.x, &point.y);
        }

        bool convex = true;
        char previousProduct = 0;

        for (short i = 0; i < n; ++i)
        {
            const Point& p1 = points[i];
            const Point& p2 = points[(i + 1) % n];
            const Point& p3 = points[(i + 2) % n];

            const char product = GetCrossProduct(p1, p2, p3);

            if (i == 0) // primeira passada
            {
                previousProduct = product;
                continue;
            }

            //Muda de direção?
            if (previousProduct >= 0 && product < 0 || previousProduct < 0 && product > 0)
            {
                convex = false;
                break;
            }
        }

        if (convex)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}