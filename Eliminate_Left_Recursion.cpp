#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << "Enter Number of non-terminals\n";
  int n;
  cin >> n;
  vector<string> t(n);
  cout << "\nEnter Productions for each non-terminal separated by | (without "
          "spaces)\n\n";
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  vector<pair<char, vector<string>>> prd(n);
  for (int i = 0; i < n; ++i) {
    char ch = t[i][0];
    vector<string> temp;
    stringstream ss(t[i].substr(3));
    string str;
    while (getline(ss, str, '|')) temp.push_back(str);
    prd[i] = {ch, temp};
  }
  vector<int> to_remove;
  for (int i = 0; i < n; ++i) {
    pair<char, vector<string>> prd1 = prd[i];
    vector<string> to_add, to_remove;
    for (int j = 0; j < i; ++j) {
      pair<char, vector<string>> prd2 = prd[j];
      for (string str1 : prd1.second) {
        if (str1[0] == prd2.first) {
          to_remove.push_back(str1);
          for (string str2 : prd2.second) {
            to_add.push_back(str2 + str1.substr(1));
          }
        }
      }
    }

    for (string str : to_remove)
      remove(prd[i].second.begin(), prd[i].second.end(), str);
    prd[i].second.resize(prd[i].second.size() - to_remove.size());
    prd[i].second.insert(prd[i].second.end(), to_add.begin(), to_add.end());
  }
  cout << "\nAfter Eliminating Left Recursion\n\n";
  bool eliminate;
  for (int i = 0; i < n; ++i) {
    eliminate = false;
    for (string str : prd[i].second) {
      if (prd[i].first == str[0]) {
        eliminate = true;
      }
    }
    if (!eliminate) {
      cout << prd[i].first << " ->";
      bool start = true;
      for (string str : prd[i].second) {
        if (start) {
          cout << str;
          start = false;
        } else {
          cout << "|" << str;
        }
      }
      cout << endl;
    } else {
      vector<string> a, a_;
      for (string str : prd[i].second) {
        if (prd[i].first == str[0]) {
          a_.push_back(str.substr(1) + prd[i].first + "\'");
        } else {
          a.push_back(((str != "#") ? str : "") + prd[i].first + "\'");
        }
      }
      a_.push_back("#");
      cout << prd[i].first << " ->";
      bool start = true;
      for (string str : a) {
        if (start) {
          cout << str;
          start = false;
        } else {
          cout << "|" << str;
        }
      }
      cout << endl;
      cout << prd[i].first << "\'->";
      start = true;
      for (string str : a_) {
        if (start) {
          cout << str;
          start = false;
        } else {
          cout << "|" << str;
        }
      }
      cout << endl;
    }
  }
  return 0;
}