#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int b[MAXN],add[MAXN],serial[MAXN],n,k,q;
pair<int,int> a[MAXN];
struct Info{
	int min_l,min_r,max_l,max_r,max_n,min_n;
	const Info operator + (const Info& data){
		return {min(min_l,data.min_l),min(min_r,data.min_r),max(max_l,data.max_l),max(max_r,data.max_r),max(max_n,data.max_n),min(min_n,data.min_n)};
	}
	static Info e(){
		return {INT_MAX,INT_MAX,INT_MIN,INT_MIN,INT_MIN,INT_MAX};
	}
};
struct SEG{
	struct Node{
		int l,r;
		Info info;
	}t[MAXN<<2];
	void raise(int k){
		t[k].info=t[k*2].info+t[k*2+1].info;
	}
	void build(int k,int l,int r){
		if(l==r){
			t[k]={l,r,{a[l].first+add[l-1],a[l].first+add[l+1],a[l].first+add[l-1],a[l].first+add[l+1],a[l].first+add[l],a[l].first+add[l]}};
			if(r==n){
				t[k].info.max_r=INT_MIN;
				t[k].info.min_r=INT_MAX;
			}
			if(l==1){
				t[k].info.max_l=INT_MIN;
				t[k].info.min_l=INT_MAX;
			}
			return ;
		}
		t[k].l=l;t[k].r=r;
		int mid=(l+r)>>1;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
		raise(k);
	}
	Info search(int k,int l,int r){
		if(l>r||r>n||l<1||t[k].r<l||t[k].l>r)return Info::e();
		if(t[k].l>=l&&t[k].r<=r)return t[k].info;
		return search(k*2,l,r)+search(k*2+1,l,r);
	}
}seg;
bool cmp(pair<int,int> l,pair<int,int> r){
	return l>r;
}
int half(int value,bool direction){
	if(direction){//最后一个比value大的位置 向右移 
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r+1)>>1;
			if(a[mid].first<value){
				r=mid-1;
			}
			else{
				l=mid;
			}
		}
		return l;
	}
	else{//第一个比value小的位置 向左移 
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(a[mid].first>=value){
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		return r;
	}
}
void solve(int rank,int value){
	int pos,maxn,minn;
	if(value<=a[rank].first){
		pos=half(value,1);
		maxn=max(seg.search(1,rank+1,pos).max_l,value+add[pos]);
		maxn=max(maxn,seg.search(1,1,rank-1).max_n);
		maxn=max(maxn,seg.search(1,pos+1,n).max_n);
		minn=min(seg.search(1,rank+1,pos).min_l,value+add[pos]);
		minn=min(minn,seg.search(1,1,rank-1).min_n);
		minn=min(minn,seg.search(1,pos+1,n).min_n);
		cout<<maxn-minn<<endl;
	}
	else{
		pos=half(value,0);
		maxn=max(seg.search(1,pos,rank-1).max_r,value+add[pos]);
		maxn=max(maxn,seg.search(1,1,pos-1).max_n);
		maxn=max(maxn,seg.search(1,rank+1,n).max_n);
		minn=min(seg.search(1,pos,rank-1).min_r,value+add[pos]);
		minn=min(minn,seg.search(1,1,pos-1).min_n);
		minn=min(minn,seg.search(1,rank+1,n).min_n);
		cout<<maxn-minn<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		serial[a[i].second]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
	}
	int len=1;
	for(int i=1;i<=k;i++){
		cin>>add[len];
		for(int j=1;j<b[i];j++){
			add[len+j]=add[len];
		}
		len+=b[i];
	}
	sort(add+1,add+1+n);
	seg.build(1,1,n);
	int x,v;
	for(int i=1;i<=q;i++){
		cin>>x>>v;
		solve(serial[x],v);
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
const int INF = INT_MAX;
const int NEG_INF = INT_MIN;

int b[MAXN], add[MAXN], serial[MAXN], n, k, q;
pair<int, int> a[MAXN];

struct Info {
    int min_l, min_r, max_l, max_r, max_n, min_n;
    
    Info operator + (const Info& other) const {
        return {
            min(min_l, other.min_l),
            min(min_r, other.min_r),
            max(max_l, other.max_l),
            max(max_r, other.max_r),
            max(max_n, other.max_n),
            min(min_n, other.min_n)
        };
    }
    
    static Info identity() {
        return {INF, INF, NEG_INF, NEG_INF, NEG_INF, INF};
    }
};

class SegmentTree {
private:
    struct Node {
        int l, r;
        Info info;
    } tree[MAXN << 2];
    
    void pushUp(int k) {
        tree[k].info = tree[k * 2].info + tree[k * 2 + 1].info;
    }
    
public:
    void build(int k, int l, int r) {
        tree[k].l = l;
        tree[k].r = r;
        
        if (l == r) {
            int base_val = a[l].first + add[l];
            tree[k].info = {
                a[l].first + add[l - 1],  // min_l
                a[l].first + add[l + 1],  // min_r  
                a[l].first + add[l - 1],  // max_l
                a[l].first + add[l + 1],  // max_r
                base_val,                 // max_n
                base_val                  // min_n
            };
            
            // 边界处理
            if (r == n) {
                tree[k].info.max_r = NEG_INF;
                tree[k].info.min_r = INF;
            }
            if (l == 1) {
                tree[k].info.max_l = NEG_INF;
                tree[k].info.min_l = INF;
            }
            return;
        }
        
        int mid = (l + r) >> 1;
        build(k * 2, l, mid);
        build(k * 2 + 1, mid + 1, r);
        pushUp(k);
    }
    
    Info query(int k, int l, int r) {
        if (l > r || r > n || l < 1 || tree[k].r < l || tree[k].l > r) {
            return Info::identity();
        }
        if (tree[k].l >= l && tree[k].r <= r) {
            return tree[k].info;
        }
        return query(k * 2, l, r) + query(k * 2 + 1, l, r);
    }
};

SegmentTree seg;

// 预计算二分查找边界
vector<int> precomputeBoundaries() {
    vector<int> boundaries(n + 2);
    // 这里可以根据实际需求预计算一些常用边界
    return boundaries;
}

int findLastGreater(int value) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid].first < value) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}

int findFirstLess(int value) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid].first >= value) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r;
}

void processQuery(int rank, int value) {
    int pos, max_val, min_val;
    
    if (value <= a[rank].first) {
        pos = findLastGreater(value);
        
        Info right_seg = seg.query(1, rank + 1, pos);
        Info left_seg = seg.query(1, 1, rank - 1);
        Info far_right_seg = seg.query(1, pos + 1, n);
        
        max_val = max({right_seg.max_l, value + add[pos], left_seg.max_n, far_right_seg.max_n});
        min_val = min({right_seg.min_l, value + add[pos], left_seg.min_n, far_right_seg.min_n});
    } else {
        pos = findFirstLess(value);
        
        Info left_seg = seg.query(1, pos, rank - 1);
        Info far_left_seg = seg.query(1, 1, pos - 1);
        Info right_seg = seg.query(1, rank + 1, n);
        
        max_val = max({left_seg.max_r, value + add[pos], far_left_seg.max_n, right_seg.max_n});
        min_val = min({left_seg.min_r, value + add[pos], far_left_seg.min_n, right_seg.min_n});
    }
    
    cout << max_val - min_val << '\n';
}

void initialize() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k >> q;
    
    // 读取并排序数组a
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a + 1, a + n + 1, greater<pair<int, int>>());
    
    // 建立序列映射
    for (int i = 1; i <= n; i++) {
        serial[a[i].second] = i;
    }
    
    // 处理add数组
    int len = 1;
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    
    for (int i = 1; i <= k; i++) {
        cin >> add[len];
        for (int j = 1; j < b[i]; j++) {
            add[len + j] = add[len];
        }
        len += b[i];
    }
    
    sort(add + 1, add + n + 1);
    seg.build(1, 1, n);
}

int main() {
    initialize();
    
    int x, v;
    for (int i = 1; i <= q; i++) {
        cin >> x >> v;
        processQuery(serial[x], v);
    }
    
    return 0;
}*/
