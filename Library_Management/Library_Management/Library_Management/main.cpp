/*
�������α׷� �����
���� �뿩 ���α׷� �����.
1. å���
2. å �뿩
3. å �ݳ�
4. å ���
5. ����

å ����ü�� �̸�, �뿩�ݾ�, å��ȣ, �뿩���� �� �ʿ��ϴ�.
å����� �����ϸ� å������ ������ش�.
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


		// �ٸ� �߸��� �Է½�, 5�� �Է½� ����, �޴� Ŭ����
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
			// å�� ����ϰ� �ɰ�� å�� ���ٰ� ���� ���̹Ƿ� bool ���� false ���� true �� ����Ǿ� ��Ż �������� ������Ų��.
			tbookArr[iBookCount].bBooks = true;
			//��Ż ���� ���� üũ
			if (tbookArr[iBookCount].bBooks == true)
				cout << "Book rental O " << endl;
			else 
				cout << "Book rental X " << endl;
			// book number
			tbookArr[iBookCount].bNumber = iNumber;

			++iNumber; //å �߰��Ǿ����Ƿ� å ��ȣ ����
			++iBookCount; //å �߰��� index ���� ����

			break;
		case MENU_BORROW:
			// ��Ż�� �ϱ� ���� �޴��� ��Ż�� ��Ż ���� ���� Ȯ�� �� ��Ż�� bool �� �����Ͽ� �ش�.
			// ��Ż ������ ��� ���� �����ϰ� ��Ż�ϰ� ���� å �̸��� Ÿ�����Ѹ� ��Ż���ΰ� ������ �ȴ�.
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

			// ����ó�� ��� �ʿ� (������� ����)
			// ��ϵ� å�� ���������ϴµ�
			cout << " ======== Book Content ======" << endl;
			for (int i = 0; i < iBookCount; ++i)
			{
				cout << i + 1<< "# "<< tbookArr[i].strBname << endl;
			}
			cout << " Type the Number on the list : ";
			// Ư�� ����� ���� å�� ���� �� å�� ������ Ȯ���Ҽ� �ִ�.
			cin >> iClick; //Ư�� å Ŭ��
			for (int i = 0; i < iNumber; ++i)
			{
				if (iClick == i + 1) 
				{
					cout << "Book   :" << tbookArr[i].strBname << endl; // å �̸�
					cout << "Price  :" << tbookArr[i].price << endl; // å ����
					cout << "Book # :" << tbookArr[i].bNumber << endl; // å ��ȣ
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