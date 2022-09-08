
#include <iostream>
using namespace std;

int main()
{
    int ans, n, i=1;
    cin >> ans >> n;

    while (i<=n)
    {
        int guess, copy = ans, a=0, b=0;

        cin >> guess;

        // A = ? 相同的位置上跟自己一不一樣
        // 1536
        // 1234

        // B = ? 答案裡有自己，但是位置不一樣
        // 1536
        // 2345

        // 1234 1536
        // 123 153
        // 12 15
        // 1 1
        // 0 0
        while (guess > 0)
        {
            if ((guess%10) == (ans%10) || (guess%10) == (ans/10%10)
                || (guess%10) == (ans/100%10) || (guess%10) == (ans/1000%10))
            {
                b++;
            }
            if ((guess%10) == (copy%10))
            {
                a++;
                b--;
            }
            guess /= 10;
            copy /= 10;
        }
        i++;

        cout << a << ' ' << b << endl;
    }
}

/*
2 % 10 = 5
2345 /= 10, 234
234 % 10 = 4
*/