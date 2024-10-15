#include <iostream>
#include "matrix.h"

using std::cin;
using std::cout;

int main(){
	Matrix<int> m({
	{1,2,6},
	{1}
	});
	
	cout<<m.GetCows()<<"\n";
	cout<<m.GetRows()<<"\n";
	
	Matrix<double> md(1,5);
	cout<<md.GetCows()<<"\n";
	cout<<md.GetRows()<<"\n";
	int el=m(0,1);
	cout<<el<<"\n";
	for(size_t i=0;i<m.GetRows();i++){
			for(size_ j=0;i<m.GetCows();j++){
				cout<<m(i,j)<<" ";
			}
			cout<<"\n";
	}
	//md[0].resize(10);                 
	return 0;
}
