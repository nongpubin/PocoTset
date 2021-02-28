#include "Level.h"

/***********     Level    *************/
Level::Level(){

}

void Level::playCard(){
	this->play();
	this->doubleScore();
	this->changeCards();
	this->peekCards();
}

void Level::play(){
	printf("\tʹ�û�������,");
}

void Level::setGameAccount(GameAccount* iGameAccount){
	this->gameAccount = iGameAccount;
}

GameAccount* Level::getGameAccount(){
	return gameAccount;
}

/***********     Primary    *************/
Primary::Primary(){

}

Primary::Primary(GameAccount* iGameAccount){
	this->setGameAccount(iGameAccount);
}

Primary::Primary(Level* level){
	getGameAccount()->setLevel(level);
}

void Primary::doubleScore(){
	return;
}

void Primary::changeCards(){
	return;
}

void Primary::peekCards(){
	return;
}

void Primary::upgradeLevel(){
	if (this->getGameAccount()->getScore() > 150){
		this->getGameAccount()->setLevel(new Secondary(this));
		printf("\t������ ����SECONDARY\n\n");
	}
	else{
		printf("\n");
	}
}

/***********     Secondary    *************/
Secondary::Secondary(){

}

Secondary::Secondary(Level* level){
	this->setGameAccount(level->getGameAccount());
	getGameAccount()->setLevel(level);
}

void Secondary::doubleScore(){
	printf("ʹ��ʤ��˫�����ּ���");
}

void Secondary::changeCards(){
	return;
}

void Secondary::peekCards(){
	return;
}

void Secondary::upgradeLevel(){
	if (this->getGameAccount()->getScore() < 150){
		this->getGameAccount()->setLevel(new Primary(this));
		printf("\t������ ����PRIMARY\n\n");
	}
	else if (this->getGameAccount()->getScore() > 200){
		this->getGameAccount()->setLevel(new Professional(this));
		printf("\t������ ����PROFESSIONAL\n\n");
	}
}

/***********     Professional    *************/
Professional::Professional(){

}

Professional::Professional(Level* level){
	this->setGameAccount(level->getGameAccount());
	getGameAccount()->setLevel(level);
}

void Professional::doubleScore(){
	printf("ʹ��ʤ��˫�����ּ���,");
}

void Professional::changeCards(){
	printf("ʹ�û��Ƽ���");
}

void Professional::peekCards(){
	return;
}

void Professional::upgradeLevel(){
	if (this->getGameAccount()->getScore() < 200){
		this->getGameAccount()->setLevel(new Secondary(this));
		printf("\t������ ����SECONDARY\n\n");
	}
	else if (this->getGameAccount()->getScore() > 250){
		this->getGameAccount()->setLevel(new Final(this));
		printf("\t������ ����FINAL\n\n");
	}
}

/***********     Final    *************/
Final::Final(){

}

Final::Final(Level* level){
	this->setGameAccount(level->getGameAccount());
	getGameAccount()->setLevel(level);
}

void Final::doubleScore(){
	printf("ʹ��ʤ��˫�����ּ���,");
}

void Final::changeCards(){
	printf("ʹ�û��Ƽ���,");
}

void Final::peekCards(){
	printf("ʹ��͵�����Ƽ���");
}

void Final::upgradeLevel(){
	if (this->getGameAccount()->getScore() < 250){
		this->getGameAccount()->setLevel(new Professional(this));
		printf("\t������ ����PROFESSIONAL\n\n");
	}
	else{
		printf("\t%s �Ѿ�����߼�\n\n", this->getGameAccount()->getName().c_str());
	}
}