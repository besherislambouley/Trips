/* 
 * sort the groups in ascending order , sort the trips in ascending order according to the mn limit of people 
 * loop through the groups and add to a set the trips with mn limit smaller than the group size 
 * since every mn limit of the trips in the set are smaller than the group size we just have to decide which mx limit is the best 
 * we greedly take the minimum mx limit greater than the group size 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , m , Ans ; 
struct G {
	int sz , id , ans ;
} group [1000009] ;
struct T {
	int mn , mx , id ;
} trips [1000009] ; 
bool cmp1 ( G a , G b ) {
	return a .sz < b .sz ;
}
bool cmp2 ( T a , T b ) {
	if ( a .mn == b .mn ) return a .mx < b .mx ;
	return a .mn < b .mn ;
}
int main () {
	cin >> n >> m ;
	for ( int i = 0 ; i < n ; i ++ ) {
		scanf("%d",&group[i].sz);
		group [i].id = i ;
		group [i].ans=-1 ;
	}
	for ( int i = 0 ; i < m ; i ++ ) {
		scanf("%d%d",&trips[i].mn,&trips[i].mx);
		trips [i].id = i ;
	}
	sort ( group , group + n , cmp1 ) ;
	sort ( trips , trips + m , cmp2 ) ;
	set < pi > s ;
	int j = 0 ; 
	for ( int i = 0 ; i < n ; i ++ ) {
		while ( j < m && group[i] .sz >= trips[j].mn ) {
			if ( trips[j].mx >= group[i] .sz ) {
				s .ins ( { trips [j].mx , trips [j].id } ) ;
			}
			j ++ ;
		}
		if ( s.size () ) {
			auto it = s.lb ( { group[i] .sz , -1 } ) ;
		       	if ( it != s.end() ) {	
				Ans ++ ;
				group [i].ans = it->se ;
				s .era ( *it ) ;
			}
		}
	}
	printf("%d\n",Ans);
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( group[i].ans == -1 ) C ;
		printf("%d %d\n",group[i] .id + 1 ,group[i] .ans + 1 ) ; 
	}
}
