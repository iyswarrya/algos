/*
 ============================================================================
 Name        : 07_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Returning data from functions, Ansi-style
 	 	 	   This program demonstrates the use of functions, parameters,
 	 	 	   and returned values to calculate statistics for a basketball
 	 	 	   game.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculateTotalPointsMade(int q1,int q2);
float calculateAveragePoints(int q1,int q2);
float twoPointsPerformance(int totalShots,int shotsMade);
float threePointsPerformance(int totalShots,int shotsMade);
void  displayStatistics(int totPts,int tot2Pts,float avgQtr,float twoPts,float threePts);

int main(void) {
	int twoPointQ1;
	int threePointQ1;  //The number of three-point shots made in Q1
	int totalShotsQ1;

	int twoPointQ2;
	int threePointQ2;  //The number of three-point shots made in Q2
	int totalShotsQ2;

		printf("enter number of shots in quarter1");
		scanf("%d",&totalShotsQ1);
		printf("enter number of 2-point shots in quarter1");
		scanf("%d",&twoPointQ1);
		printf("enter number of 3-point shots in quarter1");
		scanf("%d",&threePointQ1);

		printf("enter number of shots in quarter2");
		scanf("%d",&totalShotsQ2);
		printf("enter number of 2-point shots in quarter1");
		scanf("%d",&twoPointQ2);
		printf("enter number of 3-point shots in quarter1");
		scanf("%d",&threePointQ2);

		int totalPoints = calculateTotalPointsMade(totalShotsQ1,totalShotsQ2);
		int totalTwoPoints = calculateTotalPointsMade(twoPointQ1,twoPointQ2);
		int totalThreePoints = calculateTotalPointsMade(threePointQ1,threePointQ2);

		float averagePoints = calculateAveragePoints(totalShotsQ1,totalShotsQ2);
		float twoPoints = twoPointsPerformance(totalPoints,totalTwoPoints);
		float threePoints = threePointsPerformance(totalPoints,totalThreePoints);
		displayStatistics (totalPoints,totalTwoPoints,averagePoints,twoPoints,threePoints);



		return EXIT_SUCCESS;
}
		int calculateTotalPointsMade(int q1,int q2) {
			double sum = q1 + q2;
			return sum;

		}

		float calculateAveragePoints(int q1,int q2) {
		 double average = (q1 + q2)/2.0;
		 return average;

		}

		float twoPointsPerformance(int totalShots,int shotsMade) {
			float performance = ((float)shotsMade / (float)totalShots) * 100.0;
			return performance;
		}

		float threePointsPerformance(int totalShots,int shotsMade) {
					float performance = ((float)shotsMade / (float)totalShots) * 100.0;
					return performance;
				}

		void displayStatistics(int totPts,int tot2Pts,float avgQtr,float twoPts,float threePts)
		{ printf("total points %d\n",totPts);
		printf("total2points %d\n", tot2Pts);
		printf("totalAvgpoints %f\n", avgQtr);
		printf("2-point performance %f\n", twoPts);
		printf("3-point performance %f\n", threePts);
		}
