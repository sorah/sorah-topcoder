#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class EllysCheckers {
  string b;
  int n;
  int checkers;
  bool turn; // false: first player, true: second

public:
  string getWinner(string board) {
    int i;
    turn = true;
    b = board;
    n = b.size();
    checkers = count(b.begin(), b.end(), 'o');
    rightmost();

    while(checkers > 0) {
      turn = !turn;
      for(i=0; i < n; i++) if(jump(i) || step(i)) break;
      rightmost();
    }

    return turn ? "NO" : "YES";
  }

  bool step(int i) {
    if(b[i] == 'o' && b[i+1] == '.') {
      b[i] = '.';
      b[i+1] = 'o';
      return true;
    }
    return false;
  }

  bool jump(int i) {
    if(b[i] == 'o' && b[i+1] == 'o' && b[i+2] == 'o' && b[i+3] == '.') {
      b[i] = '.';
      b[i+3] = 'o';
      return true;
    }
    return false;
  }

  void rightmost() {
    if(b[n-1] == 'o') {
      b[n-1] = '.';
      checkers--;
    }
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
  EllysCheckers ___test;
  ___test.run_test(-1);
}
// END CUT HERE
