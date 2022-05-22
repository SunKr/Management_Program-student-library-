#include <iostream>

#define NAME_SIZE 32

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};



typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, *PSTUDENT;
/*
��ũ�帮��Ʈ : �ڷᱸ���� �������̴�. �ڷᱸ���� �����͸� �����ϴ� ����� ���Ѵ�.
��ũ�帮��Ʈ�� ������ ����� ������Ѽ� ������ �� �ִ� ������ �����Ѵ�.
��ũ�帮��Ʈ�� �����͸� �����ϱ� ���� ����°��� �����Ѵ�.
�� ����� Ư¡�� ���� ��带 �� �� �ְ� �ȴ�.(��������� �޸� �ּҸ� �����Ѵٴ� �ǹ��̴�.)
����Ʈ�� ���������� �Ǿ��ִ�. �׷��� ������ �迭ó�� Ư�� ��ҿ� �ٷ� ������ �Ұ����ϴ�.
������ �տ��� ���� ���ʴ�� Ÿ�� ���� �Ѵ�.
��带 ���� �߰��Ҷ��� ��带 �����ϰ� ������ ��忡 ���Ḹ ���ָ�Ǳ⶧����
������ ������ ����.
*/

//����Ʈ ��带 �����.
typedef struct _tagNode
{
	//��忡�� �����ʹ� �л��� �����Ѵ�.
	STUDENT tStudent;
	//��������� �ּ�
	_tagNode* pNext;

}NODE, * PNODE;

//����Ʈ ����ü�� ������ش�.
typedef struct _tagList
{
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, * PLIST;

void InitList(PLIST pList)
{
	// �����ʹ� �������̸� �ʱ�ȭ �Ҷ� NULL�� �ʱ�ȭ �صΰ� ���°��� ����.
	// �ֳ��ϸ� 0�� false 0�� �ƴ� ��� ���� true �̱� �����̴�.
	// �ʱ�ȭ�� ���� ���� ��� ������ ���� �� �ִµ� �� ������ 
	// �� ���� true�̴�.

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}

int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}


int OutputMenu()
{
	system("cls");
	cout << "1. �л� �߰� " << endl;
	cout << "2. �л� ���� " << endl;
	cout << "3. �л� Ž�� " << endl;
	cout << "4. �л� ���" << endl;
	cout << "5. ����" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
}

void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}

void Insert(PLIST pList)
{
	system("cls");
	cout << " =================�л� �߰�=================" << endl;
	STUDENT tStudent = {};

	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "�й�  : ";
	tStudent.iNumber = InputInt();

	cout << "����  : ";
	tStudent.iKor = InputInt();

	cout << "����  : ";
	tStudent.iEng = InputInt();

	cout << "����  : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iMath + tStudent.iEng + tStudent.iKor;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	//�߰��� ����Ʈ ��带 �����Ѵ�.
	PNODE pNode = new NODE; //��� �����Ҵ�
	//���� �������ŭ �����Ҵ� �� �޸� �ּҸ� pNode�� ������ �ִ�.

	//���� �߰��ϴ� ���� ���� �������� �߰��� ���̱� ������ ���� ��尡 �������� �ʴ´�.
	// �׷��� ���� ���� NULL�� �ʱ�ȭ�ϰ� ������ ������ �Է¹��� �л�������
	// �ֵ��� �Ѵ�.
	pNode->pNext = NULL;
	pNode->tStudent = tStudent;


	if (pList->pBegin == NULL)
		pList->pBegin = pNode;

	else
		pList->pEnd->pNext = pNode;

	pList->pEnd = pNode;

	++pList->iSize;
}


void ClearList(PLIST pList)
{
	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}






int main()
{
	LIST tList;

	InitList(&tList);


	while (true)
	{
		int iMenu = OutputMenu();

		if (iMenu == MM_EXIT)
			break;


		switch (iMenu)
		{
		case MM_INSERT:
			Insert(&tList); //�ּҸ� �־��ָ�ȴ�.
			break;
		case MM_DELETE:
			break;
		case MM_SEARCH:
			break;
		case MM_OUTPUT:
			break;
		case MM_EXIT:
			break;
		}

	}


	return 0;
}