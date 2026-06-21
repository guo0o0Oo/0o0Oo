#include <bits/stdc++.h>
using namespace std;
string subtract(const string& num1, const string& num2);
// �����������Ƚ������Ǹ����ַ����Ĵ�С
bool greaterOrEqual(const string& a, const string& b) {
    if (a.length() != b.length()) 
        return a.length() > b.length();
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) 
            return a[i] > b[i];
    }
    return true; // ���
}

// �����������Ƴ�ǰ����
string removeLeadingZeros(const string& num) {
    int start = 0;
    while (start < num.length() - 1 && num[start] == '0') {
        start++;
    }
    return num.substr(start);
}
// �߾��ȼӷ�
string add(const string& num1, const string& num2) {
    // �����������
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

// �߾��ȼ����������棩
string subtract(const string& num1, const string& num2) {
    // ��������
    bool num1_neg = (num1[0] == '-');
    bool num2_neg = (num2[0] == '-');
    string a = num1_neg ? num1.substr(1) : num1;
    string b = num2_neg ? num2.substr(1) : num2;
    
    // �Ƴ�ǰ����
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    // ���1: ���� - ����
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
            
            // �Ƴ�����е�ǰ����
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
    // ���2: ���� - ���� = -a - (-b) = b - a
    else if (num1_neg && num2_neg) {
        return subtract(b, a); // b - a
    }
    // ���3: ���� - ���� = -(a + b)
    else if (num1_neg && !num2_neg) {
        return "-" + add(a, b);
    }
    // ���4: ���� - ���� = a + b
    else {
        return add(a, b);
    }
}

// �߾��ȳ˷�
string multiply(const string& num1, const string& num2) {
    // ��������
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
    
    // �Ƴ�ǰ����
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    // ��������Ϊ0�����
    if (a == "0" || b == "0") {
        return "0";
    }
    
    int lenA = a.length();
    int lenB = b.length();
    vector<int> result(lenA + lenB, 0);
    
    // �ӵ�λ����λ���
    for (int i = lenA - 1; i >= 0; i--) {
        for (int j = lenB - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];
            
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    // ת��Ϊ�ַ���
    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }
    
    // ���ӷ���
    if (negative && product != "0") {
        product = "-" + product;
    }
    
    return product.empty() ? "0" : product;
}

// �߾��ȳ����������̣�
string divide(const string& num1, const string& num2) {
    // ��������
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
    
    // ����Ϊ0�����
    if (b == "0") {
        throw runtime_error("Division by zero!");
    }
    
    // ������Ϊ0���߱�����С�ڳ���
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
            // ģ����� current - b
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
            
            // �Ƴ�����е�ǰ����
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
    
    // ���ӷ���
    if (negative && quotient != "0") {
        quotient = "-" + quotient;
    }
    
    return quotient;
}

// 高精度取余（求余数）
string modulo(const string& num1, const string& num2) {
    // 处理符号
    bool num1_neg = (num1[0] == '-');
    bool num2_neg = (num2[0] == '-');
    string a = num1_neg ? num1.substr(1) : num1;
    string b = num2_neg ? num2.substr(1) : num2;
    
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    
    // 除数为0的情况
    if (b == "0") {
        throw runtime_error("Modulo by zero!");
    }
    
    // 被除数为0
    if (a == "0") {
        return "0";
    }
    
    // 模拟除法过程求余数
    string current;
    
    for (char digit : a) {
        current.push_back(digit);
        current = removeLeadingZeros(current);
        
        while (greaterOrEqual(current, b)) {
            // 模拟 current - b
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
        }
    }
    
    // current 就是余数
    if (current.empty() || current == "0") {
        return "0";
    }
    
    // 处理符号：余数的符号通常与被除数相同
    if (num1_neg) {
        current = "-" + current;
    }
    
    return current;
}

int main() {
    char op;
	string a,b;
	cin>>a>>b;
    cout<<add(a,b)<<"\n";
    cout<<subtract(a,b)<<"\n";
    cout<<multiply(a,b)<<"\n";
    cout<<divide(a,b)<<"\n";
    cout<<modulo(a,b)<<"\n";
    return 0;
}
