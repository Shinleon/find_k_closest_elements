#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

#include "TwoPointerSolution.h"
#include "PriorityQueueSolution.h"
#include "LinearSolution.h"

#define SEARCH_TARGET (100)
#define SEARCH_QUANT  (8)
#define ARRAY_LENGTH  (40)

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
  std::vector<int> result_1 = TwoPointerSolution_SearchThenExpand::findClosestElements(arr, k, x);
  std::vector<int> result_2 = PriorityQueueSolution::findClosestElements(arr, k, x);
  std::vector<int> result_3 = TwoPointerSolution_SearchRaw::findClosestElements(arr, k, x);
  std::vector<int> result_4 = LinearSolution::findClosestElements(arr, k, x);

  std::cout << "two pointer::search then expand: "; printVector(result_1);
  std::cout << "priority queue: "; printVector(result_2);
  std::cout << "two pointer::search raw: "; printVector(result_3);
  std::cout << "linear solution: "; printVector(result_4);
  std::cout << std::endl;
  arr  = {10, 10, 10, 12, 12};
  k = 2;
  x = 11;
  printVector(arr);
  std::cout << "Search Target: " << x << "\tSearch Quantity: " << k << std::endl;
  result_1 = TwoPointerSolution_SearchThenExpand::findClosestElements(arr, k, x);
  result_2 = PriorityQueueSolution::findClosestElements(arr, k, x);
  result_3 = TwoPointerSolution_SearchRaw::findClosestElements(arr, k, x);
  result_4 = LinearSolution::findClosestElements(arr, k, x);

  std::cout << "two pointer::search then expand: "; printVector(result_1);
  std::cout << "priority queue: "; printVector(result_2);
  std::cout << "two pointer::search raw: "; printVector(result_3);
  std::cout << "linear solution: "; printVector(result_4);

  return 0;
}
