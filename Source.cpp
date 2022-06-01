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
	//������������ 
	//����������� 
	//......................
	//������ ������� ������
	//������ ����������� �����
	//......................
	//������ ������� � ������
	//�������������:
	//		�������� []
	//		����� at find � ������
	//����������������:
	//		������ ����������
	//		������ ������� �� ����������
	//......................
	//��������� � �������� ������

	void reverse() {

	}

private:
	//������ � ������� (���������)
	A *allocate(int blocks) {
		A *data = new A[blocks];
		return data;
	}
	//��������� ������ ��������� malloc calloc
	//������������� ������ ����������� realloc
	//������������ ������ ����������� free
	//......................
	//���� ������, � ������� ���(���) ����
	int *data_;
	int size_;
	//......................
	//��������� ���������

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
	collection.insert(collection.begin(), 2); // ���� ���������� ������� � ��� ����������
	for (const auto &el : collection) { // ������ ��� ������ � ����� ���������, ��������� ��� ��������(���� 
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