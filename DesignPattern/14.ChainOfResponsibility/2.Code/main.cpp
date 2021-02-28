#include <iostream>
#include "ChainOfResponsibility.h"

int main()
{
	// �������ߣ��鳤�����磬���ܣ��ϰ�
	Approver *zuzhang, *bingge, *chunzong, *laoban;

	zuzhang = new GroupLeader("����");
	bingge = new Head("����");
	chunzong = new Manager("����");
	laoban = new Boss("���ϰ�");

	zuzhang->setSuperior(bingge);
	bingge->setSuperior(chunzong);
	chunzong->setSuperior(laoban);

	// ����������
	Bill *bill1 = new Bill(1, "Jungle", 8); 
	Bill *bill2 = new Bill(2, "Lucy", 14.4);
	Bill *bill3 = new Bill(3, "Jack", 32.9);
	Bill *bill4 = new Bill(4, "Tom", 89);

	// ȫ���Ƚ����鳤����
	zuzhang->handleRequest(bill1); printf("\n");
	zuzhang->handleRequest(bill2); printf("\n");
	zuzhang->handleRequest(bill3); printf("\n");
	zuzhang->handleRequest(bill4);

	printf("\n\n");
	system("pause");
	return 0;
}