#include <vector>
#include <iostream>
namespace BinarySearch {
  std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size()-k;
    // mid = (left+right)/2
    // compute mid edges if they exist
    // if they don't, we can ignore them, we have reached the edge.
    while(left < right) {
      int mid = (left+right/2);
      int l_idx = mid-1; 
      int r_idx = mid+k+1;// [ L: x, x, l_idx: x, M: x, x, r:idx: x, R: x], k = 2
      // if l_idx is closer to target(x) than r_idx is, then we should move search
      // section to the lower area; otherwise, move to upper area;
      break;
    }
    std::vector<int> ret = {1, 2, 3};
    return ret;
  }
}

int main(void) {
  std::cout << "Hello world!" << std::endl;
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int range = 2;
  int target = 7;
  std::vector<int> result = BinarySearch::findClosestElements(arr, range, target);
  return 0;
}
