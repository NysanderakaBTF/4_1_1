#ifndef APP_H
#define APP_H
#include<iostream>
#include "base.h"
#include "base_c1.h"
class app : public base
{
public:
	app(base_c1* p);
	void build_tree_objects();
	int exec_app();
};
#endif
