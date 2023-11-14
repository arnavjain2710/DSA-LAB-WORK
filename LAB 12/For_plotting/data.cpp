//For plotting random array.

#include<iostream>
#include<vector>
#include<random>
#include<ctime>

using namespace std;

void bubbleSort(vector<int> &array, bool order=true){
    for(int i{0}; i<array.size()-1; i++){
        for(int j{0}; j<array.size()-i-1; j++){
            if((array[i]>array[i+1] && order) || (array[i]<array[i+1] && !order)){
                //swap
                int x = array[i];
                int y = array[i+1];
                array[i] = y;
                array[i+1] = x;
            }
        }
    }
}

void selectionSort(vector<int> &array, bool order=true){
    for(int i{0}; i<array.size()-1; i++){
        int index = i;
        for(int j{i}; j<array.size(); j++){
            if((array[index]>array[j] && order) || (array[index]<array[j] && !order)){
                index = j;
            }
        }
        //swap
        int x = array[i];
        int y = array[index];
        array[i] = y;
        array[index] = x;
    }
}

void insertionSort(vector<int> &array, bool order=true){
    if(array.size()>1){
        for(int i{1}; i<array.size(); i++){
            int key = array[i];
            int j{i-1};
            while((array[j]>key && order) || (array[j]<key && !order && j>=0)){
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = key;
        }
    }    
}

int main(){
    vector<long int> X;
    vector<double> Y;
    int length = 5000;
    for(int dataPoints{0}; dataPoints<20; dataPoints++){
        vector<int> arr;

        for(int i{0}; i<length; i++){
            arr.push_back(rand());
        }

        // for(int i{0}; i<length; i++){
        //     arr.push_back(i);
        // }

        // for(int i{0}; i<length; i++){
        //     arr.push_back(length-i);
        // }

        clock_t t1 = clock();
        //Sort:
        //bubbleSort(arr);
        //selectionSort(arr, false);
        insertionSort(arr, false);
        clock_t t2 = clock();

        double timeTaken = static_cast<double>(t2-t1)/CLOCKS_PER_SEC;
        cout<<endl<<dataPoints<<". Time taken: "<<timeTaken<<"s";
        Y.push_back(timeTaken);
        X.push_back(length);
        length+=5000;
    }

    cout<<endl;
    for(int i:X){
        cout<<i<<", ";
    }
    cout<<endl;
    for(double i:Y){
        cout<<i<<", ";
    }
    return 0;
}