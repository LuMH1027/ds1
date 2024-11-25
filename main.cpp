#include <iostream>
#include "Polynomial.h"
using namespace std;

// 打印功能菜单
void ShowMenu() {
    cout << "==================== 多项式操作菜单 ====================" << endl;
    cout << "1. 输入两个多项式" << endl;
    cout << "2. 显示两个多项式" << endl;
    cout << "3. 两个多项式相加" << endl;
    cout << "4. 两个多项式相减" << endl;
    cout << "5. 两个多项式相乘" << endl;
    cout << "6. 对多项式求导" << endl;
    cout << "0. 退出程序" << endl;
    cout << "======================================================" << endl;
    cout << "请输入您的选择: ";
}

// 主函数
int main() {
    Polynomial poly1, poly2, result; 
    int choice;
    do 
    {
        ShowMenu();
        cin >> choice;
        switch (choice) 
        {
        case 1:     // 输入多项式
        {   
            cout << "请输入第一个多项式(系数和指数，输入0 0结束):" << endl;
            double coef;
            int exp;
            while (true) 
            {
                cin >> coef >> exp;
                if (coef == 0 && exp == 0) break;
                poly1.Insert(PolyItem(coef, exp));
            }
            cout << "请输入第二个多项式(系数和指数，输入0 0结束):" << endl;
            while (true) 
            {
                cin >> coef >> exp;
                if (coef == 0 && exp == 0) break;
                poly2.Insert(PolyItem(coef, exp));
            }
            cout << "多项式输入完成！" << endl;
            break;
        }

        case 2: 
        {           // 显示多项式
            cout << "第一个多项式: ";
            poly1.Show();
            cout << "第二个多项式: ";
            poly2.Show();
            break;
        }

        case 3: 
        {           // 多项式相加
            result = poly1 + poly2;
            cout << "相加结果: ";
            result.Show();
            break;
        }

        case 4: 
        {           // 多项式相减
            result = poly1 - poly2;
            cout << "相减结果: ";
            result.Show();
            break;
        }

        case 5: 
        {           // 多项式相乘
            result = poly1 * poly2;
            cout << "相乘结果: ";
            result.Show();
            break;
        }

        case 6: 
        {           // 对多项式求导
            cout << "选择求导的多项式(1 或 2): ";
            int polyChoice;
            cin >> polyChoice;
            if (polyChoice == 1) 
            {
                result = poly1.Differentiate(poly1);
                cout << "第一个多项式的导数: ";
            }
            else if (polyChoice == 2) 
            {
                result = poly2.Differentiate(poly2);
                cout << "第二个多项式的导数: ";
            }
            else 
            {
                cout << "输入错误！" << endl;
                break;
            }
            result.Show();
            break;
        }

        case 0:     // 退出程序
            cout << "程序已退出" << endl;
            break;

        default:
            cout << "输入错误，请重新输入！" << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);
    return 0;
}

