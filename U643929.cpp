#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

// 交易参数
struct TradeParams {
    int n;                      // 股票池大小
    int D;                      // 交易日总数
    double m;                   // 初始现金
    int L;                      // 交易最小单位（手）
    double alpha;               // 手续费率
    double com_min;             // 最低佣金
    double beta;                // 印花税率
    int K_max;                  // 单日委托上限
};

// 股票日行情数据
struct StockData {
    string date;                // 交易日
    string code;                // 股票代码
    double open;                // 开盘价
    double high;                // 最高价
    double low;                 // 最低价
    double close;               // 收盘价
    long long volume;           // 成交量（股）
    double amount;              // 成交额（元）
    double amplitude;           // 振幅（%）
    double pct_chg;             // 涨跌幅（%）
    double change;              // 涨跌额（元）
    double turnover;            // 换手率（%）
};

// 持仓信息
struct Position {
    string code;                // 股票代码
    int quantity;               // 持仓数量（股）
    double avg_cost;            // 平均成本
};

class TradingSystem {
private:
    TradeParams params;
    vector<string> stock_codes;
    map<string, StockData> current_market;  // 当前市场数据
    map<string, Position> portfolio;        // 持仓
    double cash;                            // 当前现金
    int current_day;                        // 当前交易日
    
public:
    TradingSystem() : cash(0), current_day(0) {}
    
    // 读取初始化参数
    void readInitParams() {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string init_flag;
        ss >> init_flag;
        
        if (init_flag != "INIT") {
            cerr << "Error: Expected INIT but got " << init_flag << endl;
            exit(1);
        }
        
        ss >> params.n >> params.D >> params.m >> params.L 
           >> params.alpha >> params.com_min >> params.beta >> params.K_max;
        
        cash = params.m;
    }
    
    // 解析一行行情数据
    StockData parseStockData(const string& line) {
        StockData data;
        stringstream ss(line);
        string token;
        
        // 根据实际情况调整分隔符
        // 假设是逗号分隔
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        
        if (tokens.size() >= 12) {
            data.date = tokens[0];
            data.code = tokens[1];
            data.open = stod(tokens[2]);
            data.high = stod(tokens[3]);
            data.low = stod(tokens[4]);
            data.close = stod(tokens[5]);
            data.volume = stoll(tokens[6]);
            data.amount = stod(tokens[7]);
            data.amplitude = stod(tokens[8]);
            data.pct_chg = stod(tokens[9]);
            data.change = stod(tokens[10]);
            data.turnover = stod(tokens[11]);
        }
        
        return data;
    }
    
    // 读取基准日数据
    void readDay0Data() {
        stock_codes.clear();
        current_market.clear();
        
        for (int i = 0; i < params.n; i++) {
            string line;
            getline(cin, line);
            StockData data = parseStockData(line);
            stock_codes.push_back(data.code);
            current_market[data.code] = data;
        }
        current_day = 0;
    }
    
    // 读取每日行情数据
    void readDailyData() {
        current_market.clear();
        
        for (int i = 0; i < params.n; i++) {
            string line;
            getline(cin, line);
            StockData data = parseStockData(line);
            current_market[data.code] = data;
        }
        current_day++;
    }
    
    // 计算手续费
    double calculateCommission(double transaction_value) {
        double commission = transaction_value * params.alpha;
        return max(commission, params.com_min);
    }
    
    // 执行买入委托
    bool executeBuyOrder(const string& code, int qty, double price) {
        // 检查是否为最小单位的整数倍
        if (qty % params.L != 0) {
            cerr << "Error: Quantity " << qty << " is not multiple of " << params.L << endl;
            return false;
        }
        
        // 计算交易金额和手续费
        double transaction_value = qty * price;
        double commission = calculateCommission(transaction_value);
        double total_cost = transaction_value + commission;
        
        // 检查现金是否足够
        if (cash < total_cost) {
            // 现金不足，交易失败
            return false;
        }
        
        // 更新现金
        cash -= total_cost;
        
        // 更新持仓
        if (portfolio.find(code) == portfolio.end()) {
            // 新持仓
            Position pos;
            pos.code = code;
            pos.quantity = qty;
            pos.avg_cost = (transaction_value + commission) / qty;
            portfolio[code] = pos;
        } else {
            // 已有持仓，更新平均成本
            Position& pos = portfolio[code];
            double old_value = pos.quantity * pos.avg_cost;
            double new_value = transaction_value + commission;
            pos.avg_cost = (old_value + new_value) / (pos.quantity + qty);
            pos.quantity += qty;
        }
        
        return true;
    }
    
    // 执行卖出委托
    bool executeSellOrder(const string& code, int qty, double price) {
        // 检查是否为最小单位的整数倍
        if (qty % params.L != 0) {
            cerr << "Error: Quantity " << qty << " is not multiple of " << params.L << endl;
            return false;
        }
        
        // 检查持仓是否足够
        if (portfolio.find(code) == portfolio.end() || portfolio[code].quantity < qty) {
            // 持仓不足，交易失败
            return false;
        }
        
        // 计算交易金额、手续费和印花税
        double transaction_value = qty * price;
        double commission = calculateCommission(transaction_value);
        double stamp_tax = transaction_value * params.beta;
        double total_receivable = transaction_value - commission - stamp_tax;
        
        // 更新现金
        cash += total_receivable;
        
        // 更新持仓
        Position& pos = portfolio[code];
        pos.quantity -= qty;
        if (pos.quantity == 0) {
            portfolio.erase(code);
        }
        
        return true;
    }
    
    // 计算当前总资产
    double calculateTotalAssets() {
        double total = cash;
        
        // 计算持仓市值（使用当前收盘价）
        for (const auto& pair : portfolio) {
            const string& code = pair.first;
            const Position& pos = pair.second;
            
            if (current_market.find(code) != current_market.end()) {
                double current_price = current_market[code].close;
                total += pos.quantity * current_price;
            }
        }
        
        return total;
    }
    
    // 输出委托
    void submitOrder(const string& order_type, const string& code, int qty) {
        cout << order_type << " " << code << " " << qty << endl;
    }
    
    // 提交委托完成
    void submitDone() {
        cout << "DONE" << endl;
        fflush(stdout);
    }
    
    // 你的交易策略 - 需要在这里实现你的算法
    void tradingStrategy() {
        // 示例策略：简单的均值回归策略
        // 这只是一个示例，你需要实现自己的交易策略
        
        vector<pair<string, double>> signals;
        
        for (const auto& pair : current_market) {
            const StockData& data = pair.second;
            
            // 简单示例：如果昨日跌幅超过5%，今日买入
            if (data.pct_chg < -10.0) {
                signals.push_back({data.code, -data.pct_chg});  // 跌幅越大，信号越强
            }
            
            // 简单示例：如果昨日涨幅超过5%，且持有该股票，考虑卖出
            if (data.pct_chg > 10.0 && portfolio.find(data.code) != portfolio.end()) {
                // 可以考虑卖出部分或全部持仓
            }
        }
        
        // 按信号强度排序
        sort(signals.begin(), signals.end(), 
             [](const pair<string, double>& a, const pair<string, double>& b) {
                 return a.second > b.second;
             });
        
        // 限制委托数量
        int max_orders = min(params.K_max, (int)signals.size());
        
        // 生成买入委托
        for (int i = 0; i < max_orders; i++) {
            const string& code = signals[i].first;
            // 计算买入数量：使用可用现金的一部分
            double available_cash_per_stock = cash / max_orders;  // 每只股票用10%的现金
            double price = current_market[code].close;  // 使用收盘价作为参考
            
            if (price > 0) {
                int qty = (int)(available_cash_per_stock / price / params.L) * params.L;
                qty = max(qty, params.L);  // 至少买1手
                
                if (qty >= params.L && cash > qty * price * 1.001) {  // 考虑手续费
                    submitOrder("BUY", code, qty);
                }
            }
        }
        
        // 检查是否需要卖出持仓
        for (const auto& pair : portfolio) {
            const string& code = pair.first;
            const Position& pos = pair.second;
            
            if (current_market.find(code) != current_market.end()) {
                const StockData& data = current_market[code];
                
                // 简单示例：如果股票上涨超过10%，卖出
                double current_price = data.close;
                double profit_rate = (current_price - pos.avg_cost) / pos.avg_cost;
                
                if (profit_rate > 0.3) {  // 盈利超过10%
                    // 卖出所有持仓
                    submitOrder("SELL", code, pos.quantity);
                }
            }
        }
    }
    
    // 主要运行函数
    void run() {
        // 步骤1：读取初始化参数
        readInitParams();
        
        // 步骤2：读取基准日数据
        readDay0Data();
        
        // 主循环
        for (int day = 1; day <= params.D; day++) {
            // 生成委托（使用前一天的行情）
            tradingStrategy();
            
            // 提交委托
            submitDone();
            
            // 读取当天的行情数据
            if (day < params.D) {
                readDailyData();
            } else {
                // 最后一天的特殊处理
                readDailyData();
                
                // 最后一天收盘前可以再提交一次委托
                tradingStrategy();
                submitDone();
            }
        }
        
    }
};

int main() {
    // 设置浮点数输出格式
    cout << fixed << setprecision(2);
    
    TradingSystem system;
    system.run();
    
    return 0;
}
