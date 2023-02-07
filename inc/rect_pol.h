#ifndef RECT_POL
#define RECT_POL

typedef struct complex_struct {
	double a;
	double b;
	double t;
} complex_struct;

double rect_real_part(const complex_struct z);
double rect_img_part(const complex_struct z);
double rect_magnitude(const complex_struct z);
double rect_angle(const complex_struct z);
double pol_real_part(const complex_struct z);
double	pol_img_part(const complex_struct z);
double pol_magnitude(const complex_struct z);
double pol_angle(const complex_struct z);

double (*real_part_tb1[])(const complex_struct) = {rect_real_part, pol_real_part};
double (*img_part_tb1[])(const complex_struct) = {rect_img_part, pol_img_part};
double (*magnitude_tb1[])(const complex_struct) = {rect_magnitude, pol_img_part};
double (*angle_tb1[])(const complex_struct) = {rect_angle, pol_magnitude};

#define real_part(z) real_part_tb1[z.t](z)
#define img_part(z) img_part_tb1[z.t](z)
#define magnitude(z) magnitude_tb1[z.t](z)
#define angle(z) angle_tb1[z.t](z)




#endif
