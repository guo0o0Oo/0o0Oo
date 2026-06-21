#include<bits/stdc++.h>
using namespace std;

string maxn, sum;
struct node {
    string l;
    string r;
} dc[1010];

// 比较两个字符串表示的数字大小
int compare(string num1, string num2) {
    if (num1.length() != num2.length()) {
        return num1.length() > num2.length() ? 1 : -1;
    }
    return num1.compare(num2);
}

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0);
    
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum_val = mul + result[i + j + 1];
            result[i + j + 1] = sum_val % 10;
            result[i + j] += sum_val / 10;
        }
    }
    
    string res;
    for (int num : result) {
        if (!(res.empty() && num == 0)) {
            res.push_back(num + '0');
        }
    }
    
    return res.empty() ? "0" : res;
}

string subtract(string num1, string num2) {
    int len1 = num1.length(), len2 = num2.length();
    string result;
    int borrow = 0;
    
    for (int i = 0; i < len1; i++) {
        int digit1 = num1[len1 - 1 - i] - '0';
        int digit2 = i < len2 ? num2[len2 - 1 - i] - '0' : 0;
        
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.push_back(diff + '0');
    }
    
    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// 高精度除法，返回商
string divide(string dividend, string divisor) {
    if (divisor == "0") {
        throw invalid_argument("Division by zero");
    }
    
    if (compare(dividend, divisor) < 0) {
        return "0";
    }
    
    if (divisor == "1") {
        return dividend;
    }
    
    string quotient;
    string current;
    int index = 0;
    int len = dividend.length();
    
    while (index < len) {
        current.push_back(dividend[index]);
        index++;
        
        while (current.length() > 1 && current[0] == '0') {
            current.erase(0, 1);
        }
        
        if (compare(current, divisor) < 0) {
            quotient.push_back('0');
            continue;
        }
        
        int digit = 0;
        for (int i = 9; i >= 1; i--) {
            string multiple = to_string(i);
            string temp = multiply(divisor, multiple);
            
            if (compare(temp, current) <= 0) {
                digit = i;
                current = subtract(current, temp);
                break;
            }
        }
        
        quotient.push_back(digit + '0');
    }
    
    size_t start = quotient.find_first_not_of('0');
    if (start != string::npos) {
        quotient = quotient.substr(start);
    } else {
        quotient = "0";
    }
    
    return quotient;
}

bool cmp(node a, node b) {
    string productA = multiply(a.l, a.r);
    string productB = multiply(b.l, b.r);
    return compare(productA, productB) < 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> dc[i].l >> dc[i].r;
    }
    sum = dc[0].l;
    maxn = "0";
    sort(dc + 1, dc + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        string current_gold = divide(sum, dc[i].r);
        if (compare(current_gold, maxn) > 0) {
            maxn = current_gold;
        }
        sum = multiply(sum, dc[i].l);
    }
    cout << maxn;
    return 0;
}
