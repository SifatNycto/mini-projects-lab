#include <iostream>
#include <iomanip>
#include <cmath>

namespace credit{
    int spl, spls, eng, mat, phy;
}
namespace sum_sub{
    double spl, spls, eng, mat, phy;
}

int main()
{
    //The Title
    std::cout << "+---------------------------------------+" << std::endl;
    std::cout << "| >>>>>>>        WELCOME        <<<<<<< |" << '\n';
    std::cout << "| >>>>>>>>         TO          <<<<<<<< |" << std::endl;
    std::cout << "| >>>>>>>>>  CGPA CALCULATOR  <<<<<<<<< |" << '\n';
    std::cout << "| >>>>>>>>>>.................<<<<<<<<<< |" << std::endl;
    std::cout << "| >>>>>>>>>>>...............<<<<<<<<<<< |" << '\n';
    std::cout << "| >>>>>>>>>>>>.............<<<<<<<<<<<< |" << std::endl;
    std::cout << "| >>>>>>>>>>>>>...........<<<<<<<<<<<<< |" << '\n';
    std::cout << "| >>>>>>>>>>>>>>.........<<<<<<<<<<<<<< |" << std::endl;
    std::cout << "| >>>>>>>>>>>>>>>.......<<<<<<<<<<<<<<< |" << '\n';
    std::cout << "| >>>>>>>>>>>>>>>>.....<<<<<<<<<<<<<<<< |" << std::endl;
    std::cout << "| >>>>>>>>>>>>>>>>>...<<<<<<<<<<<<<<<<< |" << '\n';
    std::cout << "| >>>>>>>>>>>>>>>>>>.<<<<<<<<<<<<<<<<<< |" << std::endl;
    std::cout << "+---------------------------------------+" << '\n';

    double spl, spls, eng, mat, phy;

    std::cout << "\nEnter SPL Grade: ";
    std::cin >> spl;
    std::cout << "\nEnter SPL Credit: ";
    std::cin >> credit::spl;

    std::cout << "\nEnter SPL Sessional Grade: ";
    std::cin >> spls;
    std::cout << "\nEnter SPL Sessional Credit: ";
    std::cin >> credit::spls;

    std::cout << "\nEnter English Grade: ";
    std::cin >> eng;
    std::cout << "\nEnter Engligh Credit: ";
    std::cin >> credit::eng;

    std::cout << "\nEnter Math Grade: ";
    std::cin >> mat;
    std::cout << "\nEnter Math Credit: ";
    std::cin >> credit::mat;

    std::cout << "\nEnter Physics Grade: ";
    std::cin >> phy;
    std::cout << "\nEnter Physics Credit: ";
    std::cin >> credit::phy;

    sum_sub::spl = spl * credit::spl;
    sum_sub::spls = spls * credit::spls;
    sum_sub::eng = eng * credit::eng;
    sum_sub::mat = mat * credit::mat;
    sum_sub::phy = phy * credit::phy;
    
    double total_sub_credit_sum = sum_sub::spl + sum_sub::spls + sum_sub::eng + sum_sub::mat + sum_sub::phy;

    double total_credit = (double) (credit::spl + credit::spls + credit::eng + credit::mat + credit::phy);

    double Final_Grade = (total_sub_credit_sum / total_credit);

    std::cout << std::endl << std::fixed << std::setprecision(2) << '\n' << "Your CGPA = " << Final_Grade;

    return 0;
}
