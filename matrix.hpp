#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "matrix.h"

template <typename T>
size_t Matrix<T>::GetRows()const{
	return data.size();
}
template <typename T>
size_t Matrix<T>::GetCows()const{
	if(data.empty()){
		return 0;
	}
	return data[0].size();
}
template <typename T>
void Matrix<T>::MakeRectangle(){
	size_t max_size=0;
	for(const auto& row:data){
		if(row.size()>max_size){
			max_size=row.size();
		}
	}
	for(auto& row:data){
		row.resize(max_size);
	}
}
template <typename T>
Matrix <T>::Matrix(size_t rows,size_t cows){
				data.resize(rows);
				for(auto& r:data){
					r.resize(cows);
				}
		}
		
template <typename T>		
std::vector<std::vector<T>>::const_iterator Matrix<T>::begin(){
			return data.cbegin();
		};
		
template <typename T>		
std::vector<std::vector<T>>::const_iterator Matrix<T>::end(){
			return data.cend();
		};
		
template <typename T>
std::ostream& operator <<(std::ostream& out,const Matrix<T>& matrix){
	const size_t rows=matrix.GetRows();
	const size_t cows=matrix.GetCows();
	for(size_t i=0;i!=rows;i++){
		for(size_t j=0;j!=cows;j++){
			if(j>0){
				out<<"\t";
			}
			out<<matrix(i,j);
		}
		out<<"\n";
	}
	return out;
}	

template <typename T>
std::istream& operator >>(std::istream& in,Matrix<T>& matrix){
	const size_t rows=matrix.GetRows();
	const size_t cows=matrix.GetCows();
	for(size_t i=0;i!=rows;i++){
		for(size_t j=0;j!=cows;j++){
			in>>matrix(i,j);
		}
		
	}
	return in;
}	


#endif //MATRIX_H
