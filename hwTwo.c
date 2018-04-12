/*
 * File: hwTwo.c
 *
 * Author: Abraham Yepremian
 *
 * Description: Homework 2 for CS 256
 * This program is  series of solutions
 * to challenge problems from our textbook.
 *
 * Last edited: 4/12/2018
 *
 */

#include <stdio.h>

int main(){
	printf("CS256 Homework Assignment #2\n");

	//Chapter 2 Challenge Problem #4
	printf("\nChapter 2 Challenge #4: Restaurant Bill\n");
	float mealCharge = 88.67;
	float tax = mealCharge * 0.0675;
	float total = mealCharge + tax;
	float tip = total * 0.2;
	printf("Meal Cost: $%.2f\nTax Amount: $%.2f\nTip Amount: $%.2f\nTotal Bill: $%.2f\n",mealCharge,tax,tip,total);
	//End of Chapter 2 Problem #4

	//Chapter 2 Challenge Problem #7
	printf("\nChapter 2 Challenge #7: Ocean Levels\n");
	float risingRate = 1.5;
	int year = 5;
	printf("The ocean level will rise %.2f millimeters in %d years.\n",year*risingRate, year);
	year += 2;
	printf("The ocean level will rise %.2f millimeters in %d years.\n",year*risingRate, year);
	year += 3;
	printf("The ocean level will rise %.2f millimeters in %d years.\n",year*risingRate, year);
	//End of Chapter 2 Problem #7

	//Chapter 3 Challenge Problem #23
	printf("\nChapter 3 Challenge #23: Stock Transaction Program\n");
	int shares = 1000;
	float originalSharePrice = 45.50;
	float commissionPercentage = 0.02;
	float newSharePrice = 56.90;
	float paid = shares*originalSharePrice;
	float received = shares*newSharePrice;

	printf("Joe paid $%.2f for %d stocks.\n",paid,shares);
	printf("Joe paid $%.2f in commission when he bought %d stocks.\n",shares*originalSharePrice*commissionPercentage, shares);
	printf("Joe received $%.2f when he sold %d stocks.\n",received,shares);
	printf("Joe paid $%.2f in commission when he sold %d stocks.\n",shares*newSharePrice*commissionPercentage,shares);
	float profit = (received - received*commissionPercentage)-(paid + paid*commissionPercentage);
	printf("Joe profited $%.2f after trading stocks.\n",profit);
	//End of Chapter 3 Problem #23

	//Chapter 5 Challenge Problem #23
	printf("\nChapter 5 Challenge #23: Pattern Displays\n");

	//pattern A
	for(int i=0;i<11;i++){
		for(int j = 0; j<i;j++){
			printf("+");
		}
		printf("\n");
	}

	printf("\n");

	//pattern B
	for(int i=10;i>=1;i--){
		for(int j = 0; j<i;j++){
			printf("+");
		}
		printf("\n");
	}
	//End of Chapter 5 Problem #23

	return 0;
}
//End of program
