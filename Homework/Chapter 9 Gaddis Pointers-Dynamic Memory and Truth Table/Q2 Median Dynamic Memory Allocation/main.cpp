/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 * Q2 Median
 * Created on September 24, 2022, 1:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Function prototypes
int *getData(int &); //return the array size and the array
void prntDat(int *,int); //print the integer array
float *median(int *, int); //fill the median array with the float array size, the median, and the integer array data
void *prntMed(float *, int); //print the median array

int main(int argc, char** argv) {
    int arySize = 0; //variable for array size
    int *array; //pointer to the array
    array = getData(arySize); //get array from user
    prntDat(array, arySize); //print the array
    float *medianptr; //pointer for median
    medianptr = median(array, arySize); //array to find median
    prntMed(medianptr, arySize); //print the median array

    return 0;
}

//the functions
int *getData(int &size) //return the array size and the array
{
    cin >> size;
    //get the array from user
    int *arrptr = nullptr;
    arrptr = new int[size];//the array
    for (int i=0; i<size; i++) //until the array is full
    {
        cin >> arrptr[i];//put into array
    }
    return arrptr;//return array and size
}

void prntDat(int *arr,int size) //print the SORTED integer array
{

    for (int i=0; i<size; i++)//print the array
    {
        if (i<size-1)
            cout << arr[i] << " ";
        else
            cout << arr[i];
    }
    cout << endl;
}

float *median(int *arr, int size) //fill the median array with the float array size, the median, and the integer array data
{
    //sort first
    //find median

    //find the median
    //if the size is odd: divide size by 2 and when i=size/2 then it is the median
    //(else)if the size is even: size/2=middle, middle-1=step, arr[0+step]=median1 , size total-step = median 2, median2/median1=median
    float median, middle, med1, med2 = 0;//variables
    if (size%2 == 0)//if the size of the array is even
    {
        middle = size/2;//middle value is half size
        med1 = middle-1; //first middle value is initial plus step value JUST LOCATION
        med2 = size-middle; //second middle value is step away from the end JUST LOCATION IN ARRAY
        for (int i=0; i<size; i++)//traverse the array for med1
        {
            for (int j=0; j<size; j++)//traverse the array for med2
            {
                if (i==med1 && j==med2) //when we get to the two middle values
                {
                    float m = arr[i];
                    float n = arr[j];
                    median = (m + n)/2; //calculate median
                }
            }
        }
    }
    else //the size of the array is odd WORKS
    {
        for (int i=0; i<size; i++)
        {
            middle = size/2;//get middle location
            if(i==middle)//when i gets to the middle value
                median = arr[i];//the median is the middle value
        }
    }
    
    //store values in the median array
    //array contains: 
    /* array size arr[0]
     * the median arr[1]
     * the integer array data arr[2+]
     */
    float *medptr = nullptr;//points to median array
    int ptrsize = size+2;
    medptr = new float[ptrsize];
    medptr[0] = size+2;//first value is median array size
    medptr[1] = median;//second value is the median
    for (int i=2; i<size+2; i++)//fill the rest of the values (2+) with array contents
    {
        medptr[i] = arr[i-2];//copy array
    }
    return medptr;//returns the median array
}

void *prntMed(float *medAry, int size) //print the median array
{
    int arySize = size+2;
    for (int i=0; i<arySize; i++)
    {
        if (i==0)
            cout << medAry[i] << " ";
        else if (i==arySize-1)
            cout << showpoint << setprecision(3) << medAry[i];
        else
            cout << showpoint << setprecision(3) << medAry[i] << " ";
    }
    return 0;
}