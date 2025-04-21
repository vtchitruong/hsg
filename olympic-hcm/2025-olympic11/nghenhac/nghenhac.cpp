#include <iostream>
#include <vector>

#define input_file "nghenhac.inp"
#define output_file "nghenhac.out"

using namespace std;

int n, k;
vector<int> songs;

// số lượng bài hát tối đa cần tìm
int max_count = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> k;

    songs.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> songs[i];
    }
}


void process()
{
    // con trỏ bên trái (con trỏ bắt đầu)
    int left = 0;

    // tổng thời gian của các bài hát trong cửa sổ trượt đang xét
    int current_sum = 0;

    // số lượng bài hát trong cửa sổ trượt đang xét
    int current_count;

    // Duyệt con trỏ bên phải (con trỏ kết thúc)
    for (int right = 0; right < n; ++right)
    {
        // Tính tổng thời gian đang xét
        current_sum += songs[right];

        // Nếu tổng thời gian đang xét vượt quá thời gian cho phép
        while (current_sum > k && left <= right)
        {
            // thì loại bỏ bài hát bên trái
            current_sum -= songs[left];

            // Thu hẹp cửa sổ nhằm làm tổng thời gian hợp lệ trở lại
            left++;
        }

        // Tính số lượng bài hát đang xét
        current_count = right - left + 1;

        // Cập nhật số lượng bài hát tối đa
        max_count = max(max_count, current_count);
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_count;
}


int main()
{
    input();
    process();
    output();

    return 0;
}