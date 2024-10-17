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
template <typename T>
Matrix<T>& operator +(const Matrix<T>& m1,const Matrix<T>& m2){
			const size_t rows=m1.GetRows();
			const size_t cows=m1.GetCows();
			if(rows!=m2.GetRows()|| cows!=m2.GetCows()){
				throw std::invalid_argument("Different size");
			}
			Matrix<T> m3(rows,cows);
			for(size_t i=0;i!=rows;i++){
				for(size_t j=0;j!=cows;j++){
					m3(i,j)=m1(i,j)+m2(i,j);
				}	
			}
			return m3;
		}

#endif //MATRIX_H
