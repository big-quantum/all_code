#include<bits/stdc++.h>
using namespace std;
int n;
 struct shuxing
{
	string name;	//����
	double str;	//����
	double dex; 	//����
	double sudu;	//�ٶ�
	double tizhi; 	//����
};
 
shuxing player;	//����ȫ�ֱ�����ɫ������Ϊ�ṹ
shuxing enemy[10] = { "ʷ��ķ",3,3,3,5 };//����ȫ�ֱ��� �������Ϊ�ṹ����
 
double hp[2];	//����ȫ�ֱ�������hp��hp[0]Ϊ��ҵģ�hp[1]Ϊ�����
int ski;	//ski���������ʲô����
double def=1;	//def�������������˺���ֵ���
string laji;	//���ڳԵ�û���������
 
bool combat(int);	//guaiΪ������
void playershuxing();	//�������
void guaiwushuxing(int);	//��������
int minjie(int);	//���ݴ����ı�������
int skill();	//���ܺ����������ͷż���
void combatend(int,bool);
 
int main(){
	int guai = 0;
	bool zhandou;
	cout << "��ӭ������Ϸ���硪����LOL����ð�ա�" << endl;
	cout << "��������������֣�";
	getline(cin, player.name);
 
	player.str = 5;
	player.dex = 5;
	player.sudu = 5;
	player.tizhi = 5;
	hp[0] = int(player.tizhi * 5);	//��ʼ������
 
	playershuxing();	//���ú������鿴�û�����
	
	cout << "��⣬�������˵�һֻ���" << endl;
	hp[1] = int(enemy[guai].tizhi * 4);	//��������г�ʼ��Ѫ��
	guaiwushuxing(guai);	//��ʾ��������
	zhandou =combat(guai);	//ս���������ս�����
	combatend(guai, zhandou);	//���ս������
 	
 
 
	system("pause");
	return 0;
	
}
 
void playershuxing()	//�鿴 ��ҵ� ���Ե��ñ�����
{
	cout << "��ã�---" << player.name << "---���������Ϊ��" << endl;
	cout << "������Ӱ���˺�����" << player.str << endl;
	cout << "���ݣ�������������" << player.dex << endl;
	cout << "�ٶȣ�Ӱ�칥�٣���" << player.sudu << endl;
	cout << "���ʣ�Ӱ�����ˣ���" << player.tizhi << endl;
	cout << "�������ֵ��" << player.tizhi * 5 << "�����ʵ�5����" << endl;
	if (hp[0] > player.tizhi * 5)hp[0] = player.tizhi * 5;
	cout << "��ǰ����ֵ��" << hp[0] << endl;
	system("pause");
	cout << endl;
}
 
void guaiwushuxing(int guai)//�鿴 ���� �����Ե��ñ�����
{
	cout << "��ǰ����***" << enemy[guai].name << "***������Ϊ��" << endl;
	cout << "������Ӱ���˺�����" << enemy[guai].str << endl;
	cout << "���ݣ�������������" << enemy[guai].dex << endl;
	cout << "�ٶȣ�Ӱ�칥�٣���" << enemy[guai].sudu << endl;
	cout << "���ʣ�Ӱ�����ˣ���" << enemy[guai].tizhi << endl;
	cout << "�������ֵ��" << enemy[guai].tizhi * 4 << "�����ʵ�4����" << endl;
	if (hp[1] >enemy[guai].tizhi * 4)hp[1] = player.tizhi * 4;
	cout << "��ǰ����ֵ��" << hp[1] << endl;
	system("pause");
	cout << endl;
}
 
bool combat(int guai)
{
	double lun = 1, V[2], v;	//lun�غ�����V[2]���飨2��Ա���ֱ�����Һ͹����ٶȣ���v�ٶȻ���
	char i,act;	//i�ж�������1Ϊ���0Ϊ��ң���actΪ�ж�����
	double minguai;	//���﹥�������Ĳ���
	int dam;	//damΪ�˺���ÿ��ʵʱ����
 
	if (player.sudu < enemy[guai].sudu) 
	{ 
		v = player.sudu;
	}
	else {  v = enemy[guai].sudu; }	//˫���ٶȵ͵ģ�Ϊ�ٶȻ���
	V[0] = V[1] = 0;
	cout << "����ս����" << endl;
	
 
	for (;hp[0] > 0 && hp[1] > 0;)	//Ѫ��������0����ִ��ս��ѭ��
	{
		cout << "*********** �� *** �� *** �� *** �� *** �� *** �� ***********" << endl;
		cout << "�����ǵ�--->>> " << lun << " <<<---�غϡ�" << endl;
		V[0] = V[0] + player.sudu;
		V[1] = V[1] + enemy[guai].sudu;	//�غϿ�ʼ�������ٶȶ�����
		while (V[0] >= v || V[1] >= v)	//ֻҪ��һ�����ٶȱ��ٶȻ����ߣ����ж��ٶȣ��ٶȸߵĳ���
		{
			if (V[0] < V[1]) { i = 1; }
			else { i = 0; }	//�����ж�����������˭�ȶ�
			if (i == 0)	//����ж���
			{
				cout << "�����ֵ����ж��ˣ�" << endl;
				cout << "�������Ķ�����" << endl;
				cout << "1.����\n2.����\n3.ʹ�ü���\n��Ķ����ǣ� ";
				act = cin.get();
				getline(cin,laji);
				cout << endl;
				if (act == '1')	//����
				{
					dam = int(player.str*minjie(guai)*(player.str / enemy[guai].tizhi));
					cout << "��� " << enemy[guai].name << " ����� " << dam << " ���˺���";
					hp[1] = hp[1] - dam;
					cout << "���˻��� " << hp[1] << " ������ֵ��" << endl << endl;
					V[0] = V[0] - v;
				}
				else if (act == '2')	//����
				{
					V[0] = 0;
					def = 0.25;
					cout << "������˷�������ķ���ָ������ˣ�" << endl << endl;
				}
				else if (act == '3')	//ʹ�ü���
				{
					act=skill();
				}
				else { cout << "����������������붯�����룺"; }
			}
			if (i == 1)	//�����ж���
			{
				cout << enemy[guai].name << "  ���й�����" << endl;
				
				minguai=minjie(guai);
				if (0==minguai) { minguai = 3; }
				else if (1 == minguai) { minguai = 1; }
				else if (2 == minguai) { minguai = 1 / 2; }
				else if (3 == minguai) { minguai = 1 / 3; }
 
				dam = int(def*enemy[guai].str*minguai*(enemy[guai].str / player.tizhi));
				hp[0] = hp[0] - dam;	//Ѫ������
				cout << "���ܵ��� " << dam << " ���˺����㵱ǰѪ��Ϊ�� " << hp[0] << endl << endl;
				if(def<=1)def = def + 0.1;
				V[1] = V[1] - v;
			}
			if (hp[0] <= 0 || hp[1] <= 0)break;
		}
		lun++;//�������ٶȶ�С���ٶȻ���ʱ���غ���+1
		def = 1;	//����ϵ����1
	}
	if (hp[1] <= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
int skill()
{
	if (ski == 0) { cout << "�㲢δѧ�Ἴ�ܣ��ж�ʧ�ܡ�" << endl; 	return 4;}
 
}
 
int minjie(int guai)	//���ݲ��������ڼ����˺�����
{
	double a, b;
	if (player.dex >= enemy[guai].dex * 2)return 3;
	else if (player.dex >= enemy[guai].dex*1.5)return 2;
	else if (player.dex >= enemy[guai].dex )
	{
		a = player.dex / enemy[guai].dex;	//ȡֵ��Χ1.5~1
		b = clock() % 100 ;	//��0~99֮�����һ����
		a = (a * 100 - 100) * 2;
		if (b <= a)return 2;
		else return 1;
	}
	else
	{
		a= player.dex / enemy[guai].dex;	//ȡֵ��Χ1~0
		a = a * 100;
		b = clock() % 100;	//��1~100֮�����һ����
		if (b <= a)return 1;
		else return 0;
	}
}
 
void combatend(int guai,bool a)
{
	double heal;
	if (a == true)
	{
		cout << "ս������........." ;
		system("pause");
		system("cls");
		cout << "***" << enemy[guai].name << "***��������ʤ������" << endl;
		if (hp[0] <= 0)hp[0] = 1;
		cout << "�㵱ǰ����ֵΪ��" << hp[0] << "�㡣" << endl;
		heal = int(player.tizhi * 2 + enemy[guai].tizhi * 1);
		hp[0] = hp[0] + heal;
		if (hp[0] >= player.tizhi * 5)hp[0] = player.tizhi * 5;
		cout << "����ս��ʤ���������� " << heal << " �����ƣ��㵱ǰ����ֵΪ	" << hp[0] << " �㡣" << endl;
		player.str = player.str + 1;
		player.dex = player.dex + 1;
		player.sudu = player.sudu + 1;
		player.tizhi = player.tizhi + 1;
		playershuxing();
	}
	else if (a == false)
	{
		cout << "ս������.........";
		system("pause");
		system("cls");
		cout << "---" << player.name << "---�ɳܵ�ʧ���ˣ�" << endl;
		cout << "�㱻һ���󺺱��˾ջ���" << endl;
		cout << "�㱻�������б��˾ջ���" << endl;
		cout << "�㱻�����������˾ջ���" << endl;
		cout << "�㱻�͵�̩����Ȼ�������г�jj������" << endl;
		cout << "�㱻�ͽ����ĳ�����º������" << endl;
		cout << "��������ʮ�˽����ݡ�������" << endl;
		cout << "���ǲҲ��̶ð���" << endl;
		cout << "�����񿴲���ȥ�ˣ����㸴����" << endl;
		player.tizhi = player.tizhi + 4;
		heal = int(player.tizhi * 2 + enemy[guai].tizhi * 1);
		hp[0] = 1;
		hp[0] = hp[0] + heal;
		if (hp[0] >= player.tizhi * 5)hp[0] = player.tizhi * 5;
		cout << "�����������������ƣ���ظ��� " << heal << " ��Ѫ����" << endl;
		cout << "��ĵ�ǰѪ��Ϊ " << hp[0] << " �㡣" << endl;
		cout << "������ԡ�˴�����Ĺ�ԣ������������� 4 �㡣��˵����������ˡ�" << endl;
		playershuxing();
	}
}

