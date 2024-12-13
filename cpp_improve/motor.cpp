#include <iostream>
using namespace std;

class MotorController {
	public:
		double speed = 1;
		int direction = 0;
};

void start() {
	cout << "请输入数字来选择你的模式" << endl
	     << "0. 关闭电机" << endl
	     << "1. 开启电机" << endl
	     << "2. 修改电机速度" << endl
	     << "3. 查看当前电机速度" << endl
	     << "4. 改变电机旋转方向 (顺时针 (0)|| 逆时针(1))" << endl
	     << "5. 查看当前电机旋转方向 (顺时针(0) || 逆时针(1))" << endl;
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
				cout << "电机未开机" << endl;
				start();
				goto put;
			} else {
				cout << "电机正在关机";
				goto over;
			}
			break;
		}

		case 1: {
			if (openmotor == false) {
				openmotor = true;
				cout << "电机正在开启" << endl;
				start();
				goto put;
			} else {
				cout << "电机已开启，请进行其他操作" << endl;
				start();
				goto put;
			}
		}
		case 2: {
			if (openmotor == 0) {
				cout << "电机未开启，请先输入1开机" << endl;
				goto put;
			} else {
				cout << "请输入电机速度" << endl;
				cin >> motor.speed;
				start();
				goto put;
			}
			break;
		}


		case 3: {
			if (openmotor == 0) {
				cout << "电机未开启，请先输入1开机" << endl;
				goto put;
			} else {
				cout << "当前电机速度为 " << motor.speed << endl;
				system("pause");
				start();
				goto put;
			}
			break;
		}
		case 4: {
			if (openmotor == 0) {
				cout << "电机未开启，请先输入1开机" << endl;
				goto put;
			} else {
				cout << "请输入电机旋转方向（0为顺时针，1为逆时针）" << endl;
				cin >> motor.direction;
				start();
				goto put;
			}
			break;
		}

		case 5: {
			if (openmotor == 0) {
				cout << "电机未开启，请先输入1开机" << endl;
				goto put;
			} else {
				if (motor.direction == 0) {
					cout << "当前电机为顺时针" << endl;
					system("pause");
				} else {
					cout << "当前电机为逆时针" << endl;
					system("pause");
				}
				start();
				goto put;
			}
			break;
		}
		default : {
			cout << "无效输入，请重新输入" << endl;
			goto put;
			break;
		}

	}
over:
	return 0;
}
