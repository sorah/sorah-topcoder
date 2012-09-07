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
#define each(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define range_each(b,e,i) for(typeof(b) i=b; i!=e; ++i)
#define find_a(x,ary) find(ary.begin(),ary.end(),x)
#define exist_in(ary,x) (find(ary.begin(),ary.end(),x) != ary.end())

class MinimalDifference {
public:
  int findNumber(int A, int B, int C)
  {
    int x;
    int c = digit_sum(C);
    int r = 0, rd = -1;
    int s;

    for (x=A; x <= B; x++) {
      s = digit_sum(x);
      if (c == s) return x;
      if (rd == -1 || abs(c-s) < rd) {
        rd = abs(c-s);
        r = x;
      }
    }
    return r;
  }

  int digit_sum(int x)
  {
    int result = 0;
    int i;
    while(x > 0) {
      i = x%10; x /= 10;
      result += i;
    }
    return result;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 10; int Arg3 = 1; verify_case(0, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 20; int Arg2 = 20; int Arg3 = 11; verify_case(1, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 999; int Arg3 = 1; verify_case(2, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 99; int Arg3 = 189; verify_case(3, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1987; int Arg1 = 9123; int Arg2 = 1; int Arg3 = 2000; verify_case(4, Arg3, findNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  MinimalDifference ___test;
  ___test.run_test(-1);
}
// END CUT HERE
