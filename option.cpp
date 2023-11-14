//
//  option.cpp
//  fdm_vanilla_option
//
//  Created by Matthew liew on 14.11.23.
//

#include "option.hpp"

VanillaOption::VanillaOption() {}

VanillaOption::VanillaOption(double _K, double _r, double _T,
                             double _sigma, std::unique_ptr<PayOff> _pay_off)
: K(_K), r(_r), T(_T), sigma(_sigma), pay_off(std::move(_pay_off)) {}

