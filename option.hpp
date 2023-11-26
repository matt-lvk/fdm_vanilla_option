//
//  option.hpp
//  fdm_vanilla_option
//
//  Created by Matthew liew on 14.11.23.
//

#ifndef option_hpp
#define option_hpp

#include "payoff.hpp"
#include <memory>

class VanillaOption {
public:
    PayOff* pay_off;
    
    double K, r, T, sigma;
    
    VanillaOption();
    VanillaOption(double _K, double _r, double _T,
                  double _sigma, PayOff* pay_off);
    ~VanillaOption(){};
};

#endif /* option_hpp */
