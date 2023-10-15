#pragma once
#include <string>


namespace ED {
	
	class ED_Map
	{
	private:
		static const int sizeMap = 100;

	public:
		struct KeyValuePair {
			std::string		key		;
			std::string		value	;
			KeyValuePair*	next1	;
			KeyValuePair*   next2   ;

			KeyValuePair(const std::string& k, const std::string& v);
		};

	private:
		KeyValuePair* data1[sizeMap];  // Розмір масиву ключ-значення мова А в мову Б
		KeyValuePair* data2[sizeMap];  // Розмір масиву ключ-значення мова Б в мову А
	public:
		ED_Map();
		~ED_Map();
		void insertAB(const std::string& key, const std::string& value); 
		void insertBA(const std::string& key, const std::string& value);
		bool getAB(const std::string& key, std::string& value) const;
		bool getBA(const std::string& key, std::string& value) const;
	private:
		unsigned int hash(const std::string& key) const;

	};

} // namespace ED




