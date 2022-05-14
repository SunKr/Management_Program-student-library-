/*
관리프로그램 만들기
도서 대여 프로그램 만들기.
1. 책등록
2. 책 대여
3. 책 반납
4. 책 목록
5. 종료

책 구조체는 이름, 대여금액, 책번호, 대여여부 가 필요하다.
책목록을 선택하면 책정보를 출력해준다.
*/


#include <iostream>

#define NAME_SIZE 12 /// max name size
#define MAX_BOOK 20 // max number for books

struct tBooks
{
	char strBname[NAME_SIZE];
	int  price;
	int  bNumber;
	bool bBooks = false;
};



enum MENU
{
	MENU_NONE,
	MENU_ENROLL,
	MENU_BORROW,
	MENU_RETURN,
	MENU_BOOKS,
	MENU_EXIT
};

using namespace std;

int main()
{
	tBooks tbookArr[MAX_BOOK] = {}; // initialize book object

	int iMenu; // menu index
	int iBookCount = 0;
	int iNumber = 1;
	int iClick;

	while(true)
	{
		system("cls");

		cout << "================== Book Management Program ======================= " << endl;
		cout << "1. Book Enroll " << endl;
		cout << "2. Book Borrow " << endl;
		cout << "3. Book Return " << endl;
		cout << "4. Books Array" << endl;
		cout << "5. Exit " << endl;
		cout << endl;
		cout << " type the Menu above :";
		cin >> iMenu;


		// 다른 잘못된 입력시, 5번 입력시 종료, 메뉴 클릭시
		if (cin.fail())
		{
			cin.clear();

			cin.ignore(1024, '\n');

			continue;
		}

		// check exception
		if (5 == iMenu) // Exit Menu
		{
			break;
		}


		switch (iMenu)
		{
		case MENU_ENROLL:
			system("cls");
			cout << "type a book that you want to enroll :";
			cin.ignore(1024, '\n');
			cin >> tbookArr[iBookCount].strBname;
			cout << "Price of the book :";
			cin >> tbookArr[iBookCount].price;
			// 책을 등록하게 될경우 책이 없다가 생긴 것이므로 bool 에서 false 에서 true 로 변경되어 렌탈 가능으로 인지시킨다.
			tbookArr[iBookCount].bBooks = true;
			//렌탈 가능 여부 체크
			if (tbookArr[iBookCount].bBooks == true)
				cout << "Book rental O " << endl;
			else 
				cout << "Book rental X " << endl;
			// book number
			tbookArr[iBookCount].bNumber = iNumber;

			++iNumber; //책 추가되었으므로 책 번호 증가
			++iBookCount; //책 추가로 index 숫자 증가

			break;
		case MENU_BORROW:
			// 렌탈을 하기 위한 메뉴로 렌탈시 렌탈 가능 여부 확인 및 렌탈시 bool 을 변경하여 준다.
			// 렌탈 가능한 목록 부터 생성하고 렌탈하고 싶은 책 이름을 타이핑한면 렌탈여부가 변경이 된다.
			system("cls");
			cout << " ======== Book Rental ======" << endl;
			for (int i = 0; i < iBookCount; ++i)
			{
				cout << i + 1 << "# " << tbookArr[i].strBname << endl;
			}
			cout << " type the book number that you want to borrow :";
			cin >> iClick;
			for (int i = 0; i < iNumber; ++i)
			{
				if (iClick == i + 1)
				{
					if (tbookArr[i].bBooks == true)
						tbookArr[i].bBooks = false;
					else
						tbookArr[i].bBooks = true;
				}
			}
			cout << "Book was rented " << endl;

			break;
		case MENU_RETURN:
			system("cls");
			cout << " ======== Book Return ======" << endl;
			for (int i = 0; i < iBookCount; ++i)
			{
				cout << i + 1 << "# " << tbookArr[i].strBname << endl;
			}
			cout << " type the book number that you want to return :";
			cin >> iClick;
			for (int i = 0; i < iNumber; ++i)
			{
				if (iClick == i + 1)
				{
					if (tbookArr[i].bBooks == true)
						tbookArr[i].bBooks = false;
					else
						tbookArr[i].bBooks = true;
				}
			}
			cout << "Book was rented " << endl;
			break;
		case MENU_BOOKS:
			system("cls");

			// 예외처리 등록 필요 (아직등록 안함)
			// 등록된 책을 출력해줘야하는데
			cout << " ======== Book Content ======" << endl;
			for (int i = 0; i < iBookCount; ++i)
			{
				cout << i + 1<< "# "<< tbookArr[i].strBname << endl;
			}
			cout << " Type the Number on the list : ";
			// 특정 목록을 보고 책을 고른후 그 책의 정보를 확인할수 있다.
			cin >> iClick; //특정 책 클릭
			for (int i = 0; i < iNumber; ++i)
			{
				if (iClick == i + 1) 
				{
					cout << "Book   :" << tbookArr[i].strBname << endl; // 책 이름
					cout << "Price  :" << tbookArr[i].price << endl; // 책 가격
					cout << "Book # :" << tbookArr[i].bNumber << endl; // 책 번호
					if (tbookArr[i].bBooks == true)
						cout << "Book rental O " << endl;
					else
						cout << "Book rental X " << endl;
				}
			}


			break;
		default:
			break;
		}
			
		system("pause");

	}

	return 0;
}