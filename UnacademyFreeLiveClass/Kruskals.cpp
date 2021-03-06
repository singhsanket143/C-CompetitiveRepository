// Problem Link - https://www.hackerrank.com/challenges/kruskalmstrsub/problem
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}


void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
}
ll find(vi &parent, ll a) {
    return parent[a] = ((parent[a] == a) ? a : find(parent, parent[a]));
}

void Union(vi &parent, vi &rank, ll a, ll b) {
    a = find(parent, a);
    b = find(parent, b);
    if(rank[a] == rank[b]) { 
        rank[a]++;
    }
    if(rank[a] > rank[b]) {// ranka > rank b
        parent[b] = a; // then after merge also rank a > rank b
        // rank[a]++;
    } else { // ranka < rank b
        parent[a] = b; // then after merge also rank a < rank b
        // rank[b]++;
    }
}
struct Edge {
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

ll kruskals(std::vector<Edge> &input, int n, int e) {
    sort(all(input), cmp);
    std::vector<Edge> output;
    vi parent(n+1, 0);
    vi rank(n+1, 1);
    for(int i = 0; i <= n; i++) parent[i] = i;
    int count = 0, i = 0;
    while(count < n-1) {
        Edge ce = input[i];

        int srcParent = find(parent, ce.src);
        int destParent = find(parent, ce.dest);
        if(srcParent != destParent) {
            output.pb(ce);
            Union(parent, rank, srcParent, destParent);
            count++;
        }
        i++;
    }
    ll ans = 0;
    for(int m = 0; m < output.size(); m++) {
        ans += output[m].wt;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, e;
    std::cin>>n>>e;
    

    std::vector<Edge> arr(e);
    loop(i, 0, e-1) {
        std::cin>>arr[i].src>>arr[i].dest>>arr[i].wt;
    } 

    std::cout<<kruskals(arr, n, e);

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}