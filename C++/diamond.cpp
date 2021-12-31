#include <iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    for(int i=1; i<=2*size; i++){//controls rows
        if(i<=size){
            for(int space=1; space<=size-i; space++){//controls spaces
                cout<<" ";
            }
            for(int star=1; star<=(2*i)-1; star++){//comtrols stars
                cout<<"*";
            }
        }
        else{
            (i==size+1)?i++:0;//skips the first line of the rows
            for(int space=1; space<=((i-size) - 1); space++){//controls spaces
                cout<<" ";
            }
            for(int star=1; star<=((2*size) - (2*(i-size)) + 1); star++){//comtrols stars
                cout<<"*";
            }
        }
        cout<<endl;//new line after every iteration
    }
    return 0;
}