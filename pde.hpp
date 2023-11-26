//
//  pde.hpp
//  fdm_vanilla_option
//
//  Created by Matthew liew on 14.11.23.
//

#ifndef pde_hpp
#define pde_hpp

#include "option.hpp"

class DiffusionPDE {
public:
    virtual double diff_coeff(const double& S, const double& t) const = 0;
    virtual double conv_coeff(const double& S, const double& t) const = 0;
    virtual double zero_coeff(const double& S, const double& t) const = 0;
    virtual double source_coeff(const double& S, const double& t) const = 0;
    
    //initial & boundary conditions
    virtual double init_cond(const double& S) const = 0;
    virtual double boundary_left(const double& S, const double& t) const = 0;
    virtual double boundary_right(const double& S, const double& t) const = 0;
};

class BlackScholesPDE : public DiffusionPDE {
public:
    VanillaOption* option;
    BlackScholesPDE(VanillaOption* _option);
    
    double diff_coeff(const double& S, const double& t) const;
    double conv_coeff(const double& S, const double &t) const;
    double zero_coeff(const double& S, const double &t) const;
    double source_coeff(const double& S, const double &t) const;
    
    //initial & boundary conditions
    double init_cond(const double& S) const;
    double boundary_left(const double& S, const double& t) const;
    double boundary_right(const double& S, const double& t) const;
};
#endif /* pde_hpp */
