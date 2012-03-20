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

class LeftOrRight {
public:

  int reach(string program)
  {
    int result=0;
    int cur=0;

    each(program,p) {
      if(*p == 'L')
        cur--;
      else if (*p == 'R')
        cur++;

      if(abs(cur) > result) result = abs(cur);
    }
    return result;
  }

  int try_the(string program,char c)
  {
    for(int i = 0; i < program.length(); i++) {
      if (program[i] != '?') continue;

      program[i] = c;
    }
    return reach(program);
  }

  int maxDistance(string program)
  {
    int l,r,a,b;

    l = count(program.begin(),program.end(),'L');
    r = count(program.begin(),program.end(),'R');

    if(l == 0 && r == 0) return program.size();
    if((l + r) == program.size()) return reach(program);

    a = try_the(program, 'L');
    b = try_the(program, 'R');
    return a < b ? b : a;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLLRLRRR"; int Arg1 = 3; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arg0 = "R???L"; int Arg1 = 4; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arg0 = "??????"; int Arg1 = 6; verify_case(2, Arg1, maxDistance(Arg0)); }
	void test_case_3() { string Arg0 = "LL???RRRRRRR???"; int Arg1 = 11; verify_case(3, Arg1, maxDistance(Arg0)); }
	void test_case_4() { string Arg0 = "L?L?"; int Arg1 = 4; verify_case(4, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  LeftOrRight ___test;
  ___test.run_test(-1);
}
// END CUT HERE
