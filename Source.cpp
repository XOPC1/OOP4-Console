#include <iostream>
#include <xmemory>
#include <chrono>
#include <vector>
#include <new>


void F00(const Collection &a) {
	if (!a.empty()) {
		auto &tmp {a.front()};
	}
}
class A {

};

class Collection {
public:
	Collection();
	Collection(int size);
	Collection(Collection&&other);
	Collection(const Collection &other);
	~Collection();
	Collection &operator = (const Collection &other);
	Collection &operator = (Collection &&other);

	auto at(int pos)->int &;
	auto at(int pos)const->const int &;
	int &operator[](int pos);
	const int &operator[](int pos)const;
	int &front() {
		return data_[0];
	};
	const int &front()const;
	int& back();
	const int &back()const;
	//----------------------
	int *data();
	const int *data()const;
	int capacity()const;
	bool empty()const {
		if (size_ > 0)
			return false;
		else
			return true;
	}

	//......................
	//конструкторы 
	//деструкторы 
	//......................
	//мотоды вставки данных
	//методы уничтожения данны
	//......................
	//методы доступы к данным
	//произыовльные:
	//		оператор []
	//		метод at find и прочие
	//последовательные:
	//		классы итераторов
	//		методы которые их возвращают
	//......................
	//операторы и свойства класса

	void reverse() {

	}

private:
	//работа с памятью (аллокация)
	A *allocate(int blocks) {
		A *data = new A[blocks];
		return data;
	}
	//выделение памяти аллокация malloc calloc
	//перевыделение памяти реаллокация realloc
	//освобождение памяти деаллокация free
	//......................
	//поля данных, у вектора два(три) поля
	int *data_;
	int size_;
	//......................
	//приватные состояния

};

int main() {

	Collection r;
	F00(r);

	int *p;
	/*std::auto_ptr <int> p_auto;
	std::unique_ptr <int> p_uniq;
	std::shared_ptr <int> p_share;
	std::weak_ptr <int> p_week;*/

	std::vector<int> collection;
	collection.push_back(1);
	collection.insert(collection.begin(), 2); // куда разместить элемент и что разместить
	for (const auto &el : collection) { // узнаем где начало и конец коллекции, выписывая все элементы(если 
		std::cout << el << ' ';
	}
	for (std::vector<int>::const_iterator it = collection.cbegin();
		it != collection.cend();
		++it)
	{
		std::cout << *it << ' ';
	}

	for (auto &el : collection)
	{
		std::cout << el << ' ';
	}
	for (std::vector<int>::iterator it = collection.begin();
		it != collection.end();
		++it)
	{
		std::cout << *it << ' ';
	}
	//std::vector<std::chrono::seconds>a;
	auto p_uniq_int = std::make_unique <int>(7);
	std::cout << *p_uniq_int;
}