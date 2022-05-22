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
링크드리스트 : 자료구조의 한종류이다. 자료구조란 데이터를 관리하는 방법을 말한다.
링크드리스트는 데이터 목록을 연결시켜서 접근할 수 있는 구조를 제공한다.
링크드리스트는 데이터를 저장하기 위한 노드라는것이 존재한다.
각 노드의 특징은 다음 노드를 알 수 있게 된다.(다음노드의 메모리 주소를 저장한다는 의미이다.)
리스트는 선형구조로 되어있다. 그렇기 때문에 배열처럼 특정 요소에 바로 접근이 불가능하다.
무조건 앞에서 부터 차례대로 타고 들어가야 한다.
노드를 새로 추가할때는 노드를 생성하고 마지막 노드에 연결만 해주면되기때문에
개수의 제한이 없다.
*/

//리스트 노드를 만든다.
typedef struct _tagNode
{
	//노드에서 데이터는 학생을 저장한다.
	STUDENT tStudent;
	//다음노드의 주소
	_tagNode* pNext;

}NODE, * PNODE;

//리스트 구조체를 만들어준다.
typedef struct _tagList
{
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, * PLIST;

void InitList(PLIST pList)
{
	// 포인터는 가급적이면 초기화 할때 NULL로 초기화 해두고 쓰는것이 좋다.
	// 왜냐하면 0은 false 0이 아닌 모든 수는 true 이기 때문이다.
	// 초기화를 하지 않을 경우 쓰레기 값이 들어가 있는데 이 쓰레기 
	// 값 조차 true이다.

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
	cout << "1. 학생 추가 " << endl;
	cout << "2. 학생 삭제 " << endl;
	cout << "3. 학생 탐색 " << endl;
	cout << "4. 학생 출력" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요 : ";
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
	cout << " =================학생 추가=================" << endl;
	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "학번  : ";
	tStudent.iNumber = InputInt();

	cout << "국어  : ";
	tStudent.iKor = InputInt();

	cout << "영어  : ";
	tStudent.iEng = InputInt();

	cout << "수학  : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iMath + tStudent.iEng + tStudent.iKor;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	//추가할 리스트 노드를 생성한다.
	PNODE pNode = new NODE; //노드 동적할당
	//힙에 노드사이즈만큼 공간할당 그 메모리 주소를 pNode가 가지고 있다.

	//현재 추가하는 노드는 가장 마지막에 추가될 것이기 때문에 다음 노드가 존재하지 않는다.
	// 그래서 다음 노드는 NULL로 초기화하고 정보는 위에서 입력받은 학생정보를
	// 주도록 한다.
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
			Insert(&tList); //주소를 넣어주면된다.
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