#include <iostream>
using namespace std;

class queue{
    private:
        int cur;
        char arr[5];
    public:
        queue(){//Constructor
            cur=-1;
        }
        void push(char);
        void pop();
        void peek();
        void display();
};

int main(){
    queue q1;
    char cha;
    int loop=0;
    while(loop==0){
        int ch;
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter a character:";
                cin>>cha;
                q1.push(cha);
                break;
            case 2:
                q1.pop();
                break;
            case 3:
                q1.peek();
                break;
                case 4:
                q1.display();
                break;
            case 5:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
        }
    }
}



void queue::push(char cha){
    int temp=cur;
    arr[temp+1]=cha;
    cur++;
    cout<<"\nThe element is pushed in the queue\n\n";
}

void queue::pop(){
    if (cur== (-1)){
        cout<<"\nThe list is empty\n\n";
    }
    else{
        char ele=arr[0];
        int temp=1;
        while (temp<=cur){
            arr[temp-1]=arr[temp];
            temp++;
        }
        arr[temp-1]=NULL;
        cur--;
        cout<<"\nThe popped element:"<<ele<<"\n\n";
    }
}

void queue::peek(){
    char top=arr[0];
    cout<<"\nTop->"<<top<<"\n\n";
}

void queue::display(){
    cout<<"\n";
    for (int i=0;i<=cur;i++){
        cout<<arr[i]<<",";
    }
    cout<<"END";
    cout<<"\n\n";
}