#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class AlgoSort {
    char type;
    int n;
    vector<int> data;

   public:
    AlgoSort(vector<string> arguments);
    void print();
    void printData();
    void sort();
    void write();
    void BubbleSort();
    void MergeSort(int low, int high);
    void Merge(int low, int mid, int high);
    void printtemp(vector<int> temp);
};
