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
    #include <iomanip>

    using namespace std;

    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define vc vector
    #define pi acos(-1)


    #define MAX 10000000
#define is_it(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define set_it(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void double_precision(int x)///sets the precision of a double
{
    std::cout << std::setprecision(x) << std::fixed;
}


///check if a string is palindrome or not (need to include<algorithm>
bool check_palindrome(string str)
{
    string s2=str;
    std::reverse(str.begin(), str.end());

    if(s2==str)return true;
    else return false;
}


string to_str(ll n)  /// converts a long long into string
{
    stringstream sin;
    sin<<n;
    return sin.str();
}

ll to_int(string str)  /// converts a string into integer
{
    ll y;
    int i;
    for(i=0;i<str.size();i++)
    {
        if(i==0)y=str[i]-'0';
        else
        {
            y*=10;
            y+=str[i]-'0';
        }
    }

    return y;
}




bool flag[MAX/64];
vector<int>prime;

void sieve(){                 ///creating a vector of all primes below 10^7
        unsigned i,j,k;
        flag[0]|=0;
        for(i=3;i<sqrt(MAX)+1;i+=2){
                if(!is_it(i)){
                        for(j=i*i,k=i<<1;j<MAX;j+=k)set_it(j);
                }
        }
        if(MAX>1)prime.pb(2);
        for(i=3;i<MAX;i+=2){
                if(!is_it(i)){
                        prime.pb(i);
                }
        }
}

///finds the gcd of two numbers
int gcd(int a,int b)
{
    //output in a text file
    freopen ("myfile.txt","w",stdout);
  printf ("This sentence is redirected to a file.");
  fclose (stdout);
    output<<ends;
    //	cin>>a>>b;
	while(a!=b)//implementing euclidean algorith

	{
		if(a>b)
		a=a-b;//subtracting the lesser number
		else
		b=b-a;

	}
	return a;

}

///finds the lcm of two numbers
long long int lcm(int a,int b)
{
    return (long long int)((a*b)/gcd(a,b));
}



vector<vector<int> > subset(vector<int> v){         ///Generates all possible subsets
        vector<vector<int> > ret;
        int n=v.size();
        int N=1<<n;
        for (int i = 0; i < N; i++){
                vector<int> tem;
                for(int j=0;j<n;j++){
                        if(i&(1<<j))tem.push_back(v[j]);
                }
                ret.push_back(tem);
        }
        return ret;
}




void str1()
{
    // converts from c++ string to c string
    //char y[100];
    string x="test";
    cout<<"C++ string to c string conversion "<<x.c_str()<<endl;

    char * st = new char[x.length()+1];// added 1 for '\0' character
    strcpy(st,x.c_str());
    cout<<st<<endl;


}


template<class T>    ///Binary Index Tree Class...
class BIT
{
      T *tree;
      int maxVal;
      public:
      BIT(int N)
      {
              tree = new T[N+1];
              memset(tree,0,sizeof(T)*(N+1));
              maxVal = N;
      }
      void update(int idx, T val)
      {
           while (idx <= maxVal)
           {
                 tree[idx] += val;
                 idx += (idx & -idx);
           }
      }
      //Returns the cumulative frequency of index idx
      T read(int idx)
      {
        T sum=0;
        while (idx>0)
        {
              sum += tree[idx];
              idx -= (idx & -idx);
        }
        return sum;
      }
};


int main()
{
    ll i,j,k,l,m,n;

    cout<<pi<<endl;
    //sieve();
    //cout<<prime.size();
    //for(i=0;i<100;i++)cout<<prime[i]<<" ";
    vector<int>x;
    vector< vector<int> >y;

    x.resize(3);
    for(i=0;i<3;i++)x[i]=i;
    y=subset(x);
    //cout<<y[1].size();
    for(i=1;i<y.size();i++){
        for(j=0;j<y[i].size();j++)cout<<" "<<y[i][j];
        cout<<endl;
    }
    return 0;
}
