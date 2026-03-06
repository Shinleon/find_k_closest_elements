#include <vector>
#include <cstdlib>
#include <deque>

#include "TwoPointerSolution.h"

namespace TwoPointerSolution {
int findIndexOfClosestElement(std::vector<int>& arr, int target) {
    int index = 0;
    int left = 0;
    int right = arr.size() - 1;
    int mid;
    while(right - left > 1) {
      mid = (right+left)/2;
      if(arr[mid] > target) {
        right = mid;
      } else if (arr[mid] < target) {
        left = mid;
      } else {
        index = mid;
        break;
      }
    }
    int left_diff = std::abs(arr[left] - target);
    int right_diff = std::abs(arr[right] - target);
    index = left_diff <= right_diff ? left : right;
    return index;
  } 


  std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
    int index = findIndexOfClosestElement(arr, x);
    std::deque<int> result_deque;
    int left = index - 1;
    int right = index + 1;
    result_deque.push_front(arr[index]);
    k--;
    while(k > 0) {
      // check if left and right exist;
      if(left < 0){
        // add only right elements;
        while(k > 0) {
          result_deque.push_back(arr[right]);
          right++;
          k--;
        }
        break;
      } else if (right >= arr.size()){
        // add only left elements;
        while (k > 0) {
          result_deque.push_front(arr[left]);
          left--;
          k--;
        }
        break;
      } else {
        // check distance of left and right elements and pick the lesser of the two
        // decrement k by one
        int left_diff = std::abs(arr[left] - x);
        int right_diff = std::abs(arr[right] - x);
        if (left_diff <= right_diff) {
          result_deque.push_front(arr[left]);
          left--;
          k--;
        } else {
          result_deque.push_back(arr[right]);
          right++;
          k--;
        }
      }
    }
    std::vector<int> result_vector;
    while(result_deque.size() > 0) {
      result_vector.push_back(result_deque.front());
      result_deque.pop_front();
    }
    return result_vector;
  }
}
