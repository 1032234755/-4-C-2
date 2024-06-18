#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

vector<double> kramer(MatrixXd a, VectorXd b) {
    double det_a = a.determinant();
    if (det_a == 0) {
        throw invalid_argument("Определитель матрицы равен нулю, решение невозможно");
    }

    int n = b.size();
    vector<double> x(n);
    for (int i = 0; i < n; ++i) {
        MatrixXd a_copy = a;
        a_copy.col(i) = b;
        x[i] = a_copy.determinant() / det_a;
    }

    return x;
}

int main() {
    MatrixXd a(3, 3);
    a << 5, 3, -2,
        2, 1, -1,
        3, -2, -3;

    VectorXd b(3);
    b << -1, 0, 2;

    vector<double> solution = kramer(a, b);

    cout << "Решение методом Крамера: ";
    for (double x : solution) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
