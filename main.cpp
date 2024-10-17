#include <iostream>
#include "matrix.h"

using std::cin;
using std::cout;


		
int main(){
	Matrix<int> m({
	{1,2},
	{1,5}
	});
	
	/*cout<<m.GetCows()<<"\n";
	cout<<m.GetRows()<<"\n";*/
	
	Matrix<double> md(10,5);
	/*cout<<md.GetCows()<<"\n";
	cout<<md.GetRows()<<"\n";*/
	//int el=m(0,1);
	/*cout<<el<<"\n";*/
	/*cout<<m;
	cout<<"\n";
	cout<<md;*/
	Matrix<int> m2(2,2);
	cin>>m2;
	cout<<"============\n";
	cout<<m2;
	cout<<"++++++++++++\n";
	cout<<m;
	cout<<"\n";
	cout<<"============\n";
	//m2+=m;
	cout<<(m2==m);
	//md[0].resize(10);                 
	return 0;
}
