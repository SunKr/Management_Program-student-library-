#include <iostream>
#define NAME_SIZE 10
#define ADDRESS_SIZE 120
#define PHONE_SIZE 12
#define MAX_STUDENT 10


//전처리기를 통해서 일정 크기 설정


/*
학생관리 프로그램
학생 : 이름, 주소, 전화번호, 학번, 한국어, 영어, 수학, 총점, 평균
메뉴 : 0없음, 1. 추가, 2, 삭제, 3. 검색, 4, 출력, 5. 나가기
*/

// 학생 관련 구조체 생성
struct tStudent
{
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhoneNumber[PHONE_SIZE];
	int  StudentNumber;
	int	 iKorea;
	int  iEnglish;
	int  iMath;
	int  iTotal;
	float fAvg;
};

// 메뉴
enum MENU
{
	MENU_NONE,
	MENU_ADD,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};



using namespace std;

int main()
{
	// 학생관련 구조체 배열을 생성하여 학생들의 묶음을 생성한다.
	tStudent tStudnetArr[MAX_STUDENT] = {}; //Initialize
	
	int iStudnetCount =0; // 학생들이 추가되거나 삭제 될때 변하는 숫자
	int iStdNumber=1; //어디에 써야하나?
	

	while (true)
	{
		system("cls"); 	// 항상 새로운 화면으로 세팅

		cout << "Student Management Program " << endl;
		cout << "=========================================" << endl;
		cout << "1. ADD student" << endl;
		cout << "2. DELETE stduent" << endl;
		cout << "3. SEARCH student" << endl;
		cout << "4. OUTPUT studnet" << endl;
		cout << "5. Exit" << endl;

		int iMenu;
		// 예외 처리 필수 사항
		// 잘못된 숫자 입력시 다시 입력
		// 잘못된 키 입력시 무시 하고 다시입력
		// 5번 입력시 프로그램 종료
		cout << " Select Menu  " ;
		cin >> iMenu;
		
		// 글자로 잘못입력시 사용 방법
		if (cin.fail())
		{
			cin.clear(); //cin 삭제

			cin.ignore(1024, '\n'); // 엔터키 까지 무시

			continue; // 다시 while loop을 돌린다. 

		}


		// 5번 메뉴 입력시 종료
		if (5 == iMenu)
		{
			break;
		}

		switch (iMenu)
		{
		case MENU_ADD: //추가 
			system("cls");
			cout << "==============================학생 추가============================== " << endl;
			//이름, 주소, 전화번호, 학번, 한국어, 영어, 수학, 총점, 평균
			// 학생들을 차례대로 입력받는다.
			cout << "이름 ";
			cin >> tStudnetArr[iStudnetCount].strName;
			// 엔터 무시
			cin.ignore(1024, '\n');
			//주소
			cout << "주소 ";
			cin.getline(tStudnetArr[iStudnetCount].strAddress, ADDRESS_SIZE);
			cout << "전화번호 ";
			// 전화번호
			cin >> tStudnetArr[iStudnetCount].strPhoneNumber;
			cout << "한국어 ";
			//한국어
			cin >> tStudnetArr[iStudnetCount].iKorea;
			cout << "영어 ";
			//영어
			cin >> tStudnetArr[iStudnetCount].iEnglish;
			cout << "수학 ";
			//수학
			cin >> tStudnetArr[iStudnetCount].iMath;
			//총점
			tStudnetArr[iStudnetCount].iTotal = (tStudnetArr[iStudnetCount].iKorea + tStudnetArr[iStudnetCount].iEnglish + tStudnetArr[iStudnetCount].iMath);
			//평균
			tStudnetArr[iStudnetCount].fAvg = tStudnetArr[iStudnetCount].iTotal / 3;
			// 학생이 추가 되었으므로 1증가 시킨다. 
			
			tStudnetArr[iStudnetCount].StudentNumber = iStdNumber;

			++iStdNumber;
			++iStudnetCount;

			cout << "학생이 추가 되었습니다.";


			break;
		case MENU_DELETE: //삭제 메뉴
			break;
		case MENU_SEARCH: //검색 메뉴
			break;
		case MENU_OUTPUT: //출력 메뉴
			// 학생을 찾아서 출력한다. 
			// 학생 출력
			system("cls");
			cout << "==============================학생 출력============================== " << endl;
			for (int i = 0; i < iStudnetCount; ++i)
			{
				cout << "학생 이름 :" << tStudnetArr[i].strName << endl;
				cout << "주소 :" << tStudnetArr[i].strAddress << endl;
				cout << "전화번호 :" << tStudnetArr[i].strPhoneNumber << endl;
				cout << "국어 :" << tStudnetArr[i].iKorea << endl;
				cout << "영어 :" << tStudnetArr[i].iEnglish << endl;
				cout << "수학 :" << tStudnetArr[i].iMath << endl;
				cout << "총점 :" << tStudnetArr[i].iTotal << endl;
				cout << "평균 :" << tStudnetArr[i].fAvg << endl;
			}
			break;
		default:
			break;
		}

		system("pause");
	}






	return 0;
}