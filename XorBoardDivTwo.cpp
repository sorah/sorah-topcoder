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

class XorBoardDivTwo {
public:
  int theMax(vector <string> board)
  {
    int result = 0;
    int bi[60][60];
    int i = 0, j = 0;
    int sizex = board.size();
    int sizey = board[0].size();

    each(board, row) {
      j = 0;
      each(*row, col) {
        bi[i][j] = (*col) == '1' ? 1 : 0;
        j++;
      }
      i++;
    }

    times(x, sizex) {
      times(y, sizey) {
        int b[60][60];
        times(x_, sizex)
          times(y_, sizey)
            b[x_][y_] = bi[x_][y_];

        times(y_,sizey)
          b[x][y_] = b[x][y_] == 1 ? 0 : 1;
        //times(x_,size) { times(y_,size) { cerr << b[x_][y_]; }; cerr << endl; };// cerr << endl;
        times(x_,sizex)
          b[x_][y] = b[x_][y] == 1 ? 0 : 1;
        // count
        int tmp = 0;
        times(x_, sizex)
          times(y_, sizey)
            if(b[x_][y_] == 1) tmp++;
        if(result < tmp) result = tmp;
      }
    }

    return result;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"101",
 "010",
 "101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(0, Arg1, theMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"111",
 "111",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, theMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"0101001",
 "1101011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, theMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"000",
 "001",
 "010",
 "011",
 "100",
 "101",
 "110",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(3, Arg1, theMax(Arg0)); }
	void test_case_4() { string Arr0[] = {"000000000000000000000000",
 "011111100111111001111110",
 "010000000100000001000000",
 "010000000100000001000000",
 "010000000100000001000000",
 "011111100111111001111110",
 "000000100000001000000010",
 "000000100000001000000010",
 "000000100000001000000010",
 "011111100111111001111110",
 "000000000000000000000000"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 105; verify_case(4, Arg1, theMax(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  XorBoardDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
