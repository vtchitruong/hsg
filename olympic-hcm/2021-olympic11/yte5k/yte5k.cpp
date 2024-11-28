#include <iostream>
#include <vector>
#include <set>

#define input_file "yte5k.inp"
#define output_file "yte5k.out"

using namespace std;

// Số lượng ghế, số lượng sự kiện
int n, m;

// Mảng lưu các sự kiện V hoặc R
vector<char> events;

// Mảng lưu giá trị x đi kèm với loại sự kiện R
// event_index[i] = x nghĩa là sự kiện x được đính kèm với sự kiện i
vector<int> event_index;

// Tập hợp lưu số thứ tự của ghế, dùng để đánh dấu đã có người ngồi
set<int> occupied_chairs;

// Mảng lưu ánh xạ sự kiện và ghế được chọn
// event_chair[i] = c nghĩa là tại sự kiện i, ghế c được chọn ngồi
vector<int> event_chair;

// Mảng lưu số thứ tự ghế, dùng để output
vector<int> result;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n >> m;

    events.resize(m + 1, 0);
    event_index.resize(m + 1, 0);

    for (int i = 1; i < m + 1; ++i)
    {
        cin >> events[i];

        // Nếu gặp loại sự kiện R
        if (events[i] == 'R')
        {
            // thì lưu số đi kèm
            cin >> event_index[i];
        } 
    }
}


void process()
{
    // Khởi tạo giá trị 0 cho toàn bộ mảng ánh xạ sự kiện - ghế
    event_chair.resize(m + 1, 0);

    // Người đầu tiên vào khu vực chờ sẽ luôn chọn ghế số 1
    // Ghế 1 được chọn cho sự kiện 1
    event_chair[1] = 1;

    // Đánh dấu ghế 1 đã có người ngồi
    occupied_chairs.insert(1);

    // Nạp vào mảng result để output
    result.push_back(1);

    // Duyệt từng sự kiện i trong phạm vi [2..m]
    for (int i = 2; i < m + 1; ++i)
    {
        // Nếu sự kiện i thuộc loại V
        if (events[i] == 'V')
        {
            // Biến tạm lưu ghế được chọn
            int selected_chair = -1;

            // Khoảng cách lớn nhất trong số các khoảng cách gần nhất
            int max_distance = -1;

            // Duyệt từng ghế (đã có lẫn chưa có người ngồi)
            for (int c = 1; c < n + 1; ++c)
            {
                // Nếu ghế c đã có người ngồi thì bỏ qua, xét ghế c tiếp theo
                if (occupied_chairs.count(c) == 1) continue;

                // nearest là khoảng cách gần nhất từ ghế c đến các ghế đã có người ngồi 
                int nearest = INT_MAX;
                
                // Duyệt từng ghế oc đã có người ngồi
                for (int oc : occupied_chairs)
                {
                    // Tính khoảng cách gần nhất từ ghế c đến các ghế oc
                    nearest = min(nearest, abs(c - oc));
                }

                // Nếu khoảng cách đến ghế gần nhất là lớn nhất
                if (nearest > max_distance)
                {
                    // thì lưu giá trị lớn nhất mới
                    max_distance = nearest;

                    // và chọn ghế c
                    selected_chair = c;
                }
                // Nếu các khoảng cách gần nhất đều là lớn nhất
                else if (nearest == max_distance && c < selected_chair)
                {
                    // thì chọn ghế có số nhỏ nhất
                    selected_chair = c;
                }
            }

            // Đánh dấu đã có người ngồi cho ghế selected_chair
            occupied_chairs.insert(selected_chair);

            // Lưu ghế đã chọn ứng với sự kiện i
            event_chair[i] = selected_chair;

            // Nạp vào mảng result để output
            result.push_back(selected_chair);
        }
        // Nếu sự kiện i thuộc loại R
        else if (events[i] == 'R')
        {
            // Lấy sự kiện x
            int x = event_index[i];

            // Lấy số ghế của sự kiện x
            int chair_to_free = event_chair[x];
            
            // Bỏ đánh dấu đã có nguòi ngồi
            occupied_chairs.erase(chair_to_free);

            // Đặt lại trạng thái ghế của sự kiện
            event_chair[x] = 0;
        }
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    for (int chair : result)
    {
        cout << chair << '\n';
    }
}


int main()
{
    input();
    process();
    output();

    return 0;
}