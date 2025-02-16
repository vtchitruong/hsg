#include <iostream>

#define input_file "tamgiac.inp"
#define output_file "tamgiac.out"

using namespace std;

struct point
{
    int x, y;
};

point A, B, C, M;

// Số epsilon
const double eps = 1e-9;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> M.x >> M.y;
}


// Hàm dùng để tính diện tích tam giác
double area(point a, point b, point c)
{
    return abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}


void process()
{
    // Tính diện tích tam giác ABC
    double abc = area(A, B, C);

    // Tính diện tích ba tam giác ABM, ACM, BCM
    double abm = area(A, B, M);
    double acm = area(A, C, M);
    double bcm = area(B, C, M);

    freopen(output_file, "w", stdout);

    // Nếu tổng diện tích ba tam giác con bằng diện tích tam giác ABC thì M thuộc tam giác ABC
    if (abs(abc - abm - acm - bcm) < eps)
        cout << 1;
    else
        cout << 0;
}


int main()
{
    input();
    process();

    return 1;
}