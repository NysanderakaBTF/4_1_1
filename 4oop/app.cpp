#include "app.h"
#include <iostream>
#include <string>

app::app(base_c1* p):base(p, "root")
{
		this->head = p;
		//root = this;
}

void app::build_tree_objects()
{
	std::string n_a, n_b;
	std::cin >> n_a;
	//root->set_name(n_a);
	base_c1* temp = nullptr;
	base* now = this;
	do{
		std::cin >> n_a >> n_b;
		if(n_a!=n_b) {
			if (n_a == now->get_name()) {
				temp = new base_c1(now, n_b);
			}
			else {
				now = now->ar_p[now->ar_p.size() - 1];
				temp = new base_c1(now, n_b);
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
