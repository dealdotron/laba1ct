#include <iostream>
#include <cmath>
#include <windows.h> // позволяет использовать команду сетконсоль
double chislitel(int nomer , double x) {
    double result = 1;
    for (int i=0; i < (nomer*2); i++) {
        result*=x;
    }
    return result;
}
    int main()
    {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // делает чтобы в консоле выводились сообщения на РУССКОМ
    int nomer = 1;
    int znak = -1;
    double To_zn;
    double x;
    std::cout << "введите значение аргумента косинуса" << std::endl;
    std::cin >> x; if (std::cin) std::cout << x << std::endl; // ввели х который будет арг косинуса
    if (std::cin.fail()) {
        std::cout << "введи число, не буквы";
        return 1;
    }
    To_zn = std::cos(x); // точное значение
    double Te_sum = 1; // текущая сумма 
    int n = 1;
    double factorial = 1 * 2;
    double razn;
    razn =(To_zn - Te_sum); 
    if (razn < 0) {
        razn = razn * (-1);
    }
    double pogr;
    std::cout << "введите допустимую погрешность" << std::endl;
    std::cin >> pogr; if (std::cin) std::cout << pogr << std::endl;
    if (std::cin.fail()) {
        std::cout << "введи число, не буквы";
        return 2;
    }
    if (pogr <= 0) {
        std::cout << "ошибка, погрешность должна быть больше 0!" << std::endl;
        return 3;
    }
    while (razn > pogr) {
        Te_sum = Te_sum + znak * (chislitel(nomer,x) / factorial);
        razn =(To_zn - Te_sum);
        if (razn < 0) {
            razn = razn * -1;
        }
        factorial = factorial * (2 * n + 1) * (2 * n + 2);
        n = n + 1;
        znak = znak * -1;
        nomer = nomer + 1;
    }
    std::cout << "сумма просумированных элементов:\n" << Te_sum << std::endl;
    std::cout << "точная сумма:\n" << cos(x) << std::endl;
    std::cout << "количество просумированных элементов:\n" << n << std::endl;
    std::cout << "разность между точным значением и суммы:\n" << razn << std::endl;
    return 0;
}
