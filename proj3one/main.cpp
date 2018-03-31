/*  Program: Project 3 (EC 1 Included)
 Author: Miguel Bravo
 Class:	CSCI 110 FRI
 Date: 11/14/2014
 Description:
 
 Project 3 - Statistical calculator
 
 I certify that the code below is my own work.
	
	Exception(s): N/A
 
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

const int SIZE = 30;


void programInfo();
void inputList(double arr[], int &count);
void printList(double arr[], int count);
void sortAscending(double arr[], int count);
double aveList(double arr[], int count);
double medianSortedList(double arr[], int count);
double stdDeviation(double arr[], int count, double ave);
void printStats(double ave, double med, double std);



int main()
{
    
    cout << "Author: Miguel Bravo\n" << endl;
    
    cout << fixed << showpoint << setprecision(1);
    
    int count = 0;
    double arrList[SIZE];
    
    programInfo();
    inputList(arrList, count);
    
    cout << "Original list: " << endl;
    printList(arrList, count);
    
    cout << "Sorted list in ascending order: " << endl;
    sortAscending(arrList, count);
    printList(arrList, count);
    
    double ave = aveList(arrList, count);
    double median = medianSortedList(arrList, count);
    double stdDev = stdDeviation(arrList, count, ave);
    
    printStats(ave, median, stdDev);
    
    return 0;
    
}




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
// Functions //


void programInfo(){
    cout << "Miguel Bravo's Statistical Calculator \n" << endl;
    cout << "Please follow insruction's carefully." << endl;
    cout << "Enter one value at a time up to 3 values." << endl;
    cout << "You must enter valid data or program will not work." << endl;
    cout << "Enter -1 to signal end of data." << endl;
}


void inputList(double arr[], int &count){
    
    double val = 0.0;
    
    while(val != -1){
        
        cout << "Please enter a value --> ";
        cin >> val;
        
        arr[count] = val;
        
        count++;
        
        // if sentinal value, subtract from count
        if(val == -1){
            count -= 1;
        }
        
    }
    
}


void printList(double arr[], int count){
    int i;
    
    if(count < 3 || count > SIZE){
        cout << "Error. List is less than 3 or more than 30." << endl;
        exit(1);
    }else{
    
        for(i = 0; i < count; i++){
        
            if(arr[i] != -1){
                if((i + 1) % 5 == 0){
                    cout << setw(10) << arr[i] << endl;
                }else{
                    cout << setw(10) << arr[i];
                }
            
            }
        
        }
        
    cout << endl;
        
    }
    
}


void sortAscending(double arr[], int count){
    
    int temp, i, j, min;
    
    /* selection sort */
    for (i = 0; i < count - 1; i = i + 1)
    {
        /* Assume that value at postion i is the smallest */
        /* If a smaller one is found, set that position to min */
        min = i;
        for (j = i + 1; j < count ; j = j + 1)
            if (arr[min] > arr[j])
                min = j;
        
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        
    }
    
}


double aveList(double arr[], int count){
    
    double total = 0.0;
    double avg = 0.0;
    
    for(int i = 0; i < count; i++){
        total = total + (double)arr[i];
    }
    avg = (total/count);
    return avg;

}

double medianSortedList(double arr[], int count){
    
    int middle = (count)/2;
    double result;
    
    
    if(count % 2 == 0){
        result = ((arr[middle-1]) + (arr[middle])) / 2;
    }else{
        result = arr[middle];
    }
    
    return result;
    
}

double stdDeviation(double arr[], int count, double ave){
    
    double total = 0;
    
    for(int i = 0; i < count; i++){
        total = total + pow(arr[i]-ave,2);
    }
    
    return sqrt(total / (count - 1));
    
}

void printStats(double ave, double med, double std){
    
    cout << "Average: " << ave << endl <<  "Median: " <<  med << endl;
    cout << "Std Deviation:" << std << endl;
    
}






