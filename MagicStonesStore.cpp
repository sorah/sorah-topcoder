#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

static const double EPS = 1e-5;

#define times(i,n) for(int i = 0; i < n; i++)
#define rtimes(i,n) for(int i = n; i >= 0; i--)
#define each(a,i) for(typeof((a).begin()) i=(a).begin(); i!=(a).end(); ++i)
#define range_each(b,e,i) for(typeof(b) i=b; i!=e; i++)
#define find_a(x,ary) find(ary.begin(),ary.end(),x)
#define exist_in(ary,x) find(ary.begin(),ary.end(),x) != ary.end()
#define not_exist_in(ary,x) find(ary.begin(),ary.end(),x) == ary.end()

class MagicStonesStore {
public:
  bool is_prime(int x) {
    int f=0;
    for (int i = 1; i <= x; i++) {
      if (x % i == 0) f++;
      if (f > 2) return false;
    }
    if (f == 2) return true;
    return false;
  }

  string ableToDivide(int n) {
    int d = n * 2;
    for(int a = 1; a < d; a++) {
      int b = d - a;
      if (is_prime(a) && is_prime(b)) return "YES";
    }
    return "NO";
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "NO"; verify_case(0, Arg1, ableToDivide(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "YES"; verify_case(1, Arg1, ableToDivide(Arg0)); }
	void test_case_2() { int Arg0 = 3; string Arg1 = "YES"; verify_case(2, Arg1, ableToDivide(Arg0)); }
	void test_case_3() { int Arg0 = 5; string Arg1 = "YES"; verify_case(3, Arg1, ableToDivide(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  MagicStonesStore ___test;
  ___test.run_test(-1);
}
// END CUT HERE
