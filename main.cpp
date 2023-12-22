#include  <iostream>
char str[20];
int main(){
    /*Normal Terminal command*/
    /*
    std::cout << "What's your name?\n";
    std::cin >> str;
    std::cout << "Hello, " << str;
    std::cout << "\n";
    */
    
    /*Define Variable and print it*/
    /*
    int b;
    do {
        std::cout << "Is it raining? (Enter 1 for true or 0 for false to print b value)\n";
        std::cin >> b;
        if (b==1){
        std::cout << "Bring your Umbrella Today!\n"; 
        }
        else if(b==0){
            std::cout << "No need for Umbrella Today!\n";
        }
        else{
            std::cout << "Please enter valid response. Try Again!!\n";
        }
    } while (b!=1 && b!=0);
    */
    /*Different kind of variables*/
    /*
    try{
    uint8_t a;
    a = 255;
    std::cout << "Value of a = " << static_cast<int>(a) << "\n";
    }
    catch(const std::runtime_error & e){
        std::cout<<"Error occured: " << e.what();
    }
    */
    /*Pointer variable*/
    /*
    int n = 5;
    int *ptr;
    ptr = &n;
    std::cout << "Value of address of n: " << &n << "\n";
    std:: cout << "Value stored at " << &n << " is " << *ptr << "\n";
    */    
    return 0; 
}