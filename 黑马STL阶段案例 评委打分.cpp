#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>   //�����ͷ�ļ�

class person    //�Զ���ѡ����
{
public:
	person(string name, int score)    //���캯������ֵ
	{
		this->m_name = name;
		this->m_score = score;
	}

	//ѡ�����ԣ����� ƽ������
	string m_name;
	int m_score;
};
void createperson(vector<person>& v)      //����vector  һ��Ҫ�����õķ�ʽ����
{
	string nameSeed = "ABCDE";    //��������
	for (int i = 0; i < 5; i++)    //С����
	{
		string name = "ѡ��";    //���ֵĹ�ͬ��
		name += nameSeed[i];     //��ƴ�������ֵĲ�ͬ��

		int score = 0;    //Ĭ�Ϸ���Ϊ0

		person p(name, score);

		//��������person���� ���뵽������
		v.push_back(p);
	}
}

//���
void setscore(vector<person> & v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί�ķ��� ���뵽deque������
		deque<int>d;
		for (int i = 0; i < 10; i++)     //ʮ����ί
		{
			int score = rand() % 41 + 60;  // ����� 60 ~ 100
			d.push_back(score);
		}

		cout << "ѡ�֣� " << it->m_name << " ��֣� " << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;

		//����
		sort(d.begin(), d.end());

		//ȥ����ߺ���ͷ�   ���Բ�Ҫ��deque
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; //�ۼ�ÿ����ί�ķ���
		}

		int avg = sum / d.size();     //��ʱsize��8��

		//��ƽ���� ��ֵ��ѡ������
		it->m_score = avg;
	}

}

void showscore(vector<person> & v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << it->m_name << " ƽ���֣� " << it->m_score << endl;
	}
}

int main()
{
	//���������   ���������̵�
	srand((unsigned int)time(NULL));

	//1������5��ѡ��
	vector<person>v;      //�������ѡ�ֵ�����v  ��ŵ��������Լ����������person
	createperson(v);     //�Ǹ�����˴��  ���Դ�������v
	//����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "������ " << (*it).m_Name << " ������ " << (*it).m_Score << endl;
	//}

	//2�����
	setscore(v);     //ͬ�� ��������v

	//3����ʾ���÷�
	showscore(v);
	system("pause");
	return 0;
}
