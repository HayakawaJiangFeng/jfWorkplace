#include <iostream>
#include <algorithm>
#include <set>

std::set<std::pair<std::pair<double, double>, double> > s;

int main(){

    for(int x1 = 0; x1 <= 19; x1++){

        for(int y1 = 0; y1 <= 20; y1++){

            for(int x2 = 0; x2 <= 19; x2++){

                for(int y2 = 0; y2 <= 20; y2++){

                    if(x1 != x2 && y1 != y2){

                        double a = y1 - y2;
                        double b = x2 - x1;
                        double c = y2 * x1 - y1 * x2;
                        double m = std::__algo_gcd(std::__algo_gcd(static_cast<int>(a),static_cast<int>(b)), static_cast<int>(c));
                        s.insert(std::make_pair(std::make_pair(a / m, b / m), c / m));
                    }
                }
            }
        }
    }
    std::cout << s.size() + 20 + 21 << std::endl;
    return 0;
}