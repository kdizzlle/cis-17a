/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2790755
 * Q4 Sum
 * Created on September 24, 2022, 1:32 PM
 * given an array.
 * create a parallel array that represents the successive sum of preceding members in the array.
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//function prototypes
int *getData(int &); //return the array size and the array from the inputs
int *sumAry(const int *, int); //return the array with successive sums
void prntAry(const int *, int); //print the array
int *copy(const int *,int ); //copy the array

//main function
int main(int argc, char** argv) {
    int arySize = 0; //variable for array size
    int *array; //pointer to the array
    array = getData(arySize); //get array from user
    prntAry(array, arySize); //print the given array
    cout << endl;
    array = sumAry(array, arySize); //successive sums
    prntAry(array, arySize); //print the summed array
    return 0;
}

//return the array size and the array from the inputs
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

//return the array with successive sums
int *sumAry(const int *array, int size)
{
    //Copy the array
    int *arr=copy(array,size);
    for (int i=1; i<size+1; i++)
    {
        arr[i] = arr[i] + arr[i-1];
    }
    return arr;
}

//print the array
void prntAry(const int *arr, int size)
{
    for (int i=0; i<size; i++)
    {
        if (i<size-1)
            cout << arr[i] << " ";
        else
            cout << arr[i];
    }
}