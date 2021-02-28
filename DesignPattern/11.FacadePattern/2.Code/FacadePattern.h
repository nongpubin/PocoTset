#ifndef __FACADE_PATTERN_H__
#define __FACADE_PATTERN_H__

//��ϵͳ���ڴ�
class Memory
{
public:
	Memory(){}
	void selfCheck(){
		printf("���������ڴ��Լ졭��\n");
	}
};

//��ϵͳ��CPU
class CPU
{
public:
	CPU(){}
	void run(){
		printf("������������CPU���С���\n");
	}
};

//��ϵͳ��Ӳ��
class HardDisk
{
public:
	HardDisk(){}
	void read(){
		printf("����������ȡӲ�̡���\n");
	}
};

//��ϵͳ������ϵͳ
class OS
{
public:
	OS(){}
	void load(){
		printf("���������������ϵͳ����\n");
	}
};

//�����
class Facade
{
public:
	Facade(){
		memory = new Memory();
		cpu = new CPU();
		hardDisk = new HardDisk();
		os = new OS();
	}
	void powerOn(){
		printf("���ڿ�������\n");
		memory->selfCheck();
		cpu->run();
		hardDisk->read();
		os->load();
		printf("������ɣ�\n");
	}
private:
	Memory *memory;
	CPU *cpu;
	HardDisk *hardDisk;
	OS *os;
};

#endif //__FACADE_PATTERN_H__