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

// 학생관련 스트럭트를 제작후에 제목을 출력하고 나서 
// 메뉴를 제작해준다.
// 메뉴 제작후 메뉴 선택을 가능하게 하여
// 특정학생 입력후 학생관련 정보 를 추가 삭제 편집이 
// 가능하도록 설정한다.

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