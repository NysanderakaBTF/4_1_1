#ifndef APP_H
#define APP_H
#include<iostream>
#include "base.h"
#include "base_c1.h"
#include "base_c2.h"
#include "base_c3.h"
#include "base_c4.h"
#include "base_c5.h"
#include "base_c6.h"
class app : public base
{
private:
	int kolob = 0;
	// a как иначе узнат сколько состояний вводить???????
public:
	app(base_c1* p);
	void build_tree_objects();
	int exec_app();
};
#endif
