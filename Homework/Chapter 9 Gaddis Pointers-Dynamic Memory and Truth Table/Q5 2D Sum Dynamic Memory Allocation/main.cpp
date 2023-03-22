/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2790755
 * Q5 2D Sum
 * Created on September 24, 2022, 1:33 PM
 * 
 * total the elements in a 2D array.
 * create the following functions to perform this task.
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//function prototypes
int **getData(int &, int &); //return the 2d array and its size
void prntDat(const int* const*array, int, int); //print the 2d array
void destroy(int **, int, int); //de-allocate memory
int sum(const int* const*, int, int); //return the sum

//main function
int main(int argc, char const *argv[]) {
    int rows; //variable for array rows
    int cols; //variable for array columns
    int **array; //pointer to the array
    array = getData(rows, cols); //get array from user
    prntDat(array, rows, cols);
    cout << sum(array, rows, cols);
    destroy(array, rows, cols);
    
    return 0;
}

//return the 2d array and its size
int **getData(int &rows, int &cols)
{
    cin >> rows >> cols;
    //get the array from user
    int **arrptr = new int *[rows];//the array
    for (int i=0; i<rows; i++) //until the rows are full
    {
        arrptr[i] = new int[cols];
        for (int j=0; j<cols; j++) //until columns are full
        {
            cin >> arrptr[i][j];
        }
    }
    return arrptr;//return array and size
}

//print the 2d array
void prntDat(const int *const *array, int rows, int cols)
{
    for (int i=0; i<rows; i++) //until the rows are full
    {
        for (int j=0; j<cols; j++) //until columns are full
        {
            cout << array[i][j];
            if (j<cols-1)cout << " ";
        }
        cout << endl;
    }
}

//de-allocate memory
void destroy(int **array, int rows, int cols)
{
    for (int i=0; i<rows; i++)//for every row
        delete[] array[i];
        delete array;
}

//return the sum
int sum(const int *const *array, int rows, int cols)
{
    int sum = 0;
    
    for(int i=0; i<rows; i++)//for every row
    {
        for (int j=0; j<cols; j++)//for every column
        {
            sum += array[i][j];
        }
    }
    return sum;
}
