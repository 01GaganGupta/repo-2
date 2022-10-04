# include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int> &arr, int low, int high) {
    int pi = arr[high];
    int j = low;
    for(int i = low; i < high; i++) {
        if(arr[i] < pi) {
            swap(arr[i], arr[j]);
            j++;
        } 
    }
    swap(arr[j], arr[high]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void merge(vector<int> &arr, int low, int mid, int high) {
    int szL = mid - low + 1;
    int szR = high - mid;
    vector<int> left(szL);
    vector<int> right(szR);
    int k = 0;
    for(int i = low; i <= mid; i++) {
        left[k++] = arr[i];
    }
    k = 0;
    for(int j = mid + 1; j <= high; j++) {
        right[k++] = arr[j];
    }
    
    k = low;
    int i = 0, j = 0;
    while(i < mid - low + 1 && j < high - mid) {
        if(left[i] < right[j]) {
            arr[k++] = left[i];
            i++;
        } else {
            arr[k++] = right[j];
            j++;
        }
    }
    while(i < mid - low + 1) {
        arr[k++] = left[i];
        i++;
    }
    while(j < high - mid) {
        arr[k++] = right[j];
        j++;
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    vector<int> arr = {5, 4, 2, 9, 2, 10, 1};
    //quicksort(arr, 0, 6);
    mergeSort(arr, 0, 6);
    print(arr);
}