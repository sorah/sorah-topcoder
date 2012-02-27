#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
//typedef map<vector<int>, int> Note;
class CasketOfStarEasy {

  int max;

public:
  int maxEnergy(vector <int> weight) {
    vector<int>::iterator it;
    max = -1;

    gen(0, weight, 0);

    return max;
  }

  void gen(int energy, vector<int> star, int depth) {
    int i,e;
    vector<int> tmp;
    vector<int>::iterator it;

    /*cout << depth << " " << energy << " - ";
    for(it=star.begin();it != star.end(); it++)
      cout << *it << ' ';
    cout << endl;*/

    for(i=1;i < (star.size()-1);i++) {
      e = energy;
      tmp.clear();
      tmp.reserve(star.size());
      copy(star.begin(), star.end(), back_inserter(tmp));
      tmp.erase(tmp.begin()+i);
      e += star[i-1] * star[i+1];
      if(tmp.size() == 2) {
        if(e > max) max = e;
        return;
      }
      else {
        gen(e, tmp, depth+1);
      }
    }
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, maxEnergy(Arg0)); }
	void test_case_1() { int Arr0[] = {100,2,1,3,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10400; verify_case(1, Arg1, maxEnergy(Arg0)); }
	void test_case_2() { int Arr0[] = {2,2,7,6,90,5,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1818; verify_case(2, Arg1, maxEnergy(Arg0)); }
	void test_case_3() { int Arr0[] = {477,744,474,777,447,747,777,474}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2937051; verify_case(3, Arg1, maxEnergy(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, maxEnergy(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  CasketOfStarEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
