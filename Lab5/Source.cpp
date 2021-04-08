#define _CRT_SECURE_NO_WARNINGS
#define mp make_pair
#define ll long long
#define pb push_back
#define pii pair< int , int >
#define pll pair< ll, ll>
#define all(x) begin(x), end(x)
//#pragma GCC optimize("O3")
//#pragma comment(linker, "/STACK:100000000000") 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <stack>
#include <math.h>
#include <fstream>
#include <time.h>

using namespace std;
const int SIZE = 500001;
const int INF = (int)1e9 + 7;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

vector< vector <double> > val(10, vector<double>(10, 0));
vector< vector <double> > cost(10, vector<double>(10, 0));
vector< vector <int> > pred(10, vector<int>(10, 0));

int main()
{
    pred[0][0] = -1;
    int n, m;
    cin >> n >> m;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            val[i][j] = (1 + cos((2 * 3.14 * i) / 10) + j);
            //cin >> val[i][j];
        }
    }
    cout.precision(5);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {       
            cout << fixed << val[i][j] << " "s;
        }
        cout << endl;
    }

    cost[0][0] = val[0][0];
    for (int c = 1; c < n; ++c)
    {
        cost[0][c] = cost[0][c - 1] + val[0][c];
        pred[0][c] = 1;
    }
    for (int r = 1; r < n; ++r)
    {
        cost[r][0] = cost[r - 1][0] + val[r][0];
        pred[r][0] = 0;
        for (int c = 1; c < m; ++c)
        {
            if (cost[r - 1][c] < cost[r][c - 1])
            {
                cost[r][c] = val[r][c] + cost[r - 1][c];
                pred[r][c] = 0;
            }
            else
            {
                cost[r][c] = val[r][c] + cost[r][c - 1];
                pred[r][c] = 1;
            }
        }
    }

    cout << "Total cost: "s << cost[n-1][m-1] << endl;
    int r = n-1, c = m-1;
    vector<pii> vp;
    cout << "x y"s << endl;
    for (;;)
    {
        vp.push_back({ c,r });
        if (pred[r][c]) --c;
        else --r;
        if (r == 0 && c == 0)
        {
            cout << "0 0"s << endl;
            break;
        }
    }
    reverse(vp.begin(), vp.end());
    for (auto& i : vp) {
        cout << i.first << " "s << i.second << endl;
    }
    return 0;
}