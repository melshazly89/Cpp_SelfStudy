#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(991,0) ;
vector<int> arr2={10,11,12,13,14,15,16,17,18,19};
void fillarray(int offset,vector<int>& arr);
int arrayaccumlate(vector<int>& arr);
void printarray(vector<int>& arr);
int main()
{
    
    int start = 10;
    cout << "Fill the array with specific values" << endl;
    fillarray(10,arr);
    cout << "Print array Elements" << endl;
    printarray(arr);
    
    int result = arrayaccumlate(arr2);
    cout << "Sum of accumlated array elements = " << result << endl;
    cout << "Print array Elements" << endl;
    printarray(arr2);

    
}

int arrayaccumlate(vector<int>& arr)
{
    int sum =0;
    for_each(arr.begin(), arr.end(), [&sum,&arr](int i) {
        sum+=i;
        
    });

    return sum;

}

void fillarray(int offset,vector<int>& arr)
{
    /*Lambda expression used to fill array*/
    for_each(arr.begin(), arr.end(), [&offset](int& i) 
            {
                i =offset++;
        
            });
}


void printarray(vector<int>& arr)
{
    /*Lambda expression to print array elements*/
    for_each(arr.begin(),arr.end(),[&arr](int& i)
            {
                cout << i <<endl;
            });

}