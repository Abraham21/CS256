/*
 * File: geometry.c
 *
 * Author: Abraham Yepremian
 *
 * Description: Homework 3 for CS 256
 * Chapter 4 Problem 23 Geometry Calculator
 *
 * Last edited: 4/19/2018
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//define PI constant
#define PI 3.14159265


int main(){
	//print menu
	printf("Chapter 4 Problem #23 Geometry Calculator\n");
	printf("1. Calculate the Area of a Circle\n");
	printf("2. Calculate the Area of a Rectangle\n");
	printf("3. Calculate the Area of a Triangle\n");
	printf("4. Quit\n");
	printf("Input selection (1-4):\n");

	//get user selection
	int selection;
	scanf("%d", &selection);

	//logic for each menu option
	if(selection == 1){
		printf("Enter the radius of the circle:\n");
		double radius;
		scanf("%le",&radius);
		if(radius<0){
			printf("Error: Invalid input.\n");
		}
		else{
			printf("The area of the circle is: %.2f\n",pow(radius,2)*PI);
		}
	}
	else if(selection == 2){
		printf("Enter the length and width of the rectangle:\n");
		double length;
		double width;
		scanf("%le%lf",&length,&width);

		if(length<0 || width<0){
					printf("Error: Invalid input.\n");
		}
		else{
		printf("The area of the rectangle is: %.2f\n", length*width);
		}
	}
	else if(selection == 3){
		printf("Enter the base and height of the triangle:\n");
		double base;
		double height;
		scanf("%le%lf",&base,&height);

		if(base<0 || height<0){
					printf("Error: Invalid input.\n");
		}
		else{
		printf("The area of the triangle is: %.2f\n", 0.5*base*height);
		}
	}
	else if(selection == 4){
		exit(0);
	}
	else{
		printf("Error: Invalid input.\n");
	}

	return 0;

}

