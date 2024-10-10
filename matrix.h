#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>

template <typename T>

class Matrix{
	private:
		std::vector<std::vector<T>> data;
		void MakeRectangle();
	public:
		size_t GetRows()const;
		size_t GetCows()const;
		
};
#include "matrix.hpp"
#endif //MATRIX_H
