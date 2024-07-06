#include<bits/stdc++.h>
using namespace std;
int n;
 struct shuxing
{
	string name;	//名字
	double str;	//力量
	double dex; 	//敏捷
	double sudu;	//速度
	double tizhi; 	//体质
};
 
shuxing player;	//声明全局变量角色，类型为结构
shuxing enemy[10] = { "史莱姆",3,3,3,5 };//声明全局变量 怪物，类型为结构数组
 
double hp[2];	//声明全局变量数组hp，hp[0]为玩家的，hp[1]为怪物的
int ski;	//ski决定玩家有什么技能
double def=1;	//def防御参数，和伤害数值相乘
string laji;	//用于吃掉没意义的输入
 
bool combat(int);	//guai为怪物编号
void playershuxing();	//玩家属性
void guaiwushuxing(int);	//怪物属性
int minjie(int);	//敏捷带来的倍击函数
int skill();	//技能函数，用于释放技能
void combatend(int,bool);
 
int main(){
	int guai = 0;
	bool zhandou;
	cout << "欢迎来到游戏世界——《LOL世界冒险》" << endl;
	cout << "请先输入你的名字：";
	getline(cin, player.name);
 
	player.str = 5;
	player.dex = 5;
	player.sudu = 5;
	player.tizhi = 5;
	hp[0] = int(player.tizhi * 5);	//初始化属性
 
	playershuxing();	//调用函数，查看用户属性
	
	cout << "糟糕，你遇见了第一只怪物！" << endl;
	hp[1] = int(enemy[guai].tizhi * 4);	//给怪物进行初始化血量
	guaiwushuxing(guai);	//显示怪物属性
	zhandou =combat(guai);	//战斗，并输出战斗结果
	combatend(guai, zhandou);	//输出战斗结算
 	
 
 
	system("pause");
	return 0;
	
}
 
void playershuxing()	//查看 玩家的 属性调用本函数
{
	cout << "你好，---" << player.name << "---。你的属性为：" << endl;
	cout << "力量（影响伤害）：" << player.str << endl;
	cout << "敏捷（触发倍击）：" << player.dex << endl;
	cout << "速度（影响攻速）：" << player.sudu << endl;
	cout << "体质（影响免伤）：" << player.tizhi << endl;
	cout << "最大生命值：" << player.tizhi * 5 << "（体质的5倍）" << endl;
	if (hp[0] > player.tizhi * 5)hp[0] = player.tizhi * 5;
	cout << "当前生命值：" << hp[0] << endl;
	system("pause");
	cout << endl;
}
 
void guaiwushuxing(int guai)//查看 怪物 的属性调用本函数
{
	cout << "当前怪物***" << enemy[guai].name << "***的属性为：" << endl;
	cout << "力量（影响伤害）：" << enemy[guai].str << endl;
	cout << "敏捷（触发倍击）：" << enemy[guai].dex << endl;
	cout << "速度（影响攻速）：" << enemy[guai].sudu << endl;
	cout << "体质（影响免伤）：" << enemy[guai].tizhi << endl;
	cout << "最大生命值：" << enemy[guai].tizhi * 4 << "（体质的4倍）" << endl;
	if (hp[1] >enemy[guai].tizhi * 4)hp[1] = player.tizhi * 4;
	cout << "当前生命值：" << hp[1] << endl;
	system("pause");
	cout << endl;
}
 
bool combat(int guai)
{
	double lun = 1, V[2], v;	//lun回合数，V[2]数组（2成员，分别是玩家和怪物速度），v速度基数
	char i,act;	//i行动参数（1为怪物，0为玩家），act为行动参数
	double minguai;	//怪物攻击带来的参数
	int dam;	//dam为伤害，每次实时计算
 
	if (player.sudu < enemy[guai].sudu) 
	{ 
		v = player.sudu;
	}
	else {  v = enemy[guai].sudu; }	//双方速度低的，为速度基数
	V[0] = V[1] = 0;
	cout << "进入战斗。" << endl;
	
 
	for (;hp[0] > 0 && hp[1] > 0;)	//血量都大于0，则执行战斗循环
	{
		cout << "*********** 这 *** 是 *** 新 *** 的 *** 回 *** 合 ***********" << endl;
		cout << "现在是第--->>> " << lun << " <<<---回合。" << endl;
		V[0] = V[0] + player.sudu;
		V[1] = V[1] + enemy[guai].sudu;	//回合开始，两人速度都增加
		while (V[0] >= v || V[1] >= v)	//只要有一个人速度比速度基数高，就判断速度，速度高的出手
		{
			if (V[0] < V[1]) { i = 1; }
			else { i = 0; }	//根据行动快慢，决定谁先动
			if (i == 0)	//玩家行动轮
			{
				cout << "现在轮到你行动了！" << endl;
				cout << "请决定你的动作：" << endl;
				cout << "1.攻击\n2.防御\n3.使用技能\n你的动作是： ";
				act = cin.get();
				getline(cin,laji);
				cout << endl;
				if (act == '1')	//攻击
				{
					dam = int(player.str*minjie(guai)*(player.str / enemy[guai].tizhi));
					cout << "你对 " << enemy[guai].name << " 造成了 " << dam << " 点伤害。";
					hp[1] = hp[1] - dam;
					cout << "敌人还有 " << hp[1] << " 点生命值。" << endl << endl;
					V[0] = V[0] - v;
				}
				else if (act == '2')	//防御
				{
					V[0] = 0;
					def = 0.25;
					cout << "你进行了防御，你的防御指数提高了！" << endl << endl;
				}
				else if (act == '3')	//使用技能
				{
					act=skill();
				}
				else { cout << "输入错误，请重新输入动作代码："; }
			}
			if (i == 1)	//怪物行动轮
			{
				cout << enemy[guai].name << "  进行攻击！" << endl;
				
				minguai=minjie(guai);
				if (0==minguai) { minguai = 3; }
				else if (1 == minguai) { minguai = 1; }
				else if (2 == minguai) { minguai = 1 / 2; }
				else if (3 == minguai) { minguai = 1 / 3; }
 
				dam = int(def*enemy[guai].str*minguai*(enemy[guai].str / player.tizhi));
				hp[0] = hp[0] - dam;	//血量减少
				cout << "你受到了 " << dam << " 点伤害。你当前血量为： " << hp[0] << endl << endl;
				if(def<=1)def = def + 0.1;
				V[1] = V[1] - v;
			}
			if (hp[0] <= 0 || hp[1] <= 0)break;
		}
		lun++;//当两人速度都小于速度基数时，回合数+1
		def = 1;	//防御系数归1
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
	if (ski == 0) { cout << "你并未学会技能，行动失败。" << endl; 	return 4;}
 
}
 
int minjie(int guai)	//敏捷参数，用于计算伤害倍数
{
	double a, b;
	if (player.dex >= enemy[guai].dex * 2)return 3;
	else if (player.dex >= enemy[guai].dex*1.5)return 2;
	else if (player.dex >= enemy[guai].dex )
	{
		a = player.dex / enemy[guai].dex;	//取值范围1.5~1
		b = clock() % 100 ;	//在0~99之间随机一个数
		a = (a * 100 - 100) * 2;
		if (b <= a)return 2;
		else return 1;
	}
	else
	{
		a= player.dex / enemy[guai].dex;	//取值范围1~0
		a = a * 100;
		b = clock() % 100;	//在1~100之间随机一个数
		if (b <= a)return 1;
		else return 0;
	}
}
 
void combatend(int guai,bool a)
{
	double heal;
	if (a == true)
	{
		cout << "战斗结束........." ;
		system("pause");
		system("cls");
		cout << "***" << enemy[guai].name << "***死亡！你胜利啦！" << endl;
		if (hp[0] <= 0)hp[0] = 1;
		cout << "你当前生命值为：" << hp[0] << "点。" << endl;
		heal = int(player.tizhi * 2 + enemy[guai].tizhi * 1);
		hp[0] = hp[0] + heal;
		if (hp[0] >= player.tizhi * 5)hp[0] = player.tizhi * 5;
		cout << "由于战斗胜利，你获得了 " << heal << " 点治疗，你当前生命值为	" << hp[0] << " 点。" << endl;
		player.str = player.str + 1;
		player.dex = player.dex + 1;
		player.sudu = player.sudu + 1;
		player.tizhi = player.tizhi + 1;
		playershuxing();
	}
	else if (a == false)
	{
		cout << "战斗结束.........";
		system("pause");
		system("cls");
		cout << "---" << player.name << "---可耻的失败了！" << endl;
		cout << "你被一个大汉爆了菊花！" << endl;
		cout << "你被两个基佬爆了菊花！" << endl;
		cout << "你被三个人妖爆了菊花！" << endl;
		cout << "你被送到泰国，然后做了切除jj手术！" << endl;
		cout << "你被送进外国某个地下红灯区！" << endl;
		cout << "————十八禁内容————" << endl;
		cout << "真是惨不忍睹啊！" << endl;
		cout << "创世神看不下去了，将你复活了" << endl;
		player.tizhi = player.tizhi + 4;
		heal = int(player.tizhi * 2 + enemy[guai].tizhi * 1);
		hp[0] = 1;
		hp[0] = hp[0] + heal;
		if (hp[0] >= player.tizhi * 5)hp[0] = player.tizhi * 5;
		cout << "创世神对你进行了治疗，你回复了 " << heal << " 点血量。" << endl;
		cout << "你的当前血量为 " << hp[0] << " 点。" << endl;
		cout << "由于沐浴了创世神的光辉，你的体质提高了 4 点。这说明你更抗揍了。" << endl;
		playershuxing();
	}
}

