#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#include "PriorityQueueSolution.h"


namespace PriorityQueueSolution {
  class Point {
  private:
    int val;
    int ref;
  public:
    Point(int v, int r);
    bool operator<(const Point& other) const;
    int getVal() const;
  };
  Point::Point(int v, int r) : val(v), ref(r) {}

  bool Point::operator<(const Point& other) const {
    int diff = abs(val - ref) - abs(other.val - other.ref);
    return diff == 0 ? (val < other.val) : (diff < 0);
  }

  int Point::getVal() const{
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
    std::deque<int> bef_result;
    std::vector<int> result;
    int pop_wrap = 0;
    while(!queue.empty()){
      int p = queue.top().getVal();
      if (p < x) {
        result.push_back(p);
      } else {
        bef_result.push_front(p);
        pop_wrap++;
      }
      queue.pop();
    }
    for(int i = 0; i < pop_wrap; i++) { 
      result.push_back(bef_result.front());
      bef_result.pop_front();
    }
    return result;
  }
}
