#include <bits/stdc++.h>
using namespace std;

ifstream in("ferma.in");
ofstream out("ferma.out");

//constants
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

//utility
queue<pair<int, int> > q;
set<int> types, nums;

//variables
int C, N, M;
char matrix[402][402];
int numbering[402][402];
bool volt[402][402];
int sizes[160000], chars[160000], result[160000];
int num;

int lee(int x, int y, int num);
std::pair<int, char> next_to(int x, int y);

int main()
{
    cin >> C;
    cin >> N >> M;

    for (int i=1; i <= N; i++){
        for (int j=1; j <= M; j++){
            cin >> matrix[i][j];
        }
    }

    // 1. SubProblem
    int max1 = 0;

    for (int i=1; i <= N; i++)
    {
        for (int j=1; j <= M; j++)
        {
            if (!volt[i][j])
            {

                int v = lee(i, j, num);
                sizes[num] = v;
                chars[num] = matrix[i][j];
                num++;

                if (v > max1){ max1 = v;}

            }
        }
    }
    if (C == 1)
    {
        cout << max1 << '\n';
    }
    else // 2. SubProblem
    {

        int max2 = 0;
        char max_val = matrix[1][1];
        pair<int, int> coords = {1, 1};

        for (int i=1; i <= N; i++)
        {
            for (int j=1; j <= M; j++)
            {
                pair<int, char> res = next_to(i, j);
                int res_int = res.first;
                char res_char = res.second;
                if (res_int > max2)
                {
                    max2 = res_int;
                    max_val = res_char;
                    coords = {i, j};
                }
            }
        }

        cout << coords.first << ' ' <<  coords.second << '\n';
        cout << max_val << '\n';
    }

    return 0;
}

// ---------------------------- FUNCTIONS ----------------------------

int lee(int x, int y, int num){

    queue<pair<int, int> >().swap(q);

    q.push({x, y});

    int area = 0;

    while (!q.empty())
    {
        pair<int, int> tmp = q.front();

        q.pop();

        x = tmp.first; y = tmp.second;

        for (int k=0; k < 4; k++)
        {
            int new_x = x + dx[k]; int new_y = y + dy[k];

            if (matrix[new_x][new_y] == matrix[x][y] && !volt[new_x][new_y] && matrix[new_x][new_y] != 0)
            {

                volt[new_x][new_y] = true;
                q.push({new_x, new_y});

                numbering[new_x][new_y] = num;
                area++;

            }
        }
    }

    return area;

}

// -------------------------------------

std::pair<int, char> next_to(int x, int y)
{
    set<int>().swap(types);
    set<int>().swap(nums);

    int val = matrix[x][y];

    int maximum = sizes[numbering[x][y]];
    char maxchar = val;

    for (int k=0; k < 4; k++)
    {
        int new_x = x + dx[k]; int new_y = y + dy[k];

        if (matrix[new_x][new_y] == val)
        {
            continue;
        }

        types.insert(matrix[new_x][new_y]);
        nums.insert(numbering[new_x][new_y]);
    }

    for (int number : nums)
    {
        result[chars[number]] += sizes[number];
        cout << number << ' ' << result[chars[number]] << "\n";
        if (result[chars[number]] + 1 > maximum )
        {
            maximum = result[chars[number]] + 1;
            maxchar = chars[number];
        }
    }

    for (int type : types)
    {
        result[type] = 0;
    }

    return {maximum, maxchar};
}

/*
2
3 3
rkr
rrk
rro
*/
