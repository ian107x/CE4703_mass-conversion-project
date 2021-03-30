/*
  CE4703 Assignment Unit 1 
  Author: Ian Rowland
  ID Number: 19190859
  Start date: 22.10.2020
  date: 12.11.2020
 */
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
//comments pertaining to each function to be found below the main fuction, with the code for each function.
double pound2Kg(double pound);
void manyPound2Kg(double poundData[], double kgData[], int size);
void printPound(double pdata[], int size);
void printKg(double kdata[], int size);

int main(int argc, char *argv[])
{
  //Checks if argc >= 3; if not, the program prints out an error message.
  if(argc >= 3)
    {
      /*if argc >= 3
      the first two arguments after the assignment name(i.e, argv[1] and argv[2]) are placed into min and max respectively.
      Any arguments after these are ignored. Non number arguments are treated as 0.
      srand function is used so that the numbers generated for poundValues will be random with each execution of the code
      lack of the srand function results in the rand function generating the same set of numbers each time the program is executed.*/
      srand(time(NULL));
      int min, max, swap;
      double poundValues[10];//array where the pound values are held
      double kgValues[10];//array where the converted kg values are held
      int arrayCount;//used as a loop counter and to define the posotions of the array poundValues in the loop.

      min = atoi(argv[1]);
      max = atoi(argv[2]);

      //if min ends up being greater than max, they will be swapped here.
      if (min > max)
	{ 
	  swap = min;
	  min = max;
	  max = swap;
	}
      
     
      
      for(arrayCount = 0; arrayCount<10; ++arrayCount){
	// loop generates random numbers in range of min to max (inclusive), to be held in each element in poundValues. 
	poundValues[arrayCount] = rand() % ((max + 1) - min) + min;
      }

      //call the declared functions to convert the generated pound values into kg, and display the pound and kg values.
      manyPound2Kg(poundValues, kgValues, 10);
      printPound(poundValues, 10);
      printKg(kgValues, 10);
    }
  else
    {
      //error message printed if argc is less than 3.
      printf("Incorrect number of arguments-please call with \t%s min max\n", argv[0]);
    }
  return EXIT_SUCCESS;
}

 /*pound2Kg(double pound)
converts pound valueheld by double pound into a kg value and returns the kg value
1lb=0.45359237kg and 1kg=2.2046226218lb.*/ 
double pound2Kg(double pound)
{
  /*use the following formula to convert the input pound to kg equivalent, hold in the kgValue variable, and return to the function.
    stored in kgValue before returning to aid readability of the code.*/
  double kgValue = pound * 0.45359237;
  return kgValue;
}

/*void manyPound2Kg(double poundData[], double kgData[], int size)
calls pound2Kg to convert values in poundData to kg and store them in kgData.
size holds the size of both poundData and kgData, poundData holds the predefined pound values, 
and kgData will hold the converted kg values when the function is terminated.
*/
void manyPound2Kg(double poundData[], double kgData[], int size)
{
  int loopCount;// used as a counter for the loop.
  for(loopCount = 0; loopCount < size; ++loopCount)
    {
      //pound2Kg is called with poundData[loopCount] as its parameter, with the result being held in kgData[loopCount]
      kgData[loopCount] = pound2Kg(poundData[loopCount]);
    }
}

/*void printPound(double pdata[], int size)
 prints out content of array "pdata"
 size holds the number of elements in "pdata", and pdata holds the pound values to be printed
*/
void printPound(double pdata[], int size)
{
  int loopCount;// used as a loop counter
  printf("[");//open square brackets for the output
  for(loopCount=0; loopCount<size; ++loopCount){
    //print the pound values(lb) to 1 decimal place, e.g 12.0lb.
        printf("%0.1flb", pdata[loopCount]);
	//prints a comma if pdata[loopCount] is not the final element in pdata, to separate each value visually.
        if (loopCount<size-1){
            printf(", ");
        }
    }
  //close square brackets for the output
    printf("]\n");
}

/*void printKg(double kdata[], int size)
 prints out content of array kdata
 size holds the number of elements in kdata, and kdata holds the kg values to be printed.
*/
void printKg(double kdata[], int size)
{
  int loopCount;// used as a loop counter
  printf("[");
  for(loopCount=0; loopCount<size; ++loopCount){
    //print the kgvalues to 1 decimal place, e.g, 15.1kg.
        printf("%0.1fkg", kdata[loopCount]);
	//print a comma if kdata[loopCount] is not the last element in kdata, to separate each value visually.
	if (loopCount<size-1){
            printf(", ");
        }
    }
  //close square brackets for the output.
  printf("]\n");
}
