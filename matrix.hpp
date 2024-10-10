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

#endif //MATRIX_H
