#include "ED_Map.h"

namespace ED {

//const int ED_Map::sizeMap = 100;

ED_Map::KeyValuePair::KeyValuePair(const std::string& k, const std::string& v)
	: key(k), value(v), next1(nullptr), next2(nullptr) {}

ED_Map::ED_Map()
{
	for (int i = 0; i < sizeMap; i++) {
		data1[i] = nullptr;
		data2[i] = nullptr;
	}
}

ED_Map::~ED_Map()
{
	for (int i = 0; i < sizeMap; i++) {
		while (data1[i] != nullptr) {
			KeyValuePair* temp = data1[i];
			data1[i] = data1[i]->next1;
			delete temp;
		}
	}
}

void ED_Map::insertAB(const std::string& key, const std::string& value)
{
	int index = hash(key);
	KeyValuePair* newPair = new KeyValuePair(key, value);
	newPair->next1 = data1[index];
	data1[index] = newPair;
	/////////////////////////////////////////////////////
	index = hash(value);
	newPair->next2 = data2[index];
	data2[index] = newPair;
}

void ED_Map::insertBA(const std::string& key, const std::string& value)
{
	insertAB(value, key);
}

bool ED_Map::getAB(const std::string& key, std::string& value) const
{
	int index = hash(key);
	KeyValuePair* current = data1[index];
	while (current != nullptr) {
		if (current->key == key) {
			value = current->value;
			return true;
		}
		current = current->next1;
	}
	return false;
}

bool ED_Map::getBA(const std::string& key, std::string& value) const
{
	int index = hash(key);
	KeyValuePair* current = data2[index];
	while (current != nullptr) {
		if (current->value == key) {
			value = current->key;
			return true;
		}
		current = current->next2;
	}
	return false;
}

unsigned int ED_Map::hash(const std::string& key) const
{
	unsigned int sum = 0;
	for (char c : key) {
		sum += static_cast<unsigned int>(c);
	}
	return sum % sizeMap;
}

} // namespace ED