#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

int main(){

    printf(" Welcome to the Pi Calculator!\n");
    printf(" First, we are going to approximate Pi using the method of Archimedes.\n");
    printf(" Archimedes approximated Pi by inscribing and circumscribing regular polygons around a circle.\n");
    printf(" As the number of sides of these polygons increases, their perimeters approach the circumference of the circle.\n");
    printf(" By comparing the perimeters of these polygons to the diameter of the circle, Archimedes derived increasingly accurate approximations of Pi.\n");
    printf(" We will simulate this process by increasing the number of sides of the polygons and calculating their perimeters.\n");
    printf(" We will then use these perimeters to approximate Pi.\n");


    int numberOfVertices;
    float Pi;
    float lengthOfEdge;
    float lengthOfEdge2;

    numberOfVertices = 3;
    lengthOfEdge2 = 1.0;

    printf("\n   Number Of Vertices |      Pi");
    printf("\n ---------------------+----------------");
    for(int i = 1; i <= 10; i++){
        numberOfVertices *= 2;
        lengthOfEdge = lengthOfEdge2;
        lengthOfEdge2 = sqrt(2.0 * pow(1, 2) - 1.0 * sqrt(4.0 * pow(1, 2) - pow(lengthOfEdge, 2)));
        Pi = lengthOfEdge2 * numberOfVertices;
        printf("\n       %8d       |   %2.10f", numberOfVertices, Pi);
    }
    printf("\n ---------------------+----------------\n");

    printf("\n Next, we are going to approximate Pi using the Monte Carlo method.\n");
    printf(" The Monte Carlo method approximates Pi by randomly generating points within a square that encloses a quarter circle.\n");
    printf(" By determining the ratio of points that fall within the quarter circle to the total number of points generated within the square,\n");
    printf(" we can approximate the area of the quarter circle relative to the area of the square.\n");
    printf(" Multiplying this ratio by 4 gives us an approximation of Pi.\n");
    printf(" As we increase the number of randomly generated points, our approximation of Pi becomes more accurate.\n");
    printf(" We will simulate this process by generating random points and counting how many fall within the quarter circle.\n");
    printf(" We will then use this information to approximate Pi.\n");


    int numberOfPointsInSquare;
    int numberOfPointsInCircle = 0;

    printf("\n   Number Of Points              | Value of  ");
    printf("\n   in total | inside the Circle  |    Pi     ");
    printf("\n -----------+--------------------+-----------");

    for(numberOfPointsInSquare = 10; numberOfPointsInSquare <= 100000000; numberOfPointsInSquare*=10){

        numberOfPointsInCircle = 0;

        float* xCoordinates = (float*)malloc(numberOfPointsInSquare * sizeof(float));
        if(xCoordinates == NULL){
            printf("Memory allocation failed for x-coordinates\n");
            return 1;
        }

        float* yCoordinates = (float*)malloc(numberOfPointsInSquare * sizeof(float));
        if(yCoordinates == NULL){
            printf("Memory allocation failed for y-coordinates\n");
            return 1;
        }

        //srand(static_cast<int>(time(NULL)));
        srand((int)time(NULL));
        for(int i = 0; i < numberOfPointsInSquare; i++){
            xCoordinates[i] = (float)rand() / (float)RAND_MAX;
            yCoordinates[i] = (float)rand() / (float)RAND_MAX;
        }

        for(int i = 0; i < numberOfPointsInSquare; i++){
            if(sqrt(pow(xCoordinates[i], 2) + pow(yCoordinates[i], 2)) <= 1){
                numberOfPointsInCircle++;
            }
        }

        Pi = 4.0 * numberOfPointsInCircle / numberOfPointsInSquare;

        printf("\n %10d |     %10d     |  %.7f  ", numberOfPointsInSquare, numberOfPointsInCircle, Pi);

        free(xCoordinates);
        free(yCoordinates);
    }

    printf("\n -----------+--------------------+-----------");

    return 0;
}
