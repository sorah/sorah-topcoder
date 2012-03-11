#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

static const double EPS = 1e-5;

#define times(i,n) for(int i = 0; i < n; i++)
#define each(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

int roman_to_int(string r)
{
  vector<int> s;
  int result = 0;

  each(r,i) {
    switch(*i) {
      case 'I':
        result++;
        break;
      case 'V':
        result = 5 - result;
        s.push_back(result); result = 0;
        break;
      case 'X':
        result = 10 - result;
        s.push_back(result); result = 0;
        break;
      case 'L':
        result = 50 - result;
        s.push_back(result); result = 0;
        break;
    }
  }
  each(s,it) result += *it;

  return result;
}

pair<string,string> split_name_roman(string a)
{
  int i;
  for(i=0;i < a.size();i++) if(a[i] == ' ') break;

  return pair<string,string>(a.substr(0,i), a.substr(i+1));
}

bool compare(string a_, string b_)
{
  pair<string,string> a,b;
  int compa;

  a = split_name_roman(a_);
  b = split_name_roman(b_);

  compa = a.first.compare(b.first);

  if (compa == 0) {
    return roman_to_int(a.second) < roman_to_int(b.second);
  }
  else if (compa > 0) {
    return false;
  }
  else {
    return true;
  }
}

class KingSort {
public:

  vector <string> getSortedList(vector <string> kings) {
    sort(kings.begin(), kings.end(), compare);
    return kings;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Louis IX", "Louis VIII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis VIII", "Louis IX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSortedList(Arg0)); }
	void test_case_1() { string Arr0[] = {"Louis IX", "Philippe II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis IX", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSortedList(Arg0)); }
	void test_case_2() { string Arr0[] = {"Richard III", "Richard I", "Richard II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Richard I", "Richard II", "Richard III" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSortedList(Arg0)); }
	void test_case_3() { string Arr0[] = {"John X", "John I", "John L", "John V"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John I", "John V", "John X", "John L" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSortedList(Arg0)); }
	void test_case_4() { string Arr0[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSortedList(Arg0)); }
	void test_case_5() { string Arr0[] = {"Philippe II", "Philip II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Philip II", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getSortedList(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  KingSort ___test;
  ___test.run_test(-1);
}
// END CUT HERE
