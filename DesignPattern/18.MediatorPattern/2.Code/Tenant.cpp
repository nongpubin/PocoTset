/*
 * @Author: your name
 * @Date: 2021-02-28 22:19:36
 * @LastEditTime: 2021-03-07 12:21:01
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \npb\DesignPattern\18.MediatorPattern\2.Code\Tenant.cpp
 */
#include "Colleague.h"
#include "Mediator.h"

Tenant::Tenant(){
	name = "none";
	setPersonType(NONE_PERSON);
}

Tenant::Tenant(string iName){
	name = iName;
	setPersonType(TENANT);
}

void Tenant::ask(){
	printf("租客%s询问房东信息\n", name.c_str()); 
	(this->getMediator())->operation(this);
}

void Tenant::answer(){
	printf("租客姓名：%s\n", name.c_str());
}