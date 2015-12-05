#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
#define g 9.81
#define EXIT_INPUT_ERROR -1

// "Copyright[2013]<CopyrightBuratinkalol>"

double* TimeFunc(int *InitHeight, int *EndHeight) {
    double time= sqrt((2*(*InitHeight-*EndHeight))/g);
    double *Time= (double*)(malloc(sizeof(*Time)));
    if (Time== NULL)
        return NULL;
    *Time= time;
    return Time;
}
 
int main(void) {
    int InitHeight, EndHeight;
    printf("Please, enter InitHeight and EndHeight \n");
    if (scanf("%d%d", &InitHeight, &EndHeight)!= 0) {
        if (InitHeight< 0 || EndHeight< 0 || InitHeight< EndHeight) {
            printf("ERROR! Please, enter InitHeight and EndHeight \n");
            return EXIT_INPUT_ERROR;
        }
        printf("Thanks! \n");
        double* TM= TimeFunc(&InitHeight, &EndHeight);
        if (TM== NULL) {
            printf("ERROR! Please, enter InitHeight and EndHeight \n");
        } else {
            printf("%.3f \n", *TM);
            free(TM);
        }
    } else {
        fflush(stdin);
        printf("ERROR! Please, enter InitHeight and EndHeight \n");
        return EXIT_INPUT_ERROR;
    }
    return EXIT_SUCCESS;
}
