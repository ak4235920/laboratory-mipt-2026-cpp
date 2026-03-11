#include <iostream>//input-output-stream//include-подключение библиотек
int main() {
    std::cout <<"hello world 1" <<123<<'d'<< std::endl;
    //out - output
    int x=0, y=0;
    float z=0.0f;
    x=10+12;
    y=x*5;
    //z=y;
    //z/=7;
    //z=y/7.0;
    z=static_cast<float>(x)/y;//перевод из одного типа в другой
    z=5.5;
    for (int idx=1; idx<5; ++idx){
        z*=5.5;
    }
    std::cout <<x<<' '<<y<<' '<<z<< std::endl;
    //std::cout <<z<<' '<< ++z <<' '<< z++ <<' '<<z<< std::endl;//префиксный меняет сразу, постфиксный после вывода
    x=y%52;
    std::cout <<x<< std::endl;
    bool flag = 12;
    flag = false;
    if ((x<y) and (y>10)) {
        std::cout <<"x<y, y>10"<< std::endl;
    } else{
        std::cout <<"no"<< std::endl;
    }
    while (x>0){
        ++x;
    }
    std::cout <<--x<< std::endl;//верхняя граница целых чисел
    return 0;
}
//ввод g++ #путь# -o main
//./main