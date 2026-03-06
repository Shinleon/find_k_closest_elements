#include <vector>
#include "LinearSolution.h"

namespace LinearSolution {
  std::vector<int> findClosestElements(std::vector<int>&arr, int k, int x){
    std::vector<int> ret;
    int left = 0;
    int right = arr.size()-1;
    for(int i = 0; i < arr.size() - k; i++) {
      if(abs(arr[right]-x) < abs(arr[left]-x)) {
        left++;
      } else {
        right--;
      }
    }
    for(int i = 0; i < k; i++) {
      ret.push_back(arr[left]);
      left++;
    }
    return ret;
  }
}
