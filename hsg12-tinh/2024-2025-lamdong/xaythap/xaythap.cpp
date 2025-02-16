#include <iostream>
#include <vector>
#include <algorithm>

#define input_file "xaythap.inp"
#define output_file "xaythap.out"

using namespace std;

struct gift
{
    int r, color;
};

int n;
vector<gift> G;

// Biến D dùng để lưu tổng số hộp quà
// D[i][c] là tổng số hộp quà nhiều nhất, trong đó hộp quà có chỉ số i nằm trên cùng và có màu c
vector<vector<int>> D;

int max_gift = 0;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> n;

    G.resize(n);

    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;

        G[i].r = abs(x);
        G[i].color = x > 0 ? 1 : 0;
    }
}


void process()
{
    // Sắp xếp hộp quà theo thứ tự độ rộng giảm dần
    sort(G.begin(), G.end(), [](const gift& a, const gift& b)
    {
        return a.r > b.r;
    });

    // Khởi tạo D với n phần tử
    D.resize(n, vector<int>(2, 0));

    // Duyệt từng hộp quà i
    for (int i = 0; i < n; ++i)
    {
        // Màu của hộp quà i
        int color_of_i = G[i].color;
        
        // Nếu chọn hộp quà i thì số hộp quà nhiều nhất tại vị trí i là 1
        D[i][color_of_i] = 1;
        
        // Duyệt từng hộp quà j trước đó
        for (int j = 0; j < i; ++j)
        {
            // Nếu hộp quà j có độ rộng nhỏ hơn hộp quà i và màu của hộp quà j khác màu của hộp quà i
            if (G[i].r < G[j].r)
                if (G[j].color != color_of_i)
                {
                    // thì cập nhật số hộp quà nhiều nhất tại vị trí i
                    D[i][color_of_i] = max(D[i][color_of_i], D[j][1 - color_of_i] + 1);
                }
        }

        // Nếu số hộp quà nhiều nhất tại vị trí i lớn hơn max_gift thì cập nhật max_gift
        max_gift = max(max_gift, D[i][color_of_i]);
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << max_gift;
}


int main()
{
    input();
    process();
    output();

    return 0;

}