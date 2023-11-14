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
    std::unique_ptr<PayOff> pay_off;
    
    double K, r, T, sigma;
    
    VanillaOption();
    VanillaOption(double _K, double _r, double _T,
                  double _sigma, std::unique_ptr<PayOff> pay_off);
};

#endif /* option_hpp */
