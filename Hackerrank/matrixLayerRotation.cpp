#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define eb emplace_back
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void rotate(vector <int> &v, int r){
    int sz = v.size();
    r %= sz;
    vector <int> co(sz);
    for(int i = 0; i < sz; ++i){
        co[(i+r)%sz] = v[i];
    }
    v = co;
}

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = 0, numofc = min(n,m)/2, rr = n-1, cc = m-1;
    while(numofc--){
        vector <int> temp;
        auto init = mp(i,j);
        while(init.ff <= rr){
            temp.eb(matrix[init.ff][init.ss]);
            ++init.ff;
        }
        --init.ff;
        ++init.ss;
        while(init.ss <= cc){
            temp.eb(matrix[init.ff][init.ss]);
            ++init.ss;
        }
        --init.ss;
        --init.ff;
        while(init.ff >= n-1-rr){
            temp.eb(matrix[init.ff][init.ss]);
            --init.ff;
        }
        ++init.ff;
        --init.ss;
        while(init.ss > m-1-cc){
            temp.eb(matrix[init.ff][init.ss]);
            --init.ss;
        }
        rotate(temp,r);
        auto pos = 0;
        init = mp(i,j);
        while(init.ff <= rr){
            matrix[init.ff][init.ss] = temp[pos];
            ++pos;
            ++init.ff;
        }
        --init.ff;
        ++init.ss;
        while(init.ss <= cc){
            matrix[init.ff][init.ss] = temp[pos];
            ++init.ss;
            ++pos;
        }
        --init.ss;
        --init.ff;
        while(init.ff >= n-1-rr){
            matrix[init.ff][init.ss] = temp[pos];
            ++pos;
            --init.ff;
        }
        ++init.ff;
        --init.ss;
        while(init.ss > m-1-cc){
            matrix[init.ff][init.ss] = temp[pos];
            ++pos;
            --init.ss;
        }

        ++i;++j;--rr,--cc;
    }
    for(auto &x: matrix) {
        for(auto &y:x) cout << y << " ";
        cout << "\n";
    }
}
