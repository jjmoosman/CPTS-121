#ifndef EQUATIONS_H
#define EQUATIONS_H


#define _CRT_SECURE_NO_WARNINGS
#define PI 3.1415
#include <stdio.h>

#include <math.h>
// used at the start to collect the data for R1, R2, and R3
int get_resistance(int resist);
// sresistance is the series resistance funtion being called and used
int get_sresistance(int R1, int R2, int R3);
// calls for the user to enter a item cost to then calcualate the tax on the item in question
double calc_total_tax(double sales_tax_rate, double item_cost);
//User inputs three values for the length, width, and height for the function to then find the area of the pyramid.
double get_pyramid(double l, double w, double h);
// this function calls apon the inputs previously used for the series resistance and inverts it
double calc_presistance(int R1, int R2, int R3);
// this calls for the user to enter a character and shift intiger for a ASCII table equation using both characters and shift values
char get_char(char plain1, int shift_int);
// This calculates the distance between two points created by the user
double calc_distance(double x1, double x2, double y1, double y2);
// This is a general equation in which the user inputs 4 values with a being an int while the rest are float/double values.
double calc_gen_equation(int a, double x, double y, double z);


#endif EQUATIONS_H