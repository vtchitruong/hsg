#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "xplore.inp"
#define output_file "xplore.out"

using namespace std;

typedef long long int lli;

const lli INF = 2e18;

int T, N;

vector<lli> positives; // mảng lưu các địa điểm dương
vector<lli> negatives; // mảng lưu các địa điểm âm

// số điểm ghé thăm
int visited_count = 0;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(input_file, "r", stdin);

    cin >> T >> N;

    for (int i = 0; i < N; ++i)
    {
        lli x;
        cin >> x;

        if (x < 0)
        {
            negatives.push_back(x);
        }
        else if (x > 0)
        {
            positives.push_back(x);
        }
        else
        {
            // Nếu 0 là địa điểm thì nó được tính là ghé thâm ngay khi xuất phát
            visited_count++;
        }
    }
}

void process()
{
    // Sắp xếp mảng địa điểm dương tăng dần
    sort(positives.begin(), positives.end());

    // Sắp xếp mảng địa điểm âm giảm dần
    sort(negatives.begin(), negatives.end(), greater<lli>());

    // biến lưu địa điểm hiện đang ghé thăm
    lli current = 0;

    // biến lưu thời gian trôi qua
    lli elapsed_time = 0;

    // hai con trỏ dành cho hai mảng dương và âm
    int p = 0;
    int n = 0;

    // Duyệt từng điểm trong hai mảng dương và âm
    while (p < positives.size() || n < negatives.size())
    {
        // Tính khoảng cách từ current đến hai điểm dương và âm
        lli p_distance = (p < positives.size()) ? abs(positives[p] - current) : INF;
        lli n_distance = (n < negatives.size()) ? abs(negatives[n] - current) : INF;

        // Chọn khoảng cách nhỏ hơn
        if (n_distance <= p_distance)
        {
            if (elapsed_time + n_distance > T)
                break;

            elapsed_time += n_distance;
            current = negatives[n];
            n++;
        }
        else
        {
            if (elapsed_time + p_distance > T)
                break;

            elapsed_time += p_distance;
            current = positives[p];
            p++;
        }

        // Cập nhật số địa điểm ghé thăm
        visited_count++;
    }
}

void output()
{
    freopen(output_file, "w", stdout);

    cout << visited_count;
}

int main()
{
    input();
    process();
    output();

    return 0;
}