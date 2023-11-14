//
//  payoff.cpp
//  fdm_vanilla_option
//
//  Created by Matthew liew on 14.11.23.
//

#include "payoff.hpp"

PayOff::PayOff() {}

PayOffCall::PayOffCall(const double& _K) : K(_K) {}

double PayOffCall::operator() (const double& S) const {
    return std::max(S - K, 0.0);
}

PayOffPut::PayOffPut(const double& _K) : K(_K) {}

double PayOffPut::operator() (const double& S) const {
    return std::max(K - S, 0.0);
}
