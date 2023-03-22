/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2790755
 * Q7 2D Augment
 * Created on September 24, 2022, 1:34 PM
 */

#include <cstdlib>

using namespace std;

//function prototypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(int argc, char** argv) {

    int rows, cols;
    int **nos;
    nos=getData(rows,cols);
    printDat(nos,rows,cols);
    rows++;
    cols++;
    nos=augment(nos,rows,cols);
    printDat(nos,rows,cols);
    destroy(nos,rows);
    return 0;
}

int **getData(int &rows,int &cols)//Get the Matrix Data
{
    cin >> rows >> cols;
    int** arr = new int*[rows];

    for(int i=0;i<rows;i++)
    {
        arr[i] = new int[cols];
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    return arr;
}

void printDat(const int * const *nos,int rows,int cols)//Print the Matrix
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<nos[i][j];
            if(j<cols-1)
            {
                cout<<" ";
            }
        }
        if(i<rows-1)
            cout<<endl;
    }
}

int **augment(const int * const *nos,int rows,int cols)//Augment the original array
{
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i)
    arr[i] = new int[cols];


    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==0) 
            {
                arr[i][j]=0;
            }
            else if(j==0)
            {
                arr[i][j]=0; 
            }
            else
            {
                arr[i][j]=nos[i-1][j-1];
            }
        }
    }
cout<<endl;
return arr;
}

void destroy(int **nos,int size)//Destroy the Matrix, i.e., reallocate memory
{
    for (int i = 0; i < size; i++)
    {
        delete[] nos[i];
    }
}