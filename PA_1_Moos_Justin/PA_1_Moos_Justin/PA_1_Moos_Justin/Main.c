
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.1415
#include <stdio.h>
#include <math.h>

int main()
{
	//		Part one of the assignment

	int series_resistance= 0, R1 = 0, R2 = 0, R3 = 0;

	printf("Please input 3 intigers:  ");

	scanf("%d%d%d", &R1, &R2, &R3); //grouping all three scans together

	series_resistance = R1 + R2 + R3;

	printf("Total Series Resistance R1 + R2 + R3:  %d\n", series_resistance);

	//		Part two of the assignment

	double item_cost = 0.0, item_tax = 0.0;

	printf("Please input the item cost:  ");

	scanf("%lf", &item_cost);

	item_tax = item_cost * 0.08;

	printf("Total Sales tax for item:  %.2lf", item_tax);

	//		Part three of the assignment

	double rectangular_pyramid = 0.0, l = 0.0, w = 0.0, h = 0.0;

	printf("\n please input the Length, Width, and Height for the Pyramid: ");

	scanf("%lf%lf%lf", &l, &w, &h);

	rectangular_pyramid = (l * w * h) / 3;

	printf("Total Volume for the pyramid:  %.2lf \n", rectangular_pyramid);

	//		Part four of the assignment

	double total_parallel_resist = 0.0;

	total_parallel_resist = 1 / ((double)1 / (double)R1 + 1 / (double)R2 + 1 / (double)R3); //doubles change the int functions to floats for the parallel resist float function

	printf("Total Parallel resistence for R1, R2, R3:  %.2lf", total_parallel_resist);

	//		Part five of the assignment
	
	char plain1 = '\0';

	printf("\nPlease enter a character:  ");

	scanf(" %c", &plain1); //literally had this as "%c" and the whole program failed at the end  added a space before %c and now the code all works im so done

	int shift_int = 0;

	printf("Please enter a shift value:  ");

	scanf("%d", &shift_int);

	char encoded_character = (plain1 - 'a') + 'A' - shift_int;

	printf("Char Result:  %c", encoded_character);




	
	//		Part six of the assignment

	double distance = 0.0, x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;

	printf("\nPlease input the first cordinate point:  ");
	scanf("%lf%lf", &x1, &y1);

	printf("Please input the second cordinate point:  ");
	scanf("%lf%lf", &x2, &y2);

	distance = sqrt((pow(x1 - x2, 2) + pow(y1 - y2, 2)));
	printf("Distance between points: %.2lf", distance);

	//		Part seven of the assignment
	
	double x = 0.0, y = 0.0, z = 0.0;
	int a = 0;

	printf("\n Please enter x, y, z, and a for a general equation:  ");
	scanf("%lf %lf %lf %d",  &x, &y, &z, &a);
	y = y / ((double)3 / 17) - z + x / (a % 2) + PI;
	printf("The general equation answer: %.2lf", y);
	

	return 0;
}