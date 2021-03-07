/*
 * @Author: your name
 * @Date: 2021-02-28 22:19:36
 * @LastEditTime: 2021-03-07 11:35:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \npb\DesignPattern\17.IteratorPattern\2.Code\Aggregate.cpp
 */
#include "Iterator.h"

Television::Television(){}

Television::Television(vector<string> iChannelList){
	this->channelList = iChannelList;
}

Iterator* Television::createIterator(){
	RemoteControl *it = new RemoteControl();
	it->setTV(this);
	return (Iterator*)it;
}

int Television::getTotalChannelNum(){
	return channelList.size();
}

void Television::play(int i){
	printf("当前频道 :  %s \n", channelList[i].c_str());
}