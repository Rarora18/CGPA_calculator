/*
Simple program that takes in either manually inserted grades or reads a direct file
with all GPAs/scores (one score per line) and calculates the Cumulative Grade Point Average.
*/

#include <iostream>
#include <iomanip>
#include<string>
#include<fstream>
#include <sstream>
#include<cmath>
#include <cctype>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::ifstream;
using std::out_of_range;
using std::round;
using std::isalpha;

double Calculate_CGPA(int &n){

    double sum = 0;
    for (int i = 0;i<n;i++){
        double input;
        cout<<"Course "<<i+1<<"'s GPA: "<<endl; 
        cin>>input;
        sum+=input;
    }

return sum/n;    
    
}
void filescan(string &filename){
    float score;
    ifstream myfile(filename);
    
    while (!myfile.is_open()){
    string newfile;
    cout<<"File could not be opened. Please try again and enter an existing file or press 0 to exit: ";
    cin>>newfile;
    if (newfile=="0"){
        
        return;
    }
    myfile.open(newfile);
    }
    float total = 0;
    int n = 0;
    while (myfile>>score){
        total+=score;
        n++;
    }
    float avg = total/n;
    cout<<"Your CGPA is "<<setprecision(3)<<avg;
  }



    


int main(){
    string input;
    cout<<"Enter M for manual insertion or F to scan a file containing all GPAs: ";
    cin>>input;
    
   
    while (true){
    if (input=="M"){
    int n;
    cout<<"Enter the number of courses taken: ";
    
    cin>>n;
    while (n<=0){
        cout<<"Please Try again and enter valid no. of courses taken: ";
        cin>>n;
    }

    double result = Calculate_CGPA(n);
    cout<<"Your CGPA is "<<setprecision(3)<<result<<endl;
    break;
   }
    
    else if (input =="F"){
    string filename;
    cout<<"Name of file: ";
    cin>>filename;
    filescan(filename);
    
    break;
    }
    else{
        cout<<"Please enter a valid input (M or F)";
        cin>>input;
    }
    }
    return 0;
}