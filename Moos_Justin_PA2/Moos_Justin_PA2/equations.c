#include "equations.h"


// this first equation is collecting R1, R2, and R3 points for me to use in the next
// part of this with the series resistance task.
int get_resistance(int resist)
{
	int resistance = 0;

	scanf("%d", &resistance);

	return resistance;

}
/* This sresistance(Series Resistance) is taking all of the ints entered before
	and adding them all together to create the total series resistance			*/
int get_sresistance(int R1, int R2, int R3) 
{

	int seriesResistance = 0;
	seriesResistance = R1 + R2 + R3;

	return seriesResistance;
}
/* The code here is taking a user created input being the cost of an item
and then finding the sales tax for it using the 0.08 which is the tax rate and then
returning the overall tax for the item in question*/
double calc_total_tax(double sales_tax_rate, double item_cost)
{
	printf("Please input the item cost:  ");

	scanf("%lf", &item_cost);

	sales_tax_rate = item_cost * 0.08;

	return sales_tax_rate;
}
/*
	This function is having the user input a length, height, and width to a pyramid
	once they have done so it then calculates the overall area for the pyramid and
	returns the estimated area to the user
*/
double get_pyramid(double l, double w, double h)
{
	double rectangular_pyramid = 0.0;

	printf("\n please input the Length, Width, and Height for the Pyramid: ");

	scanf("%lf%lf%lf", &l, &w, &h);

	rectangular_pyramid = (l * w * h) / 3;

	return rectangular_pyramid;
}
/*
	The Parallel resistance here is calling on those original three intigers from
	the first equation to then come up with an inverted version and because it is a
	double as it turns into a decimal we add double statements in to turn the ints
	R1, R2, and R3 into floating/double floating values so we can get the most
	accurate parallel resistance for the three resistance numbers.
*/
double calc_presistance(int R1, int R2, int R3) {

	double parallelResistance = 0;

	parallelResistance = 1 / (((double)1 / R1) + ((double)1 / R2) + ((double)1 / R3));

	return parallelResistance;
}
/*
	The char function here is using char values and a shift int to return an encoded
	character value to the user using the ascii table as a reference can really help when checking
	the program for any issues or errors in the end result returned to the user.
*/

char get_char(char plain1, int shift_int)
{

	printf("\nPlease enter a character:  ");

	scanf(" %c", &plain1); //literally had this as "%c" and the whole program failed at the end  added a space before %c and now the code all works im so done

	printf("Please enter a shift value:  ");

	scanf("%d", &shift_int);

	char encoded_character = (plain1 - 'a') + 'A' - shift_int;

	return encoded_character;
}
/*
	Here I am having the user input four values. two are x values and two are y and when inputing the code they start
	with x1, y1 then x2, y2.
*/
double calc_distance(double x1, double x2, double y1, double y2)
{
	double distance = 0.0;
	printf("\nPlease input the first cordinate point:  ");
	scanf("%lf%lf", &x1, &y1);

	printf("Please input the second cordinate point:  ");
	scanf("%lf%lf", &x2, &y2);
	/*
	After the inputs the values are all taken into the distance equation and then returned to the user to show the overall distance
	between the two values on a plane entered by a user.
	*/
	distance = sqrt((pow(x1 - x2, 2) + pow(y1 - y2, 2)));
	return distance;

}
/*
	for this general equation I have the user enter all four of the values of a, x, y, and z.
	After plugging in the values are then used in the general equation below to return an output to the user.
*/
double calc_gen_equation(int a, double x, double y, double z)
{


	printf("\n Please enter x, y, z, and a for a general equation:  ");
	scanf("%lf %lf %lf %d", &x, &y, &z, &a);
	y = y / ((double)3 / 17) - z + x / (a % 2) + PI;



	return y;
}