/* 
 * File:   main.cpp
 * Author: Kelly Williams
 * Created on 9/17/2022 3:52pm
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char arr[][COLMAX],int rowDet)//Outputs row and columns detected from input
{
    int rows = 0;
    int cols = 0;
    string input;
    int length;
    
    for(int i=0; i < rowDet; i++) //while input is less than row input
    {
        cin >> input; //get string from user
        length = input.length(); //record length of input
        if (length > 0 && length < COLMAX)
        {//if length is positive and less than max column length
        strcpy(arr[rows], input.c_str()); //copy to array
        rows++; //do it again if true
        if (length > cols) //if length is larger than previous
        {
            cols = length; //reset column length
        }
        }
        else
        {
            cout << "Input error: too long or too short." << endl;
        }
    }
    rowDet = rows;
    return cols; //return longest string length
}

void sort(char arr[][COLMAX],int rows,int cols)//Sort by row
{
    char hold[COLMAX];
    for (int i=0; i < rows; i++)
    {
        for (int j = 0; j < rows-1; j++)
        {
            if (strcmp(arr[j],arr[j+1])>0)
            {
                strcpy(hold, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], hold);
            }
        }
    }
}

void print(const char arr[][COLMAX],int rows,int cols)//Print the sorted 2-D array
{
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            cout << arr[x][y];
        }
        cout << endl;
    }
    
}

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn; //3
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn; //3
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    //678
    //567
    //456
    colDet=read(array,rowDet); 
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        //456
        //567
        //678
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}