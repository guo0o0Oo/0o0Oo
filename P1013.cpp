/*#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
string table[20][20];
int n,num[20],ic[20]={};
bool br=0;

bool check(){
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			int k=0;
			for(int ii=0;ii<table[i][j].size();ii++){
				k*=n-1;
				k+=num[m[table[i][j][ii]]];
			}
			if(k!=num[i]+num[j]){
				return 0;
			}
		}
	}
	return 1;
}

void dfs(int k){
	if(br)return ;
	if(k==n+1){
		br=check();
		return ;
	}
	for(int i=0;i<n-1;i++){
		if(!ic[i]){
			num[k]=i;
			ic[i]=1;
			dfs(k+1);
			ic[i]=0;
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>table[i][j];
			if(table[i][j].size()>2){
				cout<<"ERROR!"<<"\n";
				return 0;
			}
			if(i==0){
				m[table[i][j][0]]=j;
			}
		}
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<num[i]<<" ";
	}
} 
*/
#include<bits/stdc++.h>
using namespace std;

map<char, int> m;           // 字符到索引的映射
int charIndex[256];         // 字符对应的值
string table[10][10];       // 存储加法表
int n, value[10];           // value[i] 表示第i个字符的值
bool used[10] = {false};    // 数字是否被使用
bool found = false;         // 是否找到解
vector<char> chars;         // 按顺序存储字符（第一行的字符顺序）

// 将字符串转换为数字值
int strToNum(const string& s) {
    int res = 0;
    for(char c : s) {
        res = res * (n-1) + value[m[c]];
    }
    return res;
}

// 检查当前赋值是否合法
bool check() {
    // 检查所有加法是否成立
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            int left = value[i] + value[j];      // 左边：两个数的和
            int right = strToNum(table[i][j]);   // 右边：字符串表示的值
            
            // 检查是否相等（注意是在n-1进制下）
            if(left >= n-1 || right != left) {
                return false;
            }
        }
    }
    return true;
}

// 深度优先搜索，为每个字符分配数字
void dfs(int idx) {
    if(found) return;
    
    if(idx == n) {  // 所有字符都分配了值
        if(check()) {
            found = true;
        }
        return;
    }
    
    // 尝试为第idx个字符分配0到n-2的数字
    for(int num = 0; num < n-1; num++) {
        if(!used[num]) {
            // 第一个非加号字符不能是0（题目要求？实际上可以是0）
            // 根据样例，第一个字符L是0
            value[idx] = num;
            used[num] = true;
            dfs(idx + 1);
            if(found) return;
            used[num] = false;
        }
    }
}

int main() {
    cin >> n;
    
    // 读取加法表
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }
    
    // 建立字符映射（第一行，从第二列开始）
    for(int j = 1; j < n; j++) {
        char c = table[0][j][0];
        m[c] = j;                   // 字符c对应索引j
        chars.push_back(c);         // 按顺序存储字符
    }
    
    // 第一个字符（通常是加号）不需要处理
    // 从索引1开始深度优先搜索（第一个实际字符）
    dfs(1);
    
    if(found) {
        // 第一行输出：按字符顺序输出 L=0 K=1 ...
        for(int i = 0; i < n-1; i++) {
            cout << chars[i] << "=" << value[i+1];
            if(i < n-2) cout << " ";
        }
        cout << endl;
        
        // 第二行输出：进制
        cout << n-1 << endl;
    } else {
        cout << "ERROR!" << endl;
    }
    
    return 0;
}
