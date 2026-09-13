#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
int t, n, m;
double pos[18][2];

void qiu(double &a, double &b, int l, int r) {
    if (fabs(pos[l][0] - pos[r][0]) < eps) {
        a = b = 0;
        return;
    }
    a = (pos[r][0] * pos[l][1] - pos[l][0] * pos[r][1]) / 
        (pos[l][0] * pos[r][0] * (pos[l][0] - pos[r][0]));
    b = (pos[l][0] * pos[l][0] * pos[r][1] - pos[r][0] * pos[r][0] * pos[l][1]) / 
        (pos[l][0] * pos[r][0] * (pos[l][0] - pos[r][0]));
}

bool inc(double a, double b, double x, double y) {
    if (fabs(a) < eps && fabs(b) < eps) return false;
    double calc = a * x * x + b * x;
    return fabs(calc - y) < eps;
}

int dfs(vector<bool> &ic) {
    int first = -1;
    for (int i = 0; i < n; i++) {
        if (!ic[i]) {
            first = i;
            break;
        }
    }
    
    if (first == -1) return 0;
    
    int min_birds = INT_MAX;
    
    for (int j = first + 1; j < n; j++) {
        if (!ic[j]) {
            double a, b;
            qiu(a, b, first, j);
            if (a < -eps || fabs(pos[first][0] - pos[j][0]) < eps) {
                vector<bool> new_ic = ic;
                if (fabs(pos[first][0] - pos[j][0]) < eps) {
                    new_ic[first] = true;
                    min_birds = min(min_birds, 1 + dfs(new_ic));
                } else if (a < -eps) {
                    new_ic[first] = true;
                    new_ic[j] = true;
                    for (int k = 0; k < n; k++) {
                        if (!new_ic[k] && inc(a, b, pos[k][0], pos[k][1])) {
                            new_ic[k] = true;
                        }
                    }
                    min_birds = min(min_birds, 1 + dfs(new_ic));
                }
            }
        }
    }
    
    vector<bool> new_ic = ic;
    new_ic[first] = true;
    min_birds = min(min_birds, 1 + dfs(new_ic));
    
    return min_birds;
}

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &n, &m);
        for (int j = 0; j < n; j++) {
            scanf("%lf%lf", &pos[j][0], &pos[j][1]);
        }
        
        vector<bool> ic(n, false);
        int result = dfs(ic);
        printf("%d\n", result);
    }
    return 0;
}