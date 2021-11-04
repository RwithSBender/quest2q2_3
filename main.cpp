#include <iostream>
#include <list>

using namespace std;

class matrix
{
    int** num;
    int size;
public:
    matrix(int n)
    {
        size = n;
        num = new int *[size];
            for (int i = 0; i < size; ++i)
                num[i] = new int [size];
    }
    long determ_it()
    {
        if(size ==2)
        {
            return num[0][0]*num[1][1]-num[0][1]*num[1][0];
        }
        else
        {
            long det=0;
            int m = 1;
            for (int k=0;k<size;k++)
            {
                matrix temp1(size-1);
                for (int i1=1,i=0;i1<size;i1++,i++)
                {
                    for (int j1=0,j=0;j1<size;j1++)
                    {
                        if (j1!=k)
                        {
                            temp1.num[i][j] = num[i1][j1];
                            j++;
                        }
                    }
                }
                cout<<endl;
                temp1.print_matrix();
                cout<<endl;
                det+=temp1.determ_it()*m;
                m=-m;
            }
            return det;
        }

    }
    void fill_matrix()
    {
        for (int j=0;j<size;j++)
        {
            for (int i=0;i<size;i++)
            num[i][j] = rand()%10;
        }
    }
    void print_matrix()
    {
        for (int j=0;j<size;j++)
        {
            for (int i=0;i<size;i++)
                cout<<num[j][i]<<' ';
            cout<<endl;
        }
    }
    int get_size(){return size;}
    ~matrix()
    {
        for(int i = 0; i < size; i++) {
            free(num[i]);
        }
        free(num);
    }
};


class my_iter
{
    int* p;
    int num;
    int size;
public:
    my_iter();

    my_iter(int n)
    {
        size = n;
        num = 0;
        p=new int [n];
    }
    void add(int k)
    {
        p[num] = k;
        num++;
    }
    int* begin(){return p;}
    int* end(){return p+num;}
};



void add_average(list<double> &lst)
{
    double sum = 0;
    int count = 0;
    for(auto x:lst)
        {
            sum+=x;
            count++;
        }
    lst.push_back(sum/count);
}

void task1()
{
    cout<<"Task 1"<<endl;
    list<double> lst;
    for(int i=0;i<10;i++)
        {
            int k = rand()%10;
            lst.push_back(k);
            cout<<k<<" ";
        }
    cout<<endl;
    add_average(lst);
    cout<<lst.back()<<endl;
}

void task2()
{
    cout<<"Task 2"<<endl;
    matrix mas(4);
    mas.fill_matrix();
    mas.print_matrix();
    cout<<mas.determ_it()<<endl;
}
void task3()
{
    cout<<"Task 3"<<endl;
    my_iter arr(10);
    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(4);
    for (auto x:arr)
    {
        cout<<x<<' ';
    }
}

int main()
{
    task1();
    task2();
    task3();
    return 0;
}
