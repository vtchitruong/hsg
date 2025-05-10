#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "trienlam.inp"
#define output_file "trienlam.out"

using namespace std;

typedef long long int lli;

struct painting
{
    lli size;
    lli value;
};

const lli INF = -1e18;

int n;
vector<painting> P;

// lợi nhuận lớn nhất cần tìm
lli max_H;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    P.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> P[i].size >> P[i].value;
    }
}


// Hàm so sánh dùng cho hàm sắp xếp tăng dần theo kích thước tranh 
bool compare(const painting& p1, const painting& p2)
{
    return p1.size < p2.size;
}


void process()
{
    // Sắp xếp các tranh theo thứ tự kích thước tăng dần
    sort(P.begin(), P.end(), compare);

    // Tính tổng cộng dồn (prefix sum)
    // Sum[i] là tổng giá trị của các tranh từ 0 đến i - 1
    vector<lli> Sum(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        Sum[i + 1] = Sum[i] + P[i].value;
    }

    // max_H là lợi nhuận tối đa cần tìm
    // Khởi tạo max_H bằng cách chọn tranh đầu tiên
    max_H = P[0].value;

    // Đề bài yêu cầu phải trưng bày ít nhất một tranh
    // nên ta tính lợi nhuận lớn nhất với một tranh duy nhất
    for (int i = 1; i < n; ++i)
    {
        max_H = max(max_H, P[i].value);
    }

    // Khởi tạo giá trị nhỏ nhất
    lli current_min = 0 - P[0].size;

    for (int j = 1; j < n; ++j)
    {
        // Tính lợi nhuận trong đoạn [i..j]
        lli current_H = Sum[j + 1] - P[j].size - current_min;

        max_H = max(max_H, current_H);

        current_min = min(current_min, Sum[j] - P[j].size);
    }

}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_H;
}

int main()
{
    input();
    process();
    output();

    return 0;
}