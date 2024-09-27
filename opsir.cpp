#include <bits/stdc++.h>

using namespace std;

ifstream in("opsir.in");
ofstream out("opsir.out");

// Utility

int countT[255], countS[255];
vector<int> chars;
char c;

// Variables
int C;
int K;
int S, T;

int main()
{
    cin >> C;
    cin >> K;

    if (C == 1)
    {
        for (int KK=0; KK < K; KK++)
        {
            cin >> S >> T;
            for (int i=0; i < S; i++)
            {
                cin >> c;
                if (countS[c] == 0)
                {
                    chars.push_back(c);
                }
                countS[c]++;
            }
            for (int i=0; i < T; i++)
            {
                cin >> c;
                if (countS[c] == 0 && countT[c] == 0)
                {
                    chars.push_back(c);
                }
                countT[c]++;
            }
            sort(chars.begin(), chars.end());
            cout << chars.size() << '\n';
            for (int i=0; i < chars.size(); i++)
            {
                c = chars[i];
                if (countS[c] > countT[c])
                {
                    cout << c << " S\n";
                }
                else
                {
                    cout << c << " T\n";
                }
                countS[c] = 0;
                countT[c] = 0;
            }
            chars.clear();
        }
    }
    else // Case 2
    {
        for (int KK=0; KK < K; KK++)
        {
            cin >> S >> T;
            for (int i=0; i < S; i++)
            {
                cin >> c;
                if (countS[c] == 0)
                {
                    chars.push_back(c);
                }
                countS[c]++;
            }
            for (int i=0; i < T; i++)
            {
                cin >> c;
                if (countS[c] == 0 && countT[c] == 0)
                {
                    chars.push_back(c);
                }
                countT[c]++;
            }
            sort(chars.begin(), chars.end());
            bool cant = false;
            for (int i=0; i < chars.size(); i++)
            {
                c = chars[i];
                if (countS[c] > countT[c])
                {
                    cout << "NU" << '\n';
                    cant = true;
                    break;
                }
                countS[c] = 0;
                countT[c] = 0;
            }
            if (!cant){
                cout << "DA" << '\n';
            }
            chars.clear();
        }
    }

    return 0;
}
