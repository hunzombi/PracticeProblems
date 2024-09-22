#include <bits/stdc++.h>
using namespace std;

ifstream in("ferma.in");
ofstream out("ferma.out");

int V, N, M;
char matrix[402][402];
bool sz[402][402];
int sizematrix[402][402];
int max1;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

pair<int, int> temp;

queue<pair<int, int> > q;

void emptysz(){
    for (int i=1; i <= N; i++){
        for (int j=1; j <= M; j++){
            sz[i][j] = false;
        }
    }
}

int loo2(int y, int x){

    vector<pair<int, int> > coordinates(0);
    int area = 0;
    char value = matrix[y][x];

    while (!q.empty()){
        q.pop();
    }
    q.push({y, x});
    while (!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        if (sz[y][x]){
            continue;
        }
        sz[y][x] = true;
        coordinates.push_back({y, x});
        area++;

        for (int i=0; i < 4; i++){
            if (matrix[y+dy[i]][x+dx[i]] == value && !sz[y+dy[i]][x+dx[i]]){
                q.push({y+dy[i], x+dx[i]});
            }
        }
    }
    return area;
}

int loo(int y, int x){

    vector<pair<int, int> > coordinates(0);

    int area = 0;
    char value = matrix[y][x];

    while (!q.empty()){
        q.pop();
    }
    q.push({y, x});
    while (!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        if (sz[y][x]){
            continue;
        }
        sz[y][x] = true;
        coordinates.push_back({y, x});
        area++;

        for (int i=0; i < 4; i++){
            if (matrix[y+dy[i]][x+dx[i]] == value && !sz[y+dy[i]][x+dx[i]]){
                q.push({y+dy[i], x+dx[i]});
            }
        }
    }
    for (int i=0; i < coordinates.size(); i++){
        y = coordinates[i].first;
        x = coordinates[i].second;
        sizematrix[y][x] = area;
    }

    return area;
}

int main()
{
    in >> V;
    in >> N >> M;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            in >> matrix[i][j];
        }
    }

    if (V == 1)
    {
        for (int i=1;  i <= N; i++)
        {
            for (int j=1; j <= M; j++)
            {
                if (sz[i][j]){continue;}
                int v1 = loo(i, j);
                if (v1 > max1)
                {
                    max1 = v1;
                }
            }
        }
        out << max1;
    }
    else {
        for (int i=1;  i <= N; i++)
        {
            for (int j=1; j <= M; j++)
            {
                if (sz[i][j]){continue;}
                int v1 = loo(i, j);
            }
        }

        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};

        int max2 = 0;
        char maxv = 0;
        int mx = 0; int my = 0;
        emptysz();

        for (int i=1; i <= N; i++){
            for (int j=1; j <= M; j++){
                char df = matrix[i][j];
                for (int l=0; l < 4; l++){
                    matrix[i][j] = matrix[i+di[l]][j+dj[l]];
                    if (matrix[i][j] == 0){
                        continue;
                    }
                    int v2 = loo2(i, j);
                    if (v2 > max2){
                        maxv = matrix[i][j];
                        max2 = v2;
                        mx = j;
                        my = i;
                    }
                }
                matrix[i][j] = df;
            }
        }
        out << my << ' ' << mx << '\n';
        out << maxv << '\n';

    }


    return 0;
}
