#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "\nhttps://www.usna.edu/Users/cs/wcbrown/courses/F17SI340/lec/l22/"
          "lec.html\nTo minimize the DFA at the above link enter 1 or 2 to "
          "minimize a custom DFA\n";
  int x;
  cin >> x;
  if (x == 1) {
    int n = 7;
    int table[7][2];
    cout << "Given Transition Table: \n";
    cout << "\t0\t1\n";
    table[0][0] = 1;
    table[0][1] = 2;
    cout << "q0\t1\t2\n";
    table[1][0] = 3;
    table[1][1] = 4;
    cout << "q1\t3\t4\n";
    table[2][0] = 3;
    table[2][1] = 5;
    cout << "q2\t3\t5\n";
    table[3][0] = 3;
    table[3][1] = 3;
    cout << "q3\t3\t3\n";
    table[4][0] = 4;
    table[4][1] = 6;
    cout << "q4\t4\t6\n";
    table[5][0] = 5;
    table[5][1] = 6;
    cout << "q5\t5\t6\n";
    table[6][0] = 6;
    table[6][1] = 6;
    cout << "q6\t6\t6\n";
    cout << "Initial state: q0\nFinal states: q4,q5\n";
    int f = 2;
    int fn[2] = {4, 5};
    int val[n];
    bool checke;
    for (int i = 0; i < n; ++i) {
      checke = false;
      for (int j = 0; j < f; ++j) {
        if (fn[j] == i) val[i] = 1, checke = true;
      }
      if (!checke) val[i] = 0;
    }
    vector<int> ini{0, 1};
    int k = 2;
    bool che, check;
    int ch;
    while (true) {
      check = false;
      bool che;
      for (int v = 0; v != ini.size(); ++v) {
        for (int j : {0, 1}) {
          che = false;
          vector<int> temp;
          for (int i = 0; i < n; ++i) {
            if (val[i] == ini[v]) {
              if (val[table[i][j]] != ini[v]) {
                temp.push_back(1);
              } else
                temp.push_back(0);
            }
          }
          bool xx = true;
          for (int x = 1; x != temp.size(); ++x) {
            if (temp[x] != temp[x - 1]) {
              xx = false;
              break;
            }
          }
          if (!xx) {
            vector<int> tochange;
            for (int i = 0; i < n; ++i) {
              if (val[i] == ini[v]) {
                if (val[table[i][j]] != ini[v]) {
                  che = true;
                  check = true;
                  if (ini.back() != k) ini.push_back(k);
                  tochange.push_back(i);
                }
              }
            }
            for (int yy : tochange) val[yy] = k;
          }

          if (che) ++k;
        }
      }
      if (!check) break;
    }
    map<int, vector<int> > final_states;
    for (int i : ini) {
      for (int t = 0; t != n; ++t) {
        if (val[t] == i) final_states[i].push_back(t);
      }
    }
    int final_table[ini.size()][2];
    for (int i = 0; i < ini.size(); ++i) {
      for (int j : {0, 1}) {
        final_table[i][j] = val[table[final_states[i].front()][j]];
      }
    }
    cout << "\nMinimised Transition Table:\n";
    cout << "\n\t0\t1\n";
    for (int i = 0; i < ini.size(); ++i) {
      cout << (char)('A' + i) << "\t";
      cout << (char)('A' + final_table[i][0]) << "\t"
           << (char)('A' + final_table[i][1]);
      cout << "\n";
    }
    cout << "Initial state: " << (char)('A' + val[0])
         << "\nFinal state: " << (char)('A' + val[fn[0]]) << "\n";
  } else {
    int n;
    cout << "\n\nEnter the number of states\n";
    cin >> n;
    cout << "\n\nThe states are: ";
    for (int i = 0; i < n; ++i) cout << 'q' << i << '\t';
    cout << "\n\nTaking initial state as q0\nAnd the alphabet is {0,1}";
    cout << "\n\nEnter the transition table:";
    cout << "\n\n\t0 1\n";
    int table[n][2];
    for (int i = 0; i < n; ++i) {
      cout << 'q' << i << "\t";
      int x, y;
      cin >> x >> y;
      table[i][0] = x;
      table[i][1] = y;
      cout << "\n";
    }
    int f;
    cout << "\nEnter number of final states:\n";
    cin >> f;
    int fn[f];
    cout << "Enter final states each in a new line: \n";
    for (int i = 0; i < f; ++i) {
      cout << "q";
      int x;
      cin >> fn[i];
      cout << "\n";
    }
    if (n == 1) {
      cout << "q0" << endl;
      return 0;
    }
    int val[n];
    bool checke;
    for (int i = 0; i < n; ++i) {
      checke = false;
      for (int j = 0; j < f; ++j) {
        if (fn[j] == i) val[i] = 1, checke = true;
      }
      if (!checke) val[i] = 0;
    }
    vector<int> ini{0, 1};
    int k = 2;
    bool che, check;
    int ch;
    while (true) {
      check = false;
      bool che;
      for (int v = 0; v != ini.size(); ++v) {
        for (int j : {0, 1}) {
          che = false;
          vector<int> temp;
          for (int i = 0; i < n; ++i) {
            if (val[i] == ini[v]) {
              if (val[table[i][j]] != ini[v]) {
                temp.push_back(1);
              } else
                temp.push_back(0);
            }
          }
          bool xx = true;
          for (int x = 1; x != temp.size(); ++x) {
            if (temp[x] != temp[x - 1]) {
              xx = false;
              break;
            }
          }
          if (!xx) {
            vector<int> tochange;
            for (int i = 0; i < n; ++i) {
              if (val[i] == ini[v]) {
                if (val[table[i][j]] != ini[v]) {
                  che = true;
                  check = true;
                  if (ini.back() != k) ini.push_back(k);
                  tochange.push_back(i);
                }
              }
            }
            for (int yy : tochange) val[yy] = k;
          }

          if (che) ++k;
        }
      }
      if (!check) break;
    }
    map<int, vector<int> > final_states;
    for (int i : ini) {
      for (int t = 0; t != n; ++t) {
        if (val[t] == i) final_states[i].push_back(t);
      }
    }
    int final_table[ini.size()][2];
    for (int i = 0; i < ini.size(); ++i) {
      for (int j : {0, 1}) {
        final_table[i][j] = val[table[final_states[i].front()][j]];
      }
    }
    cout << "\nMinimised Transition Table:\n";
    cout << "\n\t0\t1\n";
    for (int i = 0; i < ini.size(); ++i) {
      cout << (char)('A' + i) << "\t";
      cout << (char)('A' + final_table[i][0]) << "\t"
           << (char)('A' + final_table[i][1]);
      cout << "\n";
    }
    cout << "Initial state: " << (char)('A' + val[0])
         << "\nFinal state: " << (char)('A' + val[fn[0]]) << "\n";
  }
  return 0;
}