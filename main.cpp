//20201176
//mena adel ebrahim

#include <iostream>

using namespace std;
//global char array which i will change in it through program
char **arr;
//global int array which i will count number of close micro organisms
int **counter;
//global size of 2D array
int rows,col;
//this function i count close micro organisms in int 2D array(nearby index)
void close_micro()
{
    //this is the 8-connect direction in 2D array
    int setx[8]={1,-1,0,0,1,1,-1,-1};
    int sety[8]={0,0,1,-1,1,-1,1,-1};
    int nx,ny;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            counter[i][j] = 0;
            for(int m=0;m<=8;m++)
            {
                nx =j+setx[m];
                ny =i+sety[m];
                if(nx<0||nx>=rows||ny>=col||ny<0)
                    continue;
                else
                {
                    if(arr[ny][nx]=='M'){
                        counter[i][j]+=1;
                    }
                }
            }
        }
    }
}
//this function to see if micro will stay or leave or attract new one
bool conditions(int x ,int y)
{
    if(counter[x][y]>=4)
        return false;
    else if(counter[x][y]==1)
        return false;
    else if(counter[x][y]==2 && arr[x][y]=='-')
        return false;
    else if(counter[x][y]==3)
        return true;

}
//function will change places of micro and prepare next state with the help of previous function (conditions)
void change()
{
    //if condition return true it will make element of char arr M,otherwise it return false it will make element -
    for(int x=0;x<rows;x++)
    {
        for(int y=0;y<col;y++)
        {
            if( conditions(x,y)){
                arr[x][y]='M';}
            else {
                arr[x][y]='-';
            }
        }
    }

}
//this function for print the arr which return from previous function change
void print()
{
    for(int i=0;i<rows;i++)
{
     cout<<"[";
        for(int j=0;j<col;j++)
            cout<<arr[i][j] << " ";
        cout<<"]"<<endl;
}
}
//this function will print the surface for every iteration which the user enter
void number_of_iteration(int n)
{
    for(int i=1;i<=n;i++)
    {
        close_micro();
        change();
        cout<<"# iteration: "<<i;
        cout<<endl;
        print();
        cout<<endl;
    }
}



int main()
{
    //number of iteration
    int N;
    cout<<"please enter number of iteration: ";
    cin>>N;
    //size of array
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    rows=n,col=n;
    //dynamic char 2D array
    arr = new char *[rows];
    for(int i=0;i<rows;i++)
    {
        arr[i]=new char [col];
    }
    cout<<"start iteration(0) \n";
    //make user to  enter char array which represent iteration 0
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
            cin>>arr[i][j];
    }
    // dynamic int array to hold the number of close micro in each index ,make it eqaul zero at first
    counter=new int *[rows];
    for(int i=0;i<rows;i++)
    {
        counter[i]=new int [col];
    }
    number_of_iteration(N);
    // delete the dynamic array which i use in this program
    for(int i=0;i<rows;i++)
        delete []arr[i];
    delete []arr;
    for(int i=0;i<rows;i++)
        delete []counter[i];
    delete []counter;


    return 0;
}
