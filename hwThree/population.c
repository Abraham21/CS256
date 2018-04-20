/*
 * File: population.c
 *
 * Author: Abraham Yepremian
 *
 * Description: Homework 3 for CS 256
 * Chapter 6 Problem 16 Population Simulation
 *
 * Last edited: 4/19/2018
 *
 */

#include <stdio.h>
#include <stdlib.h>

float calculatePopulation(int P, float B, float D){
	float new = (P + B*P - D*P);
	return new;
}

int main(){
	printf("Chapter 6 Problem #16 Population Simulator\n");
	int originalSize;
	float birthRate;
	float deathRate;
	int years;
	printf("Enter starting population size:\n");
	scanf("%d",&originalSize);
	if(originalSize<2){
		exit(0);
	}
	printf("Enter the annual birth rate:\n");
	scanf("%f",&birthRate);
	printf("Enter the annual death rate:\n");
	scanf("%f",&deathRate);
	if(birthRate<0 || deathRate<0){
		exit(0);
	}
	printf("Enter the amount of years to display:\n");
	scanf("%d",&years);
	if(years<1 || years<2){
		//not accepted
		exit(0);
	}
	else{
		//calculate and print population for number of years
		float population = (float)calculatePopulation(originalSize,birthRate,deathRate);
		printf("Year 1: %.0f\n",population);

		for(int i = 0; i<years-1; i++){
			population = calculatePopulation(population,birthRate,deathRate);
			printf("Year %d: %.0f\n",i+2,population);
		}
	}

	return 0;

}

