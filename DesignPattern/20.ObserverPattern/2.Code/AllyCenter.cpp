#include "AllyCenter.h"
#include "Observer.h"

/***********   AllyCenter    ****************/
AllyCenter::AllyCenter(){
	printf("�󼪴���������Լ�!\n");
}

// �������
void AllyCenter::join(Observer* player){
	if (playerList.size() == 4){
		printf("�������\n");
		return;
	}
	printf("��� %s ����\n", player->getName().c_str());
	playerList.push_back(player);
	if (playerList.size() == 4){
		printf("��ӳɹ�����Ҫ�ˣ�һ���ϣ�\n");
	}
}
// �Ƴ����
void AllyCenter::remove(Observer* player){
	printf("��� %s �˳�\n", player->getName().c_str());
	//playerList.remove(player);
}
/***********   AllyCenter    ****************/


/**********   AllyCenterController    *******/
AllyCenterController::AllyCenterController(){

}

// ʵ��֪ͨ����
void AllyCenterController::notify(INFO_TYPE infoType, std::string name){
	switch (infoType){
	case RESOURCE:
		for each (Observer* obs in playerList){
			if (obs->getName() != name){
				((Player*)obs)->come();
			}
		}
		break;
	case HELP:
		for each (Observer* obs in playerList){
			if (obs->getName() != name){
				((Player*)obs)->help();
			}
		}
		break;
	default:
		printf("Nothing\n");
	}
}
/**********   AllyCenterController    *******/