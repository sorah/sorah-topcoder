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
typedef long long ll;

typedef struct {
  int i;
  int lsum;
  int rsum;
  string str;
} Chain;

Chain new_chain(int i, int lsum, int rsum, string str)
{
  Chain chain = {i, lsum, rsum, str};
  return chain;
}

int to_int(char c) {
  switch(c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
  }
  return -1;
}

class DengklekMakingChains {
    vector<Chain> lterms, rterms;
    int middle;

public:
  int maxBeauty(vector <string> chains) {
    int i, single_max=0, lmax=0, rmax=0, max=0;
    int cid=0;
    vector<string>::iterator sit;
    vector<Chain>::iterator cita, citb;
    string str;

    lterms.clear(); rterms.clear();
    middle = 0;

    for(sit = chains.begin(); sit != chains.end(); sit++) {
      str = *sit;
      if     (str[0] != '.' && str[1] != '.' && str[2] == '.') { // NN.
        rterms.push_back(new_chain(cid, to_int(str[0])+to_int(str[1]), 0, str));
      }
      else if(str[0] != '.' && str[1] == '.' && str[2] == '.') { // N..
        rterms.push_back(new_chain(cid, to_int(str[0]), 0, str));
      }
      else if(str[0] == '.' && str[1] != '.' && str[2] != '.') { // .NN
        lterms.push_back(new_chain(cid, 0, to_int(str[1])+to_int(str[2]), str));
      }
      else if(str[0] == '.' && str[1] == '.' && str[2] != '.') { // ..N
        lterms.push_back(new_chain(cid, 0, to_int(str[2]), str));
      }
      else if(str[0] != '.' && str[1] != '.' && str[2] != '.') { // NNN
        middle += to_int(str[0]) + to_int(str[1]) + to_int(str[2]);
      }
      else if(str[0] == '.' && str[1] != '.' && str[2] == '.') { // .N.
        i = to_int(str[1]);
        if(single_max < i) single_max=i;
      }
      else if(str[0] != '.' && str[1] == '.' && str[2] != '.') { // N.N
        lterms.push_back(new_chain(cid, to_int(str[0]), to_int(str[2]), str));
        rterms.push_back(new_chain(cid, to_int(str[0]), to_int(str[2]), str));
      }
      cid++;
    }

    for(cita = lterms.begin(); cita != lterms.end(); cita++) {
      i = middle + (cita->lsum > cita->rsum ? cita->lsum : cita->rsum);
      if(lmax < i) lmax = i;
    }
    for(cita = rterms.begin(); cita != rterms.end(); cita++) {
      i = middle + (cita->lsum > cita->rsum ? cita->lsum : cita->rsum);
      if(rmax < i) rmax = i;
    }
    max = middle;
    for(cita = lterms.begin(); cita != lterms.end(); cita++) {
      for(citb = rterms.begin(); citb != rterms.end(); citb++) {
        if(cita->i == citb->i) continue;
        i = cita->rsum + citb->lsum + middle;
        if(max < i) max = i;
      }
    }

    if(rmax > max) max = rmax;
    if(lmax > max) max = lmax;
    if(single_max > max) max = single_max;
    return max;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }
	void test_case_6() { string Arr0[] = {"123", "1.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(5, Arg1, maxBeauty(Arg0)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  DengklekMakingChains ___test;
  ___test.run_test(-1);
  ___test.test_case_6();
}
// END CUT HERE
