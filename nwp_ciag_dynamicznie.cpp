#include <iostream>
#include <string>
using namespace std;
int d[50][50];
char b[50][50];
//-----------------------------------------
string nwp_rek(string X, string Y) // rekurwencyjnie dla sprawdzenia, jaki to ci¹g znaków
{ string Z, Z1, Z2;
char znak_pom;
  int m=X.size();
  int n=Y.size();
  if (m==0 || n==0) return Z;
  else
  if (X[m-1] == Y[n-1])
     Z = nwp_rek(X.erase(m-1,1), Y.erase(n-1,1)) + X[m-1];
   else
      {
       znak_pom=X[m-1];
       Z1 = nwp_rek(X.erase(m-1,1),Y);
       Z2 = nwp_rek(X+znak_pom , Y.erase(n-1,1));


      if (Z1.size()>=Z2.size()) Z=Z1; else Z= Z2;}
}


//-----------------------------------
int nwp_dyn(string X, string Y, char b[50][50])  // wypisanie tylko dlugosci max nwp
{

 int  m=X.size();
 int n=Y.size();

  int d[m+1][n+1];

 for(int i=0; i<=m;i++) d[i][0]=0;
 for(int j=0; j<=n;j++) d[0][j]=0;
  for(int i=1; i<=m;i++)
    for(int j=1; j<=n;j++)
    {
    if (X[i-1]==Y[j-1]) {d[i][j]=d[i-1][j-1]+1; b[i][j]='/';}
      else
      if(d[i-1][j]>=d[i][j-1])  {d[i][j]=d[i-1][j]; b[i][j]='|';}
      else {d[i][j]=d[i][j-1]; b[i][j]='-';}}
   return d[m][n];
}

void wypisz(int i, int j, string X, char b[50][50]) // wypisuje ciag max nwp
{
    if ( i==0 || j==0) return ;

        if (b[i][j]=='/')  {wypisz( i-1,j-1, X,b); cout<<X[i-1];}
        else if (b[i][j]=='|' ) wypisz(i-1,j,X,b); else wypisz(i,j-1,X,b);

}

int main()
{ string X, Y;
  //X="kaliiam";
  //Y="kaliaalian";
  //X ="barakudararaswatratwa";
  //Y="abrakadabraswaarbaraktrawaarbar";
 X="balonikzbalonikiemiinnymbalonemrazemzbalonikiem";
 Y="baladynazbanalnymbaaldinnymbaladynowym";
  int m=X.size();
  int n=Y.size();
  int d[m+1][n+1];
  cout<<"nwp_dyn_dlugosc="<<nwp_dyn(X,Y,b)<<endl;
  cout<<"nwp_dyn="; wypisz(m,n,X,b);
  cout<<endl;

  //cout<<"nwp_rek="<<nwp_rek(X,Y)<<endl;

  system ("pause");

}
