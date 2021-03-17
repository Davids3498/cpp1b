#include "snowman.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
const int TEN = 10;
const int EIGHT = 8;

//function that checks if correct input
bool check_num(int n)
{
    string str = to_string(n);
    if (str.length() != EIGHT)
    {
        return false;
    }
    while (n > 0)
    {
        int i = n % TEN;
        if (i < 0 || i > 4)
        {
            return false;
        }
        n = n / TEN;
    }
    return true;
}

//generater hat
string getHat(int n)
{
    switch (n)
    {
    case 1:
        return "\n _===_";
    case 2:
        return " ___ \n .....";
    case 3:
        return "  _  \n  /_\\";
    case 4:
        return " ___ \n (_*_)";
    default:
        throw std::out_of_range{"the number" + to_string(n) + "is invalid"};
    }
}

//generate nose
string getNose(int n)
{
    switch (n)
    {
    case 1:
        return ",";
    case 2:
        return ".";
    case 3:
        return "_";
    case 4:
        return " ";
    default:
        throw std::out_of_range{"the number" + to_string(n) + "is invalid"};
    }
}

//generate eye
string getEye(int n)
{
    switch (n)
    {
    case 1:
        return ".";
    case 2:
        return "o";
    case 3:
        return "O";
    case 4:
        return "-";
    default:
        throw std::out_of_range{"the number" + to_string(n) + "is invalid"};
    }
}

//generate Left arm
string getLarm(int n)
{
    switch (n)
    {
    case 1:
        return "<";
    case 2:
        return "\\";
    case 3:
        return "/";
    case 4:
        return "";
    default:
        throw std::out_of_range{"the number" + to_string(n) + "is invalid"};
    }
}

//generate Right arm
string getRarm(int n)
{
    switch (n)
    {
    case 1:
        return ">";
    case 2:
        return "/";
    case 3:
        return "\\";
    case 4:
        return "";
    default:
        throw std::out_of_range{"the number" + to_string(n) + "is invalid"};
    }
}

//generate torso
string getTorso(int n)
{
    switch (n)
    {
    case 1:
        return "( : )";
    case 2:
        return "(] [)";
    case 3:
        return "(> <)";
    case 4:
        return "(   )";
    default:
        throw std::out_of_range{"the number" + to_string(n) + "is invalid"};
    }
}

//generate base
string getBase(int n)
{
    switch (n)
    {
    case 1:
        return "( : )";
    case 2:
        return "(\" \")";
    case 3:
        return "(___)";
    case 4:
        return "(   )";
    default:
        throw std::out_of_range{"the number" + to_string(n) + "is invalid"};
    }
}

//building the sbowman
namespace ariel
{
    string snowman(int n)
    {
        if (!check_num(n))
        {
            throw std::out_of_range{"number too long or too short"};
        }
        int input = n;

        string base = getBase(input % TEN);

        input = input / TEN;
        string torso = getTorso(input % TEN);

        input = input / TEN;
        int rightArm = input % TEN;
        string Rarm = getRarm(rightArm);

        input = input / TEN;
        int leftArm = input % TEN;
        string Larm = getLarm(leftArm);

        input = input / TEN;
        string Reye = getEye(input % TEN);

        input = input / TEN;
        string Leye = getEye(input % TEN);

        input = input / TEN;
        string nose = getNose(input % TEN);

        input = input / TEN;
        string hat = getHat(input);

        string SnowWoman;

        if (leftArm == 2 && rightArm == 2)
        {
            SnowWoman = " " + hat + "\n" + Larm + "(" + Leye + nose + Reye + ")" + Rarm + "\n" + " " + torso + "\n" + " " + base;
        }
        else if (leftArm == 2)
        {
            SnowWoman = " " + hat + "\n" + Larm + "(" + Leye + nose + Reye + ")" + "\n" + torso + Rarm + "\n" + base;
        }
        else if (rightArm == 2)
        {
            SnowWoman = " " + hat + "\n" + "(" + Leye + nose + Reye + ")" + Rarm + "\n" + Larm + torso + "\n" + base;
        }
        else if (leftArm == 4)
        {
            SnowWoman = " " + hat + "\n" + " " + "(" + Leye + nose + Reye + ")"+ "\n" + " " + Larm + torso + Rarm + "\n" + " " + base;
        }
        else
        {
            SnowWoman = " " + hat + "\n" + " " + "(" + Leye + nose + Reye + ")" + "\n" + Larm + torso + Rarm + "\n" + " " + base;
        }
        return SnowWoman;
    }
}
