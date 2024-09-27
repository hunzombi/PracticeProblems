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
    in >> C;
    in >> K;

    if (C == 1)
    {
        for (int KK=0; KK < K; KK++)
        {
            in >> S >> T;
            for (int i=0; i < S; i++)
            {
                in >> c;
                if (countS[c] == 0)
                {
                    chars.push_back(c);
                }
                countS[c]++;
            }
            for (int i=0; i < T; i++)
            {
                in >> c;
                if (countS[c] == 0 && countT[c] == 0)
                {
                    chars.push_back(c);
                }
                countT[c]++;
            }
            sort(chars.begin(), chars.end());
            out << chars.size() << '\n';
            for (int i=0; i < chars.size(); i++)
            {
                c = chars[i];
                if (countS[c] > countT[c])
                {
                    out << c << " S\n";
                }
                else
                {
                    out << c << " T\n";
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
            in >> S >> T;
            for (int i=0; i < S; i++)
            {
                in >> c;
                if (countS[c] == 0)
                {
                    chars.push_back(c);
                }
                countS[c]++;
            }
            for (int i=0; i < T; i++)
            {
                in >> c;
                if (countS[c] == 0 && countT[c] == 0)
                {
                    chars.push_back(c);
                }
                countT[c]++;
            }
            sort(chars.begin(), chars.end());
            for (int i=0; i < chars.size(); i++)
            {
                c = chars[i];
                if (countS[c] < countT[c])
                {
                    out << "NU" << '\n';
                    return 0;
                }
                countS[c] = 0;
                countT[c] = 0;
            }
            out << "DA" << '\n';
            chars.clear();
        }
    }

    return 0;
}
