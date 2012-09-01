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

class TheBrickTowerEasyDivTwo {
public:
  int find(int redCount, int redHeight, int blueCount, int blueHeight)
  {
    int red, blue, height;
    map<int, int> dic;

    red = redCount;
    blue = blueCount;
    height = 0;

    while(true) {
      if(blue <= 0) break;
      blue--;
      height += blueHeight;
      dic[height] = 1;

      if(red <= 0) break;
      red--;
      height += redHeight;
      dic[height] = 1;
    }

    red = redCount;
    blue = blueCount;
    height = 0;

    while(true) {
      if(red <= 0) break;
      red--;
      height += redHeight;
      dic[height] = 1;

      if(blue <= 0) break;
      blue--;
      height += blueHeight;
      dic[height] = 1;
    }

    return dic.size();
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; int Arg4 = 4; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 4; int Arg3 = 7; int Arg4 = 12; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 7; int Arg2 = 4; int Arg3 = 4; int Arg4 = 13; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 47; int Arg2 = 47; int Arg3 = 47; int Arg4 = 94; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  TheBrickTowerEasyDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
