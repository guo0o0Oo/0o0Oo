#include<bits/stdc++.h>
using namespace std;
string s;
int n;

// 数字转字符
char digitToChar(int num) {
    if (num < 10) return '0' + num;
    else return 'A' + (num - 10);
}

// 字符转数字
int charToDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    else if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    return 0;  // 默认返回0
}

string removeLeadingZeros(const string& num) {
    int start = 0;
    while (start < num.length() - 1 && num[start] == '0') {
        start++;
    }
    return num.substr(start);
}

string add(const string& num1, const string& num2) {
    string a = num1, b = num2;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string result;
    int carry = 0;
    int maxLen = max(a.length(), b.length());
    
    for (int i = 0; i < maxLen; i++) {
        int digitA = (i < a.length()) ? charToDigit(a[i]) : 0;  // 使用charToDigit
        int digitB = (i < b.length()) ? charToDigit(b[i]) : 0;  // 使用charToDigit
        int sum = digitA + digitB + carry;
        result.push_back(digitToChar(sum % n));
        carry = sum / n;
    }
    
    if (carry > 0) {
        result.push_back(digitToChar(carry));  // 不需要取模
    }
    
    reverse(result.begin(), result.end());
    return removeLeadingZeros(result);
}

void add1(){
    string x = s;
    reverse(x.begin(), x.end());
    s = add(s, x);
}

bool check(){
    string x = s;
    reverse(x.begin(), x.end());
    return s == x;
}

int main(){
    cin >> n >> s;
    for(int i = 0; i <= 30; i++){
        if(check()){
            cout << "STEP=" << i << endl;
            return 0;
        }
        add1();
    }
    cout << "Impossible!" << endl;
    return 0;
}
