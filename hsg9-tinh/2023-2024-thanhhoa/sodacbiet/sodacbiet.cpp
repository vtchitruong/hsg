#include <iostream>
#include <set>

#define input_file "sodacbiet.inp"
#define output_file "sodacbiet.out"

using namespace std;

typedef long long int lli;

int a, b;
lli number_of_special_numbers = 0;


void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(input_file, "r", stdin);

    cin >> a >> b;
}


// Hàm dùng để kiểm tra đối xứng
bool is_palindrome(int n)
{
    // Số có một chữ số thì luôn đối xứng
    if (n <10) return true;

    // Số có hàng đơn vị là 0 thì không đối xứng
    if (n % 10 == 0) return false;

    // biến lưu số ban đầu và số đảo ngược
    int original = n;
    int reversed = 0;

    int digit;
    while (n > 0)
    {
        // Lấy ra chữ số hàng đơn vị
        digit = n % 10;

        // Ghép vào đầu của số đảo ngược
        reversed = reversed * 10 + digit;

        n /= 10;
    }

    return original == reversed;
}


// Hàm đếm số lượng ước nguyên tố khác nhau của number
int count_prime(int number)
{
    if (number == 1) return 0;

    // biến lưu các thừa số nguyên tố khác nhau
    set<int> factors;

    int n = number;

    // Kiểm tra 2 có phải là ước không
    if (n % 2 == 0)
    {
        factors.insert(2);

        while (n % 2 == 0)
        {
            n /= 2;
        }
    }

    // Kiểm tra các ước số lẻ từ 3 trở đi
    for (int i = 3; i * i < n + 1; i += 2)
    {
        if (n % i == 0)
        {
            factors.insert(i);

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    // Sau khi chia, nếu n vẫn lớn hơn 2 thì n là một ước nguyên tố
    if (n > 2)
    {
        factors.insert(n);
    }

    return factors.size();
}


void process()
{
    // Duyệt từng số từ a đến b
    for (int i = a; i < b + 1; ++i)
    {
        if (is_palindrome(i))
            if (count_prime(i) >= 3)
                number_of_special_numbers += i;
    }
}


void output()
{
    freopen(output_file, "w", stdout);

    cout << number_of_special_numbers;
}


int main()
{
    input();
    process();
    output();

    return 0;
}