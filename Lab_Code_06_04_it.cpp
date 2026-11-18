// Lab 6.4.it
// Variant 13

#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>

using namespace std;

void Create(double* a, const int n, const double Low, const double High) {
    for (int i = 0; i < n; i++)
        a[i] = Low + (High - Low) * rand() / RAND_MAX;
}

void Print(const double* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(8) << a[i];
    cout << endl;
}

// 1.1. Кількість елементів зі значеннями в діапазоні [A; B]
int CountInRange(const double* a, const int n, const double A, const double B) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= A && a[i] <= B)
            count++;
    return count;
}

// Індекс першого максимального елемента
int IndexOfMax(const double* a, const int n) {
    int iMax = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[iMax])
            iMax = i;
    return iMax;
}

// 1.2. Сума елементів, розташованих після максимального
double SumAfterMax(const double* a, const int n) {
    double sum = 0;
    for (int i = IndexOfMax(a, n) + 1; i < n; i++)
        sum += a[i];
    return sum;
}

// Індекс елемента з парним індексом (починаючи зі start) з найбільшим модулем
int IndexOfMaxAbsEven(const double* a, const int n, const int start) {
    int iMax = start;
    for (int i = start + 2; i < n; i += 2)
        if (fabs(a[i]) > fabs(a[iMax]))
            iMax = i;
    return iMax;
}

void Swap(double& x, double& y) {
    double t = x;
    x = y;
    y = t;
}

// 2. Впорядкування елементів з парними індексами за спаданням модулів,
// інші елементи залишаються на своїх місцях
void SortEvenByAbsDesc(double* a, const int n) {
    for (int i = 0; i < n; i += 2)
        Swap(a[i], a[IndexOfMaxAbsEven(a, n, i)]);
}

int main() {

    srand((unsigned)time(NULL));

    int n;
    double A, B;
    cout << "n = "; cin >> n;
    cout << "A = "; cin >> A;
    cout << "B = "; cin >> B;
    if (n <= 0) {
        cout << "n must be positive" << endl;
        return 1;
    }

    double* a = new double[n];

    Create(a, n, -50, 50);
    cout << fixed << setprecision(2);
    cout << "Original array: " << endl;
    Print(a, n);
    cout << endl;

    cout << "Count of the elements in [A; B]: " << CountInRange(a, n, A, B) << endl;
    cout << "Sum of the elements after max: " << SumAfterMax(a, n) << endl;

    SortEvenByAbsDesc(a, n);
    cout << endl;
    cout << "Modified array: " << endl;
    Print(a, n);

    delete[] a;
    return 0;
}