#include <iostream>
#define  NAME_SIZE 32


using namespace std;

struct tStudent
{
	char	strName[NAME_SIZE];	//Studnet Name
	int		iKorea;		//Korean Score
	int		iEnglish;	//English score
	int		iMath;		//Math score
	int		iTotal;		//total score
	float	fAvg;		//average
};


enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

// �л����� ��Ʈ��Ʈ�� �����Ŀ� ������ ����ϰ� ���� 
// �޴��� �������ش�.
// �޴� ������ �޴� ������ �����ϰ� �Ͽ�
// Ư���л� �Է��� �л����� ���� �� �߰� ���� ������ 
// �����ϵ��� �����Ѵ�.

int m1=0, m2=0, m3=0, m4=0; // menu index initialization

int main()
{
	while (true)
	{
		system("cls");

		cout << "--------------------------------" << endl;
		cout << "STUDENT Management Program" << endl;
		cout << "1. Add" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Search" << endl;
		cout << "4. Ouput" << endl;
		cout << "Exit" << endl;





		break;
	}

	return 0;
}