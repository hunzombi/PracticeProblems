#include <bits/stdc++.h>

using namespace std;

ifstream in("poseidon.in");
ofstream out("poseidon.out");

long long C, N, M;

long long matrix[1002][1002];
bool sz[1002][1002];

long long derangements[1001];

vector<long long> islands;
queue<pair<long long, long long> > q;

long long derange(long long x){
    if (x == 1){
        return 0;
    }
    if (x == 2){
        return 1;
    }
    if (derangements[x] != 0){
        return derangements[x];
    }
    long long der = (x-1)*(derange(x-1)+derange(x-2));

    derangements[x] = der;
    return der;
}

long long lee(long long a, long long b){
    while (!q.empty()){
        q.pop();
    }
    long long tres = 0;
    q.push({a, b});
    while (!q.empty()){
        long long y = q.front().first;
        long long x = q.front().second;
        q.pop();
        if (sz[y][x]){
            continue;
        }
        if (matrix[y][x] > 1){
            tres++;
        }
        sz[y][x] = true;

        long long dy[] = {-1, 1, 0, 0};
        long long dx[] = {0, 0, -1, 1};

        for (long long i=0; i < 4; i++){
            if (!sz[y+dy[i]][x+dx[i]] && matrix[y+dy[i]][x+dx[i]] > 0){
                q.push({y+dy[i], x+dx[i]});
            }
        }
    }
    if (tres > 0){
        islands.push_back(tres);
    }
    return tres;
}

int main()
{
    derangements[1] = 0;
    derangements[2] = 1;

    in >> C >> N >> M;

    for (long long i=1; i <= N; i++){
        for (long long j=1; j <= M; j++){
            in >> matrix[i][j];
            matrix[i][j]++;
        }
    }

    if (C == 1) // A Poszeidon szigetén lévő kincsesládák száma
    {
        long long p1, p2;
        in >> p1 >> p2;

        out << lee(p1, p2);
    }
    else // Hány féle képpen lehet elhelyezni a ládákat úgy, hogy minden láda a saját szigetén maradjon, de ne a saját helyén
    {

        for (long long i=1; i <= N; i++) //////////////// Counting the number of chests on each island
        {
            for (long long j=1; j <= M; j++)
            {
                if (!sz[i][j]){
                    lee(i, j);
                }
            }
        }

        long long result = 1;
        for (long long i=0; i < islands.size(); i++)
        {
            result *= derange(islands[i]);
            result %= 1000000007;
        }

        out << result << '\n';
    }

    return 0;
}
