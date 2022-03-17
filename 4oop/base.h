#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>
class base
{
protected:
	std::string name;
	base* head;
	base* root;
public:
	std::vector<base*> ar_p;
	base(base*, std::string);
	void set_name(std::string);
	std::string get_name();
	void display();
	void rebase(base* new_per);
	base* get_head_p();

	
};
#endif // 


