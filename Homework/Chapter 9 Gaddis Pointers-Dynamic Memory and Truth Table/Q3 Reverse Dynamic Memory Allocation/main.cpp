/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2790755
 * Q4 Reverse
 * Created on September 24, 2022, 1:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//function prototypes
int *getData(int &); //fill the array
int *sort(const int *, int); //sort smallest to largest
int *reverse(int *, int); //sort in reverse order
void prntDat(const int*, int); //print the array
int *copy(const int *,int); //copy the array

int main(int argc, char** argv) {
    int arySize = 0; //variable for array size
    int *array; //pointer to the array
    array = getData(arySize); //get array from user
    array = sort(array, arySize);
    prntDat(array, arySize); //print the array
    cout << endl;
    array = reverse(array, arySize);
    prntDat(array, arySize); //print the array
    
    return 0;
}

//fill the array
int *getData(int &size)
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

//copy the array
int *copy(const int *a,int n)
{
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

//sort smallest to largest
int *sort(const int *array, int size)//works
{
    //Copy the array
    int *arr=copy(array,size);
    
    for (int i=0; i<size-1; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (*(arr+i) > *(arr+j))
            {
                //swap values
                int *a = (arr+i);
                int *b = (arr+j);
                *a=*a^*b;
                *b=*a^*b;
                *a=*a^*b;
            }
        }
    }
    return arr;
}

//sort in reverse order
int *reverse(int *array, int size)
{
    //Copy the array
    int *arr=copy(array,size);
    
    for (int i=0; i<size-1; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (*(arr+j) > *(arr+i))
            {
                //swap values
                int *a = (arr+i);
                int *b = (arr+j);
                *a=*a^*b;
                *b=*a^*b;
                *a=*a^*b;
            }
        }
    }
    return arr;
}

//print the array
void prntDat(const int *arr, int size)
{
    for (int i=0; i<size; i++)
    {
        if (i<size-1)
            cout << arr[i] << " ";
        else
            cout << arr[i];
    }
}