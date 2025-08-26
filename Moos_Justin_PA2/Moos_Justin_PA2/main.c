#include "equations.h"


int main()
{
	//		Part one of the assignment

	int series_resistance = 0, R1 = 0, R2 = 0, R3 = 0;
	printf("Please enter the values of 3 resistors <all integers>: ");
	R1 = get_resistance(1);
	R2 = get_resistance(2);
	R3 = get_resistance(3);

	series_resistance = get_sresistance(R1, R2, R3);

	printf("Total Series Resistance R1 + R2 + R3:  %d\n", series_resistance);


	//		Part two of the assignment

	double item_cost = 0.0, sales_tax_rate = 0.0;

	sales_tax_rate = calc_total_tax(sales_tax_rate, item_cost);

	printf("Total Sales tax for item:  %.3lf", sales_tax_rate);

	//		Part three of the assignment



	double rectangular_pyramid = 0.0, l = 0.0, w = 0.0, h = 0.0;

	rectangular_pyramid = get_pyramid(l, w, h);

	printf("Total Volume for the pyramid:  %.3lf \n", rectangular_pyramid);

	//		Part four of the assignment



	double total_parallel_resist = 0.0;

	total_parallel_resist = calc_presistance((int)R1, (int)R2, (int)R3);

	printf("Total Parallel resistence for R1, R2, R3:  %.3lf", total_parallel_resist, R1, R2, R3);

	//		Part five of the assignment



	char plain1 = '\0', encoded_character = '\0';

	int shift_int = 0;

	encoded_character = get_char(plain1, shift_int);

	printf("Char Result:  %c", encoded_character);

	//		Part six of the assignment


	double distance = 0.0, x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;

	distance = calc_distance(x1, x2, y1, y2);

	printf("Distance between points: %.2lf", distance);

	//		Part seven of the assignment



	double x = 0.0, y = 0.0, z = 0.0;
	int a = 0;
	y = calc_gen_equation(a, x, y, z);
	printf("The general equation answer: %.2lf", y);

	return 0;





}