#include <cmath>
#include <map>
#include <iostream>

const std::map<char, int> letter2phone = { 
	{'a', 2}, {'b', 2}, {'c', 2}, {'d', 3},
	{'e', 3}, {'f', 3}, {'g', 4}, {'h', 4},
	{'i', 1}, {'j', 1}, {'k', 5}, {'l', 5},
	{'m', 6}, {'n', 6}, {'o', 0}, {'p', 7},
	{'q', 0}, {'r', 7}, {'s', 7}, {'t', 8},
	{'u', 8}, {'v', 8}, {'w', 9}, {'x', 9},
	{'y', 9}, {'z', 0}
};

inline std::string findShortestSeq(const int phone_number, 
                                   const std::map<int,std::string>& dictionary)
{
	std::map<int,std::string>::const_iterator it;
	std::string st = std::to_string(phone_number);
	std::string res;
	int idx = st.length()-1;      	
	int num = phone_number;
/*	       
	do {
		int nb = num / pow(10,idx);
		it = dictionary.find(nb);
		if (it != dictionary.end())    
    		res += (it->second)*pow(10,st.length()-1-i);
		++idx;
	} while (m != 0); 

	if (num > 0)
*/    	return "No solution.";

//	return res;
};

inline int word2phone(const std::string& st)
{   
	int res = 0;
	std::map<char,int>::const_iterator it;

	for (int i = 0; i < st.length(); i++) {
		it = letter2phone.find(st[i]);
		if (it == letter2phone.end())    
    		return -1;  
		res += (it->second)*pow(10,st.length()-1-i);
	}	
	return res;
};

int main()
{	
	std::map<int,std::string> dictionary;

	int phone_number = 0;
	int number_of_words = 0;

	std::cin >> phone_number;	

	do {
		std::cin >> number_of_words;	
		for (int i = 0; i < number_of_words; i++) {
			std::string st;
			std::cin >> st;
			dictionary.insert(std::pair<int,std::string>(word2phone(st),st));
		}
		std::cout << findShortestSeq(phone_number, dictionary) << std::endl;		
		std::cin >> phone_number;	
	} while (phone_number != -1);

	return 0;
}; 
