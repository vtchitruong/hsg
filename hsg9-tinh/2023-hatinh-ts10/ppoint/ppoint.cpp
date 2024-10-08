#include <iostream>
#include <vector>
#include <algorithm>

#define inputFile "ppoint.inp"
#define outputFile "ppoint.out"

using namespace std;

struct point
{
    int x;
    int m;
};

int n;
vector<point> P;
int min_len = INT_MAX; // độ dài nhỏ nhất cần tìm

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(inputFile, "r", stdin);

    cin >> n;
    P.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> P[i].x >> P[i].m;
    }
}


// Hàm so sánh dùng để sắp xếp theo toạ độ
bool compare(const point& a, const point& b)
{
    return a.x < b.x;
}


void process()
{
    // Sắp xếp mảng P theo thứ tự toạ độ tăng dần
    sort(P.begin(), P.end(), compare);

    // Khởi tạo toạ độ cuối cùng tìm thấy các màu
    int last_green = -1;
    int last_red = -1;
    int last_yellow = -1;

    int min_pos;
    int max_pos;

    // Duyệt mảng P
    for (int i = 0; i < n; ++i)
    {
        // Ghi nhận toạ độ mới khi tìm thấy màu
        if (P[i].m == 1)
            last_green = P[i].x;
        else if (P[i].m == 2)
            last_red = P[i].x;
        else if (P[i].m == 3) 
            last_yellow = P[i].x;

        // Nếu đã tìm thấy đủ ba toạ độ
        // thì tính độ dài đoạn thẳng
        if (last_green != -1)
            if (last_red != -1)
                if (last_yellow != -1)
                {
                    min_pos = min({last_green, last_red, last_yellow});
                    max_pos = max({last_green, last_red, last_yellow});
                    min_len = min(min_len, max_pos - min_pos);
                }
    }
} 


void output()
{
    freopen(outputFile, "w", stdout);

    if (min_len == INT_MAX)
        cout << -1;
    else
        cout << min_len;
}


int main()
{
    input();
    process();
    output();

    return 0;
}