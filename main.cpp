#include "Integral.h"

using namespace std;

void menu(){
    cout << "|-----------------------------------------|" << endl;
    cout << "| 1.��������� �������� sqrt(2*exp(x)-x*x) |" << endl;
    cout << "| 2.��������� �������� ln(x)/(x*x)        |" << endl;
    cout << "| 3.��������� �������� Exp                |" << endl;
    cout << "| 4.��������� �������� Sin(x)             |" << endl;
    cout << "| 5.��������� �������� Cos(x)             |" << endl;
    cout << "| 6.�����                                 |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << ">>";
}

void Inp_func(double &a, double &b, double &eps, int &steps, int &iterates){
    system("cls");
    cout << "������� ������ ������ ��������������: ";
    cin >> a;
    while(!cin){
        system("cls");
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "������� ������ ������ ��������������: ";
        cin >> a;
    }
    system("cls");
    cout << "������� ������� ������ ��������������: ";
    cin >> b;
    while(!cin){
        cin.clear();
        system("cls");
        cin.ignore(32767,'\n');
        cout << "������� ������� ������ ��������������: ";
        cin >> b;
    }
    system("cls");
    cout << "������� ��������: ";
    cin >> eps;
    while(!cin){
        cin.clear();
        cin.ignore(32767,'\n');
        system("cls");
        cout << "������� ��������: ";
        cin >> eps;
    }
    system("cls");
    cout<<"������� ���-�� ���������: ";
    cin >> steps;
    while(!cin){
        cin.clear();
        cin.ignore(32767,'\n');
        system("cls");
        cout << "������� ���-�� ���������: ";
        cin >> steps;
    }
    system("cls");
    cout<<"������� ���-�� ��������: ";
    cin >> iterates;
     while(!cin){
        cin.clear();
        cin.ignore(32767,'\n');
        system("cls");
        cout << "������� ���-�� ��������: ";
        cin >> iterates;
    }
}

double fr(double x){
    return sqrt(2*exp(x)-x*x);
}

double sc(double x){
    return log(x)/(x*x);
}

double thr(double x){
    return exp(x);
}

double frth(double x){
    return sin(x);
}

double fv(double x){
    return cos(x);
}

int main()
{
    system("chcp 1251> nul");
    int rs = 0, ch;
    double res = .0;
    ptrFunc f1 = fr;
    ptrFunc f2 = sc;
    ptrFunc f3 = thr;
    ptrFunc f4 = frth;
    ptrFunc f5 = fv;

    double a, b, eps;
    double cor_res;
    int iterates, steps;

    while(rs != 6){
        menu();
        cin >> rs;
        while((rs < 1) || (rs > 6) || (!cin)){
            system("cls");
            menu();
            cin.clear();
            cin.ignore(32767, '\n');
            cin>>rs;
        }

        if(rs >= 1 && rs <= 5){
            system("cls");
            Inp_func(a, b, eps, steps, iterates);
            if(rs ==  1){
                ch = Integral(a, b, f1, eps, iterates, res, steps);
            }
            else if(rs == 2){
                ch = Integral(a, b, f2, eps, iterates, res, steps);
            }
            else if(rs == 3){
                ch = Integral(a, b, f3, eps, iterates, res, steps);
            }
            else if(rs == 4){
                ch = Integral(a, b, f4, eps, iterates, res, steps);
            }
            else if(rs == 5){
                ch = Integral(a, b, f5, eps, iterates, res, steps);
            }

            if(ch == 0){
                cout << "��������� ��������������: " << res << endl;
            }
            else if(ch == 1){
                cout<< "��������� ��������" <<endl;
                cout<< "��������� ��������������: " << res <<endl;
            }

            if(rs == 3){
                cor_res = exp(b) - exp(a);
                cout << "������ ���������: " << cor_res << endl;

            }
            else if(rs == 4){
                cor_res = cos(a) - cos(b);
                cout << "������ ���������: " << cor_res << endl;

            }
            else if(rs == 5){
                cor_res = sin(b) - cos(a);
                cout << "������ ���������: " << cor_res << endl;

            }
            rs = 0;
        }

    }
}




