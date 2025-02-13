#include <cmath>
#include <iomanip>
#include <iostream>

/*
 Heron:    S = sqrt(p(p-a)(p-b)(p-c)) | p = (a+b+c)/2
 Shoelace: S = 1/2 * abs(x1​(y2​−y3​)+x2​(y3​−y1​)+x3​(y1​−y2​))
*/

using namespace std;

struct point {
  double x{}, y{};
};

namespace heron {
double two_point_length(point M, point N) {
  return sqrt((N.x - M.x) * (N.x - M.x) + (N.y - M.y) * (N.y - M.y));
}

double area(point A, point B, point C) {
  double AB{two_point_length(A, B)};
  double BC{two_point_length(B, C)};
  double AC{two_point_length(A, C)};

  double p{(AB + BC + AC) / 2.0};

  return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}
}  // namespace heron

namespace shoelace {
double area(point A, point B, point C) {
  return 0.5 * fabs((A.x * (B.y - C.y)) + (B.x * (C.y - A.y)) + (C.x * (A.y - B.y)));
}
}  // namespace shoelace

int main() {
  point A{}, B{}, C{};
  cout << "A(x,y) = ";
  cin >> A.x >> A.y;
  cout << "B(x,y) = ";
  cin >> B.x >> B.y;
  cout << "C(x,y) = ";
  cin >> C.x >> C.y;

  cout << fixed;
  cout << setprecision(9);
  cout << "Heron:    S = " << heron::area(A, B, C) << '\n';
  cout << "Shoelace: S = " << shoelace::area(A, B, C) << '\n';

  return 0;
}
