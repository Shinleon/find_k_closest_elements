#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

#include "TwoPointerSolution.h"
#include "PriorityQueueSolution.h"

#define SEARCH_TARGET (16)
#define SEARCH_QUANT  (6)
#define ARRAY_LENGTH  (20)

void printVector(std::vector<int>& arr) {
  for(int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main(void) {
  std::vector<int> arr;
  std::srand(std::time(nullptr));
  for(int i = 0; i < ARRAY_LENGTH; i++) {
    arr.push_back(std::rand() % 64);
  }
  std::sort(arr.begin(), arr.end());
  int k = SEARCH_QUANT;
  int x = SEARCH_TARGET;
  printVector(arr);
  std::cout << "Search Target: " << x << "\tSearch Quantity: " << k << std::endl;
  std::vector<int> result_1 = TwoPointerSolution::findClosestElements(arr, k, x);
  std::vector<int> result_2 = PriorityQueueSolution::findClosestElements(arr, k, x);
  printVector(result_1);
  printVector(result_2);
  return 0;
}
