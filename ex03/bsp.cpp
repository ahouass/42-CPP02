#include "Point.hpp"

float	ft_abs(float f)
{
	if (f < 0)
		return (-f);
	return (f);
}

//Area = 1/2 ​* ∣x1​(y2​−y3​) + x2​(y3​−y1​) + x3​(y1​−y2​)∣
float area(const Point& a, const Point& b, const Point& c) {
    return ft_abs(((a.getX() * (b.getY() - c.getY())) +
                    (b.getX() * (c.getY() - a.getY())) +
                    (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float total_area = area(a, b, c);
    float area1 = area(point, b, c);
    float area2 = area(a, point, c);
    float area3 = area(a, b, point);

    if (area1 <= 0 || area2 <= 0 || area3 <= 0)
        return false;

    return (total_area == area1 + area2 + area3);
}
