#include <iostream>
#define NAME_SIZE 10
#define ADDRESS_SIZE 120
#define PHONE_SIZE 12
#define MAX_STUDENT 10


//��ó���⸦ ���ؼ� ���� ũ�� ����


/*
�л����� ���α׷�
�л� : �̸�, �ּ�, ��ȭ��ȣ, �й�, �ѱ���, ����, ����, ����, ���
�޴� : 0����, 1. �߰�, 2, ����, 3. �˻�, 4, ���, 5. ������
*/

// �л� ���� ����ü ����
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

// �޴�
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
	// �л����� ����ü �迭�� �����Ͽ� �л����� ������ �����Ѵ�.
	tStudent tStudnetArr[MAX_STUDENT] = {}; //Initialize
	
	int iStudnetCount =0; // �л����� �߰��ǰų� ���� �ɶ� ���ϴ� ����
	int iStdNumber=1; //��� ����ϳ�?
	

	while (true)
	{
		system("cls"); 	// �׻� ���ο� ȭ������ ����

		cout << "Student Management Program " << endl;
		cout << "=========================================" << endl;
		cout << "1. ADD student" << endl;
		cout << "2. DELETE stduent" << endl;
		cout << "3. SEARCH student" << endl;
		cout << "4. OUTPUT studnet" << endl;
		cout << "5. Exit" << endl;

		int iMenu;
		// ���� ó�� �ʼ� ����
		// �߸��� ���� �Է½� �ٽ� �Է�
		// �߸��� Ű �Է½� ���� �ϰ� �ٽ��Է�
		// 5�� �Է½� ���α׷� ����
		cout << " Select Menu  " ;
		cin >> iMenu;
		
		// ���ڷ� �߸��Է½� ��� ���
		if (cin.fail())
		{
			cin.clear(); //cin ����

			cin.ignore(1024, '\n'); // ����Ű ���� ����

			continue; // �ٽ� while loop�� ������. 

		}


		// 5�� �޴� �Է½� ����
		if (5 == iMenu)
		{
			break;
		}

		switch (iMenu)
		{
		case MENU_ADD: //�߰� 
			system("cls");
			cout << "==============================�л� �߰�============================== " << endl;
			//�̸�, �ּ�, ��ȭ��ȣ, �й�, �ѱ���, ����, ����, ����, ���
			// �л����� ���ʴ�� �Է¹޴´�.
			cout << "�̸� ";
			cin >> tStudnetArr[iStudnetCount].strName;
			// ���� ����
			cin.ignore(1024, '\n');
			//�ּ�
			cout << "�ּ� ";
			cin.getline(tStudnetArr[iStudnetCount].strAddress, ADDRESS_SIZE);
			cout << "��ȭ��ȣ ";
			// ��ȭ��ȣ
			cin >> tStudnetArr[iStudnetCount].strPhoneNumber;
			cout << "�ѱ��� ";
			//�ѱ���
			cin >> tStudnetArr[iStudnetCount].iKorea;
			cout << "���� ";
			//����
			cin >> tStudnetArr[iStudnetCount].iEnglish;
			cout << "���� ";
			//����
			cin >> tStudnetArr[iStudnetCount].iMath;
			//����
			tStudnetArr[iStudnetCount].iTotal = (tStudnetArr[iStudnetCount].iKorea + tStudnetArr[iStudnetCount].iEnglish + tStudnetArr[iStudnetCount].iMath);
			//���
			tStudnetArr[iStudnetCount].fAvg = tStudnetArr[iStudnetCount].iTotal / 3;
			// �л��� �߰� �Ǿ����Ƿ� 1���� ��Ų��. 
			
			tStudnetArr[iStudnetCount].StudentNumber = iStdNumber;

			++iStdNumber;
			++iStudnetCount;

			cout << "�л��� �߰� �Ǿ����ϴ�.";


			break;
		case MENU_DELETE: //���� �޴�
			break;
		case MENU_SEARCH: //�˻� �޴�
			break;
		case MENU_OUTPUT: //��� �޴�
			// �л��� ã�Ƽ� ����Ѵ�. 
			// �л� ���
			system("cls");
			cout << "==============================�л� ���============================== " << endl;
			for (int i = 0; i < iStudnetCount; ++i)
			{
				cout << "�л� �̸� :" << tStudnetArr[i].strName << endl;
				cout << "�ּ� :" << tStudnetArr[i].strAddress << endl;
				cout << "��ȭ��ȣ :" << tStudnetArr[i].strPhoneNumber << endl;
				cout << "���� :" << tStudnetArr[i].iKorea << endl;
				cout << "���� :" << tStudnetArr[i].iEnglish << endl;
				cout << "���� :" << tStudnetArr[i].iMath << endl;
				cout << "���� :" << tStudnetArr[i].iTotal << endl;
				cout << "��� :" << tStudnetArr[i].fAvg << endl;
			}
			break;
		default:
			break;
		}

		system("pause");
	}






	return 0;
}