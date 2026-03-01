#include <iostream>
#include <vector>

#define input_file "river.inp"
#define output_file "river.out"

using namespace std;

string river;

// số lần vượt sông ít nhất
int result;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);
    cin >> river;
    river = '0' + river;
}

void process()
{
    int n = river.size();

    // Khởi tạo vị trí xuất phát
    int current_left = 0;
    int current_right = 1;

    // Duyệt từng nhánh sông từ 1 đến n - 1
    for (int i = 1; i < n; ++i)
    {
        // Khởi tạo biến tạm
        int next_left = 0;
        int next_right = 0;

        if (river[i] == 'L')
        {
            next_left = min(current_left + 1, current_right + 1);
            next_right = min(current_left + 1, current_right);
        }
        else if (river[i] == 'R')
        {
            next_left = min(current_left, current_right + 1);
            next_right = min(current_left + 1, current_right + 1);
        }
        else if (river[i] == 'B')
        {
            next_left = min(current_left + 1, current_right + 2);
            next_right = min(current_left + 2, current_right + 1);
        }

        // Cập nhật current để chuẩn bị cho lần lặp tiếp theo
        current_left = next_left;
        current_right = next_right;
    }

    // Bước cuối cùng để đến nhà ngoại
    result = min(current_left + 1, current_right);
}

void output()
{
    freopen(output_file, "w", stdout);
    cout << result;
}

int main()
{
    input();
    process();
    output();

    return 0;
}