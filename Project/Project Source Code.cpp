#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class PolygonTriangulation {
private:
    int n;
    Point* points;
    double dp[100][100];
    int split[100][100];


    double distance(const Point &p1, const Point &p2) {
        return hypot(p1.x - p2.x, p1.y - p2.y);
    }

    double trianglePerimeter(const Point &p1, const Point &p2, const Point &p3) {
        return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
    }

public:
    PolygonTriangulation(int n, Point* points) : n(n), points(points) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = 0;
                split[i][j] = -1;
            }
        }
    }

    double computeOptimalTriangulation() {
        int i,j;
        for (int len = 2; len < n; ++len) {
            for ( i = 0; i + len < n; ++i) {
                 j = i + len;
                dp[i][j] = numeric_limits<double>::infinity();
                for (int k = i + 1; k < j; ++k) {
                    double cost = dp[i][k] + dp[k][j] +
                    trianglePerimeter(points[i], points[k], points[j]);
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
            cout<<endl;
            printDPTable();
        }
        return dp[0][n - 1];
    }

    void printTriangulation(int i, int j) {
        if (j <= i + 1) {
            return;
        }

        int k = split[i][j];
        cout << "Triangle: (" << i << ", " << k << ", " << j << ")\n";

        // Recurse on left and right sub-polygons
        printTriangulation(i, k);
        printTriangulation(k, j);
    }

    void printDPTable() {
        cout << "DP Table:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j) {
                    cout << setw(8) << (dp[i][j] == numeric_limits<double>::infinity() ? 0 : dp[i][j]) << " ";
                } else {
                    cout << setw(8) << "0" << " "; // Lower triangle is not used
                }
            }
            cout << "\n";
        }
        cout<<endl;
        cout << "DP Table:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j) {
                    cout << setw(8) << (split[i][j] == numeric_limits<double>::infinity() ? 0 : split[i][j]) << " ";
                } else {
                    cout << setw(8) << "0" << " "; // Lower triangle is not used
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices in the polygon: ";
    cin >> n;

    Point* points = new Point[n];
    cout << "Enter the coordinates of the vertices (x y):\n";
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    PolygonTriangulation pt(n, points);

    double minCost = pt.computeOptimalTriangulation();

    cout << fixed << setprecision(2);
    cout << "Minimum cost of triangulation: " << minCost << "\n";
    cout << "Optimal triangulation steps:\n";
    pt.printTriangulation(0, n - 1);

    cout << "\n\nDP Table:\n";
    pt.printDPTable();

    delete[] points;

    return 0;
}
