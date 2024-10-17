#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "picture.inp"
#define output_file "picture.out"

using namespace std;

int n, m;
vector<pair<int, int>> pictures; // bức tranh
vector<int> frames; // khung tranh

// Biến cnt dùng để đếm số bức tranh đặt vào khung
int cnt = 0;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> m;

    pictures.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> pictures[i].first >> pictures[i].second;
    }

    int x;
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        frames.push_back(x);
    }
}


void process()
{
    // Sắp xếp các bức tranh theo kích thước tăng dần
    // Nếu cùng kích thước thì sắp xếp theo giá trị tăng dần
    sort(pictures.begin(), pictures.end());

    // Sắp xếp các khung tranh theo kích thước tăng dần
    sort(frames.begin(), frames.end());

    // Biến i dùng để duyệt các bức tranh
    int i = 0;

    // Giá trị của bức tranh đặt vào khung trước đó
    int previous_value = 0;

    // Duyệt các khung tranh
    for (int j = 0; j < m; ++j)
    {
        // Duyệt các bức tranh có kích thước phù hợp với khung
        while (i < n && pictures[i].first <= frames[j])
        {
            // Nếu tìm thấy bức tranh thoả về kích thước lẫn giá trị
            if (pictures[i].second >= previous_value)
            {
                // Đặt tranh vào khung
                cnt += 1;

                // Lưu giá trị của bức tranh vừa đặt vào khung
                previous_value = pictures[i].second;

                // Xét bức tranh tiếp theo
                i += 1;

                // Ngắt vòng lặp while để xét khung tranh tiếp theo
                break;
            }

            // Xét bức tranh tiếp theo
            i += 1;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);
    cout << cnt;

}

int main()
{
    input();
    process();
    output();

    return 0;
}