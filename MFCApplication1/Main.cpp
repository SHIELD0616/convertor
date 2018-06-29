#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string weight[20]= {"Gg","Mg","kg","g","mg","ug","lb","oz"};
double weight1[20]= {1000000,1000,1,0.001,0.000001,0.000000001,0.453592,0.028348};
string lenth[20]= {"Mm","km","m","dm","cm","mm","ft","in","yd"};
double lenth1[20]= {1000000,1000,1,0.1,0.01,0.001,0.3048,0.0254,0.9144};
string press[20]= {"Kgf","Mpa","Bar","Kpa","mBar","psi","atm","mmHg"};
double press1[20]= {1,10.19716,1.01972,0.010197,0.0010197,0.07031,1.033228,0.0013595};
string volume[20]= {"m^3","L","ml","ft^3","in^3","UKgal","USgal","USbbl"};
double volume1[20]= {61023.7,61.0237,0.0610237,1728,1,277.42,231,9701.794};
string time[20]= {"h","min","s","ms","day","week","month","year"};
double time1[20]= {60,1,1.0/60,1.0/60000,60*24,60*24*7,60*24*7*30,60*24*7*365};
string currency[20]= {"RMB/�����","USD/��Ԫ","GBP/Ӣ��","JPY/��Ԫ","EUR/ŷԪ","HKD/��Ԫ","Gold(g)/�ƽ�(��)","bitcoin/���ر�"};
double currency1[20]= {1,0.1583,0.1159,16.9099,0.1319,1.2066,1270/0.1159/31.10,6175/0.1583};
typedef struct unitclass
{
    string classname;
    string *unitname;
    double *unitquantity;
    int quantity;
} unitclass;
int numbersofclass;
unitclass un[20];
void init()
{
    numbersofclass=6;
    un[1].classname="weight/����";
    un[1].quantity=8;
    un[1].unitname=weight;
    un[1].unitquantity=weight1;
    un[2].classname="lenth/����";
    un[2].quantity=9;
    un[2].unitname=lenth;
    un[2].unitquantity=lenth1;
    un[3].classname="press/ѹǿ";
    un[3].quantity=8;
    un[3].unitname= press;
    un[3].unitquantity= press1;
    un[4].classname="volume/���";
    un[4].quantity=8;
    un[4].unitname= volume;
    un[4].unitquantity= volume1;
    un[5].classname="time/ʱ��";
    un[5].quantity=8;
    un[5].unitname= time;
    un[5].unitquantity= time1;
    un[6].classname="currency/����";
    un[6].quantity=8;
    un[6].unitname= currency;
    un[6].unitquantity= currency1;
}
class change
{
public:
    void choose()
    {
        cout<<"һ����"<<numbersofclass<<"�����ĵ�λ�ɹ�ѡ��"<<endl;
        for(int i=1; i<=numbersofclass; i++)
            cout<<i<<"."<<un[i].classname<<endl;
        cout<<"��������������ĵ�λ�����Ļ�����λ������";
        cin>>howmany;
        cout<<endl<<"��˳�����뵥λ����Կո��������";
        for(int i=1; i<=howmany; i++)
            cin>>classchoose[i];
    }
    void units()
    {
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"һ���� ";
        for(int i=1; i<=howmany; i++)
            cout<<un[classchoose[i]].quantity<<" ";
        cout<<"����λ�ɹ�ѡ��"<<endl;
        for(int i=1; i<=howmany; i++)
            {
                for(int j=0; j<un[classchoose[i]].quantity; j++)
                    cout<<j+1<<". "<<un[classchoose[i]].unitname[j]<<"  ";
                cout<<endl;
            }

        cout<<"������ "<<howmany<<" �����ԭʼ��λ�Ļ�����λ���ɣ������m/sתkm/h���������� m h�� km s����������ת��Ϊ�˷���";
        for(int i=1; i<=howmany; i++)
            cin>>unit1[i];
        cout<<endl;
        cout<<"������ "<<howmany<<" �����Ŀ�굥λ�Ļ�����λ���ɣ�";
        for(int i=1; i<=howmany; i++)
            cin>>unit2[i];
        cout<<endl;
        ratios=1;
        for(int i=1; i<=howmany; i++)
        {
            ratios/=un[classchoose[i]].unitquantity[unit1[i]-1];
            ratios*=un[classchoose[i]].unitquantity[unit2[i]-1];
        }
    }
    void ch()
    {
        int changenumber;
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"����Զ��ٸ���ֵ����ת����������10000����";
        cin>>changenumber;
        cout<<endl;
        double cha[10000];
        double chb[10000];
        cout<<"����������Ҫת������ֵ���Կո������"<<endl;
        for(int i=1; i<=changenumber; i++)
            {
                cin>>cha[i];
                chb[i]=cha[i]/ratios;
            }
        cout<<"����ǣ�"<<endl;
        for(int i=1; i<=changenumber; i++)
            {
                cout<<chb[i];
            }
        cout<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
    }
    int howmany;
    int classchoose[20];
    int unit1[20];
    int unit2[20];
    double ratios;
private:

};
int main()
{
    init();
    change cc;
    while(1)
        {
            char a;
            cc.choose();
            cc.units();
            cc.ch();
            cout<<"����ת��?(y/n):";
            cin>>a;
            cout<<endl;
            if(a=='n')
                break;
        }
    return 0;
}
