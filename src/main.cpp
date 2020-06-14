#include "QuadTree.h"
#include <cstdlib>
#include <iostream>

const double width = 20000.0;
const double height = 20000.0;

const int POINTS = 20000;

double random(double bound) { return bound * (rand() / ((double)RAND_MAX)); }

void overlapping_points(std::vector<Point> &points, QuadTree &t) {
  long count = 0;
  for (auto &p : points) {
    auto others = t.query({p.x, p.y, 5, 5});
    for (auto &other : others) {
      // for (auto &other : points) {
      if (&p != &other) {
        if ((p.x > (other.x - 5)) && (p.x < other.x) && (p.y > (other.y - 5)) &&
            (p.y < other.y)) {
          count++;
        }
      }
    }
  }

  std::cout << "There are " << count << " overlapping points" << std::endl;
}

int main(int argc, char const *argv[]) {
  QuadTree t{width / 2, height / 2, width / 2, height / 2, 4};
  std::vector<Point> points{POINTS};

  for (int i = 0; i < POINTS; i++) {
    Point p{random(1), random(1)};
    t.insert(p);
    points.push_back(p);
  }

  auto founds = t.query(Rectangle{61.0, 95.6, 30.0, 15.1});
  for (auto &p : founds) {
    std::cout << p << std::endl;
  }

  return 0;
}
