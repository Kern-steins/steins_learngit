#include <stdio.h>
#include <math.h>
#include "../inc/rect_pol.h"



int main(int argc, char const *argv[])
{
		
	return 0;
}

double rect_real_part(const complex_struct z)
{
	return z.a;
}

double rect_img_part(const complex_struct z)
{
	return z.b;
}

double rect_magnitude(const complex_struct z)
{
	return sqrt(z.a * z.a + 
				z.b * z.b);
}

double rect_angle(const complex_struct z)
{
	double PI = acos(-1.0);
	if(z.a > 0)
		return atan(z.b / z.a);
	else
		return atan(z.b / z.a) + PI;
}

double pol_real_part(const complex_struct z)
{
	return z.a * cos(z.b);
}

double	pol_img_part(const complex_struct z)
{
	return z.a * sin(z.b);
}

double pol_magnitude(const complex_struct z)
{
	return z.a;
}

double pol_angle(const complex_struct z)
{
	return z.b;
}




