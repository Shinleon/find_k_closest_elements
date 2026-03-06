#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

#include "PriorityQueueSolution.h"


namespace PriorityQueueSolution {
  Point::Point(int v, int r) : val(v), ref(r) {}

  bool Point::operator<(const Point& other) const {
    int diff = abs(val - ref) - abs(other.val - other.ref);
    return diff == 0 ? (val < other.val) : (diff < 0);
  }

  int Point::getVal(){
    return this->val;
  }

  std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
    std::priority_queue<Point> queue;
    for(int ele : arr) {
      queue.push(Point(ele, x));
      while(queue.size() > k) {
        queue.pop();
      }
    }
    std::vector<int> result;
    while(!queue.empty()){
      Point p = queue.top();
      result.insert(result.begin(), p.getVal());
      queue.pop();
    }
    std::sort(result.begin(), result.end());
    return result;
  }
}
