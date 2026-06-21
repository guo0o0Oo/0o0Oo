#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Station {
    double distance; // 距离起点的距离
    double price;    // 油价
    Station(double d = 0, double p = 0) : distance(d), price(p) {}
};

int main() {
    double S, C, L, P0;
    int N;
    cin >> S >> C >> L >> P0 >> N;
    
    vector<Station> stations;
    stations.push_back(Station(0.0, P0)); // 起点作为第0个加油站
    
    for (int i = 0; i < N; i++) {
        double d, p;
        cin >> d >> p;
        stations.push_back(Station(d, p));
    }
    stations.push_back(Station(S, 0.0)); // 终点，油价为0（不能加油）
    
    // 按距离排序
    sort(stations.begin(), stations.end(), 
         [](const Station& a, const Station& b) {
             return a.distance < b.distance;
         });
    
    int n = stations.size(); // 包括起点和终点
    double maxDist = C * L;   // 满油能行驶的距离
    double curGas = 0.0;      // 当前油量（升）
    double totalCost = 0.0;
    int cur = 0;              // 当前所在加油站索引
    
    // 检查相邻加油站距离是否超过油箱容量能行驶的距离
    for (int i = 0; i < n - 1; i++) {
        if (stations[i + 1].distance - stations[i].distance > maxDist + 1e-9) {
            cout << "No Solution" << endl;
            return 0;
        }
    }
    
    while (cur < n - 1) {  // 还未到达终点
        int next = -1;
        double minPrice = 1e9;
        int cheaperStation = -1;
        
        // 在当前油箱容量允许的范围内寻找加油站
        for (int i = cur + 1; i < n; i++) {
            if (stations[i].distance - stations[cur].distance > maxDist + 1e-9) {
                break;  // 超出油箱容量能到达的范围
            }
            
            // 记录范围内的最低油价（不包括当前站）
            if (stations[i].price < minPrice) {
                minPrice = stations[i].price;
                next = i;  // 暂时记录为最便宜站
            }
            
            // 如果找到第一个比当前站便宜的加油站，就选它
            if (stations[i].price < stations[cur].price) {
                cheaperStation = i;
                break;
            }
        }
        
        if (next == -1) {  // 没有找到可达的加油站，理论上不会发生（前面已检查）
            cout << "No Solution" << endl;
            return 0;
        }
        
        // 如果有更便宜的加油站，直接去最近的更便宜的加油站
        if (cheaperStation != -1) {
            next = cheaperStation;
        }
        
        double needDist = stations[next].distance - stations[cur].distance;
        double needGas = needDist / L;  // 需要的油量（升）
        
        if (needGas <= curGas) {
            // 当前油量足够，不用加油
            curGas -= needGas;
            cur = next;
            continue;
        }
        
        // 需要加油
        double addGas = needGas - curGas;  // 需要加的油
        
        if (cheaperStation != -1) {
            // 前方有更便宜的加油站，只加到刚好到那里
            totalCost += addGas * stations[cur].price;
            curGas = 0;  // 到达下一个站时刚好用完
        } else {
            // 前方没有更便宜的，在当前站加满
            addGas = C - curGas;
            totalCost += addGas * stations[cur].price;
            curGas = C - needGas;  // 到达下一个站后剩余的油
        }
        
        cur = next;
    }
    
    // 输出结果，四舍五入到两位小数
    cout << fixed << setprecision(2) << totalCost << endl;
    
    return 0;
}
