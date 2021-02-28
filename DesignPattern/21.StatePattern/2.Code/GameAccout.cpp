#include "GameAccount.h"
#include "Level.h"
#include <Windows.h>
#include <time.h>
#define  random(x) (rand()%x)

GameAccount::GameAccount(){
	printf("������Ϸ��ɫ�����֣�100������PRIMARY\n");
	score = 100;
	name = "none";
	setLevel(new Primary(this));
}

GameAccount::GameAccount(string iName){
	printf("������Ϸ��ɫ�����֣�100������PRIMARY\n");
	score = 100;
	name = iName;
	setLevel(new Primary(this));
}

void GameAccount::setLevel(Level* iLevel){
	this->level = iLevel;
}

string GameAccount::getName(){
	return name;
}

void GameAccount::playCard(){
	this->level->playCard();

	Sleep(100);
	srand((int)time(0));
	int res = random(2);
	if (res % 2 == 0){
		this->win();
	}
	else{
		this->lose();
	}

	this->level->upgradeLevel();
}

void GameAccount::win(){
	if (this->getScore() < 200){
		setScore(getScore() + 50);
	}
	else{
		setScore(getScore() + 100);
	}
	printf("\n\tʤ�������»���Ϊ %d\n", score);
}

void GameAccount::lose(){
	setScore(getScore() + 30);
	printf("\n\t���ƣ����»���Ϊ %d\n", score);
}

int GameAccount::getScore(){
	return this->score;
}

void GameAccount::setScore(int iScore){
	this->score = iScore;
}