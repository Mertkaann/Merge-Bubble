#include "AlgoSort.h"

AlgoSort::AlgoSort(vector<string> arguments) {
    this->type = arguments[0][0];
    this->n = stoi(arguments[1]);
    string fileName = arguments[2];
    ifstream inFile;
    inFile.open(fileName);

    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);  // call system to stop
    }
    int x;
    int i = 0;
    while (inFile >> x) {
        if (i >= n)
            break;
        data.push_back(x);
        i++;
    }
}
void AlgoSort::print() {
    cout << "type: " << type << endl;
    cout << "data: ";
    printData();
    cout << "n: " << n << endl;
}
void AlgoSort::printData() {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
void AlgoSort::write() {
    ofstream myfile;
    myfile.open("output.txt");
    for (int i = 0; i < n; i++) {
        myfile << data[i] << "\n";
    }
    myfile.close();
}
void AlgoSort::sort() {
    if (type == 'm' || type == 'M') {
        MergeSort(0, n - 1);
    } else if (type == 'b' || type == 'B') {
        BubbleSort();
    } else {
        cout << "unrecognised type is entered" << endl;
        exit(-1);
    }
}
void AlgoSort::BubbleSort() {
    bool sorted = false;
    int size = n;
    while (size > 1 && sorted == false) {
        int temp;
        sorted = true;
        for (int j = 1; j < size; j++) {
            if (data[j] < data[j - 1]) {
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
                sorted = false;
            }
        }
        size--;
    }
}
void AlgoSort::MergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}
void AlgoSort::Merge(int low, int mid, int high) {
    vector<int> temp(data);
    int k = low, i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (data[i] <= data[j]) {
            temp[k] = data[i];
            i++;
        } else {
            temp[k] = data[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = data[i];
        k++;
        i++;
    }
    while (j <= high) {
        temp[k] = data[j];
        k++;
        j++;
    }
    for (int i = low; i < k; i++) {
        data[i] = temp[i];
    }
}

void AlgoSort::printtemp(vector<int> temp) {
    cout << "temp : ";
    for (int i = 0; i < n; i++)
        cout << temp[i] << ' ';
    cout << endl;
}