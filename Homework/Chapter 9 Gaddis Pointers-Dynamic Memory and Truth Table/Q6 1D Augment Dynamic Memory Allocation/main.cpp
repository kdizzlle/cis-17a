/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2790755
 * Q6 1D Augment
 * Created on September 24, 2022, 1:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//function prototypes
int *getData(int &); //read the array
int *augment(const int *, int); //augment and copy the original array
void prntAry(const int *, int); //print the array

int main(int argc, char** argv) {

    int size;
    cin >> size;
    int *array = getData(size);
    prntAry(array, size);
    array = augment(array, size);
    cout << endl;
    prntAry(array, size+1);
    return 0;
}

//read the array
int *getData(int &size) 
{
    int *arr = new int[size];
    for (int i=0; i<size; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

//augment and copy the original array
int *augment(const int *arr, int size) 
{
    int *res = new int[size+1];
    res[0] = 0;
    for (int i=0; i<size; i++)
    {
        res[i+1] = arr[i];
    }
    return res;
}

//print the array
void prntAry(const int *arr, int size) 
{
    for (int i=0; i<size; i++)
    {
        cout << arr[i];
        if (i<size-1)cout << " ";
    }
}