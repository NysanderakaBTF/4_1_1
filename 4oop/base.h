#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>
class base
{
protected:
	std::string name;
	base* head;
	int status;
	std::vector<base*> ar_p;
public:
	
	base(base*, std::string = "Def_name", int stat = 0);
	void set_name(std::string);
	std::string get_name();
	void display();
	void rebase(base* new_per);
	base* get_head_p();
	base* find_b_n(std::string fn);
	void print_with_stat();
	
};
#endif // 


