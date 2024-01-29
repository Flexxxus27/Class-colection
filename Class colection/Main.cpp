#include <iostream>
#include <string>


// коллекции и шаблонные классы
// типы коллекций:
// - линейный массив
//    - динамический  vector
//    - статичекский  array
// - списки
//    - односвязные forward_list 
//    - двусвязные списки list
//      - кольца
// - деревья set, map, и их производные
// - графы 
// ------------
// * очереди FIFO first inside first outside | queue
// * стэки   FILO first inside last outside  | stak


class DinamicArray {
private:
	float* data_; //где храним данные 
	int size_; // сколько
	//int capacity; требуется для более сложной, но эфективной работы с выделенной памятью

public:
	DinamicArray() :data_(nullptr), size_(0) {}
	
	DinamicArray(const DinamicArray& other){
		size_ = other.size_;
		data_ = new float[size_];
		for(int i = 0; i < size_; i++){
			data_[i] = other.data_[i];
		}
	}

	DinamicArray(DinamicArray&& other) {
		size_ = 0;
		data_ = nullptr;
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
	}



	~DinamicArray() {
		if (data_) {
			delete[] data_;
		}
	}

	void AddBack(float value) {
		if (data_) {
			auto tmp = new float[size_ + 1];
			for (int i = 0; i < size_; i++) {
				tmp[i] = data_[i];
			}
			tmp[size_] = value;
			std::swap(tmp, data_);
			size_ += 1;
			delete[] tmp;
		}
		else {
			data_ = new float[1] {value};
			size_ += 1;
		}
	}

	void PopBack() {
		if (data_) {
			auto tmp = new float[size_ - 1];
			for (int i = 0; i < size_ - 1; i++) {
				tmp[i] = data_[i];
			}
			std::swap(tmp, data_);
			size_ -= 1;
			delete[] tmp;
			if (size_ == 0) {
				delete[] data_;
				data_ = nullptr;
			}
		}
	}


	float& operator[](int n) {
		return data_[n];
	}
	const float& operator[](int n) const {
		return data_[n];
	}

	// оператор присваивания копирования
	DinamicArray& operator = (const DinamicArray& other) {
		if (data_) {
			delete[] data_;
		}
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
		return *this;
	}

	// оператор присваивания переноса
	DinamicArray& operator = (DinamicArray&& other) {
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
		return *this;
	}

};

	

	void FOO(DinamicArray obj){}


	int main() {
		setlocale(0, "");


		
		DinamicArray arrd;
		arrd.AddBack(1234.5);
		std::cout << arrd[0];
		FOO(arrd);
		arrd.PopBack();
		DinamicArray arrd2;
		arrd2 = arrd;


		
		
		return 0;
	}
		