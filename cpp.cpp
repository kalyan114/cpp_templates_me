#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
// #include <boost/math/common_factor.hpp>
//Lucky
using namespace std;
#define endl "\n"
#define pct     __builtin_popcount
#define all(x)  (x).begin(), (x).end()
#define sz(x)   (x).size()
#define pb      push_back
#define mp      make_pair
#define fr      first
#define sc      second
#define opy          cout<<"YES"<<endl
#define opn          cout<<"NO"<<endl
#define yes(x)       if(x){out("YES");}else{out("NO");}
#define tolower(x)   transform(x.begin(),x.end(),x.begin(),::tolower);
#define toupper(x)   transform(x.begin(),x.end(),x.begin(),::toupper);
#define sortall(x)    sort(x.begin(),x.end())
#define revsort(x)    sort(x.rbegin(),x.rend())
#define reverse(x)    reverse(x.begin(),x.end())
#define maxi(x)       *max_element(x.begin(),x.end())
#define mini(x)       *min_element(x.begin(),x.end())
#define sum(x,n)      accumulate(x.begin(),x.end(),n)
#define cnt(x,n)      count(x.begin(),x.end(),n)
#define cov(x,n)      find(x.begin(),x.end(),n)
#define frn(i,a)         for(ll i=0;i<a;i++)
#define frd(i,a)         for(ll i=a-1;i>=0;i--)
#define forn(i,a,b)       for(ll i=a;i<b;i++)
#define ford(i,a,b)       for(ll i=b-1;i>=a;i--)
#define form(i,a)         for(ll i=a;i>=0;i--)
#define trav(i,a)         for(auto &i:a)
#define inp(a)            for(auto& i:a){cin>>i;}
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef map<ll,ll> ml;
typedef map<string,string>ms;
typedef map<string,ll>msl;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
const int INF=0x3f3f3f3f;
const long long LLINF=1e18;
const ll MAXN=2e5+10;
const ll mod=998244353;
const ll maxv=0;
const ll minv=1e9;
const ll maxn=110;
bool prime(int x){
    for(int i=2;i*i<=x;i++){if(x%i==0){return 0;}}
    return 1;
}
ll gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a[],ll n){
    ll r=a[0];
    for(ll i=1;i<n;i++){r=((a[i]*r)/gcd(a[i],r));}
    return r;
}
ll mypow(ll a,ll b){
    ll res=1LL;while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;b>>=1;
    }return res;
}
ll fact(ll m){
    if(m==0 or m==1){return 1;}
    else{return m*fact(m-1);}
}
ll set_bits(ll h)
{
    ll c=0;
    while(h){c+=(h&1);h>>=1;}
    return c;
}
void sortme(ll a[],ll n){sort(a,a+n);}
template<typename T> void out(T res){cout<<res<<endl;}
template<class T> bool ckmin(T& a,const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a,const T& b){return a<b?a=b,1:0;}
vector<ll>::iterator it;
ll ncr(ll n,ll r){
    if(n<r){return 0;}
    if(r>n-r){r=n-r;}
    ll dp[r+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    forn(i,1,n+1){
        for(ll j=min(i,r);j>0;j--){
            dp[j]=dp[j]+dp[j-1];
        }
    }
    return dp[r];
}
class Disjointset{
    vl r,p,s;
    public:
    Disjointset(ll n){
        r.resize(n+1,0);
        p.resize(n+1,0);
        s.resize(n+1,0);
        frn(i,n+1){p[i]=i;s[i]=1;}
    }
    ll findpar(ll node){
        if(node==p[node]){return node;}
        return p[node]=findpar(p[node]);
    }
    void unionbyrank(ll u,ll v){
        ll pu=findpar(u);
        ll pv=findpar(v);
        if(pu==pv){return ;}
        if(r[pu]<r[pv]){p[pu]=pv;}
        else if(r[pv]<r[pu]){p[pv]=pu;}
        else{
            p[pv]=pu;
            r[pu]++;
        }
    }
    void unionbysize(ll u,ll v){
        ll pu=findpar(u);
        ll pv=findpar(v);
        if(pu==pv){return ;}
        if(s[pu]<s[pv]){
            p[pu]=pv;
            s[pv]+=s[pu];
        }
        else{
            p[pv]=pu;
            s[pu]+=s[pv];
        }
    }
};
void hi()
{
    ll n,c=0;cin>>n;vl v(n),r;inp(v);
    if(sum(v,0)%2==0){out(0);return;}
    trav(i,v){
        c=1;
        while(true){
            ll d=i-i/2;
            if(d&1){r.pb(c);break;}
            else{
                i/=2;c++;
            }
        }
    }
    ll res=maxi(r);
    trav(i,r){
        if(i>0){res=min(res,i);}
    }
    out(res);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t=1;cin>>t;while(t--){hi();}
    return 0;
}
