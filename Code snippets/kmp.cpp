    #include<cstdio>
    #include<cstring>
    #include<cstdlib>
    #include<cmath>
    #include<cctype>
    #include<climits>
    #include<ctime>
    #include<iostream>
    #include<sstream>
    #include<string>
    #include<vector>
    #include<map>
    #include<stack>
    #include<queue>
    #include<algorithm>
    #include<set>
    #include<bitset>
    #include<complex>
    #include<numeric>
    #include<valarray>

    using namespace std;

    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define vector vc

    string s,w;
    int T[100000];



    kmp_table()
    {

//algorithm kmp_table:
    //input:
      ///  an array of characters, W (the word to be analyzed)
        ///an array of integers, T (the table to be filled)
    //output:
        ///nothing (but during operation, it populates the table)

    ///define variables:
       int pos = 2; // an integer, pos ← 2 (the current position we are computing in T)
        int cnd = 0; //an integer, cnd ← 0 (the zero-based index in W of the next
//character of the current candidate substring)


    //(the first few values are fixed but different from what the algorithm
//might suggest)
     T[0] = -1;
     T[1] = 0;


    while (pos<w.size())
    {
    ///        (first case: the substring continues)
        if (w[pos - 1] == w[cnd])
          {
              cnd = cnd + 1;
           T[pos] = cnd;
            pos = pos + 1;
            }

        //(second case: it doesn't, but we can fall back)
        else if(cnd>0)//otherwise, if cnd > 0, let cnd ← T[cnd]
            cnd=T[cnd];

        //(third case: we have run out of candidates.  Note cnd = 0)
        else //otherwise, let T[pos] ← 0, pos ← pos + 1
            {
                T[pos]=0;
                pos=pos+1;
            }
    }

    }

    int kmp_search(string s, string w)
    {

//algorithm kmp_search:
  //  input:
   //     an array of characters, S (the text to be searched)
     //   an array of characters, W (the word sought)
    //output:
      //  an integer (the zero-based position in S at which W is found)

    //define variables:
        int m=0;    //an integer, m ← 0 (the beginning of the current match in S)
        int i=0;    //an integer, i ← 0 (the position of the current character in W)
                    ///an array of integers, T (the table, computed elsewhere)

      while(m+i<s.size())    //while m+i is less than the length of S, do:
        {
            if (w[i] == s[m + i])
             {
                 if (i == w.size()-1)
                    return m;
                 i = i + 1;
             }
            else
            {
                 m = m + i - T[i];
                if (T[i]> -1)
                 i = T[i];
                else
                 i = 0;
            }
        }
    ///(if we reach here, we have searched all of S unsuccessfully)
    return s.size();    ///the length of S


    }

    int main()
    {

    }
