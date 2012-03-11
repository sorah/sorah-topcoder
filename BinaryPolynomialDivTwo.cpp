#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

static const double EPS = 1e-5;

#define times(i,n) for(int i = 0; i < n; i++)
#define each(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define find_a(x,ary) find(ary.begin(),ary.end(),x)
#define exist_in(ary,x) find(ary.begin(),ary.end(),x) == ary.end()

class BinaryPolynomialDivTwo {
public:
  int countRoots(vector <int> a) {
    int i=0;
    if(p(0,a) == 0) i++;
    if(p(1,a) == 0) i++;
    return i;
  }

  int pow(int a, int b) {
    int result=1;
    times(i,b) result = result * a;
    return result;
  }

  int p(int x, vector <int> a)
  {
    int result = 0;
    int i = 0;

    each(a,it) {
      if(i == 0) {
        result += (*it) * 1;
      }
      else {
        result += (*it) * pow(x,i);
      }
      i++;
    }

    return result % 2;
  }

  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
