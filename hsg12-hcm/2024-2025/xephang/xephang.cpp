#include <iostream>
#include <vector>

#define input_file "xephang.inp"
#define output_file "xephang.out"

using namespace std;

struct team
{
    int a;
    int b;
    
    // Mặc định a và b đều là 0
    team() : a(0), b(0) {}
};

int n, m;
vector<team> T;
vector<int> R;


// Hàm dùng để so sánh đội T[1] với đội khác
// Trả về True nếu đội khác tốt hơn
bool is_another_team_better(const team& t1, const team& another)
{
    return t1.a < another.a || (t1.a == another.a && t1.b > another.b);
}


// Hàm dùng để xếp hạng đội T[1]
int process()
{
    // Khởi tạo đội T[1] hạng nhất
    int rank = 1;

    // Duyệt từng đội từ 1 đến n
    for (int i = 1; i < n + 1; ++i)
    {
        // Nếu đội T[i] nào đó tốt hơn đội T[1] thì tăng hạng đội T[1]
        if (i != 1 && is_another_team_better(T[1], T[i]))
        {
            rank += 1;
        }
    }

    return rank;
}


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);
    freopen(output_file, "w", stdout);

    cin >> n >> m;

    // Khởi tạo mảng T chứa dữ liệu của n đội
    T.resize(n + 1);

    int team_id, penalty;
    int r;

    // Duyệt từng lượt nộp bài
    for (int i = 0; i < m; ++i)
    {
        // Đọc mã đội và điểm phạt
        cin >> team_id >> penalty;

        // Ghi nhận điểm số và điểm phạt của đội team_id
        T[team_id].a += 1;
        T[team_id].b += penalty;

        // Xếp hạng cho đội T[1]
        r = process();
        R.push_back(r);
    }
}


void output()
{
    freopen(output_file, "w", stdout);
    for (int i = 0; i < m; ++i)
    {
        cout << R[i];      
        if (i != m - 1) cout << '\n';
    }    
}


int main()
{
    input();
    output();

    return 0;
}