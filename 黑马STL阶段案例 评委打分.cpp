#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>   //随机数头文件

class person    //自定义选手类
{
public:
	person(string name, int score)    //构造函数赋初值
	{
		this->m_name = name;
		this->m_score = score;
	}

	//选手属性：姓名 平均分数
	string m_name;
	int m_score;
};
void createperson(vector<person>& v)      //传入vector  一定要用引用的方式传入
{
	string nameSeed = "ABCDE";    //名称种子
	for (int i = 0; i < 5; i++)    //小技巧
	{
		string name = "选手";    //名字的共同点
		name += nameSeed[i];     //再拼接上名字的不同点

		int score = 0;    //默认分数为0

		person p(name, score);

		//将创建的person对象 放入到容器中
		v.push_back(p);
	}
}

//打分
void setscore(vector<person> & v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数 放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)     //十个评委
		{
			int score = rand() % 41 + 60;  // 随机数 60 ~ 100
			d.push_back(score);
		}

		cout << "选手： " << it->m_name << " 打分： " << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;

		//排序
		sort(d.begin(), d.end());

		//去除最高和最低分   所以才要用deque
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; //累加每个评委的分数
		}

		int avg = sum / d.size();     //此时size是8人

		//将平均分 赋值给选手身上
		it->m_score = avg;
	}

}

void showscore(vector<person> & v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << it->m_name << " 平均分： " << it->m_score << endl;
	}
}

int main()
{
	//随机数种子   给后面做铺垫
	srand((unsigned int)time(NULL));

	//1、创建5名选手
	vector<person>v;      //创建存放选手的容器v  存放的类型是自己定义的类型person
	createperson(v);     //是给五个人打分  所以传入容器v
	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名： " << (*it).m_Name << " 分数： " << (*it).m_Score << endl;
	//}

	//2、打分
	setscore(v);     //同理 传入容器v

	//3、显示最后得分
	showscore(v);
	system("pause");
	return 0;
}
