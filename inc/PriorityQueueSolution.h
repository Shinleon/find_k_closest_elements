
#ifndef PRIORITYQUEUESOLUTION
#define PRIORITYQUEUESOLUTION

namespace PriorityQueueSolution {
class Point {
private:
  int val;
  int ref;
public:
  Point(int v, int r);
  bool operator<(const Point& other) const;
  int getVal();
};
  std::vector<int> findClosestElements(std::vector<int>&arr, int k, int x);
}

#endif
