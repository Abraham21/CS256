/*
 * File: CS256Project1.c
 *
 * Author: Abraham Yepremian
 *
 * Description: Project 1 for CS 256
 * Chapter 7 Problem 20 Theater Seating
 *
 * Last edited: 4/22/2018
 *
 */

#include <stdio.h>
#include <stdlib.h>

void printTheater(char array[15][30]){
	printf("\t\tSeats\n");
	printf("\t123456789012345678901234567890");
	//print 2d array
		for (int i = 0; i < 15; i++) {
			printf("\nRow %d\t", i+1);
			    for (int j = 0; j < 30; j++) {
			    	printf("%c", array[i][j]);
			    }
			}
		printf("\n");
}

int main(){
	int arrayPrices[15];
	int totalTicketSales = 0;
	int seatsSold = 0;
	int rowSeatsAvailable[15] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
	//print
	printf("\nChapter 7 Problem #20 Theater Seating\n");
	//get seat prices for 15 rows and store in array
	printf("You will need to set the prices for each row with integer values.\n");
	for(int i = 1; i < 16; i++){
		printf("Enter Seat Prices For Row %d\n", i);
		int price;
		scanf("%d", &price);
		arrayPrices[i-1] = price;
	}
	//generate and print 2d array of movie theater
	//sets all seats to available
	char seats[15][30];
	for (int i = 0; i < 15; i++) {
	    for (int j = 0; j < 30; j++) {
	        seats[i][j] = '#';
	    }
	}

	printTheater(seats);

	//set up managing menu
	int selection = 0;

	while(selection != 6) {

	printf("\nMenu");
	printf("\n1. View Seat Prices\n");
	//have a for loop that goes through row prices
	printf("2. Purchase a Ticket\n");
	//let them purchase a ticket and display cost
	printf("3. View Available Seats\n");
	//print theater out
	printf("4. View Ticket Sales\n");
	//show total of ticket prices sold
	printf("5. View Specific Information\n");
	//show total number of seats sold, how many seats are available in each row
	//and how many seats are left in the whole auditorium
	printf("6. Quit\n");
	printf("Input selection (1-6):\n");

	//get user selection
	scanf("%d", &selection);

	//logic for each menu option
	if(selection == 1){
		for(int i = 0; i < 15; i++){
			printf("\nPrice for Row %d: $%d", 1+i, arrayPrices[i]);
		}
		printf("\n");
	}
	else if(selection == 2){
		printf("Enter the row and column of the seat you want to purchase:\n");
		int row;
		int column;
		scanf("%d%d",&row,&column);
		if(row<1 || column<1 || row>15 || row>30){
					printf("Error: Input out of bounds.\n");
		}
		else{
		row--;
		column--;
		if(seats[row][column]=='*'){
			printf("Seat taken.\n");
		}
		else{
			seats[row][column] = '*';
			seatsSold++;
			rowSeatsAvailable[row]--;
			int seatPrice = arrayPrices[row];
			totalTicketSales+=seatPrice;
			printf("Seat %d,%d successfully purchased for $%d\n", ++row, ++column, seatPrice);
		}
		}
	}
	else if(selection == 3){
		printTheater(seats);
	}
	else if(selection == 4){
		//view total ticket sales
		printf("\nTotal of tickets sold: $%d\n", totalTicketSales);
	}
	else if(selection == 5){
		//show total number of seats sold, how many seats are available in each row
		//and how many seats are left in the whole auditorium
		printf("\nTotal number of seats sold: %d\n\n", seatsSold);
		for(int i = 0; i < 15; i++){
			printf("Available Seats Left in Row %d: %d\n", 1+i, rowSeatsAvailable[i]);
		}
		printf("\nSeats remaining in the auditorium: %d seats\n", 450-seatsSold);
		}
	else if(selection == 6){
				printf("End of program");
			}
	else{
		printf("Error: Invalid input.\n");
	}

	}

	return 0;

}

