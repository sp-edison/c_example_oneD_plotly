#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <math.h>

#define PI 3.140592
#define SIZE 128

typedef struct _inputparam {
//y = A sin(Bx + C) +D
    double a;       //A
    double b;       //B
    double c;       //C
    double d;       //D
} INPUT;

int main (int argc, char *argv[]) {
    int opt;
    FILE *fp_input, *fp_output;
    char buf_char[512];
    INPUT input;
    
    double x,y;
    int t;


    // Detect the end of the options.
    while((opt = getopt(argc, argv, "i:")) != -1 ) {
        switch(opt) {
            case 'i': 
                fp_input = fopen(optarg,"r");
                break;
            default:
                printf("Usage: %s -i [Inputfile path]\n", argv[0]);
                exit(1);
        }
    }

    // Input file open
    if(fp_input == NULL){
        printf("Failed to open input file for -i \n");
        exit(1);
    }

    // Write an algorithm program in this section.
    
    while(1) {
        fscanf(fp_input, "%s", buf_char);

        if(feof(fp_input))
            break;
        
        if(!strcmp(buf_char, "a")) {
            fscanf(fp_input, "%*s %lf %*s", &input.a);
        } else if(!strcmp(buf_char, "b")) {
            fscanf(fp_input, "%*s %lf %*s", &input.b);
        } else if(!strcmp(buf_char, "c")) {
            fscanf(fp_input, "%*s %lf %*s", &input.c);
        } else if(!strcmp(buf_char, "d")) {
            fscanf(fp_input, "%*s %lf %*s", &input.d);
        } else {
			 printf("Error Invalid value name :: %s\n", buf_char);
			exit(1);
		}
    }
    // Input file close
    fclose(fp_input);

    printf("User input is : \n");
    printf("A = %f \n", input.a);
    printf("B = %f \n", input.b);
    printf("C = %f \n", input.c);
    printf("D = %f \n", input.d);


    system("rm -rf result");
    system("mkdir result");

    // Make oneD file
    fp_output = fopen("result.oneD","w");
    
    fprintf(fp_output,"#NumField: 1\n");
    fprintf(fp_output,"#LabelX: time, LabelY: a*sine(bx+c)+d \n"); 
    fprintf(fp_output,"#Field1: a=%f b=%f c=%f d=%f,NumPoint:%d\n", input.a, input.b, input.c, input.d, SIZE);

    for(t=0; t< SIZE; t++) {
        x = (4*PI * t)/SIZE -2*PI;
        y = input.a*(sin( input.b*x +input.c)) +input.d;
        fprintf(fp_output, "%10.3f  %10.3f\n", x, y);
    }

    fclose(fp_output);
    system("mv result.oneD result/");
	return 0;
}
