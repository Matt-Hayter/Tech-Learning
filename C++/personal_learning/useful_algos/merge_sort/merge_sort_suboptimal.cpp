#include <vector>
#include <iostream>

using namespace std;

void merge_sort(vector<int> &arr) {
  if(arr.size() == 1) return;

  int mid = arr.size()/2;

  vector<int> L_arr(arr.begin(), arr.begin() + mid);
  vector<int> R_arr(arr.begin() + mid, arr.end());

  merge_sort(L_arr);
  merge_sort(R_arr);

  int i = 0, j = 0, k = 0;


  while(i < L_arr.size() && j < R_arr.size()) {
    if(L_arr[i] < R_arr[j]) {
      arr[k] = L_arr[i];
      i++;
      k++;
    } else {
      arr[k] = R_arr[j];
      j++;
      k++;
    }
  }
  while(i < L_arr.size()) {
    arr[k] = L_arr[i];
    i++;
    k++;
  }
  while(j < R_arr.size()) {
    arr[k] = R_arr[j];
    j++;
    k++;
  }
}


int main() {
  vector<int> arr = {4, 3, 10, 5, 1, 7, 6, 2, 9, 8};
  merge_sort(arr);
  for(auto i : arr) {
    cout << i << ", ";
  }

}