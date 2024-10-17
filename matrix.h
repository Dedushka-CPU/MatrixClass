#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>

class Matrix{
	private:
		std::vector<std::vector<T>> data;
		void MakeRectangle();
	public:
		size_t GetRows()const;
		size_t GetCows()const;
		Matrix(const std::vector<std::vector<T>>&d):data{d}{
			MakeRectangle();
		}
		Matrix(size_t tows,size_t cows);
		/*const std::vector<T>& operator[] (size_t i) const{
			return data[i];
		};
		std::vector<T>& operator[] (size_t i){
			return data[i];
		};*/
		T& operator() (size_t i,size_t j){
			return data[i][j]; 
		}
		const T& operator()(size_t i,size_t j) const{
			return data[i][j]; 
		}
		using const_iterator = decltype(data.cbegin());
		std::vector<std::vector<T>>::const_iterator begin() ;
		std::vector<std::vector<T>>::const_iterator end() ;
		Matrix<T>& operator +=(const Matrix<T>& other){
			const size_t rows=GetRows();
			const size_t cows=GetCows();
			if(rows!=other.GetRows()|| cows!=other.GetCows()){
				throw std::invalid_argument("Different size");
			}
			for(size_t i=0;i!=rows;i++){
				for(size_t j=0;j!=cows;j++){
					data[i][j]+=other.data[i][j];
				}
				
			}
			return *this;
		}
		template <typename T1>	
		bool operator ==(const Matrix<T1>& other)const{
			const size_t rows=GetRows();
			const size_t cows=GetCows();
			if(rows!=other.GetRows()|| cows!=other.GetCows()){
				return false;
			}
			for(size_t i=0;i!=rows;i++){
				for(size_t j=0;j!=cows;j++){
					if(!((*this)(i,j)==other(i,j))){
						return false;
					}
				}
				
			}
			return true;
		}
		
		
};
template <typename T>
std::ostream& operator <<(std::ostream& out,const Matrix<T>& matrix);

template <typename T>
std::istream& operator >>(std::istream& in,const Matrix<T>& matrix);


template <typename T>
Matrix<T> operator +(const Matrix<T>& m1,const Matrix<T>& m2){
			auto temp {m1};
			temp+=m2;
			return temp;
		}

template <typename T1,typename T2>
bool operator !=(const Matrix<T1>& m1,const Matrix<T2>& m2){
		return !(m1==m2);
}
#include "matrix.hpp"
#endif //MATRIX_H
