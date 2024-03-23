#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double f(double x)
{
    return (3./4)*x - (7./4);
}

int main()
{
    string fileName = "data.csv";
    ifstream ifstr(fileName);

    if(ifstr.fail())
    {
        cerr << "File not found" << endl;
        return 1;
    }

    double x = 0.0;
    double sum = 0.0;
    double mean = 0.0;
    unsigned int n = 0;

    ofstream ofstr("result.csv");

    string ofHeader = "# N Mean";
    ofstr << ofHeader << endl;

    while(ifstr >> x)
    {
        double val = f(x);
        sum += val;
        mean = sum/++n;
        ofstr << n << " " << setprecision(16) << scientific << mean << endl;
    }

    ifstr.close();
    ofstr.close();

    return 0;
}
