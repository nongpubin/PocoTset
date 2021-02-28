#include <iostream>
#include "Iterator.h"

int main()
{
	vector<string> channelList = { "����Ƶ��", "�ƾ�Ƶ��", "����Ƶ��", "��ӰƵ��", "����Ƶ��", "ũҵƵ��", "�Ĵ�����", "�ɶ�����" };
	// ��������
	Television *tv = new Television(channelList);
	// ����ң����
	Iterator *remoteControl = tv->createIterator();

	// ˳�����
	printf("˳�����:\n");
	remoteControl->first();
	// ������������Ƶ��
	while (remoteControl->hasNext()){
		remoteControl->currentChannel();
		remoteControl->next();
	}

	printf("\n\n");

	// �������
	printf("�������:\n");
	remoteControl->last();
	// ������������Ƶ��
	while (remoteControl->hasPrevious()){
		remoteControl->currentChannel();
		remoteControl->previous();
	}

	printf("\n\n");
	system("pause");
	return 0;
}