#include <iostream>
using namespace std;

class MotorController {
	public:
		double speed = 1;
		int direction = 0;
};

void start() {
	cout << "������������ѡ�����ģʽ" << endl
	     << "0. �رյ��" << endl
	     << "1. �������" << endl
	     << "2. �޸ĵ���ٶ�" << endl
	     << "3. �鿴��ǰ����ٶ�" << endl
	     << "4. �ı�����ת���� (˳ʱ�� (0)|| ��ʱ��(1))" << endl
	     << "5. �鿴��ǰ�����ת���� (˳ʱ��(0) || ��ʱ��(1))" << endl;
}

int main() {
	MotorController motor;
	start();
	int n;
	bool openmotor = false;
put:
	cin >> n;
	switch (n) {
		case 0: {
			if (openmotor == 0) {
				cout << "���δ����" << endl;
				start();
				goto put;
			} else {
				cout << "������ڹػ�";
				goto over;
			}
			break;
		}

		case 1: {
			if (openmotor == false) {
				openmotor = true;
				cout << "������ڿ���" << endl;
				start();
				goto put;
			} else {
				cout << "����ѿ������������������" << endl;
				start();
				goto put;
			}
		}
		case 2: {
			if (openmotor == 0) {
				cout << "���δ��������������1����" << endl;
				goto put;
			} else {
				cout << "���������ٶ�" << endl;
				cin >> motor.speed;
				start();
				goto put;
			}
			break;
		}


		case 3: {
			if (openmotor == 0) {
				cout << "���δ��������������1����" << endl;
				goto put;
			} else {
				cout << "��ǰ����ٶ�Ϊ " << motor.speed << endl;
				system("pause");
				start();
				goto put;
			}
			break;
		}
		case 4: {
			if (openmotor == 0) {
				cout << "���δ��������������1����" << endl;
				goto put;
			} else {
				cout << "����������ת����0Ϊ˳ʱ�룬1Ϊ��ʱ�룩" << endl;
				cin >> motor.direction;
				start();
				goto put;
			}
			break;
		}

		case 5: {
			if (openmotor == 0) {
				cout << "���δ��������������1����" << endl;
				goto put;
			} else {
				if (motor.direction == 0) {
					cout << "��ǰ���Ϊ˳ʱ��" << endl;
					system("pause");
				} else {
					cout << "��ǰ���Ϊ��ʱ��" << endl;
					system("pause");
				}
				start();
				goto put;
			}
			break;
		}
		default : {
			cout << "��Ч���룬����������" << endl;
			goto put;
			break;
		}

	}
over:
	return 0;
}