#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class EllysDirectoryListing
{
  public:
    vector<string> getFiles(vector<string> files)
    {
      vector <string> result, a;
      vector<string>::iterator it;
      if(check_end(files)) return files; // 1

      result.reserve(files.size());
      copy(files.begin(), files.end(), back_inserter(result));

      for(it = result.begin(); it != result.end(); it++) {
        if(*it == "." || *it == "..") {
          iter_swap(it, --result.end());
          break;
        }
      }

      if(check_end(result)) return result;

      for(it = result.begin(); it != result.end(); it++) {
        if(*it == "." || *it == "..") {
          iter_swap(it, result.end()-2);
          if(check_end(result)) return result;
        }
      }

      return result;
    }

    bool check_end(vector<string> files)
    {
      if((*(--files.end()) == "." && *(files.end()-2) == "..") ||
         (*(--files.end()) == ".." && *(files.end()-2) == ".")) return true;
      return false;
    }
};


