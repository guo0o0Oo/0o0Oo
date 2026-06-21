#include <bits/stdc++.h>
using namespace std;
string subtract(const string& num1, const string& num2);
// 辅助函数：比较两个非负数字符串的大小
bool greaterOrEqual(const string& a, const string& b) {
    if (a.length() != b.length()) 
        return a.length() > b.length();
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) 
            return a[i] > b[i];
    }
    return true; // 相等
}

// 辅助函数：移除前导零
string removeLeadingZeros(const string& num) {
    int start = 0;
    while (start < num.length() - 1 && num[start] == '0') {
        start++;
    }
    return num.substr(start);
}
// 高精度加法
string add(const string& num1, const string& num2) {
    // 处理负数情况
    if (num1[0] == '-' && num2[0] == '-') {
        return "-" + add(num1.substr(1), num2.substr(1));
    }
    if (num1[0] == '-') {
        // -a + b = b - a
        string a = num1.substr(1);
        string b = num2;
        return subtract(num2, num1.substr(1));
    }
    if (num2[0] == '-') {
        // a + (-b) = a - b
        string a = num1;
        string b = num2.substr(1);
        return subtract(num1, num2.substr(1));
    }

    string a = num1, b = num2;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string result;
    int carry = 0;
    int maxLen = max(a.length(), b.length());
    
    for (int i = 0; i < maxLen; i++) {
        int digitA = (i < a.length()) ? (a[i] - '0') : 0;
        int digitB = (i < b.length()) ? (b[i] - '0') : 0;
        int sum = digitA + digitB + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    
    if (carry > 0) {
        result.push_back(carry + '0');
    }
    
    reverse(result.begin(), result.end());
    return removeLeadingZeros(result);
}

// 高精度减法（完整版）
string subtract(const string& num1, const string& num2) {
    // 处理符号
    bool num1_neg = (num1[0] == '-');
    bool num2_neg = (num2[0] == '-');
    string a = num1_neg ? num1.substr(1) : num1;
    string b = num2_neg ? num2.substr(1) : num2;
    
    // 移除前导零
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    // 情况1: 正数 - 正数
    if (!num1_neg && !num2_neg) {
        if (greaterOrEqual(a, b)) {
            // a >= b
            string result;
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            
            int borrow = 0;
            for (int i = 0; i < a.length(); i++) {
                int digitA = (a[i] - '0') - borrow;
                int digitB = (i < b.length()) ? (b[i] - '0') : 0;
                
                if (digitA < digitB) {
                    digitA += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                
                result.push_back((digitA - digitB) + '0');
            }
            
            // 移除结果中的前导零
            while (result.length() > 1 && result.back() == '0') {
                result.pop_back();
            }
            
            reverse(result.begin(), result.end());
            return removeLeadingZeros(result);
        } else {
            // a < b
            return "-" + subtract(b, a);
        }
    }
    // 情况2: 负数 - 负数 = -a - (-b) = b - a
    else if (num1_neg && num2_neg) {
        return subtract(b, a); // b - a
    }
    // 情况3: 负数 - 正数 = -(a + b)
    else if (num1_neg && !num2_neg) {
        return "-" + add(a, b);
    }
    // 情况4: 正数 - 负数 = a + b
    else {
        return add(a, b);
    }
}

// 高精度乘法
string multiply(const string& num1, const string& num2) {
    // 处理符号
    bool negative = false;
    string a = num1, b = num2;
    
    if (a[0] == '-') {
        negative = !negative;
        a = a.substr(1);
    }
    if (b[0] == '-') {
        negative = !negative;
        b = b.substr(1);
    }
    
    // 移除前导零
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    // 处理乘数为0的情况
    if (a == "0" || b == "0") {
        return "0";
    }
    
    int lenA = a.length();
    int lenB = b.length();
    vector<int> result(lenA + lenB, 0);
    
    // 从低位到高位相乘
    for (int i = lenA - 1; i >= 0; i--) {
        for (int j = lenB - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];
            
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    // 转换为字符串
    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }
    
    // 添加符号
    if (negative && product != "0") {
        product = "-" + product;
    }
    
    return product.empty() ? "0" : product;
}

// 高精度除法（返回商）
string divide(const string& num1, const string& num2) {
    // 处理符号
    bool negative = false;
    string a = num1, b = num2;
    
    if (a[0] == '-') {
        negative = !negative;
        a = a.substr(1);
    }
    if (b[0] == '-') {
        negative = !negative;
        b = b.substr(1);
    }
    
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    // 除数为0的情况
    if (b == "0") {
        throw runtime_error("Division by zero!");
    }
    
    // 被除数为0或者被除数小于除数
    if (a == "0" || !greaterOrEqual(a, b)) {
        return "0";
    }
    
    string quotient;
    string current;
    
    for (char digit : a) {
        current.push_back(digit);
        current = removeLeadingZeros(current);
        
        int count = 0;
        while (greaterOrEqual(current, b)) {
            // 模拟减法 current - b
            string temp_a = current;
            string temp_b = b;
            reverse(temp_a.begin(), temp_a.end());
            reverse(temp_b.begin(), temp_b.end());
            
            int borrow = 0;
            string new_current;
            for (int i = 0; i < temp_a.length(); i++) {
                int digitA = (temp_a[i] - '0') - borrow;
                int digitB = (i < temp_b.length()) ? (temp_b[i] - '0') : 0;
                
                if (digitA < digitB) {
                    digitA += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                
                new_current.push_back((digitA - digitB) + '0');
            }
            
            // 移除结果中的前导零
            while (new_current.length() > 1 && new_current.back() == '0') {
                new_current.pop_back();
            }
            
            reverse(new_current.begin(), new_current.end());
            current = removeLeadingZeros(new_current);
            count++;
        }
        
        quotient.push_back(count + '0');
    }
    
    quotient = removeLeadingZeros(quotient);
    
    // 添加符号
    if (negative && quotient != "0") {
        quotient = "-" + quotient;
    }
    
    return quotient;
}

int main() {
    char op;
	string a,b;
	cin>>op>>a>>b;
	switch(op){
		case '+':
			cout<<add(a,b);
			break;
		case '-':
			cout<<subtract(a,b);
			break;
		case '*':
			cout<<multiply(a,b);
			break;
		case '/':
			cout<<divide(a,b);
			break;
	}
    return 0;
}
