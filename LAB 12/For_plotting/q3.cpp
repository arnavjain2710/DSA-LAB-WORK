//insertion sort
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
    int length = 5000; //set the length accordingly. (for 1Million, it would take too long)

    vector<int> arr1;
    for(int i{0}; i<length; i++){
        arr1.push_back(rand());
    }
    clock_t t1_1 = clock();
    //Sort:
    //bubbleSort(arr);
    //selectionSort(arr, false);
    insertionSort(arr1, false);
    clock_t t2_1 = clock();
    double timeTaken = static_cast<double>(t2_1-t1_1)/CLOCKS_PER_SEC;
    cout<<endl<<"Time taken for randomized: "<<timeTaken<<"s";

    vector<int> arr2;
    for(int i{0}; i<length; i++){
        arr2.push_back(i);
    }
    clock_t t1_2 = clock();
    //Sort:
    //bubbleSort(arr);
    //selectionSort(arr, false);
    insertionSort(arr2, false);
    clock_t t2_2 = clock();
    timeTaken = static_cast<double>(t2_2-t1_2)/CLOCKS_PER_SEC;
    cout<<endl<<"Time taken for increasing order: "<<timeTaken<<"s";

    vector<int> arr3;
    for(int i{0}; i<length; i++){
        arr3.push_back(length-i);
    }
    clock_t t1_3 = clock();
    //Sort:
    //bubbleSort(arr);
    //selectionSort(arr, false);
    insertionSort(arr3, false);
    clock_t t2_3 = clock();
    timeTaken = static_cast<double>(t2_3-t1_3)/CLOCKS_PER_SEC;
    cout<<endl<<"Time taken for decreasing order: "<<timeTaken<<"s";
    
    return 0;
}