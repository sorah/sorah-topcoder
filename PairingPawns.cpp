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
#define exist_in(ary,x) find(ary.begin(),ary.end(),x) == ary.end()

class PairingPawns {
public:
  int savedPawnCount(vector <int> start) {
    rtimes(i,start.size()-1) {
      if(i <= 0) break;
      start[i-1] += start[i]/2;
      start[i] %= 2;
    }
    return start[0];
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, savedPawnCount(Arg0)); }
	void test_case_1() { int Arr0[] = {10,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(1, Arg1, savedPawnCount(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, savedPawnCount(Arg0)); }
	void test_case_3() { int Arr0[] = {0,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, savedPawnCount(Arg0)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, savedPawnCount(Arg0)); }
	void test_case_5() { int Arr0[] = {1000,2000,3000,4000,5000,6000,7000,8000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3921; verify_case(5, Arg1, savedPawnCount(Arg0)); }
	void test_case_6() { int Arr0[] = {0, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7, 0, 0, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, savedPawnCount(Arg0)); }


// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  PairingPawns ___test;
  ___test.run_test(-1);
}
// END CUT HERE
