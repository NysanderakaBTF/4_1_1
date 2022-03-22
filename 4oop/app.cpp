#include "app.h"
#include <iostream>
#include <string>

app::app(base_c1* p):base(p, "root")
{
		//this->head = new base(p);
		//this->head = p;
		//Тут не добавляется элемент
		// мы не можем ничего добавить
		//root = this;
}

void app::build_tree_objects()
{
	base_c1* temp = nullptr;
	app* now = this;
	std::string n_a, n_b;
	if (this->get_head_p() == nullptr) {
		std::cin >> n_a;
		//root->set_name(n_a);
		//head = new base(this->get_head_p(), n_a);
		this->set_name(n_a);
	}
	else {
	//	temp = new base_c1(this->head, n_b);
	}
	
	do{
		std::cin >> n_a >> n_b;
		if(n_a!=n_b) {
			if (n_a == this->get_name()) {
				/*if (this->get_head_p() != nullptr)
					temp = new base_c1(this->get_head_p(), n_b);
				else*/
					temp = new base_c1(now, n_b);
			}
			else {
				/*now = now->ar_p[now->ar_p.size() - 1];
				temp = new base_c1(now, n_b);*/
				if(temp->get_name()==n_a)
					temp = new base_c1(temp, n_b);
				else 
					temp = new base_c1(temp->get_head_p(), n_b);
				//now->build_tree_objects();
			}
		}
	} while (n_a != n_b);

}

int app::exec_app()
{
	this->display();
	//this->root->rebase(this->root->ar_p[1]->ar_p[1]);
	//std::cout << std::endl;
	//this->display();
	return 0;
}
